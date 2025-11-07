
Python example using stapsdt
Environment Ubuntu 24.04

## Setup (create venv, activate and install requirements):

```shell
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

## Instal bcc
```shell
sudo apt-get install bpfcc-tools linux-headers-$(uname -r)
```

## Run the example:
Send message
```shell
   python example.py
```
receive message
```shell
# use pgrep to find the PID of the process title 'pythonapp' and pass it to trace-bpfcc
sudo /sbin/trace-bpfcc -p $(pgrep -f "^pythonapp$" | head -n1) 'u::firstProbe "%s - %d", arg1, arg2'
```