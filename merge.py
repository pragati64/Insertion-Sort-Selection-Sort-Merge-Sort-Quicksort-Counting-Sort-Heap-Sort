def ms(List):
    if len(List) > 1:
        mid = len(List) // 2
        l = List[:mid]
        r = List[mid:]

        
        ms(l)
        ms(r)

        
        i = 0
        j = 0
        
       
        k = 0
        
        while i < len(l) and j < len(r):
            if l[i] <= r[j]:
              
              List[k] = l[i]
             
              i += 1
            else:
                List[k] = r[j]
                j += 1
            
            k += 1

       
        while i < len(l):
            List[k] = l[i]
            i += 1
            k += 1

        while j < len(r):
            List[k]=r[j]
            j += 1
            k += 1

List = [11,21,13,22,45,65]
ms(List)
print(List)
