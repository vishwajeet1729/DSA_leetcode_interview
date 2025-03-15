class Solution {
public:
 bool check(int mid,vector<int>&v,int k){
        bool back=0;
        int ct=0;
    for(int i=0;i<v.size();++i){
          if(back){
           back=!back;
          }
          else {if(v[i]<=mid){ct++;back=1;}}
               
    }
    // cout<<"ct :" <<ct<<endl;
    return ct>=k;
}
    int minCapability(vector<int>& v, int k) {
           int l=1,h=*max_element(v.begin(),v.end());
         int ans=-1;
        
        while(l<=h){
              int mid=(l+h)>>1;
            //   cout<<mid<<endl;
              if(check(mid,v,k)){
                ans=mid;
              h=mid-1;
              }
              else l=mid+1;
        }
        return ans;
    }
};