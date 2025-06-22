class Solution {
public:
    int minimumDeletions(string s, int k) {
        //  string s;
// cin>>s;
 int n=s.size();

   map<char,int>ct;
// int k=0;
// cin>>k;

for(auto ut:s){ct[ut]++;}

int ans=INT_MAX;

vector<int>v;
   for(auto it:ct) v.push_back(it.second);
    sort(v.begin(),v.end());   
   n=v.size();
   int xx=0;
   int sum=0;
   for(int i=0;i<n;++i){
        //int mi=v[i];
        
             for(int j=i+1;j<n;++j){
                 if(v[j]-v[i]<=k)continue;
                  int diff=v[j]-v[i];
                  int ll=abs(k-diff);
                  xx+=ll;
                  
             }   
             ans=min(ans,xx);
             sum+=v[i];
             xx=sum;

     }
  

// for(auto it:v)cout<<it<<" ";
return ans;
// cout<<ans<<endl;
    }
};