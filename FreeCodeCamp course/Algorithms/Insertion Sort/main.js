/**
 * Insertion sort algorithm
 * @param {number[]} array unsorted array
 * @returns {number[]} sorted one
 */
function insertionSort(array) {
    for(let i = 1; i < array.length; i++){
        let j = i - 1
        let curr = array[i]
        while(j > -1 && curr < array[j]){
            array[j + 1] = array[j]
            j--
        }
        array[j + 1] = curr
    }
    return array;
}

console.log(insertionSort([12, 11, 13, 5, 6]))