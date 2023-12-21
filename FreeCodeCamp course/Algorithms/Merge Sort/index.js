function mergeSort(array) {
  if (array.length <= 1) return array;
  const center = Math.floor(array.length / 2);
  return merge(
    mergeSort(array.slice(0, center)),
    mergeSort(array.slice(center))
  );
}
function merge(left, right) {
  let leftIndex = 0,
    rightIndex = 0;
  const merged = [];
  while (leftIndex < left.length && rightIndex < right.length) {
    if (left[leftIndex] > right[rightIndex]) merged.push(right[rightIndex++]);
    else merged.push(left[leftIndex++]);
  }
  while (leftIndex < left.length) {
    merged.push(left[leftIndex++]);
  }
  while (rightIndex < right.length) {
    merged.push(right[rightIndex++]);
  }
  return merged;
}

console.log(mergeSort([3, 4, 1, 5, 2]));
