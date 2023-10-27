import sys
from bt import * 

values = [0, 0, 0]
values[0] = input("KP:")
values[1] = input("KI:")
values[2] = input("KD:")

if values is None:
    print("No values read!")

print(values[0], values[1], values[2])

if(not connect()):
    print("Cannot Connect Bluetooth!")

write_pid(values[0], values[1], values[2])
print("Written values")

read_bt()
