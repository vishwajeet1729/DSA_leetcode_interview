// Last updated: 1/17/2026, 12:29:16 PM
class Solution {
public:
    int partitionArray(vector<int>& v, int k) {
int n=v.size();
int i=0;
int ct=0;

// i++;
sort(v.begin(),v.end());
int mi=v[0],mx=v[0];
while(i<n){
    
        if(abs(v[i]-mi)<=k&&abs(v[i]-mx)<=k){
                mi=min(mi,v[i]);mx=max(mx,v[i]);
                i++;
                if(i==n)ct++;
               
        }
        else {
                 ct++;
                 mi=v[i],mx=v[i];
                //  i++;
        }
        
}         
    
  if(n==1)return 1;       
return ct;
    }
};