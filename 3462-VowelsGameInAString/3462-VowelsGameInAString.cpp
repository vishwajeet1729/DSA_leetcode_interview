// Last updated: 1/17/2026, 12:27:03 PM
class Solution {
public:
   bool is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
    bool doesAliceWin(string s) {
        //easy
        int ct=0;
        for(auto it:s){
            if(is_vowel(it))ct++;
        }
       return ct>0;

    }
};