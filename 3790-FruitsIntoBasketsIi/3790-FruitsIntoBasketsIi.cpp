// Last updated: 1/17/2026, 12:25:49 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& a, vector<int>& b) {
           // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    
   int n = a.size();
    // int n=a.size();
        int ct=0;

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(b[j]>=a[i]){
                    ct++;
                    // cout<<"jii";
                    b[j]=0;
                    break;
                }
            }
        }
        return n-ct;
    }
};