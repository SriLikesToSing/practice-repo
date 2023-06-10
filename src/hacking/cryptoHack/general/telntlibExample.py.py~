import telnetlib
import json
import pybase64 
import codecs
from Crypto.Util.number import bytes_to_long
from Crypto.Util.number import long_to_bytes

HOST = "socket.cryptohack.org"
PORT = 13377

tn = telnetlib.Telnet(HOST, PORT)

def decode(encoding, string):
    message = ""
    
    if encoding == "base64":
        message = pybase64.b64decode(string)
        message = message.decode("utf-8")
        return message
    elif encoding == "hex":
       message = bytes.fromhex(string).decode('utf-8')
       print("BRO THIS IS THE HEX MSSAGE BRO")
       print(message)
       return message
    elif encoding == "rot13":
        message = lambda s : codecs.getencoder("rot-13")(s)[0]
        print("BRO THIS IS THE ROT13 MESSAGE BRO")
        print(message(string))
        return message(string)
    elif encoding == "bigint":
        string = int(string, 16)
        message = long_to_bytes(string)
        return message.decode("utf-8")
    elif encoding == "utf-8":
        for x in string:
            message+=chr(x)
        return message

def readline():
    return tn.read_until(b"\n")

def json_recv():
    line = readline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    tn.write(request)

received = json_recv()

print("Received type: ")
print(received["type"])
print("Received encoded value: ")
print(received["encoded"])

encoding = received["type"]
message = received["encoded"]


result = decode(encoding, message)
to_send = {
        "decoded": result 
        }

json_send(to_send)

for x in range(2, 101):
    recv = json_recv()

    result = decode(recv["type"], recv["encoded"])
    to_send = {
            "decoded" : result
            }
    json_send(to_send)



print("RESULT")
print(json_recv()) 
