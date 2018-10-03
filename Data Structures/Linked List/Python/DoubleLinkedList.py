#Defined Node
class ListNode:  
    def __init__(self, data):
        "constructor class to initiate this object"

        # store data
        self.data = data

        # store reference (next item)
        self.next = None

        # store reference (previous item)
        self.previous = None
        return

    def has_value(self, value):
        "method to compare the value with the node data"
        if self.data == value:
            return True
        else:
            return False
            
 #Doubly Linked List
 
 class DoubleLinkedList:  
    def __init__(self):
        "constructor to initiate this object"

        self.head = None
        self.tail = None
        return

    def list_length(self):
        "returns the number of list items"

        count = 0
        current_node = self.head

        while current_node is not None:
            # increase counter by one
            count = count + 1

            # jump to the linked node
            current_node = current_node.next

        return count

    def output_list(self):
        "outputs the list (the value of the node, actually)"
        current_node = self.head

        while current_node is not None:
            print(current_node.data)

            
            current_node = current_node.next

        return

    def unordered_search (self, value):
        "search the linked list for the node that has this value"

        
        current_node = self.head

        
        node_id = 1

        
        results = []

        while current_node is not None:
            if current_node.has_value(value):
                results.append(node_id)

            
            current_node = current_node.next
            node_id = node_id + 1

        return results
        
        #Adding nodes
        
def add_list_item(self, item):
        "add an item at the end of the list"

        if isinstance(item, ListNode):
            if self.head is None:
                self.head = item
                item.previous = None
                item.next = None
                self.tail = item
            else:
                self.tail.next = item
                item.previous = self.tail
                self.tail = item

        return
        
        #Removing Nodes
       
 def remove_list_item_by_id(self, item_id):
        "remove the list item with the item id"

        current_id = 1
        current_node = self.head

        while current_node is not None:
            previous_node = current_node.previous
            next_node = current_node.next

            if current_id == item_id:
                # if this is the first node (head)
                if previous_node is not None:
                    previous_node.next = next_node
                    if next_node is not None:
                        next_node.previous = previous_node
                else:
                    self.head = next_node
                    if next_node is not None:
                        next_node.previous = None
                # we don't have to look any further
                return

            # needed for the next iteration
            current_node = next_node
            current_id = current_id + 1

        return
        
        
