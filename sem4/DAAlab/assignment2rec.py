def recInsertionSort(arr,n):
    if n<=1:
        return
     
    recInsertionSort(arr,n-1)

    last = arr[n-1]
    j = n-2

    while (j>=0 and arr[j]>last):
        arr[j+1] = arr[j]
        j = j-1
 
    arr[j+1]=last
     



arr = [10,54,35,2,4]
n = len(arr)
recInsertionSort(arr, n)
print(arr)

