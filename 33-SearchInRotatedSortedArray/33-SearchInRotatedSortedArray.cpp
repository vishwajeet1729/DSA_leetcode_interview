// Last updated: 1/17/2026, 12:35:09 PM
#define ll long long
class Solution {
public:
    int search(vector<int>&  v, int op) {
           ll n=v.size();
             
             ll l=0,h=n-1;
             while(l<=h){
                   
                   ll mid=(l+h)/2;
                    if(l>mid)return -1;
                    if(v[mid]==op)return mid;
                   if(v[l]<=v[mid]){
                    if(op>=v[l]&&op<=v[mid])h=mid-1;
                     else l=mid+1; 
                   }
                   else if(op>=v[mid]&&op<=v[h])l=mid+1;
                    else h=mid-1;   

             }

      return -1;

    }
};