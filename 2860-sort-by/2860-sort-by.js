var sortBy = function(arr, fn) {
    return arr.sort((a, b) => fn(a) - fn(b));
};


console.log(sortBy([5, 4, 1, 2, 3], x => x)); 


console.log(sortBy([{x: 1}, {x: 0}, {x: -1}], d => d.x)); 


console.log(sortBy([[3, 4], [5, 2], [10, 1]], x => x[1])); 

