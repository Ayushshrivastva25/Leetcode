var cancellable = function(fn, args, t) {
    const timeoutId = setTimeout(() => fn(...args), t);
     return function cancelFn() {
        clearTimeout(timeoutId);
    };
};

