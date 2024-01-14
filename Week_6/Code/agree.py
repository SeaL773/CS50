# s = input("Do you agree? ")

# if s == "Y" or s == "y":
#     print("Agreed")
# elif s == "N" or s == "n":
#     print("Not agreed")

s = input("Do you agree? ").lower()
    
if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")