from serial.tools import list_ports
import serial
import time
from pyclick import HumanClicker
from pynput import keyboard
import cv2

#initialize the human clicker object
hc = HumanClicker()

ports = list_ports.comports()
for port in ports: print(port)

#open the serial communication to microcontroller 
serialCom = serial.Serial('COM10', 9600)

serialCom.setDTR(False)
time.sleep(1)
serialCom.flushInput()
serialCom.setDTR(True)

while True:
    sBytes = serialCom.readline()
    decodedBytes = sBytes.decode("utf-8").strip('\r\n')
    if decodedBytes == "HOLA AMIGOS":
        hc.click()

    if cv2.waitKey(1) & 0xFF == ord('q'):
        print(serialCom.is_open)
        serialCom.close()
        break

    print(decodedBytes)

        












