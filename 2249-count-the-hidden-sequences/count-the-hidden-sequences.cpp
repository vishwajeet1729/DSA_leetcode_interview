class Solution {
public:
    int numberOfArrays(vector<int>& v, int l, int u) {
        vector<long long>ans;
   ans.push_back(1);
//    int l=-4,u=5;
 long long  mi=1,mx=1;
   for(auto it:v){
          int y=ans.back();

          //k-y=it
          ans.push_back((long long)it+y);
          mi=min(mi,(long long)it+y);
          mx=max(mx,(long long)it+y);
   }

    if(mi<l){
        long long x=l-mi;
        for(auto &it:ans)it+=x;
    }
    if(mx>u){
          long long x=mx-u;
          for(auto &it:ans)it-=x;
    }
    mi=INT_MAX,mx=INT_MIN;
    for(auto it:ans){
        if(it>u||it<l){
            return 0;
        }
        mi=min(mi,it);mx=max(mx,it);
        
    }
    // for(auto it:ans)cout<<it<<" ";line;
//    return ans;
long long ct;
     return  ct=abs(mx-u)+abs(mi-l)+1;
    }
};