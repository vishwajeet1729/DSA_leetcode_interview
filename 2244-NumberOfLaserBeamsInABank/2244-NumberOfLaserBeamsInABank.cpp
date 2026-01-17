// Last updated: 1/17/2026, 12:29:39 PM
class Solution {
public:
    int numberOfBeams(vector<string>& v) {
        //   vector<string>v={"000","111","000"};

  int prev=0;
  int cur=0;    int sum=0;
 
  int n=v.size();
  for(int i=0;i<n;++i){
    for(int j=0;j<v[i].size();++j)
        if(v[i][j]=='1')cur++;
    
    if(i==0){
        prev=cur;
        cur=0;
    }
    else {
        if(cur!=0){
        sum+=(prev*cur);
        prev=cur;
        cur=0;}
    }
  }
//   cout<<cur<<" "<<prev;
return sum;
//   cout<<sum<<endl;
    }
};