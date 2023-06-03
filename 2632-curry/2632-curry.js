/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    // No of parameter which is original function expecting
    const noOfArgs = fn.length;
    // No of parameter in which curried function called
    let getArgs = 0;
    // Store all the inputs
    const totalArgs = [];
    return function curried(...args) {
        // adding no of inputs
        getArgs += args.length;
        // adding no of inputs values
        totalArgs.push(...args);
        // if no of inputs is equal to original function then we call original function with input values
        if(getArgs === noOfArgs) return fn(...totalArgs);
        // otherwise called curried function
        return curried;
    };
};
/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
