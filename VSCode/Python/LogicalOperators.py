#Logical Operators(and, or, not)
#Result is boolean(True, False)

#variable type boolean
x = (1 < 2) #True
y = (4 <= 3) #False
z = x and y #False and True = False

#Output
print(z) #False
print(x or y) #True
print(not x and y) #False
print(not(x and y)) #True
print(x and not y) #True