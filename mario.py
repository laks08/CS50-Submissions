# TODO

def main():

    h = height()
    for i in range(h):  # loop for height times
        print(' ' * (h - (i+1)) + '#' * (i+1))


def height():
    while True:
        try:
            height = int(input("Height: "))  # input height for user
            if (height > 0) and (height < 9):
                break
        except ValueError:
            True
    return height

main()