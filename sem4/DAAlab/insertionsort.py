import time
import random
def insertionSort(arr):
  swap = 0
  comp = 0
  for i in range(1, len(arr)):
    key = arr[i]
    j = i-1
    while j >=0 :
      
      comp += 1
      if key < arr[j]:
        arr[j+1] = arr[j]
        swap+=1
      j -= 1
    arr[j+1] = key
  return swap, comp
for i in [100,200,500,1000,2000,3000,4000,5000]:
  arr=[]
  for j in range(0,i):
    arr.append(random.randrange(0,1000))
  start=time.time()
  swap,comp = insertionSort(arr)
  end=time.time()
  print(str(end-start))

