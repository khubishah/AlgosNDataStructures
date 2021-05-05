/*
Given that a character can be 0,1,or *, where * means both a 0 or 1 are allowed, return all the possible valid strings

e.g. 10*1 [1001,1011]

*/
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<string> results;
    public:
        void recursiveCreateStrings(string s, int idx, string path) {
            if (idx == s.length()) {
                results.emplace_back(path);
                return;
            }
            if (s[idx] == '1' || s[idx] == '0') {
                recursiveCreateStrings(s,idx + 1, path += s[idx]);
                return;
            }
            recursiveCreateStrings(s, idx + 1, path += '0');
            recursiveCreateStrings(s, idx + 1, path += '1');

        }
        vector<string> getAllBinaryStrings(string s) {
            recursiveCreateStrings(s,0, "");
            return results;
        }
};

// runtime worst case: O(2^n) (C++ strings are mutable, so body runtime is O(1))


