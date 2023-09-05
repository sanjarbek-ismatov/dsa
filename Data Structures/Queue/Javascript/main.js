class Queue{
    constructor(capacity) {
        this.size = 0;
        this.capacity = capacity
        this.front = -1
        this.rear = -1
        this.items = {}
    }
    isEmpty(){
        return this.size === 0
    }
    isFull(){
        return this.size === this.capacity
    }
    enqueue(data){
       if(!this.isFull()){
           this.rear = (this.rear + 1) % this.capacity
           this.items[this.rear] = data
           this.size++;
           if(this.front === -1) this.front = this.rear
       }else{
           console.log("Queue is full")
       }
    }
    dequeue(){
        if(this.isEmpty()) return null
        this.items[this.front] = null
        this.size--
        if(this.isEmpty()) this.front = this.rear = -1
        else this.front = (this.front + 1) % this.capacity
    }
    printQueue(){
        let string = ""
        let i;
        for(i = this.front; i !== this.rear; i = (i + 1) % this.capacity){
            string += this.items[i] + " "
        }
        string += this.items[i]
        console.log(string)
    }
}
const queue = new Queue(5)
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
queue.enqueue(5)
queue.dequeue()
queue.enqueue(6)
queue.printQueue()