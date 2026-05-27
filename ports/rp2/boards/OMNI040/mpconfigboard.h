// mpconfigboard.h

// ==========================================
// 1. 开发板基本信息
// ==========================================
#define MICROPY_HW_BOARD_NAME "OmniDebug RP2040"
#define MICROPY_HW_MCU_NAME   "RP2040"

// ==========================================
// 2. 核心修改：解除引脚霸占 (解决死机的关键)
// ==========================================
// 标准的 Pico 固件会在这里强制保留引脚：
// GPIO23 (内部电源控制), GPIO24 (VBUS检测), GPIO25 (LED), GPIO29 (VSYS电压检测)
// 
// 我们通过让保留判断永远返回 0，强制释放所有的引脚！
// 这样你在板子上把 ADC（26-29）当成普通 GPIO 连线时，底层固件绝对不会再去干涉它们。
#define MICROPY_HW_PIN_RESERVED(i) (0)

// ==========================================
// 3. USB 串口终端 (必需)
// ==========================================
// 开启通过 USB 进行的 REPL 串口通信，否则你插上电脑无法敲 Python 代码
#define MICROPY_HW_ENABLE_USBDEV (1)

// ==========================================
// 4. 其他外设 (根据你板子的实际情况选择性保留)
// ==========================================

// 如果你的板子上有一颗专门用来指示状态的 LED，可以取消下面的注释，
// 并把引脚号换成你实际连接的 GPIO (例如 pin_15)
// #define MICROPY_HW_LED_STATUS   (&pin_15)
// #define MICROPY_HW_LED_ON(mac)  ((mac)->value(1))
// #define MICROPY_HW_LED_OFF(mac) ((mac)->value(0))

// 如果你的板子预留了硬件 UART 引脚作为默认串口，可以在这里指定
// 如果你想自己在 Python 脚本里用 machine.UART 灵活分配，这里就保持注释状态
// #define MICROPY_HW_UART1_TX (pin_0)
// #define MICROPY_HW_UART1_RX (pin_1)