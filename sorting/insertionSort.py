def insertionSort(array): 
  
    for index in range(1, len(array)): 
  
        key = array[index]  
        j = index-1
        while(j >=0 and key < array[j]): 
                array[j+1] = array[j] 
                j=j-1      
        array[j+1] = key 
