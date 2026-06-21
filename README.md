# ![btop++](Img/logo.png)

[![Linux](https://img.shields.io/badge/-Linux-grey?logo=linux)](https://github.com/aristocratos/btop)
[![macOS](https://img.shields.io/badge/-macOS-black?logo=apple)](https://github.com/aristocratos/btop)
[![FreeBSD](https://img.shields.io/badge/-FreeBSD-red?logo=freebsd)](https://github.com/aristocratos/btop)
[![c++23](https://img.shields.io/badge/cpp-c%2B%2B23-green)](https://github.com/aristocratos/btop)
[![中文版](https://img.shields.io/badge/中文-汉化版-blue)](https://github.com/dijiaozhibei-top/btop-cn)

# btop-cn — btop++ 中文汉化版

基于 [btop++](https://github.com/aristocratos/btop) 的中文汉化版本，全界面中文翻译，静态编译，开箱即用。

**GitHub 仓库：** https://github.com/dijiaozhibei-top/btop-cn

---

## 📦 一键安装

```bash
bash <(curl -sL https://www.dijiaozhibei.top/btop-cn.sh)
```

安装时选择：
- **1** → 安装为 `btop-cn`（保留原版，互不影响）
- **2** → 覆盖系统 `btop`

## ✨ 功能

- ✅ **全界面中文**：菜单、对话框、标签、提示全部汉化
- ✅ **静态编译**：不依赖系统库版本，任何 Linux 都能运行
- ✅ **多架构**：x86_64 / ARM64 / ARMv7 / i686 全部支持
- ✅ **配置独立**：与原版 btop 配置文件完全隔离
- ✅ 实时显示 CPU、内存、磁盘、网络、进程
- ✅ GPU 监控（NVIDIA/AMD/Intel）
- ✅ 完整的鼠标支持
- ✅ 游戏风格菜单系统
- ✅ 进程树状视图
- ✅ 可自定义主题

## 📸 截图

![normal](Img/normal.png)
![main-menu](Img/main-menu.png)
![options-menu](Img/options-menu.png)
![help-menu](Img/help-menu.png)

## 🖥️ 使用方法

| 命令 | 说明 |
|---|---|
| `btop-cn` | 启动中文版（独立配置） |
| `btop` | 启动原版（如果安装了原版） |

### 快捷键

| 按键 | 功能 |
|---|---|
| `ESC` / `m` | 主菜单 |
| `F1` / `?` / `h` | 帮助 |
| `F2` / `o` | 选项 |
| `1`-`4` | 切换 CPU/内存/网络/进程面板 |
| `q` / `Ctrl+C` | 退出 |
| `↑` / `↓` | 选择进程 |
| `Enter` | 查看进程详情 |
| `f` / `/` | 过滤进程 |
| `t` | 终止进程 |
| `k` | 杀死进程 |
| `p` | 切换预设 |
| `+` / `-` | 调整刷新间隔 |

## 🔧 编译

需要 GCC 14+ 或 Clang 19+，支持 C++23。

```bash
# Ubuntu 24.04+
sudo apt install coreutils sed git build-essential lowdown
git clone https://github.com/dijiaozhibei-top/btop-cn.git
cd btop-cn
make CXX=g++-14
```

### 静态编译（推荐）

```bash
make STATIC=true GPU_SUPPORT=false CXX=g++-14
```

### CMake 编译

```bash
cmake -B build -G Ninja
cmake --build build
```

## ⚙️ 配置

配置文件位于 `~/.config/btop/btop-cn.conf`（独立模式）或 `~/.config/btop/btop.conf`（覆盖模式）。

在配置文件添加 `lang = "zh"` 启用中文。所有选项可在界面中修改。

## 🌐 语言

- 中文：设置 `lang = "zh"`（默认）
- 英文：设置 `lang = "en"`

## 📄 开源协议

Apache License 2.0

## 🙏 致谢

- [btop++](https://github.com/aristocratos/btop) — 优秀的系统资源监视器
