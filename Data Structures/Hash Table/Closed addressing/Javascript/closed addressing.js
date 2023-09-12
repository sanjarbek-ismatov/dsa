const LinkedList = require('./linked list')
class HashTable{
    constructor() {
        /**
         * Table
         * @type {Record<string, {}>}
         */
        this.table = {}
    }
    /**
     * Key hasher
     * @param {string} key
     * @returns {number} hashed key
     */
    hash(key){
        let hash = 0;
        for(let i = 0; i < key.length; i++){
            hash += key.charCodeAt(i)
        }
        return hash % key.length
    }

    /**
     * Insert method for table
     * @param {string} key
     * @param {string} value
     */
    insert(key, value){
        const hashedKey = this.hash(key)
        const currentTable = this.table[hashedKey]
        if(currentTable) currentTable.append(value)
        this.table[hashedKey] = new LinkedList()
        this.table[hashedKey].append(value)
    }

    /**
     * Get method
     * @param {string} key
     * @returns {string[]}
     */
    get(key){
        const hashedKey = this.hash(key)
        const currentTable = this.table[hashedKey]
        if(!currentTable) return []
        return Array.from(currentTable.valueOf())
    }
    remove(){

    }
}

const table = new HashTable()
table.insert("name", "Sanjarbek")
console.log(table.get("name"))
