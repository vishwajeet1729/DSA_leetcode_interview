// Last updated: 1/17/2026, 12:25:20 PM
class Solution {
public:
    long long minOperations(vector<int>& num1, vector<int>& num2) {
         int n1=num1.size(),n2=num2.size();
    int last=num2[n2-1];
    bool is_it=false;
    long long first_ops=1;
    for(int i=0;i<n1;++i){
         
        if((num1[i]<=last&&last<=num2[i])||(num2[i]<=last&&last<=num1[i]))is_it=true;
        first_ops+=abs(num1[i]-num2[i]);
    }
 
    if(is_it){
        // cout<<first_ops<<endl;
        return first_ops;
    }
     long long ans=INT_MAX;
    for(int i=0;i<n1;++i){
 ans=min(ans,first_ops+min(abs(num1[i]-last),abs(num2[i]-last)));    }
  
    // cout<<ans<<endl;
return ans;
    }
};