#List
numList = []
numList = [1, 2, 3, 4, 5, 6]
nameList = ["Mr.A", "Mr.B", "Mr.C"]
all = ["Egg", 7, True]
#declare constructor
name = list(["Buck", 48, True])

print(name)
print(name[1])
print(numList[2] + numList[-1])
print(numList[1:]) #element index 1 to last

#Editing list
print("Before Edit:", numList)
numList[3] = 120
print("After Edit:",numList)

#for loop with list (for each)
for x in numList:
    print(x, end = ' ') # elements concatenate
print()

#if else with list (Ternary Operator)
a = 2
print(a, "is in numList") if a in numList else print(a, "is not in numList")

#list length
print(len(nameList))

#normal loop
for i in range(len(nameList)):
    print(nameList[i])
    
#add element in list(apppend)
print("Before:", nameList)
nameList.append("Mrs.Mp")
print("After: ", nameList)

#insert element in list
nameList.insert(2, "Rudy") #insert at index 2
print(nameList)

#remove element in list
nameList.remove("Mr.C") #remove element at index
print(nameList)
nameList.pop() #remove last element
print(nameList)

#del / clear
print(numList)
del numList[3]
print(numList)
numList.clear() #clear all elements
print(numList)
print()

#copy
y = list()
print(y)
y = nameList.copy()
print(y)

#merge list
z = nameList + all + name
print(z)
print()

#count list
num = list([1, 1, 2, 5, 7, 1, 6, 8]) 
print(num.count(1)) #count how many 1 in list num

#extend
print(y)
y.extend(num)
print(y)

'''
    list.sort()
    list.reverse()
    min(list)
    max(list)
'''