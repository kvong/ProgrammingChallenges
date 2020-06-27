import sys

# Check for negative sign in a string
def hasNegative(string):
    return '-' in string

# Remove negative sign in a string
def stripNegative(string):
    if hasNegative(string):
        return string.replace('-', '')
    return string

def mixMatch(content_1, content_2, match_num, matches=0):
    if content_1 + content_2 in match_num:
        matches += 1
    if content_2 + content_1 in match_num:
        matches += 1
    return matches
    

if len(sys.argv) != 4:
    print("ERROR")
    exit()

file_one = sys.argv[1]
file_two = sys.argv[2]
match_num = sys.argv[3]

try:
    with open(file_one, 'r') as file:
        content_one = file.read()
        content_one_array = content_one.split()
    with open(file_two, 'r') as file:
        content_two = file.read()
        content_two_array = content_two.split()
except IOError:
    print('ERROR')
    exit()

# Filter list to have only number that can be matched with match_num
# Negative sign stripped off during comparison but kept when added to list
match_list_1 = [i for i in content_one_array if stripNegative(i) in match_num]
match_list_2 = [i for i in content_two_array if stripNegative(i) in match_num]
match = 0

if hasNegative(match_num):
    # If the match_num was a negative number
    for i in match_list_1:
        for j in match_list_2:
            if (hasNegative(i) and not hasNegative(j)):
                content_1 = stripNegative(i)
                content_2 = j

                match = mixMatch(content_1, content_2, match_num, match)
            elif (hasNegative(j) and not hasNegative(i)):
                content_1 = i
                content_2 = stripNegative(j)

                match = mixMatch(content_1, content_2, match_num, match)
else:
    # If match_num is a positive number
    for i in match_list_1:
        for j in match_list_2:
            if (hasNegative(i) and hasNegative(j)):
                content_1 = stripNegative(i)
                content_2 = stripNegative(j)

                match = mixMatch(content_1, content_2, match_num, match)

            elif (not hasNegative(i) and not hasNegative(j)):
                content_1 = i
                content_2 = j

                match = mixMatch(content_1, content_2, match_num, match)

print('MATCH %d' % match)
