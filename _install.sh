#!/bin/bash
# btop-cn 一键安装 - 直接下载二进制
# 使用: bash <(curl -sL https://www.dijiaozhibei.top/btop-cn.sh)
set -e

URL="https://www.dijiaozhibei.top/btop-cn.tar.gz"

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

echo ""
echo "================================================"

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
curl -sL "$URL" -o btop-cn.tar.gz

# 解压
echo "[2/3] 解压..."
tar xzf btop-cn.tar.gz

# 安装
echo "[3/3] 安装..."

if [ "$MODE" = "independent" ]; then
    # === 独立模式 ===
    # 把二进制放到 /usr/local/libexec/btop-cn（不直接在 PATH 里）
    $SUDO mkdir -p /usr/local/libexec
    $SUDO cp btop-cn /usr/local/libexec/btop-cn
    $SUDO chmod 755 /usr/local/libexec/btop-cn

    # 创建独立的配置文件
    CONF_DIR="$HOME/.config/btop"
    CONF_FILE="$CONF_DIR/btop-cn.conf"
    mkdir -p "$CONF_DIR"

    if [ ! -f "$CONF_FILE" ]; then
        /usr/local/libexec/btop-cn --default-config > "$CONF_FILE"
    fi
    # 确保 lang=zh
    if grep -q 'lang' "$CONF_FILE" 2>/dev/null; then
        sed -i 's/.*lang.*/lang = "zh"/' "$CONF_FILE"
    else
        echo 'lang = "zh"' >> "$CONF_FILE"
    fi

    # 创建封装脚本 /usr/local/bin/btop-cn
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

    # 共用配置文件，追加 lang=zh
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
echo "================================================"
echo "  安装完成！"
echo "================================================"
