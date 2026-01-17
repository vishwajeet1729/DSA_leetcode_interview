// Last updated: 1/17/2026, 12:35:25 PM
class Solution {
public:
    bool isPalindrome(int x) {
             string s=to_string(x);
            string p=s;
            reverse(s.begin(),s.end());
            if(s==p)return true;
            else return false;
    }
};