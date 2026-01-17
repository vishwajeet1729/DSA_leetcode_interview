// Last updated: 1/17/2026, 12:26:36 PM
class Solution {
public:
    int minElement(vector<int>& v) {
           int mi=INT_MAX;
        for(int i=0;i<v.size();++i){
             int x=v[i];  
            int sum=0;
            while(v[i]){
                   sum+=v[i]%10;
                v[i]=v[i]/10;
            }
            mi=min(mi,sum);
            
        }
        return mi;
        
        
    }
};