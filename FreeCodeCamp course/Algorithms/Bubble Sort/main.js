/**
 * Bubble Sort algorithm
 * @param {number[]} unsortedArr Unsorted array
 * @returns {number[]} Sorted array
 */
function bubbleSort(unsortedArr){
     const result = [...unsortedArr]
     let swapped;
     do{
          swapped = false
          for(let i = 0; i < result.length; i++){
               if(result[i] > result[i + 1]){
                    let current = result[i + 1]
                    result[i + 1] = result[i]
                    result[i] = current
                    swapped = true
               }
          }
     } while(swapped)
     return result
}

/**
 * Bubble Sort algorithm
 * @param {number[]} unsortedArr Unsorted array
 * @returns {number[]} Sorted array
*/
function bubbleSortRecursion(unsortedArr){
     function bubbler(arr, index, swapped){
          if(!swapped && index < arr.length - 1) return arr
          if(arr[index] > arr[index + 1]){
               [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]]
               index++
               swapped = true
          }
     }
}