import sys

class Marker:
    def __init__(self):
        self.current_x = 0
        self.current_y = 0
        self.farthest_north = [0, 0]
        self.farthest_south = [0, 0]
        self.farthest_east = [0, 0]
        self.farthest_west = [0, 0]

    def moveNorth(self):
        self.current_y += 1
        if self.current_y > self.farthest_north[1]:
            self.farthest_north = [self.current_x, self.current_y]

    def moveSouth(self):
        self.current_y -= 1
        if self.current_y < self.farthest_south[1]:
            self.farthest_south = [self.current_x, self.current_y]

    def moveEast(self):
        self.current_x += 1
        if self.current_x > self.farthest_east[0]:
            self.farthest_east = [self.current_x, self.current_y]

    def moveWest(self):
        self.current_x -= 1
        if self.current_x < self.farthest_west[0]:
            self.farthest_west = [self.current_x, self.current_y]

    def __repr__(self):
        return '(%s,%s)(%s,%s)(%s,%s)(%s,%s)(%s,%s)' % (self.current_x,
                                                        self.current_y,
                                                        self.farthest_north[0],
                                                        self.farthest_north[1],
                                                        self.farthest_east[0],
                                                        self.farthest_east[1],
                                                        self.farthest_south[0],
                                                        self.farthest_south[1],
                                                        self.farthest_west[0],
                                                        self.farthest_west[1])
        

if len(sys.argv) != 2:
    print('ERROR')
    exit()

directions = []
try:
    with open(sys.argv[1]) as f:
        directions = f.read().split()
except IOError:
    print('ERROR')
    exit()

if len(directions) == 0:
    print('ERROR')
    exit()

direction_string = ""
for string in directions:
    direction_string  += string

print(direction_string)

direction_list = [direction_char for direction_char in direction_string]


marker = Marker()
for direction in direction_list:
    if direction == "N":
        marker.moveNorth()
    elif direction == "S":
        marker.moveSouth()
    elif direction == "E":
        marker.moveEast()
    elif direction == "W":
        marker.moveWest()

print(marker)
