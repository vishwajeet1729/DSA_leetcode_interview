class Solution {
public:
 bool check(string s1,string s2){
    int flag=0;
      for(int i=0;i<s1.size();++i){
        if(s1[i]!=s2[i])flag++;
      }
      return flag==1;
}
    int ladderLength(string beg, string end, vector<string>& v) {
           queue<string>q;
    q.push(beg);
    int n=v.size();
   vector<bool>vis(n,0);
   int ct=0;
     while(!q.empty()){
          queue<string>demo;
          ct++;
          int x=q.size();
          for(int i=0;i<x;++i)
          {
             string s=q.front();
             q.pop();
             for(int j=0;j<n;++j){
            if(vis[j])continue;
             if(check(s,v[j])){
                if(v[j]==end){
                return ct+1;
                }
                // demo.push(v[j]);
                q.push(v[j]);
                vis[j]=1;}  
             }
          }
     }
    //  cout<<0<<endl;
    return 0;

    }
};