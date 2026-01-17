// Last updated: 1/17/2026, 12:31:41 PM
class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        //  vector<string>v={"cba","daf","ghi"};
       int n=v.size();
       int stl=v[0].size();
int ct=0;
       for(int i=0;i<stl;++i){
          char mx='a';
        for(int j=0;j<n;++j){
            
            if(v[j][i]<mx){ct++;break;}
            else {
                mx=max(v[j][i],mx);
            }
        }

       }
       return ct;
    //    cout<<ct<<endl;
      
    }
};