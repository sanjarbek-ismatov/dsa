/**
 * Pairwise
 * @param {number[]} arr
 * @param {number} target
 * @returns {number}
 */
function pairwise(arr, target){
    const usedIndices = []
    /**
     * Finder for pairwise function
     * @param {number[]} arr
     * @param {number} target
     * @param {number[]} usedIndices
     */
    function pairwiseFinder(arr, target, usedIndices){
        let sum = 0
        for(let i = 0; i < arr.length; i++){
            for(let j = 0; j < arr.length; j++){
                if(!(usedIndices.includes(i) || usedIndices.includes(j)) && i !== j) {
                    if (arr[i] + arr[j] === target) {
                        sum += i + j
                        usedIndices.push(i, j)
                    }
                }
            }
        }
        return sum
    }
    return pairwiseFinder(arr, target, usedIndices)
}

console.log(pairwise([1,4,2,3,0,5], 7))
console.log(pairwise([1, 3, 2, 4], 4))
console.log(pairwise([1, 1, 1], 2))
console.log(pairwise([], 100))