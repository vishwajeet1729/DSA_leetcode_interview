// Last updated: 1/17/2026, 12:35:04 PM
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) { 
            string demo = "";
            int i = 0;
            while (i < s.size()) {
                int ct = 1;  
                char c = s[i];
                while (i + 1 < s.size() && s[i] == s[i + 1]) {
                    ct++;
                    i++;
                }
                demo += to_string(ct); 
                demo += c; 
                i++;  
            }
            s = demo;  
        }
        return s;
    }
};
