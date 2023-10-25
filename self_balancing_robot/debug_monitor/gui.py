import PySimpleGUI as sg
from file_manage import * 
import sys

layout_pid_input = [
    [sg.Text("KP", size = (10, 1)), sg.InputText()],
    [sg.Text("KI"), sg.InputText()],
    [sg.Text("KD"), sg.InputText()],
    [sg.Button("OK")],
    [sg.Button("Use previous values")]
]


def setup_pid_window():
    sg.theme('DarkAmber')
    global window
    window = sg.Window("PID Values for Stabletron", layout_pid_input, size = (500, 500))
    return window

#the pid window generates event on press.

def wait_for_pid():
    while True:
        event, values = window.read()
        if event == 'OK':
            window.close()
            write_pid_values(values[0],  values[1],  values[2])
            return values

        if event == "Use previous values":
            values = read_pid_values()
            print(values)
            sys.exit(0)

        if event == sg.WIN_CLOSED:
            window.close()
            return None
