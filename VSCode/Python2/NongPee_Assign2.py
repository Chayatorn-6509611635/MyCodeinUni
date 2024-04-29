n = int(input())

number = [0] * n
start = [0] * n
end = [0] * n

for i in range (0, n):
    x1 = input()
    y1 = x1.split()
    number[i] = int(y1[0])
    start[i] = int(y1[1])
    end[i] = int(y1[2])

m = int(input())

mystart = [0] * m
myend = [0] * m

for i in range (0, m):
    x1 = input()
    y1 = x1.split()
    mystart[i] = int(y1[0])
    myend[i] = int(y1[1])

result = [0] * m


for i in range (0, m):
    each_result = [0] * n
    for j in range (n):
        isUp = 0
        im_up = 0
        is_pass = False
        if (myend[i] > mystart[i]):
            im_up = 1
        elif(myend[i] < mystart[i]):
            im_up = -1
        if(end[j] > start[j]):
            isUp = 1
        elif(end[j] < start[j]):
            isUp = -1
        if(isUp == im_up):
            is_pass = True
        if(is_pass == True):
            if(((mystart[i] - end[j])*isUp) < 0) ^ (((mystart[i] - start[j])*isUp) > 0):
                    each_result[j] = abs(myend[i] - end[j])
        else:
            each_result[j] = abs(end[j] - mystart[i]) + abs(myend[i] - mystart[i]) 
        result[i] = each_result.index(min(each_result))+1
    print(">>", result[i])
     