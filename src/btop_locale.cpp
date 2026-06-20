/* Copyright 2021 Aristocratos (jakob@qvantnet.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

indent = tab
tab-size = 4
*/

#include "btop_locale.hpp"

#include <string>
#include <string_view>
#include <unordered_map>

using std::string;

namespace Locale {

	static std::unordered_map<string, string> translations;
	static string current_lang = "en";

	bool init(const string& lang) {
		translations["Enter signal number: "] = "输入信号编号：";
		translations["Description:"] = "描述：";
		translations["Key:"] = "键：";
		if (lang == "en") return true;
		if (lang != "zh") return false;

		// ========== Help text ==========
		translations["Clicks buttons and selects in process list."] = "点击按钮并在进程列表中选择。";
		translations["Scrolls any scrollable list/text under cursor."] = "滚动光标下的列表或文本。";
		translations["Toggles main menu."] = "切换主菜单。";
		translations["Cycle view presets forwards."] = "向前循环视图预设。";
		translations["Cycle view presets backwards."] = "向后循环视图预设。";
		translations["Toggle CPU box."] = "切换 CPU 面板。";
		translations["Toggle MEM box."] = "切换 MEM 面板。";
		translations["Toggle NET box."] = "切换 NET 面板。";
		translations["Toggle PROC box."] = "切换 PROC 面板。";
		translations["Toggle GPU box."] = "切换 GPU 面板。";
		translations["Toggle disks view in MEM box."] = "切换 MEM 面板中的磁盘视图。";
		translations["Shows options."] = "显示选项。";
		translations["Shows this window."] = "显示此窗口。";
		translations["Sleep program and put in background."] = "暂停程序并放入后台。";
		translations["Reloads config file from disk."] = "从磁盘重新加载配置文件。";
		translations["Quits program."] = "退出程序。";
		translations["Add/Subtract 100ms to/from update timer."] = "更新间隔增加/减少 100 毫秒。";
		translations["Select in process list."] = "在进程列表中选择。";
		translations["Show detailed information for selected process."] = "显示选定进程的详细信息。";
		translations["Expand/collapse the selected process in tree view."] = "在树视图中展开/折叠选中的进程。";
		translations["Expand/collapse the selected process' children."] = "展开/折叠选中进程的子进程。";
		translations["Jump 1 page in process list."] = "在进程列表中跳转一页。";
		translations["Jump to first or last page in process list."] = "跳转到进程列表的第一页或最后一页。";
		translations["Select previous/next sorting column."] = "选择上一个/下一个排序列。";
		translations["Select previous/next network device."] = "选择上一个/下一个网络设备。";
		translations["Toggle disks io mode with big graphs."] = "切换磁盘 IO 模式（大图表）。";
		translations["Toggle totals reset for current network device"] = "重置当前网络设备的总计数据";
		translations["Toggle auto scaling for the network graphs."] = "切换网络图表自动缩放。";
		translations["Toggle synced scaling mode for network graphs."] = "切换网络图表的同步缩放模式。";
		translations["To enter a process filter. Start with ! for regex."] = "输入进程过滤器。以 ! 开头使用正则表达式。";
		translations["Follow selected process."] = "跟踪选中的进程。";
		translations["Pause process list."] = "暂停进程列表。";
		translations["Clear any entered filter."] = "清除输入的过滤器。";
		translations["Toggle per-core cpu usage of processes."] = "切换进程的每核心 CPU 使用率显示。";
		translations["Reverse sorting order in processes box."] = "反转进程面板的排序顺序。";
		translations["Toggle processes tree view."] = "切换进程树状视图。";
		translations["Collapse/expand all processes in tree view."] = "折叠/展开树状视图中的所有进程。";
		translations["Toggles memory display mode in processes box."] = "切换进程面板中内存显示模式。";
		translations["Terminate selected process with SIGTERM - 15."] = "使用 SIGTERM - 15 终止选中的进程。";
		translations["Kill selected process with SIGKILL - 9."] = "使用 SIGKILL - 9 杀死选中的进程。";
		translations["Select or enter signal to send to process."] = "选择或输入要发送给进程的信号。";
		translations["Select new nice value for selected process."] = "为选中进程选择新的 nice 值。";
		translations["For bug reporting and project updates, visit:"] = "报告错误或了解项目更新，请访问：";

		// ========== Shortcut hints ==========
		translations["No boxes shown!"] = "没有显示面板！";
		translations["Show CPU box"] = "显示 CPU 面板";
		translations["Show MEM box"] = "显示内存面板";
		translations["Show NET box"] = "显示网络面板";
		translations["Show PROC box"] = "显示进程面板";
		translations["Show GPU boxes"] = "显示 GPU 面板";
		translations["Show menu"] = "显示菜单";

		// ========== Help dialog labels ==========
		translations["To choose signal."] = "选择信号。";
		translations["Enter manually."] = "手动输入。";
		translations["To send signal."] = "发送信号。";
		translations["To abort."] = "取消。";
		translations["To change value."] = "更改值。";
		translations["To change value by 5."] = "每次增减 5。";
		translations["To set nice value."] = "设定 nice 值。";
		translations["Renice PID "] = "重设 PID ";
		translations["Enter nice value: "] = "输入 nice 值：";

		// ========== Menu items ==========
		translations["Options"] = "选项";
		translations["Help"] = "帮助";
		translations["Quit"] = "退出";

		// ========== Box titles ==========
		translations["cpu"] = "CPU";
		translations["mem"] = "内存";
		translations["net"] = "网络";
		translations["proc"] = "进程";
		translations["GPU"] = "GPU";

		// ========== Config key display names (for options menu) ==========
		translations["lang"] = "语言";
		translations["color_theme"] = "颜色主题";
		translations["theme_background"] = "主题背景";
		translations["truecolor"] = "真彩色";
		translations["force_tty"] = "强制 TTY";
		translations["vim_keys"] = "Vim 键位";
		translations["disable_mouse"] = "禁用鼠标";
		translations["disable_presets"] = "禁用预设";
		translations["presets"] = "预设布局";
		translations["shown_boxes"] = "显示面板";
		translations["update_ms"] = "更新间隔";
		translations["rounded_corners"] = "圆角边框";
		translations["terminal_sync"] = "终端同步";
		translations["graph_symbol"] = "全局图表符号";
		translations["graph_symbol_cpu"] = "CPU 图表符号";
		translations["graph_symbol_gpu"] = "GPU 图表符号";
		translations["graph_symbol_mem"] = "内存图表符号";
		translations["graph_symbol_net"] = "网络图表符号";
		translations["graph_symbol_proc"] = "进程图表符号";
		translations["clock_format"] = "时钟格式";
		translations["base_10_sizes"] = "十进制单位";
		translations["background_update"] = "后台更新";
		translations["show_battery"] = "显示电池";
		translations["selected_battery"] = "选择电池";
		translations["show_battery_watts"] = "显示电池功率";
		translations["log_level"] = "日志级别";
		translations["save_config_on_exit"] = "退出时保存配置";
		translations["cpu_bottom"] = "CPU 面板位置";
		translations["cpu_graph_upper"] = "CPU 上部图表";
		translations["cpu_graph_lower"] = "CPU 下部图表";
		translations["cpu_invert_lower"] = "反转下部图表";
		translations["cpu_single_graph"] = "单一 CPU 图表";
		translations["check_temp"] = "CPU 温度";
		translations["cpu_sensor"] = "CPU 传感器";
		translations["show_coretemp"] = "核心温度";
		translations["cpu_core_map"] = "核心映射";
		translations["temp_scale"] = "温度单位";
		translations["show_cpu_freq"] = "显示 CPU 频率";
		translations["freq_mode"] = "频率模式";
		translations["custom_cpu_name"] = "自定义 CPU 名称";
		translations["show_uptime"] = "显示运行时间";
		translations["show_cpu_watts"] = "CPU 功耗";
		translations["show_gpu_info"] = "显示 GPU 信息";
		translations["gpu_mirror_graph"] = "GPU 镜像图表";
		translations["nvml_measure_pcie_speeds"] = "NVIDIA PCIe 速度";
		translations["rsmi_measure_pcie_speeds"] = "AMD PCIe 速度";
		translations["custom_gpu_name0"] = "GPU 0 名称";
		translations["custom_gpu_name1"] = "GPU 1 名称";
		translations["custom_gpu_name2"] = "GPU 2 名称";
		translations["custom_gpu_name3"] = "GPU 3 名称";
		translations["custom_gpu_name4"] = "GPU 4 名称";
		translations["custom_gpu_name5"] = "GPU 5 名称";
		translations["shown_gpus"] = "显示 GPU 厂商";
		translations["mem_below_net"] = "内存在网络下方";
		translations["mem_graphs"] = "内存图表模式";
		translations["show_disks"] = "显示磁盘";
		translations["show_io_stat"] = "IO 统计";
		translations["io_mode"] = "IO 模式";
		translations["io_graph_combined"] = "组合 IO 图表";
		translations["io_graph_speeds"] = "IO 图表速度";
		translations["show_swap"] = "显示交换分区";
		translations["swap_disk"] = "交换作为磁盘";
		translations["only_physical"] = "仅物理磁盘";
		translations["use_fstab"] = "使用 fstab";
		translations["zfs_hide_datasets"] = "隐藏 ZFS 数据集";
		translations["disk_free_priv"] = "磁盘可用空间";
		translations["disks_filter"] = "磁盘过滤器";
		translations["zfs_arc_cached"] = "ZFS ARC 缓存";
		translations["swap_upload_download"] = "交换上传下载";
		translations["net_download"] = "网络下载速度";
		translations["net_upload"] = "网络上传速度";
		translations["net_auto"] = "自动缩放";
		translations["net_sync"] = "同步缩放";
		translations["net_iface"] = "网络接口";
		translations["base_10_bitrate"] = "十进制比特率";
		translations["proc_left"] = "进程面板位置";
		translations["proc_sorting"] = "进程排序";
		translations["proc_reversed"] = "反转排序";
		translations["proc_tree"] = "树状视图";
		translations["proc_aggregate"] = "汇总子进程";
		translations["proc_tree_auto_collapse"] = "自动折叠阈值";
		translations["proc_colors"] = "进程颜色";
		translations["proc_gradient"] = "进程渐变";
		translations["proc_per_core"] = "每核心 CPU";
		translations["proc_mem_bytes"] = "内存以字节显示";
		translations["keep_dead_proc_usage"] = "保留已退出进程";
		translations["proc_cpu_graphs"] = "进程 CPU 图表";
		translations["proc_info_smaps"] = "smaps 内存信息";
		translations["proc_filter_kernel"] = "过滤内核进程";
		translations["proc_follow_detailed"] = "跟踪详细信息";

		// ========== Button labels and UI controls ==========
		translations["erminate"] = "终止";
		translations["ignals"] = "信号";
		translations["ollow"] = "跟踪";
		translations["ause"] = "暂停";
		translations["ore"] = "核心";
		translations["everse"] = "反转";
		translations["ilter"] = "过滤";
		translations[" delete "] = " 删除 ";
		translations[" select "] = " 选择 ";
		translations["info "] = "信息 ";
		translations["term"] = "终止";
		translations["ill"] = "杀死";
		translations["signal"] = "信号";
		translations["ice"] = "优先级";
		translations["pause"] = "暂停";
		translations["core"] = "核心";
		translations["reverse"] = "反转";
		translations["filter"] = "过滤";
		translations["del"] = "删除";

		// ========== Column headers ==========
		translations["Pid:"] = "PID：";
		translations["Program:"] = "程序：";
		translations["Command:"] = "命令：";
		translations["Tree:"] = "树：";
		translations["Threads: "] = "线程：";
		translations["User:"] = "用户：";
		translations["MemB"] = "内存B";
		translations["Mem%"] = "内存%";
		translations["Cpu%"] = "CPU%";

		// ========== Process detailed info ==========
		translations["Status:"] = "状态：";
		translations["Elapsed:"] = "已运行：";
		translations["IO/R:"] = "IO/读：";
		translations["IO/W:"] = "IO/写：";
		translations["Parent:"] = "父进程：";
		translations["Nice:"] = "优先级：";
		translations["CMD"] = "命令";
		translations["Memory: "] = "内存：";
		translations["M: "] = "内存：";

		// ========== Memory/disk labels ==========
		translations["Total:"] = "总计：";
		translations["Swap:"] = "交换：";
	translations["Upload"] = "上传";
	translations["Download"] = "下载";
	translations["isks"] = "磁盘";
	translations["enu"] = "菜单";
	translations["reset "] = "预设 ";
		translations["Used"] = "已用";
		translations["Free"] = "空闲";
		translations[" Used:"] = " 已用：";
		translations[" Free:"] = " 空闲：";
		translations["U"] = "用";
		translations["F"] = "空";
		translations[" IO% "] = " IO% ";
		translations[" IO   "] = " IO   ";

		// ========== Network labels ==========
		translations["Top: "] = "最高：";
		translations["Total: "] = "总计：";

		// ========== GPU labels ==========
		translations["PWR "] = "功耗 ";
		translations["P-state: "] = "P-状态：";
		translations["vram"] = "显存";
		translations["Utilization:"] = "利用率：";
		translations[" MHz"] = " MHz";
		translations["VRAM total:"] = "显存总计：";
		translations["VRAM usage:"] = "显存使用：";
		translations["VRAM clock:"] = "显存频率：";
		translations["ENC "] = "编码 ";
		translations["DEC "] = "解码 ";
		translations["TX:"] = "发送：";
		translations["RX:"] = "接收：";

		// ========== Process states ==========
		translations["Running"] = "运行中";
		translations["Sleeping"] = "休眠中";
		translations["Waiting"] = "等待中";
		translations["Zombie"] = "僵尸";
		translations["Stopped"] = "已停止";
		translations["Tracing"] = "跟踪中";
		translations["Dead"] = "已退出";
		translations["Wakekill"] = "唤醒杀死";
		translations["Unknown"] = "未知";
		translations["Parked"] = "已暂停";

		// ========== Config options display labels ==========
		translations["general"] = "通用";
		translations["gpu"] = "GPU";

		// ========== Temperature units ==========
		translations["°C"] = "°C";
		translations["°F"] = "°F";
		translations["K "] = "K ";
		translations["°R"] = "°R";

		// ========== Dialog texts ==========
		translations["signals"] = "信号";
		translations["Send signal to PID "] = "发送信号给 PID ";
		translations["↑ ↓ ← → | To choose signal."] = "↑ ↓ ← → | 选择信号。";
		translations["0-9 | Enter manually."] = "0-9 | 手动输入。";
		translations["ENTER | To send signal."] = "回车 | 发送信号。";
		translations["ESC or \"q\" | To abort."] = "ESC 或 \"q\" | 取消。";
		translations["Send signal: "] = "发送信号：";
		translations["To PID: "] = "目标 PID：";
		translations["Failure:"] = "失败：";
		translations["Unsupported signal!"] = "不支持的信号！";
		translations["Insufficient permissions to send signal!"] = "权限不足，无法发送信号！";
		translations["Process not found!"] = "未找到进程！";
		translations["Unknown error! (errno: "] = "未知错误！（错误号：";
		translations["Error:"] = "错误：";
		translations["error"] = "错误";
		translations["Terminal size too small to"] = "终端尺寸太小，无法";
		translations["display menu or box!"] = "显示菜单或面板！";
		translations["    Ok    "] = "    确定    ";
		translations["    Yes    "] = "    是    ";
		translations["    No    "] = "    否    ";
		translations["renice"] = "重设优先级";
		translations["↑ ↓ | To change value."] = "↑ ↓ | 更改值。";
		translations["← → | To change value by 5."] = "← → | 每次增减 5。";
		translations["ENTER | To set nice value."] = "回车 | 设定 nice 值。";
		translations["ESC or 'q' | To abort."] = "ESC 或 'q' | 取消。";
		translations[" page "] = " 页 ";
		translations["zero"] = "归零";
		translations["uto"] = "自动";
		translations["ync"] = "同步";

		// ========== Battery ==========
		translations["charging"] = "充电中";
		translations["discharging"] = "放电中";
		translations["full"] = "已满";
		translations["BAT"] = "电池";

		// ========== Sort options ==========
		translations["pid"] = "PID";
		translations["name"] = "名称";
		translations["command"] = "命令";
		translations["threads"] = "线程";
		translations["user"] = "用户";
		translations["memory"] = "内存";

		// ========== Messages ==========
		translations["Failed to join _runner thread on exit!"] = "退出时无法等待工作线程结束！";
		translations["Quitting! Runtime: "] = "正在退出！运行时间：";
		translations["Running in DEBUG mode!"] = "正在以调试模式运行！";
		translations["Failed to create user theme directory: "] = "无法创建用户主题目录：";
		translations["Failed to set locale "] = "无法设置区域 ";
		translations[" continuing anyway."] = " 将继续运行。";
		translations["Running on "] = "运行于 ";
		translations["Failed to get size of terminal!"] = "无法获取终端尺寸！";
		translations["Failed to create _runner thread!"] = "无法创建工作线程！";

		// ========== Config error messages ==========
		translations["Too many presets entered!"] = "输入的预设过多！";
		translations["Too many boxes entered for preset!"] = "预设中输入的面板过多！";
		translations["Malformatted preset in config value presets!"] = "配置值 presets 中的预设格式错误！";
		translations["Invalid box name in config value presets!"] = "配置值 presets 中的面板名称无效！";
		translations["Invalid position value in config value presets!"] = "配置值 presets 中的位置值无效！";
		translations["Invalid graph name in config value presets!"] = "配置值 presets 中的图表名称无效！";
		translations["Invalid graph symbol identifier: "] = "无效的图表符号标识符：";
		translations["Invalid graph symbol identifier for "] = "无效的图表符号标识符用于 ";
		translations["No boxes selected!"] = "未选择面板！";
		translations["Terminal too small to display entered boxes!"] = "终端太小，无法显示所选面板！";
		translations["Invalid box name(s) in shown_boxes!"] = "shown_boxes 中的面板名称无效！";
		translations["Logger set to "] = "日志级别已设为 ";
		translations["Invalid"] = "无效";
		translations["Could not detect a valid "] = "无法检测到有效的 ";
		translations["Please report the following bug: "] = "请报告以下错误：";

		// ========== CLI help ==========
		translations["Usage: btop [OPTIONS]"] = "用法：btop [选项]";
		translations["Options:"] = "选项：";
		translations["Path to a config file"] = "配置文件路径";
		translations["Start in debug mode with additional logs and metrics"] = "以调试模式启动，输出额外日志和指标";
		translations["Set an initial process filter"] = "设置初始进程过滤器";
		translations["Override automatic UTF locale detection"] = "覆盖自动 UTF 区域设置检测";
		translations["Disable true color, 256 colors only"] = "禁用真彩色，仅使用 256 色";
		translations["Start with a preset (0-9)"] = "以指定预设启动（0-9）";
		translations["Force tty mode with ANSI graph symbols and 16 colors only"] = "强制 TTY 模式，仅使用 ANSI 图表符号和 16 色";
		translations["Path to a custom themes directory"] = "自定义主题目录路径";
		translations["Force disable tty mode"] = "强制禁用 TTY 模式";
		translations["Set an initial update rate in milliseconds"] = "设置初始更新间隔（毫秒）";
		translations["Print default config to standard output"] = "输出默认配置到标准输出";
		translations["Show this help message and exit"] = "显示此帮助信息并退出";
		translations["Show a version message and exit (more with --version)"] = "显示版本信息并退出（使用 --version 查看更多）";
		translations["btop version: "] = "btop 版本：";
		translations["Compiled with: "] = "编译工具：";
		translations["Configured with: "] = "配置参数：";
		translations["error: "] = "错误：";
		translations["Filter requires an argument"] = "过滤器需要参数";
		translations["Update must be a positive number"] = "更新间隔必须为正数";
		translations["Update argument is out of range: "] = "更新间隔超出范围：";
		translations["Unknown argument '"] = "未知参数 '";
		translations["invalid default config: '=' not found"] = "无效的默认配置：未找到 '='";
		translations["For more information, try '--help'"] = "更多信息请尝试 '--help'";
		translations["Show a version message and exit"] = "显示版本信息并退出";

		// ========== CPU name filters ==========
		translations["Processor"] = "处理器";
		translations["CPU"] = "CPU";
		translations["(R)"] = "(R)";
		translations["(TM)"] = "(TM)";
		translations["Intel"] = "Intel";
		translations["AMD"] = "AMD";
		translations["Apple"] = "Apple";
		translations["Core"] = "Core";

		// ========== Config file descriptions (for config file comments) ==========
		translations["#* Name of a btop++/bpytop/bashtop formatted \".theme\" file, \"Default\" and \"TTY\" for builtin themes.\n#* Themes should be placed in \"../share/btop/themes\" relative to binary or \"$HOME/.config/btop/themes\""] =
			"#? btop++/bpytop/bashtop 格式的 \".theme\" 主题文件名称，\"Default\" 和 \"TTY\" 为内置主题。\n#* 主题文件应放在 \"../share/btop/themes\"（相对于可执行文件）或 \"$HOME/.config/btop/themes\"";
		translations["#* If the theme set background should be shown, set to False if you want terminal background transparency."] =
			"#* 是否显示主题背景色，设为 False 以使用终端背景透明效果。";
		translations["#* Sets if 24-bit truecolor should be used, will convert 24-bit colors to 256 color (6x6x6 color cube) if false."] =
			"#* 是否使用 24 位真彩色，设为 false 时将转换至 256 色。";
		translations["#* Set to true to force tty mode regardless if a real tty has been detected or not.\n#* Will force 16-color mode and TTY theme, set all graph symbols to \"tty\" and swap out other non tty friendly symbols."] =
			"#* 设为 true 以强制 TTY 模式（无论是否检测到真实 tty）。\n#* 将强制 16 色模式和 TTY 主题，所有图表符号设为 \"tty\"。";
		translations["#* Option to disable presets. Either the default preset, custom presets, or all presets.\n#* \"Off\" All presets are enabled.\n#* \"Default\" preset is disabled.\n#* \"Custom\" presets are disabled."] =
			"#* 禁用预设选项：可禁用默认预设、自定义预设或全部预设。\n#* \"Off\" 全部预设启用。\n#* \"Default\" 禁用默认预设。\n#* \"Custom\" 禁用自定义预设。";
		translations["#* Disable all mouse events."] = "#* 禁用所有鼠标事件。";
		translations["#* Rounded corners on boxes, is ignored if TTY mode is ON."] = "#* 面板的圆角边框，TTY 模式下忽略此设置。";
		translations["#* Use terminal synchronized output sequences to reduce flickering on supported terminals."] = "#* 使用终端同步输出序列以减少闪烁（支持的终端）。";
		translations["#* Set to True to enable \"h,j,k,l,g,G\" keys for directional control in lists.\n#* Conflicting keys for h:\"help\" and k:\"kill\" is accessible while holding shift."] =
			"#* 设为 True 以启用 \"h,j,k,l,g,G\" 方向控制键。\n#* 与 h:\"帮助\" 和 k:\"杀死\" 冲突的按键请在按住 Shift 时使用。";
		translations["#* Manually set which boxes to show. Available values are \"cpu mem net proc\" and \"gpu0\" through \"gpu5\", separate values with whitespace."] =
			"#* 手动设置要显示的面板。可用值有 \"cpu mem net proc\" 和 \"gpu0\" 至 \"gpu5\"，用空格分隔。";
		translations["#* Update time in milliseconds, recommended 2000 ms or above for better sample times for graphs."] = "#* 更新间隔（毫秒），建议 2000 毫秒以上以获得更好的图表采样时间。";
		translations["#* Reverse sorting order, True or False."] = "#* 反转排序顺序，True 或 False。";
		translations["#* Show processes as a tree."] = "#* 以树状图显示进程。";
		translations["#* Use the cpu graph colors in the process list."] = "#* 在进程列表中使用 CPU 图表颜色。";
		translations["#* Use a darkening gradient in the process list."] = "#* 在进程列表中使用渐变色。";
		translations["#* If process cpu usage should be of the core it's running on or usage of the total available cpu power."] = "#* 进程 CPU 使用率是基于其运行的核心还是总 CPU 能力。";
		translations["#* Show process memory as bytes instead of percent."] = "#* 以字节而非百分比显示进程内存。";
		translations["#* Show cpu graph for each process."] = "#* 为每个进程显示 CPU 图表。";
		translations["#* Use /proc/[pid]/smaps for memory information in the process info box (very slow but more accurate)"] = "#* 使用 /proc/[pid]/smaps 获取进程内存信息（很慢但更准确）";
		translations["#* Show proc box on left side of screen instead of right."] = "#* 在屏幕左侧而非右侧显示进程面板。";
		translations["#* (Linux) Filter processes tied to the Linux kernel(similar behavior to htop)."] = "#* (Linux) 过滤与 Linux 内核相关的进程（类似 htop 的行为）。";
		translations["#* Should the process list follow the selected process when detailed view is open."] = "#* 打开详细信息视图时，进程列表是否跟踪选中的进程。";
		translations["#* In tree-view, always accumulate child process resources in the parent process."] = "#* 在树状视图中，始终将子进程资源累加到父进程。";
		translations["#* In tree-view, auto-collapse processes with this many or more direct children when entering tree mode. 0 to disable."] = "#* 在树状视图中，进入树模式时自动折叠具有此数量或更多直接子进程的进程。设为 0 禁用。";
		translations["#* Should cpu and memory usage display be preserved for dead processes when paused."] = "#* 暂停时是否保留已退出进程的 CPU 和内存使用显示。";
		translations["#* Sets the CPU stat shown in upper half of the CPU graph, \"total\" is always available."] = "#* 设置 CPU 图表上半部分显示的统计项，\"total\" 始终可用。";
		translations["#* Sets the CPU stat shown in lower half of the CPU graph, \"total\" is always available."] = "#* 设置 CPU 图表下半部分显示的统计项，\"total\" 始终可用。";
		translations["#* Toggles if the lower CPU graph should be inverted."] = "#* 切换是否反转下半部分 CPU 图表。";
		translations["#* Set to True to completely disable the lower CPU graph."] = "#* 设为 True 以完全禁用下半部分 CPU 图表。";
		translations["#* Show cpu box at bottom of screen instead of top."] = "#* 将 CPU 面板显示在屏幕底部而非顶部。";
		translations["#* Shows the system uptime in the CPU box."] = "#* 在 CPU 面板中显示系统运行时间。";
		translations["#* Shows the CPU package current power consumption in watts. Requires running `make setcap` or `make setuid` or running with sudo."] = "#* 显示 CPU 当前功耗（瓦特）。需要运行 `make setcap` 或 `make setuid` 或以 sudo 运行。";
		translations["#* Show cpu temperature."] = "#* 显示 CPU 温度。";
		translations["#* Which sensor to use for cpu temperature, use options menu to select from list of available sensors."] = "#* 用于 CPU 温度的传感器，在选项菜单中从可用传感器列表选择。";
		translations["#* Show temperatures for cpu cores also if check_temp is True and sensors has been found."] = "#* 当 check_temp 为 True 且已找到传感器时，同时显示 CPU 核心温度。";
		translations["#* Which temperature scale to use, available values: \"celsius\", \"fahrenheit\", \"kelvin\" and \"rankine\"."] = "#* 使用的温度单位：\"celsius\"（摄氏）、\"fahrenheit\"（华氏）、\"kelvin\"（开尔文）或 \"rankine\"（兰金）。";
		translations["#* Use base 10 for bits/bytes sizes, KB = 1000 instead of KiB = 1024."] = "#* 使用十进制单位，KB = 1000 而非 KiB = 1024。";
		translations["#* Show CPU frequency."] = "#* 显示 CPU 频率。";
		translations["#* Draw a clock at top of screen, formatting according to strftime, empty string to disable."] = "#* 在屏幕顶部显示时钟，根据 strftime 格式化，留空禁用。";
		translations["#* Update main ui in background when menus are showing, set this to false if the menus is flickering too much for comfort."] = "#* 菜单显示时是否在后台更新主界面，如果菜单闪烁太厉害请设为 false。";
		translations["#* Custom cpu model name, empty string to disable."] = "#* 自定义 CPU 型号名称，留空禁用。";
		translations["#* Optional filter for shown disks, should be full path of a mountpoint, separate multiple values with whitespace \" \"."] = "#* 可选的要显示的磁盘过滤器，应为挂载点的完整路径，多个值用空格分隔。";
		translations["#* Show graphs instead of meters for memory values."] = "#* 使用图表而非仪表显示内存值。";
		translations["#* Show mem box below net box instead of above."] = "#* 将内存面板显示在网络面板下方而非上方。";
		translations["#* Count ZFS ARC in cached and available memory."] = "#* 将 ZFS ARC 计入缓存和可用内存。";
		translations["#* If swap memory should be shown in memory box."] = "#* 是否在内存面板中显示交换分区。";
		translations["#* Show swap as a disk, ignores show_swap value above, inserts itself after first disk."] = "#* 将交换分区作为磁盘显示，忽略上面的 show_swap 值，插入到第一个磁盘之后。";
		translations["#* If mem box should be split to also show disks info."] = "#* 是否拆分内存面板以同时显示磁盘信息。";
		translations["#* Filter out non physical disks. Set this to False to include network disks, RAM disks and similar."] = "#* 过滤非物理磁盘。设为 False 以包含网络磁盘、内存盘等。";
		translations["#* Read disks list from /etc/fstab. This also disables only_physical."] = "#* 从 /etc/fstab 读取磁盘列表。同时禁用 only_physical。";
		translations["#* Setting this to True will hide all datasets, and only show ZFS pools. (IO stats will be calculated per-pool)"] = "#* 设为 True 将隐藏所有数据集，仅显示 ZFS 存储池。（IO 统计将按池计算）";
		translations["#* Set to true to show available disk space for privileged users."] = "#* 设为 true 以向特权用户显示可用磁盘空间。";
		translations["#* Toggles if io activity %% (disk busy time) should be shown in regular disk usage view."] = "#* 切换是否在常规磁盘使用视图中显示 IO 活动百分比（磁盘繁忙时间）。";
		translations["#* Toggles io mode for disks, showing big graphs for disk read/write speeds."] = "#* 切换磁盘 IO 模式，显示磁盘读写速度的大图表。";
		translations["#* Set to True to show combined read/write io graphs in io mode."] = "#* 设为 True 以在 IO 模式下显示组合读写 IO 图表。";
		translations["#* Set fixed values for network graphs in Mebibits. Is only used if net_auto is also set to False."] = "#* 以 Mebibit 为单位设置网络图表的固定值。仅在 net_auto 设为 False 时使用。";
		translations["#* Use network graphs auto rescaling mode, ignores any values set above and rescales down to 10 Kibibytes at the lowest."] = "#* 使用网络图表自动缩放模式，忽略上述设定值，最低缩放到 10 KiB。";
		translations["#* Sync the auto scaling for download and upload to whichever currently has the highest scale."] = "#* 同步下载和上传的自动缩放，以当前最高缩放值为准。";
		translations["#* Starts with the Network Interface specified here."] = "#* 以此处指定的网络接口启动。";
		translations["#* \"True\" shows bitrates in base 10 (Kbps, Mbps). \"False\" shows bitrates in binary sizes (Kibps, Mibps, etc.). \"Auto\" uses base_10_sizes."] = "#* \"True\" 以十进制显示比特率（Kbps、Mbps）。\"False\" 以二进制显示（Kibps、Mibps 等）。\"Auto\" 使用 base_10_sizes 设置。";
		translations["#* Show battery stats in top right if battery is present."] = "#* 如果存在电池，在右上角显示电池状态。";
		translations["#* Which battery to use if multiple are present. \"Auto\" for auto detection."] = "#* 如果存在多个电池时使用的电池。\"Auto\" 为自动检测。";
		translations["#* Show power stats of battery next to charge indicator."] = "#* 在充电指示器旁显示电池功率状态。";
		translations["#* Set loglevel for \"~/.local/state/btop.log\" levels are: \"ERROR\" \"WARNING\" \"INFO\" \"DEBUG\".\n#* The level set includes all lower levels, i.e. \"DEBUG\" will show all logging info."] =
			"#* 设置 \"~/.local/state/btop.log\" 的日志级别：\"ERROR\"、\"WARNING\"、\"INFO\"、\"DEBUG\"。\n#* 设置的级别包含所有更低级别，即 \"DEBUG\" 将显示所有日志信息。";

		// ========== Process box labels and banners ==========
		translations["Process list paused"] = "进程列表已暂停";
		translations["Following process"] = "正在跟踪进程";
		translations["Paused list and Following process"] = "已暂停，正在跟踪进程";
		translations["Pause"] = "暂停";
		translations["PerCore"] = "每核心";
		translations["TreeView"] = "树状";
		translations["select "] = "选择 ";
		translations["cpu direct"] = "CPU 直接";
		translations["cpu lazy"] = "CPU 惰性";
		translations["Zero"] = "归零";
		translations["Sync"] = "同步";
		translations["free"] = "空闲";
		translations["Available"] = "可用";
		translations["Cached"] = "缓存";

		return true;
	}

	const std::string& get(const string& key) {
		auto it = translations.find(key);
		if (it != translations.end()) return it->second;
		return key; // fallback to key (English)
	}

	const string& currentLanguage() {
		return current_lang;
	}

	std::vector<string> availableLanguages() {
		return {"en", "zh"};
	}

	bool reload() {
		return init(current_lang);
	}

}
