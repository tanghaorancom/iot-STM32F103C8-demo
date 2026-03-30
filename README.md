# STM32F103C8 IoT Demo Project

## 项目概述

这是一个基于STM32F103微控制器的IoT演示项目，展示了如何使用STM32F103系列微控制器进行嵌入式系统开发。

## 目录结构

```
iot-STM32F103-demo/
├── Library/           # STM32F103标准库文件
├── Start/             # 启动文件和系统初始化
├── System/            # 系统级功能模块
├── User/              # 用户应用代码
├── MyProject.uvprojx  # Keil项目文件
├── MyProject.uvoptx   # Keil项目选项文件
├── keilkill.bat       # 清理Keil生成文件的批处理脚本
└── .gitignore         # Git忽略文件配置
```

## 开发环境

- **IDE**: Keil MDK-ARM
- **编译器**: ARM Compiler 5或更高版本
- **调试器**: ST-Link或J-Link
- **硬件**: STM32F103系列开发板

## 编译步骤

1. 打开Keil MDK-ARM
2. 加载`MyProject.uvprojx`项目文件
3. 点击"Build"按钮编译项目
4. 编译成功后会生成`.hex`和`.bin`文件

## 烧录步骤

1. 将ST-Link或J-Link连接到开发板
2. 在Keil中点击"Download"按钮烧录程序
3. 或使用STM32CubeProgrammer等工具烧录生成的`.hex`文件

## 主要功能

- 系统初始化
- GPIO控制
- 串口通信
- 延时功能

## 代码说明

### User目录
- `main.c`: 主函数，程序入口点
- `stm32f10x_it.c`: 中断处理函数
- `stm32f10x_conf.h`: 库配置文件

### System目录
- `Delay.c`: 延时功能实现
- `Delay.h`: 延时功能头文件

### Library目录
包含STM32F103标准库文件，提供各种外设的驱动代码

### Start目录
包含启动文件和系统初始化代码

## 注意事项

- 确保正确安装了STM32F103的标准库
- 选择正确的启动文件对应你的STM32F103型号
- 如需修改时钟配置，请参考`system_stm32f10x.c`文件

## 许可证

本项目仅供学习和参考使用。
