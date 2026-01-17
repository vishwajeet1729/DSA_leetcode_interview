// Last updated: 1/17/2026, 12:25:29 PM

    class Solution {
public:
    string resultingString(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && isConsecutive(stack.back(), c)) {
                stack.pop_back(); 
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }

private:
    bool isConsecutive(char a, char b) {
        return abs(a - b) == 1 || abs(a - b) == 25;
    }


};