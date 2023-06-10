import binascii 



result = binascii.unhexlify("0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104")
result = result.decode("utf-8")

list = []
list.append(ord(result[0]) ^ ord('c'))
list.append(ord(result[1]) ^ ord('r'))
list.append(ord(result[2]) ^ ord('y'))
list.append(ord(result[3]) ^ ord('p'))
list.append(ord(result[4]) ^ ord('t'))
list.append(ord(result[5]) ^ ord('o'))
list.append(ord(result[6]) ^ ord('{'))
list.append(ord(result[-1]) ^ ord('}'))


# m y x o r k e y 
listTwo = [chr(x) for x in list]
ascii =[]

index =0
str = ""
for x in range(0, len(result)):
    if index == len(listTwo):
        index = 0

    temp = ord(result[x]) ^ ord(listTwo[index])
    str+=chr(temp)
    index+=1

print(str)

















