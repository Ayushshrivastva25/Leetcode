Array.prototype.last = function() {
    return this.length > 0 ? this[this.length - 1] : -1;
};


const nums1 = JSON.parse('[null, {}, 3]');
console.log(nums1.last()); 

const nums2 = JSON.parse('[]');
console.log(nums2.last()); 
