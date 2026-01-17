// Last updated: 1/17/2026, 12:33:38 PM
class Solution {
public:
    int rob(vector<int>& v) {
           
       //rob=max(v[0]+rob(2,n),rob(1,n));
        int rob1=0,rob2=0;
int n=v.size();
int temp=0;
        for(int i=0;i<n;++i){
           
           temp=max(v[i]+rob1,rob2);
           rob1=rob2;
           rob2=temp;     
        }

      return max(rob1,rob2);

    }
};