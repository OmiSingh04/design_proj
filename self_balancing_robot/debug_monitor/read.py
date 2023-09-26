import serial

incoming = "COM4"
outgoing = "COM5"

baud_rate = 9600 

try:
    incoming_serial = serial.Serial(incoming, baud_rate, timeout = 1)
    outgoing_serial = serial.Serial(outgoing, baud_rate, timeout = 1)
    print("Success!")
    while True:
        a = incoming_serial.read() # read a byte of data with timeout = 1
        print(a.decode())


except serial.SerialException as e:
    print(f"Serial communication error: {e}")

except KeyboardInterrupt:
    print("Communication terminated.")
