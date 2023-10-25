#something that
#supports multiple windows (preferrably)
#logs texts
#has textboxes for inputs

from file_manage import *
import struct
import sys
import serial 

incoming = "COM4"

my_serial = None

baud_rate = 9600 

def connect():
    try:
        global my_serial
        my_serial = serial.Serial(incoming, baud_rate, timeout = 1)
        return True 

    except my_serial.SerialException as e:
        print(f"Serial communication error: {e}")
        return False

    except KeyboardInterrupt:
        print("Communication terminated.")
        return False

def write_pid(kp, ki, kd):
    a = struct.pack('d', float(kp))
    my_serial.write(a)
    print("kp written")

    b = struct.pack('d', float(ki))
    my_serial.write(b)
    print("ki written")

    c = struct.pack('d', float(kd))
    my_serial.write(c)
    print("kd written")

def read_bt():
    #can be implemented as an infinity loop.
    while True:
        r = my_serial.read().decode('utf-8')
        if r.startswith('Init:'):
            write_message(r)

        if(r.startswith('Error:')):
            write_message(r)
            break

        if(r.startswith("pitch:")):
            write_pitch_control(r.split(",")[0].split(":")[1], r.split(",")[1].split(":")[1])

