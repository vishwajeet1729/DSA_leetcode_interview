// Last updated: 1/17/2026, 12:28:49 PM
class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
    //    cin>>n;
    //    string s;
    //    cin>>s;/
      int cy=0;
       for(int i=n-1;i>=0;--i)if(s[i]=='Y')cy++;
       int cn=0;
       int ans=cy;
       int ind=-1;
       for(int i=0;i<n;++i){
              if(s[i]=='Y')cy--;
              else cn++;
              if(cn+cy<ans){
                                ans=min(ans,cn+cy);
                     ind=i;
              }
       }
      return ind+1;
    //    cout<<ind<<endl;  
    //can be done in the single pass also remember 
    }
};