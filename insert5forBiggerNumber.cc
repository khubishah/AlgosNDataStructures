/*
Insert 5 at any location in a number represented as a string to create the larger possible number.

i.e. "499" -> "5449"
"-493" -> "-4593"
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
    public:
        int insert5ForBiggestNumber(int number) {
            if (number == 0)
                return 5;
            ostringstream ss;
            ss << number;
            string num = ss.str();
            int i;
            int five = number < 0 ? -5 : 5;
            for (i = number < 0 ? 1 : 0; i < num.length (); i++) {    
                if (five > (num[i] - 48) * (number < 0 ? -1 : 1))
                    break;
            }
            num.insert (i, "5");
            istringstream ansStream{num};
            int ans;
            ansStream >> ans;
            return ans;
        
        }
};

// runtime: O(n), space: O(n)