class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans=0;
        for(int i=1;i<v.size();++i){
             if(v[i]>v[i-1])ans+=v[i]-v[i-1];
        }
        return ans;
    }
};