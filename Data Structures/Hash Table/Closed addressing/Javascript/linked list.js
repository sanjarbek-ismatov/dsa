/**
 * Node creator
 * @param data
 * @constructor
 */
function Node(data){
    if(!new.target) return new Node(data)
    this.value = data
    this.next = null
    this.prev = null
}

/**
 * Double Linked List
 * @constructor
 */
function DoublyLinkedList(){
    this.head = null
    this.tail = null
    this.size = 0
    /**
     * Inserts before head
     * @param {any} value
     */
    this.prepend = function(value){
        const node = new Node(value)
        if(this.isEmpty()){
            this.head = node
            this.tail = node
        }else{
            node.next = this.head
            this.head.prev = node
            this.head = node
        }
        this.size++
    }
    /**
     * Inserts value after tail
     * @param {any} value
     */
    this.append = function(value){
        if(this.isEmpty()) this.prepend(value)
        else{
            const node = new Node(value)
            node.prev = this.tail
            this.tail.next = node
            this.tail = node
            this.size++
        }
    }

    /**
     * Removes item from the end
     */
    this.pop = function(){
        if(this.size === 1){
            this.head = null
            this.tail = null
        } else {
            const prev = this.tail.prev
            prev.next = null
            this.tail = prev
        }
        this.size--
    }
    /**
     * Removes item from beginning
     */
    this.shift = function(){
        if(this.size === 1) this.pop()
        else{
            this.head = this.head.next
            this.head.prev = null
            this.size--
        }
    }
    this.valueOf = function*(){
        let current = this.head
        while(current){
            yield current.value
            current = current.next
        }
    }
    /**
     * @returns {boolean} size of linked list
     */
    this.isEmpty = function(){
        return this.size === 0
    }
}
module.exports = DoublyLinkedList