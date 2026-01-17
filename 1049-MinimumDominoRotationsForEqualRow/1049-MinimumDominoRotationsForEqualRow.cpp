// Last updated: 1/17/2026, 12:31:31 PM
class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bott) {
        int n=top.size();
      int a=top[0],b=bott[0];
      int ct1=0;bool re1=1,re2=1;
    for(int i=1;i<n;++i){
            if(top[i]!=a){
                    if(bott[i]==a){
                        ct1++;
                    }
                    else {
                        re1=false;break;
                    }
            }
    }
       int ct2=1;
       for(int i=1;i<n;++i){
          if(bott[i]!=a){
              if(top[i]==a)ct2++;
              else {
                re2=false;
              }
          }
       }
  bool re3=1;
  int ct3=0,ct4=1;
   for(int i=1;i<n;++i){
           if(bott[i]!=b){
              if(top[i]==b)ct3++;
              else {
                re3=false;
              }
           }

   }
   bool re4=1;
   for(int i=1;i<n;++i){
            if(top[i]!=b){
                if(bott[i]==b)ct4++;
                else re4=0;
            }
   }

       if(!re1)ct1=INT_MAX;
       if(!re2)ct2=INT_MAX;
       if(!re3)ct3=INT_MAX;
       if(!re4)ct4=INT_MAX;
     
       if(min({ct1,ct2,ct3,ct4})==INT_MAX)return -1;
       else return min({ct1,ct2,ct3,ct4});
    
    }
};