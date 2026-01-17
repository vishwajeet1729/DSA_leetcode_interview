// Last updated: 1/17/2026, 12:27:38 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    //   vector<int>apple={5,5,5},capacity={2,4,2,7};
  int n=apple.size(),m=capacity.size();
     
  sort(capacity.rbegin(),capacity.rend());
  int sum=accumulate(apple.begin(),apple.end(),0);
   int cur_sum=0;
int i=0;
   while(cur_sum<sum&&i<m){
    cur_sum+=capacity[i];
    i++;
   }
return i;
cout<<i<<endl;
  
    }
};