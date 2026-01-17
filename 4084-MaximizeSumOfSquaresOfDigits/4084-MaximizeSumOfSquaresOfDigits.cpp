// Last updated: 1/17/2026, 12:25:13 PM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
            // int sum=17,num=2;
//    cin>>num>>sum;
     /*
     sum/9
     sare 9 ko primnt
     remsingon ko last mai
  */
 int total=sum/9;
string ans="";

if(total>num||(sum%9!=0)&&total+1>num){
    // cout<<"not possible "<<endl;
    return "";
}


while(total--)ans+='9';
if(ans.size()+1<=num)ans+=to_string(sum%9);
while(ans.size()<num)ans+='0';
// cout<<ans<<endl;
return ans;
    }
};