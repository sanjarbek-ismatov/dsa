class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
class LinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0
    def isEmpty(self):
        return self.size == 0
    def append(self, data):
        node = Node(data)
        if(self.isEmpty()):
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = self.tail.next
        self.size += 1
    def display(self):
        printable = ""
        current = self.head
        while(current):
            printable += str(current.data) + " "
            current = current.next
        print(printable)
list = LinkedList()
list.append(10)
list.append(20)
list.append(30)
list.display()