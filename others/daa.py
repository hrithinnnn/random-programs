time=input()
answer = list()
for i in range (0,len(time)):
    if time[i]=='?':
        answer.append(i)
res=0
count={
            0:2,
            1:10,
            3:5,
            4:10
        }
for i in answer:
    if i==1 and time[0]==2:
        res+=4
    else:
        res+=count[i]
print(res)