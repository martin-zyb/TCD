# Character Triangle coded by martin-zyb

# Fri Apr 29 12:28:32 UTC+08:00 2023

import os

def prints(ch, rhombus = False, num = 3):
    num = int(num)
    i = 1
    while i <= num:
        j = 1
        temp = num - i
        while j <= temp:
            print(" ", end = "")
            j = j + 1
        k = 1
        temp = i * 2 - 1
        while k <= temp:
            print(ch, end = "")
            k = k + 1
        print()
        i = i + 1
    if int(rhombus) != 0:
        i = num - 1
        while i >= 1:
            j = 1
            temp = num - i
            while j <= temp:
                print(" ", end = "")
                j = j + 1
            k = 1
            temp = i * 2 - 1
            while k <= temp:
                print(ch, end = "")
                k = k + 1
            print()
            i = i - 1

def main():
    ch = input("Character:")
    rhombus = input("Type:")
    num = input("Number:")
    prints(ch, rhombus, num)
    os.system("pause")

if __name__ == '__main__':
    main()
