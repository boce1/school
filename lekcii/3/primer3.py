import PySimpleGUI as sg
import time

BGN_EUR = 0.51129188
EUR_BGN = 1.95

if 7 < time.localtime(time.time()).tm_hour < 18:
    sg.theme("Purple")
else:
    sg.theme("v")

layout = [
    [sg.Combo(("BGN", "EUR"), default_value = "BGN",key = "-IN-CURRENCY-"), sg.InputText(size=20, key="-IN-"),sg.Button("Convert")],
    [sg.Text("EUR", key = "-OUT-CURRENCY-", size = 5), sg.InputText(size=20, readonly=True, key="-OUT-")]
]

window = sg.Window("BGN to EUR", layout)

while True:
    event, values = window.read()

    if event == sg.WIN_CLOSED:
        break
    elif event == "Convert" and values["-IN-"] != '':
        #print(float(values["-IN-"]) * BGN_EUR)
        #if values["-IN-CURRENCY-"]
        window["-OUT-"].update(round(float(values["-IN-"]) * BGN_EUR, 6))

window.close()