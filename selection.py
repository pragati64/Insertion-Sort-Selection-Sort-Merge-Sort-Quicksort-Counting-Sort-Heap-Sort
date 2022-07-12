def selection(a):
  n = len(a)
  for i in range(n):
    min = i

    for j in range(i+1, n):
      if (a[j] < a[min]):
        minimum = j
    temp = a[i]
    a[i] = a[min]
    a[min] = temp
    
  return a
a = [11, 32, 19, 34, 8,12]
print(selection(a))
