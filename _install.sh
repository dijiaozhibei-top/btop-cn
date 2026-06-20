#!/bin/bash
# btop-cn 一键安装 - 多架构支持
# 使用: bash <(curl -sL https://www.dijiaozhibei.top/btop-cn.sh)
set -e

REPO="dijiaozhibei-top/btop-cn"
API="https://api.github.com/repos/$REPO/releases/latest"
URL_WEB="https://www.dijiaozhibei.top/btop-cn.tar.gz"

echo "================================================"
echo "  btop 中文版一键安装"
echo "================================================"
echo ""
echo "请选择安装方式:"
echo "  1) 安装为 btop-cn（保留原版 btop，配置文件独立）"
echo "  2) 安装为 btop（覆盖原版，共用配置文件）"
echo ""
read -p "请输入 1 或 2: " choice

case "$choice" in
    1) MODE="independent" ;;
    2) MODE="override" ;;
    *) echo "无效选择，退出"; exit 1 ;;
esac

# 检测架构
ARCH=$(uname -m)
case "$ARCH" in
    x86_64|amd64)     BIN_ARCH="linux-x86_64" ;;
    aarch64|arm64)    BIN_ARCH="linux-aarch64" ;;
    armv7l|armv7)     BIN_ARCH="linux-armv7" ;;
    i686|i386)        BIN_ARCH="linux-i686" ;;
    *)                BIN_ARCH="" ;;
esac

# 检测 sudo
SUDO=""
if [ "$(id -u)" != "0" ]; then
    if command -v sudo &> /dev/null; then
        SUDO="sudo"
    else
        echo "需要 root 权限"
        exit 1
    fi
fi

# 下载
echo "[1/3] 下载 btop-cn..."

cd /tmp
rm -f btop-cn btop-cn.tar.gz

if [ -n "$BIN_ARCH" ]; then
    # 优先从 GitHub Release 下载对应架构的二进制
    echo "  检测到架构: $ARCH → 从 GitHub Releases 下载..."
    DOWNLOAD_URL=$(curl -sL "$API" | python3 -c "
import sys, json
try:
    data = json.load(sys.stdin)
    assets = data.get('assets', [])
    for a in assets:
        if '$BIN_ARCH' in a['name']:
            print(a['browser_download_url'])
            break
except: pass
" 2>/dev/null)
    if [ -n "$DOWNLOAD_URL" ]; then
        echo "  下载: $DOWNLOAD_URL"
        curl -sL "$DOWNLOAD_URL" -o btop-cn
    else
        echo "  GitHub Release 未找到，改用网站下载..."
        BIN_ARCH=""
    fi
fi

if [ -z "$BIN_ARCH" ]; then
    # 后备：从网站下载 x86_64 二进制
    echo "  从网站下载通用二进制..."
    curl -sL "$URL_WEB" -o btop-cn.tar.gz
    tar xzf btop-cn.tar.gz
fi

# 验证
if [ ! -f btop-cn ]; then
    echo "下载失败！"
    exit 1
fi

# 安装
echo "[2/3] 安装..."

if [ "$MODE" = "independent" ]; then
    # === 独立模式 ===
    $SUDO mkdir -p /usr/local/libexec
    $SUDO cp btop-cn /usr/local/libexec/btop-cn
    $SUDO chmod 755 /usr/local/libexec/btop-cn

    # 创建独立配置文件
    CONF_DIR="$HOME/.config/btop"
    CONF_FILE="$CONF_DIR/btop-cn.conf"
    mkdir -p "$CONF_DIR"

    if [ ! -f "$CONF_FILE" ]; then
        /usr/local/libexec/btop-cn --default-config > "$CONF_FILE" 2>/dev/null || true
    fi
    if grep -q 'lang' "$CONF_FILE" 2>/dev/null; then
        sed -i 's/.*lang.*/lang = "zh"/' "$CONF_FILE"
    else
        echo 'lang = "zh"' >> "$CONF_FILE"
    fi

    # 创建封装脚本
    $SUDO tee /usr/local/bin/btop-cn > /dev/null << 'WRAPPER'
#!/bin/bash
CONF="$HOME/.config/btop/btop-cn.conf"
exec /usr/local/libexec/btop-cn --config "$CONF" "$@"
WRAPPER
    $SUDO chmod 755 /usr/local/bin/btop-cn

    echo "  运行 btop-cn → 中文版（配置独立）"
    echo "  运行 btop    → 原版（不受影响）"
else
    # === 覆盖模式 ===
    $SUDO cp btop-cn "/usr/local/bin/btop"
    $SUDO chmod 755 "/usr/local/bin/btop"

    mkdir -p ~/.config/btop
    if [ -f ~/.config/btop/btop.conf ] && grep -q 'lang' ~/.config/btop/btop.conf 2>/dev/null; then
        sed -i 's/.*lang.*/lang = "zh"/' ~/.config/btop/btop.conf
    else
        echo 'lang = "zh"' >> ~/.config/btop/btop.conf
    fi

    echo "  运行 btop → 中文版"
fi

# 清理
rm -f btop-cn btop-cn.conf btop-cn.tar.gz

echo ""
echo "[3/3] 完成！"
echo "================================================"
