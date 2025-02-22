function cancellable(fn, args, t) {

    fn(...args);
    
    const intervalId = setInterval(() => fn(...args), t);
    
    return function cancelFn() {
        clearInterval(intervalId);
    };
}
const fn1 = (x) => x * 2;
const cancelFn1 = cancellable(fn1, [4], 35);
setTimeout(cancelFn1, 190);

const fn2 = (x1, x2) => x1 * x2;
const cancelFn2 = cancellable(fn2, [2, 5], 30);
setTimeout(cancelFn2, 165);

const fn3 = (x1, x2, x3) => x1 + x2 + x3;
const cancelFn3 = cancellable(fn3, [5, 1, 3], 50);
setTimeout(cancelFn3, 180);