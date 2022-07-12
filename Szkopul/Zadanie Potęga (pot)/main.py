
a =  int(input())

cycle = [2,4,8,6]

if(a == 0):
    print("1")
else:
    print(cycle[(a+3)%4])
