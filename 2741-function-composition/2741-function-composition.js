/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
    return (x) => functions.reduceRight((acc, fn) => fn(acc), x);
};

// Example usage:
const fn = compose([
    x => x + 1,  // Add 1
    x => x * 2,  // Multiply by 2
    x => x + 3   // Add 3
]);

console.log(fn(4)); // Output: 11
