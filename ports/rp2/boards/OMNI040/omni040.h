// omni040.h

#ifndef _BOARDS_OMNI040_H
#define _BOARDS_OMNI040_H

// 1. 外部晶振配置 (通常 RP2040 使用标准的 12MHz)
#define XOSC_MHZ 12

// #define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

// 启用最保守的通用单线 SPI 启动代码 (03h 慢速模式)
#define PICO_BOOT_STAGE2_CHOOSE_GENERIC_03H 1
// #define PICO_BOOT_STAGE2_CHOOSE_IS25LP080 1

// 这里的容量保持不变，HX25Q16 就是 2MB
#define PICO_FLASH_SPI_CLKDIV 2
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)

// ==========================================
// 核心：故意留白！
// 这里绝不定义任何 PICO_VSYS_PIN、PICO_DEFAULT_UART_TX_PIN 等宏！
// 这样 C SDK 启动时就像一张白纸，没有任何引脚会被隐式初始化。
// ==========================================
#define PICO_DEFAULT_I2C 0
#define PICO_DEFAULT_I2C_SDA_PIN 0
#define PICO_DEFAULT_I2C_SCL_PIN 1

#define PICO_DEFAULT_SPI 0
#define PICO_DEFAULT_SPI_TX_PIN 3
#define PICO_DEFAULT_SPI_RX_PIN 0
#define PICO_DEFAULT_SPI_SCK_PIN 2

#define PICO_DEFAULT_UART 0
#define PICO_DEFAULT_UART_TX_PIN 0
#define PICO_DEFAULT_UART_RX_PIN 1

#endif