# NRF24-UTILS

A lightweight **C++ utilities library for embedded development** (Arduino, ESP32, and similar platforms) providing:

-   Colorized logging
-   Timestamped messages
-   Simple formatted logging
-   Hardware abstraction helpers
-   Experimental NRF24 communication utilities

This project was created to simplify debugging and logging during embedded development while keeping the implementation small, dependency-free, and portable.

---

# Features

## Colorized Logging

Logs are printed with ANSI terminal colors to make debugging easier.

Example output:

```
[00:00:01] [INFO] Booting system
[00:00:02] [SUCCESS] NRF24 connected
[00:00:03] [WARN] Signal strength low
[00:00:04] [ERROR] Packet lost
[00:00:05] [DEBUG] Payload size: 32 bytes
```

Supported log levels:

-   `INFO`
-   `SUCCESS`
-   `WARN`
-   `ERROR`
-   `DEBUG`

---

## Timestamped Logs

Each message is automatically prefixed with a timestamp:

```
[HH:MM:SS]
```

The timestamp is derived from system uptime.

---

## Simple Format System

The logger supports placeholder replacement using `%t`.

Example:

```cpp
logger.info("Hello %t %t", magenta("world"), blue("!"));
```

Output:

```
[00:00:10] [INFO] Hello world !
```

Formatting is implemented using variadic templates to keep the logger lightweight and dependency-free.

---

---

# Project Structure

```
nrf24-utils
│
├── include
│   ├── hal_serial.h
│   ├── hal_time.h
│   ├── log.h
│   ├── log_format.h
│   ├── radio.h
│   └── utilities.h
│
├── src
│   ├── core
│   │   └── log
│   │       ├── log.cpp
│   │       └── ansi-codes.txt
│   │
│   ├── radio
│   │   ├── radio_arduino.cpp
│   │   └── radio_native.cpp
│   │
│   ├── hal
│   └── main.cpp
│
├── test
│   └── test_logger
│       └── test_log.cpp
│
├── platformio.ini
└── library.json
```

---

# Installation

### PlatformIO

Add the repository as a dependency:

```
lib_deps =
    https://github.com/YOUR_USERNAME/nrf24-utils
```

Or clone manually:

```
git clone https://github.com/YOUR_USERNAME/nrf24-utils
```

---

# Usage

Include the logger:

```cpp
#include "log.h"
```

Use the global logger instance:

```cpp
logger.info("System started");
logger.success("NRF24 connected");
logger.warn("Low signal strength");
logger.error("Packet lost");
logger.debug("Payload size: 32 bytes");
```

---

# Formatted Logging

Example with placeholders:

```cpp
logger.info("Colored %t %t", magenta("hello"), blue("world"));
```

---

# Testing

Unit tests are implemented using Unity (PlatformIO).

Run tests with:

```
pio test
```

Tests include:

-   Timestamp formatting
-   Logger output
-   Colored formatting

---

# Hardware Abstraction

The logger depends on two small hardware abstraction layers.

### Serial HAL

```
hal_serial_print()
hal_serial_println()
```

### Time HAL

```
hal_time_ms()
```

This keeps the logger portable across boards.

---

# NRF24 Support (Experimental)

The repository also contains NRF24 radio utilities for Arduino and native builds.

These modules may evolve or be moved to a separate repository depending on project scope.

---

# Goals

-   Lightweight
-   Embedded friendly
-   No external dependencies
-   Clean serial debugging
-   Simple formatting

---

# Possible Future Improvements

-   Compile-time log levels
-   Log disabling in production builds
-   File logging for native builds
-   Expanded formatting support
-   Header-only version of the logger

---

## Regular colors

| Color   | ANSI Code  | Example Code Snippet     |
| ------- | ---------- | ------------------------ |
| Black   | `\x1B[30m` | `"\x1B[30mHello\x1B[0m"` |
| Red     | `\x1B[31m` | `"\x1B[31mHello\x1B[0m"` |
| Green   | `\x1B[32m` | `"\x1B[32mHello\x1B[0m"` |
| Yellow  | `\x1B[33m` | `"\x1B[33mHello\x1B[0m"` |
| Blue    | `\x1B[34m` | `"\x1B[34mHello\x1B[0m"` |
| Magenta | `\x1B[35m` | `"\x1B[35mHello\x1B[0m"` |
| Cyan    | `\x1B[36m` | `"\x1B[36mHello\x1B[0m"` |
| White   | `\x1B[37m` | `"\x1B[37mHello\x1B[0m"` |

## Bright colors

| Color               | ANSI Code  | Example Code Snippet     |
| ------------------- | ---------- | ------------------------ |
| Bright Black (Gray) | `\x1B[90m` | `"\x1B[90mHello\x1B[0m"` |
| Bright Red          | `\x1B[91m` | `"\x1B[91mHello\x1B[0m"` |
| Bright Green        | `\x1B[92m` | `"\x1B[92mHello\x1B[0m"` |
| Bright Yellow       | `\x1B[93m` | `"\x1B[93mHello\x1B[0m"` |
| Bright Blue         | `\x1B[94m` | `"\x1B[94mHello\x1B[0m"` |
| Bright Magenta      | `\x1B[95m` | `"\x1B[95mHello\x1B[0m"` |
| Bright Cyan         | `\x1B[96m` | `"\x1B[96mHello\x1B[0m"` |
| Bright White        | `\x1B[97m` | `"\x1B[97mHello\x1B[0m"` |

---

# License

MIT License

---

# Contributing

Pull requests and suggestions are welcome.

If you find bugs or have improvements for embedded workflows, feel free to open an issue.
