# Format floating points
floatnum = 425.256789

# f-strings
two_digit_of_floatnum = f"{floatnum:.2f}"
print(two_digit_of_floatnum)
print(type(two_digit_of_floatnum))

# .format()
two_digit_of_floatnum_2 = "{:.2f}".format(floatnum)
print(two_digit_of_floatnum_2)
print(type(two_digit_of_floatnum_2))

# f-strings and .format() are converting float to str