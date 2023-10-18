import PySimpleGUI as sg

layout_pid_input = [
    [sg.Text("KP", size = (10, 1)), sg.InputText()],
    [sg.Text("KI"), sg.InputText()],
    [sg.Text("KD"), sg.InputText()],
    [sg.Button("OK")]
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
            return values

        if event == sg.WIN_CLOSED:
            window.close()
            return None


def setup_debug_window():
    global window
    
