from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for i in range(height):
    for j in range(height):
        if i + j < height - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print(" ", end="")
    for j in range(height):
        if j <= i:
            print("#", end="")
    print("\n", end="")