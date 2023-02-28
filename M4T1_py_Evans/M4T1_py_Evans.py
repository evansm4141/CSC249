"""
CSC 249
M4T1 - Singly Linked Lists
Melody Evans
2-28-23
"""

""" 
LinkedList consists of:
// node and pointer collection of Node objects
// pointer to head and tail
// methods to access and mutate the list
"""

class Node:
    # Represents a singly linked node
    # Python constructors written as __init__ (double underscores)
    def __init__(self, data=None, next=None):
        # Instantiates a Node with None as default next
        self.data = data
        self.next = None
        
    # str function provides string conversion
    def __str__(self):
        # node contains data and next
        data_string = str(self.data)
        next_string = str(self.next)
        return("[" + data_string + " | next=" + next_string + "]")
        
class LinkedList:
    def __init__(self):
        # Instantiates an empty linked list
        self.head = None   # pointer to head
        self.tail = None   # pointer to tail
        
# end of class definitions
def main():
    #node1 = None
    #node2 = Node("A", None)
    #node3 = Node("B", node2)
    
    head = None
    
    for count in range(1,6):
        head = Node(count,head)
        
        #print contents
        probe = head
        while probe != None:
            print(probe.data)
            probe = probe.next
    
# run program
if __name__ == "__main__":
    main()

""" We've turned off main, so running this .py file
simply provides a "sandbox" of objects and methods """
# some examples
"""
node1 = None # an empty link
node2 = Node("A", None) # data plus an empty link
node3 = Node("B", node2) # data plus a link to node2

print(node1)
print(node2)
print(node3)
"""