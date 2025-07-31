class Solution {
public:
    int maxProduct(vector<string>& s) {

        int n = s.size();
        vector<int> mask(n, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < s[i].size(); ++j)
                mask[i] |= (1 << (s[i][j] - 'a'));

int mx=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if((mask[i]&mask[j])==0)mx=max(mx,(int)s[i].size()*(int)s[j].size());
        }
    }        
    return mx;
    }
};