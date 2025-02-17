/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let called = false; // Track if fn has been called
    
    return function(...args) {
        if (!called) {
            called = true; // Mark fn as called
            return fn(...args); // Call and return result
        }
        return undefined; // Return undefined after first call
    };
};

/**
 * Example Usage
 */
let fn = (a, b, c) => (a + b + c);
let onceFn = once(fn);

console.log(onceFn(1, 2, 3)); // 6
console.log(onceFn(2, 3, 6)); // undefined
