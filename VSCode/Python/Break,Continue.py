i = 0
while i < 10:
    i+=1
    if i == 5:
        break # if i = 5, jump off the loop
    print(i)
    
print()

i = 0
while i < 10:
    i+=1
    if i == 5 :
        continue # if i = 5, jump print(i) and start new loop
    print(i)