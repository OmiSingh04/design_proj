from gui import *
import sys
from bt import * 

window = setup_pid_window()
    
values = wait_for_pid()

if values is None:
    print("No values read!")

print(values[0], values[1], values[2])

if(not connect()):
    print("Cannot Connect Bluetooth!")

write_pid(values[0], values[1], values[2])
print("Written values")


read_bt()



