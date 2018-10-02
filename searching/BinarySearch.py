def binarySearch(alist, item):
2	    if len(alist) == 0:
3	        return False
4	    else:
5	        midpoint = len(alist)//2
6	        if alist[midpoint]==item:
7	          return True
8	        else:
9	          if item<alist[midpoint]:
10	            return binarySearch(alist[:midpoint],item)
11	          else:
12	            return binarySearch(alist[midpoint+1:],item)
