#define t.sz (int)t.size()
class Solution {
public:
    string pushDominoes(string s) {
            string res=s;
            int n=s.size();
         vector<int>timer(n,0); 
         int i=0;
         bool re=true;
           
          while(i<n){
                 
            if(s[i]=='R'){
            int j=i+1;
            while(j<n){
                if(s[j]=='.'){res[j]='R';timer[j]=j-i;}
                else break;
                j++;
            }
            i=j;
            }
            else i++;
                 

          }   
       
        i=n-1;
        // s=res;
        cout<<res<<endl;
        while(i>=0){
             
            if(s[i]=='L'){
                  
                int j=i-1;
                while(j>=0){
                    if(res[j]=='.')res[j]='L';else
                     if((s[j]=='.'&&i-j<timer[j])){
                        res[j]='L';
                     }  
                     else if(s[j]=='.'&&i-j==timer[j])res[j]='.';
                     else break;
                     j--;

                }
                i=j;

            }
            else i--;


        }





        // cout<<res<<endl;
        return res;


    }
};