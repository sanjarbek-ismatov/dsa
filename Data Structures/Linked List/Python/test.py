class Node:
    def __init__(self, data: int):
        self.value = data
        self.next = None
        self.prev = None
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    def is_empty(self):
        return self.size == 0
    def push(self, data: Node) -> int:
        if(self.is_empty()):
            self.head = data
            self.tail = self.head
        else:
            self.tail.next = data
            data.prev = self.tail
            self.tail = self.tail.next
        self.size += 1
        return self.size
    def unshift(self, data: Node) -> int:
        if(self.is_empty()):
            self.push(data)
        else:
            self.head.prev = data
            data.next = self.head
            self.head = data
            self.size += 1
        return self.size
llist = LinkedList()
print(llist.size)