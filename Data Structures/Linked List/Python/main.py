class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
        self.prev = None


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
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
        self.size += 1

    def prepend(self, data):
        if self.is_empty():
            self.append(data)
        else:
            node = Node(data)
            self.head.prev = node
            node.next = self.head
            self.head = node
            self.size += 1

    def pop(self):
        if self.is_empty():
            return None
        current = self.head
        found = self.tail.data
        while current.next and current.next.next != self.tail:
            current = current.next
        current.next = None
        self.tail = current
        self.size -= 1
        return found

    def reverse(self):
        temp = None
        current = self.head
        self.tail = current
        while current is not None:
            temp = current.prev
            current.prev = current.next
            current.next = temp
            current = current.prev
        self.head = temp.prev if temp else None

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
# llist.pop()
llist.reverse()
llist.display()
