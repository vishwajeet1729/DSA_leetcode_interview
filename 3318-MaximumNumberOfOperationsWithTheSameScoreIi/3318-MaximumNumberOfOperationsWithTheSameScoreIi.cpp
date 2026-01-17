// Last updated: 1/17/2026, 12:27:47 PM
class Solution {
public:
int dp[2001][2001];
vector<int>a;
int su;
int make(int i,int j){
     if(j-i<=0)return 0;
     if(dp[i][j]==-1){
       int ans=0;
       if(a[i]+a[j]==su)ans=max(ans,1+make(i+1,j-1));
       if(a[i]+a[i+1]==su)ans=max(ans,1+make(i+2,j));
       if(a[j]+a[j-1]==su)ans=max(ans,1+make(i,j-2));
        dp[i][j]=ans;
        return dp[i][j];
     }
    return dp[i][j];
}
int maxOperations(vector<int>&nums){
  a=nums;
  int n=a.size();
  for(int i=0;i<a.size();++i){
    for(int j=0;j<a.size();++j){
      dp[i][j]=-1;
    }
  }
  su=a[0]+a[1];
    int ans=0;
   ans=max(ans,make(0,n-1));
    for(int i=0;i<a.size();++i){
    for(int j=0;j<a.size();++j){
      dp[i][j]=-1;
    }
  }
 su=a[0]+a[n-1];
 ans=max(ans,make(0,n-1));
 for(int i=0;i<a.size();++i){
  for(int j=0;j<a.size();++j)dp[i][j]=-1;
 }
 su=a[n-1]+a[n-2];
 ans=max(ans,make(0,n-1));
 return ans;



    }
};
