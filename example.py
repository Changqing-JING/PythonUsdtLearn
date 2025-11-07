from time import sleep
import os
import stapsdt
import setproctitle

# set the process title so tools like trace-bpfcc can match by name
setproctitle.setproctitle("pythonapp")
print(f"PID: {os.getpid()}")
try:
    print(f"process title: {setproctitle.getproctitle()}")
except Exception:
    pass

provider = stapsdt.Provider("pythonapp")
probe = provider.add_probe(
    "firstProbe", stapsdt.ArgTypes.uint64, stapsdt.ArgTypes.int32)
provider.load()


while True:
    print("Firing probe...")
    if probe.fire("My little probe", 42):
        print("Probe fired!")
    sleep(1)
