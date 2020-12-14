# implement binary search function
from math import floor
from cs50 import get_int

numbers = [2, 4, 6, 7, 8, 11, 14, 18, 20]


def main():
    target = get_int("Enter a number: ")

    if bin_search(numbers, target):
        print("Found!")
    else:
        print("Not found!")

            
def bin_search(numbers, target):
    min_val = 0
    n = len(numbers)
    max_val = n - 1
    while min_val <= max_val:
        mid = (min_val + max_val) // 2
        if target < numbers[mid]:
            max_val = mid - 1
        elif target > numbers[mid]:
            min_val = mid + 1
        elif target == numbers[mid]:
            return True
    return False


main()
