def get_int(prompt):
    while True:
        try:
            value = int(input(prompt))
            if 1 <= value <= 8:
                return value
            else:
                print("Invalid input. Please enter a positive integer between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a positive integer.")


def main():
    height = get_int("Height: ")

    for i in range(1, height + 1):
        # Print spaces
        print(" " * (height - i), end="")
        # Print hashes
        print("#" * i)


if __name__ == "__main__":
    main()
