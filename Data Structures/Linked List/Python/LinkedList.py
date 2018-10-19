class node:
    def __init__(self):
        self.data = None
        self.next = None

class linked_list:
    def __init__(self):
        self.head = None

    def add(self, data):
        new_node = node()
        new_node.data = data
        new_node.next = self.head
        self.head = new_node

    def remove(self, data):

        prev = None
        node = self.head
        while node:
            if node.data == data:
                if prev:
                    prev.next = node.next
                else:
                    self.head = node.next
                return True
            prev = node
            node = node.next
        return False

    def list_print(self):
        node = self.head
        while node:
            print node.data
            node = node.next

    def search_data(self, data):
        node = self.head
        while node:
            if (node.data == data):
                return True
            node = node.next
        return False

# Creating the list
ll = linked_list()

# Adding elements
ll.add(1)
ll.add(2)
ll.add(3)

# Printing the list
ll.list_print()

ll.remove(3)

# Printing the list after removing element
ll.list_print()

# Searching for an element that doesn't exist
ll.search_data(20)
