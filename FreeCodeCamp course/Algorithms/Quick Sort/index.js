function quickSort1(arr){
    if(arr.length <= 1) return arr
    const pivot = Math.floor(arr.length / 2)
    const left = []
    const right = []
    for(let i = 0; i < arr.length; i++){
        if(i === pivot) continue
        if(arr[pivot] > arr[i]) left.push(arr[i])
        else right.push(arr[i])
    }
    return [...quickSort1(left), arr[pivot], ...quickSort1(right)]
}

//Swapping array elements via ES6 array destructuring
function swap(arr, x, y) {
    [arr[x], arr[y]] = [arr[y], arr[x]];
}

//Pivot function returns the fixed pivot point
function pivot(arr, left = 0, right = arr.length - 1) {
    let shift = left;
    for (let i = left + 1; i <= right; i++) {
        //Move all the small elements on the left side
        if (arr[i] < arr[left]) swap(arr, i, ++shift);
    }

    //Finally swapping the last element with the left
    swap(arr, left, shift);
    return shift;
}

function quickSort(array, left = 0, right = array.length - 1) {
    if (left < right) {
        let pivotIndex = pivot(array, left, right);

        //Recursively calling the function to the left of the pivot and to the right of the pivot
        quickSort(array, left, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, right);
    }
    return array;
}
console.log(quickSort([3, 4, 1, 5, 2]))