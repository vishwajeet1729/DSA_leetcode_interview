// Last updated: 1/17/2026, 12:31:57 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& h, int g) {
           
           int n=h.size();
           map<int,int>m;
           for(int i=0;i<n;++i)m[h[i]]++;
          
          for(auto it:m){
              if(it.second==0)continue;
              for(int i=it.first;i<it.first+g;++i){
               if(it.second>m[i]||m.count(i)==0)return false;
               m[i]-=it.second;

              }

          }
            
            return true;
    }
};