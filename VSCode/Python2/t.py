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