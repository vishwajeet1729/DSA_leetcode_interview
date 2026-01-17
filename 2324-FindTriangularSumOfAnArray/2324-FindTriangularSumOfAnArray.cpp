// Last updated: 1/17/2026, 12:29:19 PM
class Solution {
public:
    int triangularSum(vector<int>& v) {
        int n=v.size();

    int k=n-1;
    
    while(k--){
          
        for(int i=0;i<=k;++i){
            v[i]+=v[i+1];
            v[i]%=10;
        } 
        // for(int i=0;i<n;++i)cout<<v[i]<<" ";
        // cout<<endl;  
    }
    return v[0];  
    }
};