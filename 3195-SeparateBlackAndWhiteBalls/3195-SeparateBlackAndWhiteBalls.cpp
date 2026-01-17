// Last updated: 1/17/2026, 12:28:10 PM
class Solution {
public:
    long long minimumSteps(string s) {
   long long int sum=0,j=0;
  for(int i=0;i<s.size();++i)if(s[i]=='0')sum+=i-j,j++;
  return sum;
    }
};