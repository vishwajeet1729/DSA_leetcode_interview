// Last updated: 1/17/2026, 12:32:53 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto it:nums)m[it]++;

        vector<pair<int,int>>ans;
        for(auto it:m)ans.push_back({it.second,it.first});
        sort(ans.begin(),ans.end());

        vector<int>fi;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<k;++i)fi.push_back(ans[i].second);

        return fi;
    }
};