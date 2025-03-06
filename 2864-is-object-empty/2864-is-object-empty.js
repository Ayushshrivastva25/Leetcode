function isEmpty(obj) {
    return obj.constructor === Object ? Reflect.ownKeys(obj).length === 0 : obj.length === 0;
}


console.log(isEmpty({"x": 5, "y": 42})); 
console.log(isEmpty({}));               
console.log(isEmpty([null, false, 0])); 
console.log(isEmpty([]));               
