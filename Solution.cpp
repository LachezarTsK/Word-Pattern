
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:

    bool wordPattern(string pattern, string input) {

        string temp;
        stringstream s(input);
        vector<string> words;
        while (getline(s, temp, ' ')) {
            words.push_back(temp);
        }


        if (words.size() != pattern.length()) {
            return false;
        }

        unordered_map<string, int> mapIndex;
        size_t size = pattern.length();

        for (size_t i = 0; i < size; i++) {

            string charID = "_";
            charID.push_back(pattern[i]);

            if (mapIndex.find(charID) == mapIndex.end()) {
                mapIndex[charID] = i;
            }
            if (mapIndex.find(words[i]) == mapIndex.end()) {
                mapIndex[words[i]] = i;
            }
            if (mapIndex[charID] != mapIndex[words[i]]) {
                return false;
            }
        }
        return true;
    }
};
