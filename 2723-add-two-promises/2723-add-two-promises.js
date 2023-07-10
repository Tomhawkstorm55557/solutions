/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
//Given two promises promise1 and promise2, return a new promise. promise1 and promise2 will both resolve with a number. The returned promise should resolve with the sum of the two numbers.
var addTwoPromises = async function(promise1, promise2) {
    
    let sum =0;
    sum+= await promise1;
    sum+= await promise2;
  return   Promise.resolve(sum)
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
//The Promise object represents the eventual completion (or failure) of an asynchronous operation and its resulting value.
//The await operator is used to wait for a Promise and get its fulfillment value. It can only be used inside an async function or at the top level of a module.

//An async function declaration creates an AsyncFunction object. Each time when an async function is called, it returns a new Promise which will be resolved with the value returned by the async function, or rejected with an exception uncaught within the async function.
//Promise resolve() method: The promise.resolve() method in JS returns a Promise object that is resolved with a given value. Any of the three things can happen: 

//If the value is a promise then the promise is returned.
//If the value has a “then” attached to the promise, then the returned promise will follow that “then” to till the final state.
//The promise fulfilled with its value will be returned.