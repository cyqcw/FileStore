n=int(input())
for index in range(n):
    set_good=set()
    set_bad=set()
    flag=0  # 
    for count in range(3):
        string_lst=input().split()
        if string_lst[-1]=='even':
            for i in range(len(string_lst[0])):
                set_good.add(string_lst[1][i])
                set_good.add(string_lst[0][i])
        else:
            for i in range(len(string_lst[0])):
                if string_lst[0][i] in set_good:
                    
