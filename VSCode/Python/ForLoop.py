#for loop start at 0 and end at n-1
#for loop Syntax

#for i in range(end)
for i in range(10):
    print(i+1) # print 0 - 9
    
print()

#for i in range(start, end)
for i in range(1, 5):
    print(i) # print 1 - 4
    
print()

#for i in range(start, end, step)
for i in range(1, 20, 2):
    print(i) # print 1 , 3, 5, ..., 17, 19 
print()
for i in range(20, 0, -1):
    print(i) # print 20 - 1