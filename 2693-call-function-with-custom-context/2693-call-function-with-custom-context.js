/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    const uniqueId=Symbol();
    context[uniqueId]=this;
    const ans=context[uniqueId](...args);
    delete context[uniqueId];
    return ans;

};

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */