/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  let length = arr.length;
  let ans = [];
  let k = 0;

  for (let i = 0; i < length; i += size) {
    ans[k] = arr.slice(i, i + size);
    k++;
  }

  return ans;
};