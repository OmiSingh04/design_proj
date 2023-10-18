name = "debug.txt"

f = open(name, "a")

def write_pid_values(kp, ki, kd):
        f.write("kp:" + str(kp) + "ki:" + str(ki) + "kd:" + str(kd) + "\n")
        f.flush()



def write_pitch_control(pitch, control):
        f.write(str(pitch) + "," + str(control) + "\n")
        f.flush()

def write_message(m):
        f.write(m + "\n")
        f.flush()
