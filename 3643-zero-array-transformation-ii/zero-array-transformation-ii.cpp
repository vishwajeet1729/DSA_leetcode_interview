class Solution {
public:
    int minZeroArray(vector<int>& act, vector<vector<int>>& v) {

function<bool(int)>check=[&](int k)->bool{
      vector<int>ans(act.size()+1,0);

    for(int i=0;i<k;++i){ans[v[i][0]]+=v[i][2];ans[v[i][1]+1]-=v[i][2];}
     for(int i=1;i<act.size();++i)ans[i]+=ans[i-1];
for(int i=0;i<act.size();++i){
    if(act[i]>ans[i])return false;
}
return 1;
};
       int l=0,r=v.size();
      int ans=-1;   
      while(l<=r){
           int mid=(l+r)>>1;
           
           if(check(mid)){
            ans=mid;
            r=mid-1;
           }
           else l=mid+1;
      }
        //  if()
           return ans;
// cout<<ans<<endl;
 
    }
};