class Solution {
public:
    void nextPermutation(vector<int>& v) {
          int n=v.size();
   int i=n-1;

   for(;i>0;--i){
    if(v[i]>v[i-1]){
        break;
    }
   }

if(i!=0){
   int j=i;
   for(j=n-1;j>=i;--j){
    if(v[j]>v[i-1]){
         break;
   }}
   swap(v[j],v[-1+i]);}
   reverse(v.begin()+i,v.end());
//    return v;
    }
};