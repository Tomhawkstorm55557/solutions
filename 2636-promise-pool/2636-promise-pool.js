/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    const res = [];

    async function evaluateNext() 
    {
        if (functions.length === 0) 
            return;
        const fn = functions.shift();
        const ref = await fn();
        
        res.push(ref);
        await evaluateNext();
    }

    const nPromises = Array(n).fill().map(evaluateNext);
    await Promise.all(nPromises);

    return [res, res[res.length - 1]];
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */