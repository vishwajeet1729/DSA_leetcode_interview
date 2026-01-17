// Last updated: 1/17/2026, 12:27:11 PM
class Solution {
public:
    string clearStars(string s) {
          int n = s.size();
        string res="";
        multiset<pair<char, int>> st; 

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                auto it = st.begin();
                int index = it->second;
               st.erase(it);
                s[-index] = '*';
                continue;
            } 
            
         st.insert({s[i], -i});
            
        }
        
      
        for (auto ch : s) {
            if (ch != '*') 
                res.push_back(ch);
            
        }
        return res;
    }
};