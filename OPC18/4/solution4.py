import sys

if len(sys.argv) != 2:
    print('ERROR')

try:
    with open(sys.argv[1]) as f:
        Lines = f.readlines()
except IOError:
    print('ERROR')
    exit()

waitingLine = []
for line in Lines:
    line = line.split()
    if line[0] == 'enqueue':
        item = [line[2]]
        if line[1] == 'front':
            item.extend(waitingLine)
            waitingLine = item
        elif line[1] == 'end':
            waitingLine.extend(item)
    elif line[0] == 'dequeue':
        waitingLine.pop(0)

for i, patient in enumerate(waitingLine):
    if i == len(waitingLine) - 1:
        print(patient)
    else:
        print(patient, ",", sep='', end='')
