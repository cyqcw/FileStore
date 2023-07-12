import math
n=int(input())
dict={}
for i in range(n):
    x=int(input())
    index=2
    while index<=x:
        if x%index==0:
            dict[index]=dict.get(index,0)+1
            x//=index
        else:
            index+=1
count=1
for val in dict.values():
    count=(count*(val+1))%(1e9+7)
print(int(count))