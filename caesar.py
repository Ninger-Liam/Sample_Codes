from cs50 import get_string
import sys

if len(sys.argv) != 2:
    print("Exit Code 0: Incorrect number of arguments")

if sys.argv[1].isalpha():
    print("Exit Code 1: Contains numeric characters")
    sys.exit
plainText = get_string("plaintext: ")
k = int(sys.argv[1])
num = 0
ciph = 0
i = 0
for i in range(len(plainText)):
    if plainText[i].isalpha():
        if plainText[i].isupper():
            char = ord(plainText[i])
            num = char - 65
            num += k
            ciph = num % 26
            ciph += 65
            ciph = chr(ciph)
            print(f"{ciph}", end="")
        elif plainText[i].islower():
            char = ord(plainText[i])
            num = char - 97
            num += k
            ciph = num % 26
            ciph += 97
            ciph = chr(ciph)
            print(f"{ciph}", end="")
    else:
        print(f"{plainText[i]}", end="")
print("")