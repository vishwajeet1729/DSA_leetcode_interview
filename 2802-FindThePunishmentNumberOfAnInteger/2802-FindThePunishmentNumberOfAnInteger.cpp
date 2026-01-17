// Last updated: 1/17/2026, 12:28:29 PM
class Solution {
public:
bool split(int sum,int target ,vector<int>v,int idx){
    if(idx==v.size())return target==sum;
int cur=0;                  
for(int i=idx;i<v.size();i++){
  cur=cur*10+v[i];
  if(split(sum+cur,target,v,i+1))return true;
}
return 0;
}

bool chk(int n){
    int x=n;
       vector<int>v;
   while(n){
       v.push_back(n%10);
       n=n/10;
   }
   reverse(v.begin(),v.end());
    return split(0,sqrt(x),v,0);
}
int punishmentNumber(int n) {
      
vector<int>v(n+1);
    for(int i=1;i<=n;++i){
           v[i]=chk(i*i);  
            // cout<<" for i: "<<i<<" i*i is  :"<<i*i<<" is "<<v[i]<<endl;                                                                                                                      
    }
       int sum=0;
    for(int i=1;i<=n;++i){
           if(v[i])sum+=i*i;                                                                              

    }
    return sum;

}
};