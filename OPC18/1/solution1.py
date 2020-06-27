import sys

# Get the next index in a list: next of last element will be the first element
def nextIndex(sequence, current_index):
    return sequence[(current_index + 1) % len(sequence)]

# Check for circular number
def isWrapped(s1, s2):
    if (len(s1) != len(s2)):
        return False

    # Get all possible starting points in s2
    start_pos = [ j for j, x in enumerate(s2) if int(x) == int(s1[0])]

    # Compare s1 from each starting point of s2
    for k in start_pos:
        count = 0
        match = False
        for l in range(len(s1)):
            if int(s1[( l + 1 ) % len(s1)]) != int(nextIndex(s2, k + l)):
                break
            else:
                count += 1
                match = True
        # If the both sequences match on all
        # elements we have a wrap
        if count == len(s1) and match == True:
            return True
    return False


if len(sys.argv) < 2:
    exit()

sequence = sys.argv[1]
sequence_list = [char for char in sequence]

for i, _ in enumerate(range(len(sequence_list))):
    new_sequence = int(sequence) * ( i + 1 )
    new_sequence = str(new_sequence)
    new_sequence_list = [char for char in new_sequence]
    if not isWrapped(sequence_list, new_sequence_list) and i != 0:
        print('not wrap')
        exit()
print('wrap')

