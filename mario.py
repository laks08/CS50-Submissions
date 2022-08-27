# TODO

height = int(input("Height: "))  # input height for user

for i in range(height):  # loop for height times
    print(' ' * (height - (i+1)) + '#' * (i+1))  