def QuickSort(a):

    list = len(a)
    
    
    if list < 2:
        return a
    
    x = 0 

    for i in range(1, list): 
         if a[i] <= a[0]:
              x += 1
              temp = a[i]
              a[i] = a[x]
              a[x] = temp

    temp = a[0]
    a[0] = a[x] 
    a[x] = temp 
    
    l = QuickSort(a[0:x]) 
    r = QuickSort(a[x+1:list]) 
    a = l + [a[x]] + r
    
    return a



elements= [11,33,10,16,23]
print("Sorted Array: ",QuickSort(elements))
