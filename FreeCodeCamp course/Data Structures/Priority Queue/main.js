function PriorityQueue(start) {
    this.collection = [];
    this.printCollection = function () {
        console.log(this.collection);
    };
    // Only change code below this line
    this.enqueue = function (item) {
        const index = this.collection.findIndex((elem) => elem[1] > item[1])
        if (index !== -1) {
            this.collection.splice(index, 0, item)
        } else this.collection.push(item)
    }
    this.dequeue = function () {
        return this.collection.shift()
    }
    this.isEmpty = function () {
        return this.collection.length === 0
    }
    this.front = function () {
        return this.collection[0]
    }
    this.size = function () {
        return this.collection.length
    }
}

const priorityQueue = new PriorityQueue()
priorityQueue.enqueue(["Hello", 1])
priorityQueue.enqueue(["Sarvinoz", 3])
priorityQueue.enqueue(['my love', 2])
console.log(priorityQueue.collection)