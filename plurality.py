from cs50 import get_string, get_int
from sys import argv, exit

MAX = 9

candidates = {}


def main():

    # Check for invalid usage
    if len(argv) < 2:
        print("Usage: python plurality [candidate ...]")
        exit(1)

    # Populate candidates dictionary
    if len(argv) - 1 > MAX:
        print(f"Maximum number of candidates is {MAX}")
        exit(2)

    for candidate in argv[1:]:
        candidates[candidate] = 0

    voter_count = get_int("Number of voters: ")
    if voter_count <= 0:
        print(f"Please provide a positive integer")
        exit(3)
    # Loop over all voters
    for i in range(voter_count):
        while True:
            name = get_string("Vote: ")
            if vote(name):
                break

            else:
                print("Invalid vote.")

    # Display winner of election
    print_winner()


# Update vote totals given a new vote
def vote(name):
    for key in candidates:
        if name in candidates:
            candidates[name] += 1
            return True
    return False


# Print the winner (or winners) of the electrion
def print_winner():
    most_votes = 0
    c = 0
    for keys,value in candidates.items():
        for key in candidates:
            if c >= 1:
                break
            if candidates[key] > most_votes:
                most_votes = candidates[key]
        if value == most_votes :
            print(keys)
        c += 1
    return
if __name__ == "__main__":
    main()
