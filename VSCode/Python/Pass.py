i = int(input("Enter Score "))

if i >= 50:
    if i >= 80:
        pass    #if i >= 80, pass the condition(Jump to outer scope)
    elif i >= 70:
        print("Grade B")
    elif i >= 60:
        print("Grade C")
    elif i>= 50:
        print("Grade D")
    print("More than 50")