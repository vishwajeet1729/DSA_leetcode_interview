// Last updated: 1/17/2026, 12:30:54 PM
// C++
class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for (char &c : s) {
            if (c == '6') { c = '9'; break; }
        }
        return std::stoi(s);
    }
};