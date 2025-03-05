class Solution {
public:
    int longestStrChain(vector<string>& v) {
         int n=v.size();
    sort(v.begin(),v.end(),[](const string &a, const string &b) {
        return a.size() < b.size();
    });
    vector<int>dp(n,1);
    vector<int>prev(n,0);
     for(int i=0;i<n;++i)prev[i]=i;
    for(int i=0;i<n;++i){
     for(int j=0;j<i;++j){
        auto isPredecessor = [&]() -> bool {
            if (v[i].size() != v[j].size() + 1) return false;
            int k = 0, l = 0;
            while (k < v[i].size()) {  
                if (l < v[j].size() && v[i][k] == v[j][l]) {
                    l++; 
                }
                k++;
            }
            return l == v[j].size();
        } ; 

            if(isPredecessor()&&dp[i]<1+dp[j]){
                      dp[i]=1+dp[j];
                      prev[i]=j;
              }
             }
     }
    
     int mx=*max_element(dp.begin(),dp.end());
//      int ind=0;
//      for(int i=0;i<n;++i){
//          if(dp[i]==mx){
//              ind=i;break;
//          }
//      }
//     vector<string>ans;
//     while(prev[ind]!=ind){
//       ans.push_back(v[ind]);
//       ind=prev[ind];
//     }
//    ans.push_back(v[ind]);
//   for(auto it:ans)cout<<it<<" ";line;     
    //  cout<<mx<<endl;
    return mx;
    }
};