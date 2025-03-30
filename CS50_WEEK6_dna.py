import csv
import sys

def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], encoding="utf-8") as f:
        read_data = f.read()

    # Find longest match of each STR in DNA sequence
    STR_List = list(rows[0].keys())
    STR_List.remove('name')

    DNA_Info = {}
    for STR in STR_List:
        DNA_Info[STR] = longest_match(read_data, STR)

    # Check database for matching profiles
    for people in rows:  # Fixing iteration over the list
        match = True
        for STR in STR_List:
            if int(people[STR]) != DNA_Info[STR]:
                match = False
                break
        if match:  # Dedenting the condition
            print(people['name'])
            return  # Stop after finding the first match

    print("No match")  # If no match is found

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

main()
