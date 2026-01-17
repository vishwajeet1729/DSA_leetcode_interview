// Last updated: 1/17/2026, 12:29:17 PM
class Solution {
public:
    int largestCombination(vector<int>& v) {
           
        int arr[31]={0};
        int mx=0;
        for(int i=0;i<v.size();++i){
                
                for(int j=0;j<=30;++j){
                       
                    int x=(1<<j)&v[i];
                    if(x)arr[j]++;
         mx=max(mx,arr[j]);
                }


        }
   return mx;
    }
};