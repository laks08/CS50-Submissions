# TODO

def main():
    while True:
        try:
            cents1 = float(input("Change owed: "))
            if cents1 > 0:
                break
        except ValueError:
            True

    quarters = calculate_quarters(cents1)
    cents2 = round((cents1 - (quarters * 0.25)),2)

    dimes = calculate_dimes(cents2)
    cents3 = round((cents2 - (dimes * 0.10)),2)

    nickels = calculate_nickels(cents3)
    cents4 = round((cents3 - (nickels * 0.05)),2)


    pennies = calculate_pennies(cents4)
    cents5 = round((cents4 - (pennies * 0.01)),2)

    coins = quarters + dimes + nickels + pennies

    print(coins)


def calculate_quarters(cents1):
    a = cents1 / 0.25
    return int(a)

def calculate_dimes(cents2):
    b = cents2 / 0.10
    return int(b)

def calculate_nickels(cents3):
    c = cents3 / 0.05
    return int(c)

def calculate_pennies(cents4):
    d = cents4 / 0.01
    return int(d)

main()