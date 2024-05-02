def initializearray(size):
    array1=[None] * size
    array2=[None] * size
    return array1,array2

def linear_probing_insert(data, array, size):
    i = 0
    while array[(data + i) % size] is not None:
        i += 1
    array[(data + i) % size] = data

def inser_quad(data,array,size):
    i=0
    while array[(data+(i*i))%size] is not None:
        i+=1
    array[(data+(i*i))%size]=data

def linear_search(data,array,size):
    i=0
    comp=0
    while array[(data+i)%size] is not None:
        comp+=1
        if array[(data+i)%size]==data:
            print(" linear prob Element found! \n And no. comparison",comp)
            return
        if i > size*2:
            print("not found")
            return
        i+=1
    print("not there")

def quad_search(data, array, size):
    i=0
    comp=0
    while array[(data+(i*i))%size] is not None:
        comp+=1
        if array[(data+(i*i))%size] == data:
            print("Quad prob Element found! \n And no. comparison",comp)
            return
        if i > 2*size:
            print("no elem")
            return
        i+=1
    print("no there")

def display(array1,array2):
    print("linear probe: ")
    print(array1)
    print("quad probe: ")
    print(array2)

size=int(input("enter the size of hash table: "))
array1,array2=initializearray(size)

while True:
    print("enter choice : \n 1.insert 2.search 3.exit ")
    choice = int(input("enter the choice: "))

    if choice == 1:
        data= int(input("enter the element: "))
        linear_probing_insert(data,array1,size)
        inser_quad(data,array2,size)
        display(array1,array2)

    if choice == 2:
        data=int(input("enter the number to be searched: "))
        linear_search(data,array1,size)
        quad_search(data,array2,size)

    if choice == 3:
        break
