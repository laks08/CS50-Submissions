# TODO

while True:
    height = input("Height: ")  # input height for user
    try:
        int(height)
        break
    except ValueError:
        True

height = int(height)
while True:
    if (height > 0) and (height < 9):
        break

for i in range(height):  # loop for height times
    print(' ' * (height - (i+1)) + '#' * (i+1))