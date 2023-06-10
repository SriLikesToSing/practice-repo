import codecs

'''
xor properties:
    commutative: A ^ B = B ^ A
    associative: A ^ (B ^ C) = (A ^ B) ^ C
    identity: A ^ 0 = A
    self-inverse: A ^ A = 0

    https://stackoverflow.com/questions/33312583/how-to-xor-two-hex-strings-in-python-3

'''

#key1 = bytes.fromhex("a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313")
#key12 = bytes.fromhex("90d07eec17e3b1c6d8daf94c35d4c9191a5e1e")


key1 = "a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313"
key12 = "90d07eec17e3b1c6d8daf94c35d4c9191a5e1e"
key2 = 0xa6c8b6733c9b224eabbec925851240a52fa381ddb79700dd6d0d

#finding key2
print("key2")
print(hex(int(key1, 16) ^ int(key12, 16)))

key23 = "c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1"

#finding key3
print("key 3")
print(hex(int(key23, 16) ^ key2))

key3 = 0x679ce12554e5573d709d6339b140e03d98b9fe62b84add0332cc


#finding flag

flagkey1key2key3 = "04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf"

print("flag")
print(hex(int(flagkey1key2key3, 16) ^ key2 ^ key3 ^ int(key1, 16)))



flag = "63727970746f7b7830725f69355f61737330633161743176337d"



print(bytearray.fromhex(flag).decode("utf-8"))
