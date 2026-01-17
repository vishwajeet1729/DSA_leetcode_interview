// Last updated: 1/17/2026, 12:33:13 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  return s==t;

    }
};