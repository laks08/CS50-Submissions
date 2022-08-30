import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    data = []
    dataset = sys.argv[1]
    with open(dataset) as file:
        g = csv.reader(file, delimiter = ',')
        for row1 in g:
            data.append(row1)

    for q in range(1, len(data)):
        for w in range(1, len(data[q])):
            data[q][w] = int(data[q][w])

    # with open(dataset,'r') as file:
    #     r = csv.DictReader(file, delimiter = ',')
    #     data = list(r)

    # print(data)
    # TODO: Read DNA sequence file into a variable
    filename = sys.argv[2]
    with open(filename) as f:
        seq = f.read()

    # print(seq)

    # TODO: Find longest match of each STR in DNA sequence
    with open(dataset) as a:
        b = csv.reader(a, delimiter = ',')
        header = []
        for row in b:
            header.append(row)
            break

    match = []

    for i in range(1,len(header[0])):
        match.append(longest_match(seq,header[0][i]))

    # TODO: Check database for matching profiles
    j = (match)
    for m in range(1, len(data)):
        k = (data[m][1:])
        if j == k:
            break
        else:
            continue

    if j == k:
        print(data[m][0])
    else:
        print("No Match")


    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
