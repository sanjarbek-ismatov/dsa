/**
 * 
 * @param {number[]} searchList 
 * @param {number} value 
 * @returns 
 */
function binarySearch(searchList, value) {
  // checked arrays
  let arrayPath = [];
  // left, right or low and high
  let left = 0,
    right = searchList.length - 1,
    // if it is found, it gets true
    found = false;
  // if there is no target and left is already bigger than right, the loop stops
  while (left <= right) {
    // middle to compare with the target
    let mid = Math.floor((left + right) / 2);
    // to record how many steps done
    arrayPath.push(searchList[mid]);
    if (searchList[mid] === value) {
      // the loop breaks here
      found = true;
      break;
      // deciding what to do with the array
    } else if (searchList[mid] > value) right = mid - 1;
    else left = mid + 1;
  }
  // finally, the result is returned
  return found ? arrayPath : "Value Not Found";
}

const testArray = [
  0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  23, 49, 70,
];

console.log(binarySearch(testArray, 0)); // [13, 5, 2, 0]
