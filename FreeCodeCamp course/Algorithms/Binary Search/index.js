function binarySearch(searchList, value) {
  let arrayPath = [];
  let left = 0,
    right = searchList.length - 1,
    found = false;
  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    arrayPath.push(searchList[mid]);
    if (searchList[mid] === value) {
      found = true;
      break;
    } else if (searchList[mid] > value) right = mid - 1;
    else left = mid + 1;
  }
  return found ? arrayPath : "Value Not Found";
}

const testArray = [
  0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  23, 49, 70,
];

console.log(binarySearch(testArray, 0)); // [13, 5, 2, 0]
