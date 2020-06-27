import sys

if len(sys.argv) < 2:
    exit()

args = sys.argv[1:]
args = [int(i) for i in args]

first_set = set()
second_set = set()

size_index = 0
for i in range(args[0]):
    first_set.add(args[ i + 1 ])
size_index += args[0] + 1

for i in range(args[size_index]):
    second_set.add(args[size_index + i + 1])

union = first_set.union(second_set)
intersection = first_set.intersection(second_set)


print('%d ' % len(union), end="")
union_list = list(union).sort()
for i in union:
    print('%s ' % i, end="")
    
print('%d ' % len(intersection), end="")
intersection_list = list(intersection).sort()
for i in intersection:
    print('%s ' % i, end="")
print()

