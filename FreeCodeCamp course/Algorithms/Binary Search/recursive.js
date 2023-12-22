/**
 * Binary Search recursive
 * @param {number[]} array
 * @param {number} target
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
function binarySearch(array, target, left = 0, right = array.length - 1) {
  let mid = Math.floor((left + right) / 2);
  if (left > right) return -1;
  if (array[mid] === target) return mid;
  else if (array[mid] > target)
    return binarySearch(array, target, left, mid - 1);
  else return binarySearch(array, target, mid + 1, right);
}
const testArray = [
  0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  23, 49, 70,
];
console.log(binarySearch(testArray, 100));
