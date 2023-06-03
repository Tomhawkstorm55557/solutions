/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
const objDiff = (sourceObj, targetObj) => {
    // Special case: Objects are the same
    if (sourceObj === targetObj) return {};

    // Special cases: Null values or different types
    if (sourceObj === null || targetObj === null) return [sourceObj, targetObj];
    if (typeof sourceObj !== 'object' || typeof targetObj !== 'object') return [sourceObj, targetObj];
    if (Array.isArray(sourceObj) !== Array.isArray(targetObj)) return [sourceObj, targetObj];

    const diffObj = {}; // Object to store the differences

    // Iterate over the keys in sourceObj
    Object.keys(sourceObj).forEach(key => {
        if (key in targetObj) {
            const subDiff = objDiff(sourceObj[key], targetObj[key]); // Recursive call for nested objects

            // If there are differences, add them to the diffObj
            if (Object.keys(subDiff).length > 0) {
                diffObj[key] = subDiff;
            }
        }
    });

    return diffObj; // Return the object containing the differences
};