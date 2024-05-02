def hash_function(key, size):
    return hash(key) % size

def create_dictionary(size):
    return [[] for _ in range(size)]

def insert(dictionary, key, value):
    index = hash_function(key, len(dictionary))
    for pair in dictionary[index]:
        if pair[0] == key:
            pair[1] = value
            return
    dictionary[index].append([key, value])

def find(dictionary, key):
    index = hash_function(key, len(dictionary))
    for pair in dictionary[index]:
        if pair[0] == key:
            return pair[1]
    return None

def delete(dictionary, key):
    index = hash_function(key, len(dictionary))
    for i, pair in enumerate(dictionary[index]):
        if pair[0] == key:
            del dictionary[index][i]
            return

# Example usage:
size = 10
dictionary = create_dictionary(size)

while True:
    action = input("Enter action (insert/find/delete/exit): ").lower()
    
    if action == 'insert':
        key = input("Enter key: ")
        value = input("Enter value: ")
        insert(dictionary, key, value)
        print("Key-Value pair inserted.")
    
    elif action == 'find':
        key = input("Enter key to find: ")
        result = find(dictionary, key)
        if result is not None:
            print("Value found:", result)
        else:
            print("Key not found.")
    
    elif action == 'delete':
        key = input("Enter key to delete: ")
        delete(dictionary, key)
        print("Key deleted.")
    
    elif action == 'exit':
        break
    
    else:
        print("Invalid action. Please enter insert/find/delete/exit.")
