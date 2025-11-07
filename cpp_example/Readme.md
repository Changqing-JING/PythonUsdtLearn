C++ example using SystemTap USDT probes

## Prerequisites

Install SystemTap development headers:
```shell
sudo apt-get install -y systemtap-sdt-dev
```

## Build

From the project root directory:
```shell
mkdir -p build
cd build
cmake ..
make
```

## Run the example:

Send message (run the C++ application):
```shell
./build/cpp_example
```

Receive message (trace the USDT probes):
```shell
# List available USDT probes (optional):
sudo /sbin/tplist-bpfcc -p $(pgrep -f cpp_example | head -n1)

# Trace the probe (note: probe name requires quotes: "cppapp"):
sudo /sbin/trace-bpfcc -p $(pgrep -f cpp_example | head -n1) "u:$(readlink -f ./build/cpp_example):cppapp:firstProbe \"%llu - %d\", arg1, arg2"
```
