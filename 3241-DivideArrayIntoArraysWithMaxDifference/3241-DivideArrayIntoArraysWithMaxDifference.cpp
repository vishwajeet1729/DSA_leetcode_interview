// Last updated: 1/17/2026, 12:28:04 PM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
      sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>s(n/3,vector<int>(3));
        int j=0;
        for(int i=0;i<n&&i+2<n;i+=3){
              // v.push_back(v[i])
            s[j][0]=v[i];
                        s[j][1]=v[i+1];

                        s[j][2]=v[i+2];
            j++;

        }
        bool re=false;
        vector<vector<int>>p;
        
        for(int i=0;i<n/3;++i){
            if(s[i][2]-s[i][0]>k){
                re=true;
            }
        }
        if(re)return p;
        else return s;
    }
};