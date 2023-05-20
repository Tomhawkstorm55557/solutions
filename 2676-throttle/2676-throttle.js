/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
const throttle = (fn, t) => {
  let interval = null;   // Variable to store the interval ID
  let queuedArgs = null; // Variable to store the queued arguments

  const processArgs = () => {
    if (queuedArgs === null) {
      clearInterval(interval); // If no queued arguments, clear the interval
      interval = null;         // Enter the waiting phase
    } else {
      fn(...queuedArgs); // Call the function with the queued arguments
      queuedArgs = null; // Clear the queued arguments
    }
  };

  return (...args) => {
    if (interval) {
      queuedArgs = args; // If interval is active, queue the arguments
    } else {
      fn(...args);                 // Call the function with the arguments
      interval = setInterval(processArgs, t); // Enter the looping phase with a specified time interval
    }
  };
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */