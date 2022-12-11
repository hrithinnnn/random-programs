import time
import random
def bubbleSort(arr):
    n = len(arr)
    flag = 0
    comparison = 0;
    swaps = 0
    for i in range(n):
        for j in range(0, n-i-1):
            comparison+=1
            if arr[j] > arr[j+1]:
                flag = 1
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swaps += 1
        if(flag == 0):
          break
        flag = 0
    return comparison, swaps

for j in range(1,5):    
    arr = []
    for i in range(0, 2*10**j):
        arr.append(random.randrange(0, 1000))
    
    start = time.time()
    c = bubbleSort(arr)
    end = time.time()
    print(str(2*10**j)+","+str(c[0])+","+str(end-start) +","+str(c[1]))
  
