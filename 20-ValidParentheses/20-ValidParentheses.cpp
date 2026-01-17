// Last updated: 1/17/2026, 12:35:14 PM
class Solution
{
public:
   bool isValid(string s) {
    vector<char> v;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            v.push_back(s[i]);
        else {
            if (v.empty() ||
                (s[i] == ')' && v.back() != '(') ||
                (s[i] == ']' && v.back() != '[') ||
                (s[i] == '}' && v.back() != '{'))
                return false;
            else
                v.pop_back();
        }
    }

    return v.empty(); 
}

};