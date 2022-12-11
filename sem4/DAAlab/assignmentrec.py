def recbubble(arr,n):
    if(n==1):
        return

    for i in range(n-1):
	    if(arr[i]>arr[i+1]):
  	        arr[i],arr[i+1]=arr[i+1],arr[i]

    recbubble(arr,n-1)

arr=[58,10,45,32,23]
recbubble(arr,len(arr))
print(arr)
