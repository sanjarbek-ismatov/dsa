// MY SOLUTION
function updateInventory1(arr1, arr2) {
    arr2.forEach((curItem) => mergeInventory(curItem, arr1))
    return sort(arr1);
}

/**
 * Sorts the array
 * @param {[number, string][]} arr
 * @returns {[number, string][]}
 */
function sort(arr){
   return arr.sort((a, b) => a[1].localeCompare(b[1]))
}

/**
 * Merges item into curInv
 * @param {[number, string] | []} item
 * @param {[number, string][]} curInv
 */
function mergeInventory(item, curInv){
    if(item.length === 0) return
    const theSameAsItem = curInv.find((curItem) => curItem[1] === item[1])
    if(theSameAsItem  && theSameAsItem.length === 2)
        theSameAsItem[0] = theSameAsItem[0] + item[0]
    else curInv.push(item)
}

// ANOTHER ONE

function updateInventory2(curInv, newInv){
    for(let item2 of newInv){
        let found = false
        for(let item1 of curInv){
            if(item1[1] === item2[1]){
                item1[0] += item2[0]
                found = true
                break
            }
        }
        if(!found) curInv.push([...item2])
    }
    return curInv.sort((a, b) => a[1] < b[1] ? -1 : 1)
}

// ANOTHER ONE

function updateInventory3(curInv, newInv){
    const combinedInventory = {}
    for(let item of curInv){
        combinedInventory[item[1]] = item[0]
    }
    for(let item of newInv){
        combinedInventory[item[1]] ??= 0
        combinedInventory[item[1]] += item[0]
    }
    return Object.keys(combinedInventory).sort().map(item => [combinedInventory[item], item])
}
// Example inventory lists
var curInv = [
    [21, "Bowling Ball"],
    [2, "Dirty Sock"],
    [1, "Hair Pin"],
    [5, "Microphone"]
];

var newInv = [
    [2, "Hair Pin"],
    [3, "Half-Eaten Apple"],
    [67, "Bowling Ball"],
    [7, "Toothpaste"]
];

// console.log(updateInventory1(curInv, newInv))
// console.log(updateInventory2(curInv, newInv))
console.log(updateInventory3(curInv, newInv))