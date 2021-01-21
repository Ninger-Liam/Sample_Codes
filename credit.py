from cs50 import get_string
import sys
import math


def checkNumeric(creditNum):

    if creditNum.isdigit():
        return True
    return False
    

def checkCardType(creditNum):
    l = len(creditNum)
    if creditNum[0] == '4':
        if l == 13 or l == 16:  # Visa
            return 2
        else:
            return 1
    elif creditNum[0] == '3':  # AmEx
        if creditNum[1] == '4' or creditNum[1] == '7':
            if l == 15:
                return 3
            else:
                return 1
    elif creditNum[0] == '5':  # MasterCard
        if creditNum[1] == '1' or creditNum[1] == '2' or creditNum[1] == '3' or creditNum[1] == '4' or creditNum[1] == '5':
            if l == 16:
                return 4
            else:
                return 1
    else:
        return 1


def checkSum(creditNum):
    l = len(creditNum)
    ccn = int(creditNum)
    xx = 0
    yy = xx
    xx = ccn % 10
    yy += xx
    ccn = math.floor(ccn / 10)
    x = 0
    z = 0
    y = x + z
    jj = l / 2
    math.floor(jj)
    j = int(jj)

    for i in range(j):
        z = 0
        x = ccn % 10
        x *= 2
        if x > 9:
            z = x % 10
            x = math.floor(x / 10)
        y = x + y + z
        ccn = math.floor(ccn / 10)
        xx = ccn % 10
        yy += xx
        ccn = math.floor(ccn / 10)
    y += yy

    if y % 10 == 0:
        return 10
    else:
        return 0


while True:
    creditNum = get_string("Enter Your Credit Card Number: ")
    if checkNumeric(creditNum):
        break
    print("Please enter a valid number")
ct = checkCardType(creditNum)
if ct == 1:
    print("INVALID")
if ct == 2:
    v = checkSum(creditNum)
    if v == 10:
        print("VISA")
    else:
        print("INVALID")
elif ct == 3:
    a = checkSum(creditNum)
    if a == 10:
        print("AMEX")
    else:
        print("INVALID")
elif ct == 4:
    mc = checkSum(creditNum)
    if mc == 10:
        print("MASTERCARD")
    else:
        print("INVALID")