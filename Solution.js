
/**
 * @param {string} pattern
 * @param {string} words
 * @return {boolean}
 */
var wordPattern = function (pattern, words) {
    let mapIndex = new Map();
    const arrayWords = words.split(' ');

    if (arrayWords.length !== pattern.length) {
        return false;
    }

    let size = pattern.length;
    for (let i = 0; i < size; i++) {

        let charID = "_" + pattern.charAt(i);

        if (!mapIndex.has(charID)) {
            mapIndex.set(charID, i);
        }

        if (!mapIndex.has(arrayWords[i])) {
            mapIndex.set(arrayWords[i], i);
        }

        if (mapIndex.get(charID) !== mapIndex.get(arrayWords[i])) {
            return false;
        }
    }
    return true;
};
