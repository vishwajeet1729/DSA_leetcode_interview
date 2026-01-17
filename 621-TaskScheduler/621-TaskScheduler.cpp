// Last updated: 1/17/2026, 12:32:26 PM
class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
      
        //  vector<int> a(26,0);
        //  int sz=t.size();
        //  for(int i=0;i<sz;++i)a[(int)(t[i]-'a')]++;
        //  sort(a.rbegin(),a.rend());
        //  int ex=0;
        //  for(int i=1;i<a.size();++i){
        //     if(a[i]==a[0])ex++;
        //  }
        //  int ct=0;
        // while(1){
        //     if(a[0]==0)break;
        //     int ind;
        //     for(int i=1;i<a.size();++i){
        //         if(a[i]<=0){ind=i;break;}
        //     }
        //     ind--;
        //      if(ind>=n)ct+=ind;
        //      else {
        //         ct+=n-ind;
        //      }
        //      for(int i=0;i<a.size();++i){
        //        a[i]--;
        //     }

    
        // } 
        // return ct+ex;
        // int mx=INT_MIN;
    //     int ct=0;
    //    for(auto it:m)mx=max(mx,it.second);
    //    for(auto it:m)if(it.second==mx)ct++;
    //    ct--;
    //    mx--;
    //    int ex=mx;
    //    mx=mx*n;
    //    mx+=ct;
    //    return mx+ex;
    vector<int>v(26,0);
    for(auto it:t) v[it-'A']++;
    sort(v.rbegin(),v.rend());
    int ex=(v[0]-1)*n;
    for(int i=1;i<26;++i){
        ex-=min(v[0]-1,v[i]);

    }  
    return ex>0?ex+t.size():t.size();

    }
};