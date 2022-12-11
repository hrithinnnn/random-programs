t=int(input())
for i in range(0,t):
    n=int(input())
    s=input()
    if n%3==2:
        print("NO")
    else:
        if n%3!=0:
            n=n-1
        while(len(s)>0):
            j=s[0:3]
            if j[1]!=j[2]:
                print("NO")
            else:
                s.remove(j)
        
            
        

