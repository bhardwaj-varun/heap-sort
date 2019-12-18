

def heapify(a, n, index):
    """ 
       Max heapify the array
    """
    largest = index
    left = 2*index+1
    right = 2*index+2

    if left < n and a[left] > a[largest] :
        largest = left

    # check if right child is larger than root or left
    # largest will become left child by now if left > root
    if right < n and a[right] > a[largest]:
        largest = right
    
    if largest != index:
        #swap the data
        a[largest] , a[index] = a[index], a[largest]
        heapify(a, n, largest)

# build max heap
def buildHeap(a, n):
    """
     leaf nodes ensures max heap property
     all non leaf nodes are one level up which would be (n//2)-1
    """
    startIndex = (n//2)-1;
    
    index = startIndex
    while index >=0 :
        heapify(a,n,index)        
        index -= 1

def printHeap(a):

    for i in a:
        print(i, end=' ')


def deleteRoot(a, n) ->  'integer':
    # exchange root with last element and then delete last element
    # then heapify
    
    a[n-1], a[0] = a[0], a[n-1]


    # n-1 means omit last element for heapification
    heapify(a, n-1, 0) #heapify from root only

    return a[n-1] #return last element
    
def sort(a, n):
    print("\nSorted Array : ")

    i=0
    while i<n:
        print( deleteRoot(a, n-i) , end=' ')
        i +=1
    print()

if __name__ == '__main__':
    n = int(input())
    # read array input
    a = [int(k) for k in input().split()] 

    print('Initial Heap : ')
    printHeap(a)

    buildHeap(a, n)

    print('\nMax Heap : ')
    printHeap(a)

    sort(a, n)