FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# 安装编译所需的全部依赖
RUN apt-get update 
RUN apt-get install -y build-essential cmake  git  python3 
RUN apt-get install -y gcc-arm-none-eabi libnewlib-arm-none-eabi
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

# 容器启动时，默认执行映射进来的 build.sh 脚本
CMD ["bash", "/workspace/build.sh"]