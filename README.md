# Kash-nohv

kash-nohv是“心灵融合”的瓦肯语形式。在这里是一个（除了最开始自行开通OSS之外）傻瓜式的文件同步程序，利用云厂商的OSS服务来实现尽可能快速的传输。大体来讲就是一个OneDrive的复刻版——除了巨硬的土豆服务器。

## 构建

1. 按照https://github.com/aliyun/aliyun-oss-cpp-sdk 的描述构建阿里云OSS SDK。将得到的`alibabacloud-oss-cpp-sdk.lib`放入`libs/aliyun-oss-cpp-sdk/lib/Debug`。

2. 将`CMakeLists.txt`中的`set(CMAKE_PREFIX_PATH "D:/Qt/6.6.3/msvc2019_64/lib/cmake")`改为对应你本机的地址。

3. 除此之外应该不需要特殊配置了。

## 饼

1. 列表和平铺切换；
2. 支持腾讯云/华为云/AWS/Azure；
3. 用NAT穿透替代OSS；

## 其他开源信息

1. 使用了https://github.com/aliyun/aliyun-oss-cpp-sdk ，Apache 2.0 license。
