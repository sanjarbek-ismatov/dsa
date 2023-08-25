class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def append(self, data):
        node = Node(data)
        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = self.tail.next
        self.size += 1

    def prepend(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
        self.size += 1

    def display(self):
        printable = ""
        current = self.head
        while current:
            printable += str(current.data) + " "
            current = current.next
        print(printable)


llist = LinkedList()
# llist.append(10)
# llist.append(20)
# llist.append(30)
llist.prepend(10)
llist.prepend(20)
llist.prepend(30)
llist.display()
