/**
 * Selection Sort algorithm
 * @param {number[]} array given array
 * @returns {number[]} sorted array
 */
function selectionSort(array){
    const result = [...array]
    for(let i = 0; i < result.length - 1; i++){
        let min = i
        for(let j = min; j < result.length; j++){
            if(result[min] > result[j])
                min = j
        }
        if(min !== i) [result[i], result[min]] = [result[min], result[i]]
    }
    return result
}
console.log(selectionSort([3, 4, 1, 5, 2]))