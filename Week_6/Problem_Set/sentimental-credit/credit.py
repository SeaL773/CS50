def get_length(number):
    return len(str(number))


def check_luhn(number):
    sum = 0
    alternate = False
    number_str = str(number)[::-1]

    for digit_str in number_str:
        digit = int(digit_str)

        if alternate:
            digit *= 2
            if digit > 9:
                digit -= 9

        sum += digit
        alternate = not alternate

    return sum % 10 == 0


def print_card_type(number):
    start_digits = int(str(number)[:2])

    if (get_length(number) == 15) and (start_digits in [34, 37]):
        print("AMEX")
    elif (get_length(number) == 16) and (51 <= start_digits <= 55):
        print("MASTERCARD")
    elif (get_length(number) in [13, 16]) and (str(number).startswith("4")):
        print("VISA")
    else:
        print("INVALID")


def main():
    while True:
        try:
            card_number = int(input("Number: "))
            if card_number > 0:
                break
        except ValueError:
            pass

    if check_luhn(card_number):
        print_card_type(card_number)
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
