# Complete the selection sort function

# List of numbers to sort
numbers = [1, 8, 4, 6, 0, 3, 5, 2, 7, 9]


def main():
    selection_sort(numbers)

    for number in numbers:
        print(number, end=" ")
    print()


# Sort list using selection sort
def selection_sort(numbers):
    s = 0
    a = 0
    n = len(numbers)
    for i in range(n - 1):
        s = i
        for j in range(i + 1, n - 1):
            if numbers[j] < numbers[s]:
                s = j
        a = numbers[s]
        numbers[s] = numbers[i]
        numbers[i] = a
    return


main()
