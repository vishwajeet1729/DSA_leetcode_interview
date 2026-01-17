// Last updated: 1/17/2026, 12:28:34 PM
class Solution {
public:
    int minimizeMax(vector<int>& v, int p) {
       int n=v.size();
    //    cin>>n;
    //   vector<int>v(n); 
       
    //   for(auto &it:v)cin>>it;
      
    //    int p;
    //    cin>>p;
       
       int l=0,h=1e9;
       sort(v.begin(),v.end());
       function<bool(int)>check=[&](int mid){
            
         int i=1;
int ct=0;
         while(i<n){

              if(v[i]-v[i-1]<=mid){ct++;i+=2;}
              else i++;

         }

            return ct>=p;
       };
       while(l<h)
       {
             int mid=(l+h)>>1;
             
             if(check(mid)){
                    h=mid;
             }
             else l=mid+1;
      
       }
       return h;
 
    }
};