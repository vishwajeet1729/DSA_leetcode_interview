// Last updated: 1/17/2026, 12:32:14 PM
class Solution {
public:
 vector<int>v;
 int n;

 bool check(int mid,int k){
     int i=0,j=0;
int ans=0;
     while(i<n){
         
      while(j<n&&v[j]-v[i]<=mid)j++;
      ans+=(j-i-1);
      i++;
     }
     return ans>=k;
 }

    int smallestDistancePair(vector<int>& nums, int k) {
         
// int k=18;
v=nums;
n=v.size();
   sort(v.begin(),v.end());
int low=0,heigh=v.back()-v.front();
while(low<heigh){
  
  int mid=(low+heigh)/2;
  
  if(check(mid,k))heigh=mid;
  else low=mid+1;

}

// cout<<low<<endl;
return low;
    }
};