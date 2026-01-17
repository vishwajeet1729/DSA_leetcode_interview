// Last updated: 1/17/2026, 12:34:42 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
            int n=v.size();
    //    cin>>n;
    //    vector<int>v(n);
       int ind=n-1;
    //    for(auto &it:v)cin>>it;
int carry=0;
vector<int>temp(n,0);
      v[ind]++;
       // else {
              
              
              for(int i=n-1;i>=0;--i){
                            int r=carry+v[i];
                            int rem=r%10;
                            temp[i]=rem;
                            carry=r/10;
                     
                                 
       }

      if(carry!=0){
       temp.insert(temp.begin(),carry);
      }
      return temp;
    //   for(auto &it:temp)cout<<it<<" ";   
    }
};