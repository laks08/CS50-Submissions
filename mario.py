# TODO

while True:
    height = int(input("Height: "))  # input height for user
    if (height > 0) and (height < 9):
        break

for i in range(height):  # loop for height times
    print(' ' * (height - (i+1)) + '#' * (i+1))