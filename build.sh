#!/bin/bash
# 当遇到错误时立即退出
set -e 

echo "==== 开始 OMNI040 MicroPython 自动化编译 ===="

cd /workspace

# 3. 编译交叉编译器 mpy-cross (使用 -j 开启多线程加速)
echo "-> 编译 mpy-cross..."
make -C mpy-cross -j$(nproc)

# 4. 编译 RP2040 端口
echo "-> 编译 RP2040 OMNI040 固件..."
cd ports/rp2
make BOARD=OMNI040 submodules
make BOARD=OMNI040 clean    # 确保每次都是干净的编译
make BOARD=OMNI040 -j$(nproc)

# 5. 提取生成的 .uf2 文件到外部输出目录
echo "-> 正在导出固件..."
mkdir -p /workspace/output
cp build-OMNI040/firmware.uf2 /workspace/output/OMNI040_firmware.uf2

echo "==== 编译完成！请在 output 目录下查看 OMNI040_firmware.uf2 ===="