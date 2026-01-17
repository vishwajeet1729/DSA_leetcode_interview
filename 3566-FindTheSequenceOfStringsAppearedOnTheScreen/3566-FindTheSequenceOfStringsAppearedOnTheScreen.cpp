// Last updated: 1/17/2026, 12:26:42 PM
class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string current = "";  
        for (char c : target) {
            current += 'a';
            result.push_back(current);  
            
            while (current.back() != c) {
                current.back() = (current.back() == 'z') ? 'a' : current.back() + 1;  
                result.push_back(current); 
            }
        }

        return result;
    }
};