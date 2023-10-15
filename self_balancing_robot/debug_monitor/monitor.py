#something that
#supports multiple windows (preferrably)
#logs texts
#has textboxes for inputs


import PySimpleGUI as sg

sg.theme('DarkAmber')

layout_debug = [
    [sg.Text("KP"), sg.InputText()],
    [sg.Text("KI"), sg.InputText()],
    [sg.Text("KD"), sg.InputText()],
    [sg.Button("OK")]
]

window = sg.Window("Debug Console for Stabletron", layout_debug, size = (500, 500))

while True:
    event, value = window.read()
    if event == sg.WIN_CLOSED or event == 'OK':
        print(value[0])
        print(value[1])
        print(value[2])


