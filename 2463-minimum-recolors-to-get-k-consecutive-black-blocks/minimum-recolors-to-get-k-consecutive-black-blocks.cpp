class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();
          int mi=s.size();
          for(int i=0;i+k-1<n;++i){
   int ct=0;
            for(int j=i;j<k+i;++j){
                   if(s[j]=='W')ct++;
            }
            mi=min(mi,ct);
          }
          return mi;
    }
};