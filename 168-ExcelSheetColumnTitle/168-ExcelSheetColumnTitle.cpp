// Last updated: 1/17/2026, 12:33:42 PM
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";

        while (columnNumber > 0) {
            columnNumber--;
            res = char((columnNumber % 26) + 'A') + res;
            columnNumber /= 26;
        }
        
        return res;        
    }
};