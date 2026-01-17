// Last updated: 1/17/2026, 12:30:17 PM
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
         set<int>s;
         vector<int>v(2*n-1,0);
         function<bool(int)> track=[&](int i){
               if(i==v.size())return true;
               if(v[i]!=0)return track(i+1);
               for(int j=n;j>0;--j){
                   if(s.find(j)!=s.end())continue;
                   if(j>1&&(j+i>=v.size()||v[i+j]!=0))continue;
                   v[i]=j;
                   if(j>1)v[i+j]=j;
                   s.insert(j);
                   if(track(i+1))return true;
                   v[i]=0;
                   if(j>1)v[i+j]=0;
                   s.erase(j);
               }
               return false;
          };
          track(0);
          return v;

    }
};