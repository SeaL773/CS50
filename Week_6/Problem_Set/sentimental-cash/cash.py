from cs50 import get_float


def main():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break

    cents = round(change * 100)

    coins = 0

    # Count quarters
    coins += cents // 25
    cents %= 25

    # Count dimes
    coins += cents // 10
    cents %= 10

    # Count nickels
    coins += cents // 5
    cents %= 5

    # Count pennies
    coins += cents

    print(coins)


if __name__ == "__main__":
    main()