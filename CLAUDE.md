# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

- **Make (primary):** `make` (in project root). Uses GCC/Clang with C++23.
- **Make with debug:** `make DEBUG=true`
- **Make static:** `make STATIC=true`
- **Make without GPU:** `make GPU_SUPPORT=false`
- **Make verbose:** `make VERBOSE=true`
- **CMake (community maintained):** `cmake -B build -G Ninja && cmake --build build`
- **CMake release:** `cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build build`
- **CMake no GPU:** `cmake -B build -G Ninja -DBTOP_GPU=OFF && cmake --build build`
- **Make flags:** `ADDFLAGS=-march=native`, `CXX=clang++`, `STRIP=true`
- **Clean:** `make clean` (objects only), `make distclean` (objects + binaries)
- **Install:** `sudo make install PREFIX=/usr/local`
- **Set capabilities:** `sudo make setcap` (preferred) or `sudo make setuid`

## Test Commands

Tests use GoogleTest, built via CMake automatically:

```bash
cmake -B build -G Ninja
cmake --build build
ctest --test-dir build
```

To disable tests: `cmake -B build -DBUILD_TESTING=OFF`

There are currently two test files in `tests/`: `cpu_names.cpp` and `tools.cpp`.

## Code Architecture

**btop++** is a cross-platform resource monitor for Linux, macOS, FreeBSD, NetBSD, and OpenBSD.

### Entry Point

`src/main.cpp` — minimal entry that delegates to `btop_main()` in `src/btop.cpp`.

### Core Modules (all in `src/`)

Each major concern is split into a `.cpp`/`.hpp` pair:

| Module | Responsibility |
|---|---|
| `btop.cpp` / `btop.hpp` | Main loop, initialization, signal handling, terminal setup, runner thread lifecycle |
| `btop_config.cpp` / `btop_config.hpp` | Config file reading/writing (TOML), option access |
| `btop_draw.cpp` / `btop_draw.hpp` | Box drawing, text editing, graph & meter widgets, layout calculation |
| `btop_input.cpp` / `btop_input.hpp` | Keyboard & mouse input polling, signal mask, action processing |
| `btop_menu.cpp` / `btop_menu.hpp` | Interactive UI menus (main menu, options, help) |
| `btop_shared.cpp` / `btop_shared.hpp` | Shared data types and namespace declarations for Cpu, Mem, Net, Proc, Gpu |
| `btop_theme.cpp` / `btop_theme.hpp` | Theme file loading and color management |
| `btop_tools.cpp` / `btop_tools.hpp` | Utility functions, terminal init, escape codes (Fx namespace), atomic waiting lock |
| `btop_cli.cpp` / `btop_cli.hpp` | CLI argument parsing |
| `btop_log.cpp` / `btop_log.hpp` | Logging (ERROR/WARNING/INFO/DEBUG levels) |

### Platform-Specific Collectors

System data collection is fully platform-specific, in separate source directories:

- `src/linux/btop_collect.cpp` — Linux `/proc`, `/sys`, GPU (NVML/ROCm/Intel)
- `src/freebsd/btop_collect.cpp` — FreeBSD via kvm, devstat
- `src/netbsd/btop_collect.cpp` — NetBSD via kvm, proplib
- `src/openbsd/btop_collect.cpp` — OpenBSD via kvm, custom sysctlbyname
- `src/osx/btop_collect.cpp` — macOS via IOKit, CoreFoundation

Each implements `collect()` functions in the `Cpu`, `Mem`, `Net`, and `Proc` namespaces with the same interface, selected at compile time via CMake.

### Data Namespaces (defined in `btop_shared.hpp`)

- **Cpu** — CPU stats, core temperatures, battery info, wattage
- **Mem** — Memory, swap, disk usage, disk I/O
- **Net** — Network bandwidth per interface, auto-scaling
- **Proc** — Process listing, sorting, tree view, filtering
- **Gpu** — GPU stats (NVIDIA/AMD/Intel/Apple Silicon), compiled with `GPU_SUPPORT`

### Data Flow

1. `Runner::run()` triggers `collect()` on each enabled namespace in a background thread
2. Each namespace's `collect()` reads raw system data and returns a struct (e.g., `cpu_info`, `mem_info`)
3. `Draw::calcSizes()` computes box positions based on config
4. Each namespace's `draw()` renders the collected data to a string with terminal escape codes
5. The main loop writes the combined output to stdout

### Coding Conventions

- **C++23** required (std::optional monads, std::expected, std::ranges, std::ranges::to, std::string::contains)
- **Indent:** tabs, tab-size 4
- **Braces:** same-line opening (`if (...) {`)
- Use alternative operators: `and`, `or`, `not`
- Use `fmt::format()` / `fmt::format_to()` for string building (not manual concatenation)
- Use `std::ranges` algorithms where applicable
- RAII for resource management
- Files start with Apache 2.0 license header

### Dependencies

- **Required:** C++23 compiler (GCC 14+ or Clang 19+), pthreads
- **Header-only:** fmt library (bundled in `include/fmt/`)
- **Optional:** lowdown (man page generation), GPU libraries (nvidia-ml, ROCm SMI, Intel GPU top)
- **Test:** GoogleTest (fetched via CMake FetchContent)

### GPU Support

Enabled by default on Linux x86_64 (dynamic linking only). Supports NVIDIA (`nvidia-ml`), AMD (`rocm_smi_lib`), and Intel GPUs. On macOS arm64, Apple Silicon GPU monitoring via IOReport.

### Config

TOML-based config at `$XDG_CONFIG_HOME/btop/btop.conf`. All options are changeable from the UI. Logs at `~/.local/state/btop.log`.

### Internationalization (i18n)

The project supports UI text translation via `src/btop_locale.hpp` / `src/btop_locale.cpp`.

- **Language selection:** Set `lang` in config file (`btop.conf`): `lang = "zh"` for Chinese, `lang = "en"` for English (default)
- **Adding translations:** Edit `src/btop_locale.cpp` — add entries to the `translations` map in `Locale::init()` with key=English string, value=translated string
- **Usage in code:** `#include "btop_locale.hpp"` then `Locale::get("English text")` — falls back to the English key if translation not found
- **Currently supported:** English (`en`) and Simplified Chinese (`zh`)

### Dependencies

- **Required:** C++23 compiler (GCC 14+ or Clang 19+), pthreads
- **Header-only:** fmt library (bundled in `include/fmt/`)
- **Optional:** lowdown (man page generation), GPU libraries (nvidia-ml, ROCm SMI, Intel GPU top)
- **Test:** GoogleTest (fetched via CMake FetchContent)

### GPU Support

Enabled by default on Linux x86_64 (dynamic linking only). Supports NVIDIA (`nvidia-ml`), AMD (`rocm_smi_lib`), and Intel GPUs. On macOS arm64, Apple Silicon GPU monitoring via IOReport.

### Config

TOML-based config at `$XDG_CONFIG_HOME/btop/btop.conf`. All options are changeable from the UI. Logs at `~/.local/state/btop.log`.
