class Solution {
public:
     

    int change(int amount, vector<int>& v) {
               //{}
int n=v.size();
    //  amount=5;/
     vector<vector<int>>dp(n,vector<int>(amount,-1));
     function<int(int,int)>rec=[&](int cur,int ind)->int{                
    if(cur==amount)return 1;
    if(cur>amount||ind>=n)return 0;
    if (dp[ind][cur] != -1) return dp[ind][cur];
    return dp[ind][cur]=rec(cur+v[ind],ind)+rec(cur,ind+1);  
     };
       return rec(0,0);
    }
};