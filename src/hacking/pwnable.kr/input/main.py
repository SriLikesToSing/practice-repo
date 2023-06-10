


print(int.from_bytes(b'\x00', "big"))


print(int.from_bytes(b'\x20\x0a\x0d', "big"))

str=""
for x in range(1, 100):
    if x == 64:
        str+=" "+"\\x00"
        continue
    if x == 65:
        str+=" "+'\\x20\\x0a\\x0d'
        continue
    str+=" "+"1"
print(str)
print(len(str)//2)

 for y in coins:
  1         for x in range(y, N):
  2             DP[x]+=DP[x-y]



