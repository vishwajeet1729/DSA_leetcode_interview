class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        map<char,int>m;
        vector<int>v;
        int b=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                b++;
            }
            else{
                m[secret[i]]++;
                v.push_back(i);
            }
        }
        for(int i:v){
            if(m[guess[i]]){
                m[guess[i]]--;
                c++;
            } 
        }
        return to_string(b) + 'A' + to_string(c) + 'B';
    }
};