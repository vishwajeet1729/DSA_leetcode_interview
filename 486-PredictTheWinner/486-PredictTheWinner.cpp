// Last updated: 1/17/2026, 12:32:41 PM
class Solution {
public:
int dp[30][30]={0};
    int rec(int i,int j,vector<int>v){
           
           if(i>j)return 0;
           if(dp[i][j]!=-1)return dp[i][j];
         int a=v[i]+min(rec(i+2,j,v),rec(i+1,j-1,v));
         int b=v[j]+min(rec(i+1,j-1,v),rec(i,j-2,v));
         dp[i][j]=max(a,b);
         return dp[i][j];

    }
    bool predictTheWinner(vector<int>& v) {
           
           int n=v.size();
           
        int two=0;
        for(int i=0;i<30;++i)for(int j=0;j<30;++j)dp[i][j]=-1;
        for(int i=0;i<n;++i)two+=v[i];
        int one=rec(0,n-1,v);
        two-=one;
         if(one>=two)return 1;
         else return 0;


    }
};