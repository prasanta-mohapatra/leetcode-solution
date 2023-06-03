/* 
Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]
*/

const rotate_array = (n, k, arr) => {
  let start_slice = arr.slice(n - k, n);
  let end_slice = arr.slice(0, n - k);
  return [...start_slice, ...end_slice];
};

const rotate_array_2nd_method = (n, k, arr) => {
  const new_array = Array(n).fill(0);

  for (let i = 0; i < n; i++) {
    new_array[(k + i) % n] = arr[i];
  }
  return new_array;
};

nos_element = 7;
steps = 3;
array = [1, 2, 3, 4, 5, 6, 7];
solution = [5, 6, 7, 1, 2, 3, 4];

result = rotate_array_2nd_method(nos_element, steps, array);

console.log(result);

if (JSON.stringify(result) == JSON.stringify(solution)) {
  console.log("Matched");
} else [console.log("Error in the Code")];
