/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length;
};

// Example usage:
console.log(argumentsLength(5)); // Output: 1
console.log(argumentsLength({}, null, "3")); // Output: 3
console.log(argumentsLength(1, 2, 3, 4, 5)); // Output: 5
console.log(argumentsLength()); // Output: 0
