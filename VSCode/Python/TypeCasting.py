x = 10
y = 200.3
z = "59"

result = x + y
#result2 = x + z => error
result2 = x + int(z) # 59 + 10 = 69
result3 = str(x) + z # "59" + "10" = 5910

print(result)
print()
print(result2)
print()
print(result3)
print()
print(type(x))
print(type(y))
print(type(z))
print()
print(float(z))