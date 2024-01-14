# # from cs50 import get_int
# import cs50

# # x = get_int("x: ")
# # y = get_int("y: ")

# # x = int(input("x: "))
# # y = int(input("y: "))

# x = cs50.get_float("x: ")
# y = cs50.get_float("y: ")

# print(x + y)

# x = int(input("x: "))
# y = int(input("y: "))

# z = x / y
# print(f"{z:.50}")

def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")

def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)


main()