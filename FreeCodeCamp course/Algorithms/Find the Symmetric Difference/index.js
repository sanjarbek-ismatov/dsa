function sym(...args) {
    function symDifference(arr1, arr2){
        const result = []
        for(const item1 of arr1){
            if(!arr2.includes(item1) && !result.includes(item1)) result.push(item1)
        }
        for(const item2 of arr2){
            if(!arr1.includes(item2) && !result.includes(item2)) result.push(item2)
        }
        return result
    }
    return args.reduce(symDifference);
}
console.log(sym([1, 2, 3], [5, 2, 1, 4]));
// console.log(sym([1, 2, 3, 3], [5, 2, 1, 4]))