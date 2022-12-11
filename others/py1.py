numRows=3
a = [[0 for x in range(numRows)] for y in range(numRows)]    
count =numRows-2
#for x in range(0,numRows):
for i in range (0,numRows):
    print(i%2)
    if i%(2)==0:
        for j in range(0,numRows):
            a[j][i]=1
            count = numRows-2
    #else:
     #   a[count][i]=1
      #  count-=1
print(a)