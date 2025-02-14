function reduce(nums, fn, init) {
    let val = init;
    for (let i = 0; i < nums.length; i++) {
        val = fn(val, nums[i]);
    }
    return val;
}

// Example usage:
const nums = [1, 2, 3, 4];
const fn = (acc, curr) => acc + curr;
const init = 0;
console.log(reduce(nums, fn, init)); // Output: 10
