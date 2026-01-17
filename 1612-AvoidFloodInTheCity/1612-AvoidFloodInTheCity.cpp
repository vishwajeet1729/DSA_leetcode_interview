// Last updated: 1/17/2026, 12:30:37 PM
class Solution {
public:
    vector<int> avoidFlood(vector<int>& v) {
        //    vector<int> v = {1,2,0,1,2};
    int n = v.size();
    int dry = 0;
   set<int>s;
   unordered_map<int,int>m;
   vector<int>ans(n,1);
   for(int i=0;i<n;++i){
        
    if(v[i]>0){
        ans[i]=-1;
       
        if(m.find(v[i])!=m.end()){ 
        
            //it shpuld dry before the current day
            auto it=s.lower_bound(m[v[i]]);
            if(it==s.end()){
                return vector<int>{};
            }
            ans[*it]=v[i];
            s.erase(it);
        }
        m[v[i]]=i;

    }
    else s.insert(i);

   }
return ans;
 
    }
};