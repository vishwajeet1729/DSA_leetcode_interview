// Last updated: 1/17/2026, 12:32:09 PM
class Solution {
public:
    int numRabbits(vector<int>& v) {
    int n=v.size();

    unordered_map<int,int>m;

      int ct=0;
    for(int i=0;i<n;++i){
          
     m[v[i]+1]++;
     if(m[v[i]+1]==v[i]+1){
        ct+=v[i]+1;
        m.erase(m[v[i]+1]);
     }

    }
    for(auto it:m){
                ct+=(it.first);
    }
    return ct;
      
    }
};