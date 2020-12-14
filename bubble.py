# Complete the bubble sort function

# List of numbers to sort
numbers = [1, 8, 4, 6, 0, 3, 5, 2, 7, 9]


def main():
    bubble_sort(numbers)

    for number in numbers:
        print(number, end=" ")
    print()


# Sort list using bubble sort
def bubble_sort(numbers):
    a = 0
    b = 0
    c = 0
    for i in (numbers - 2):
        c = 0
        for j in (numbers - 1):
            if numbers[j] > numbers[j + 1]:
                a = numbers[j]
                b = numbers[j + 1]
                numbers[j] = b
                numbers[j + 1] = a
                c += 1
        print(f"{c}")
        if c == 0:
            break
    return


main()
