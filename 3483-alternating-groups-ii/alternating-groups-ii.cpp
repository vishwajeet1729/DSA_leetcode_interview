class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k) {
       int i=0,j=1;
    int n=v.size();
    // for(int i=0;i<n;++i)
    int ct=0;
    while(i<n){
        if(j-i+1==k&&v[(j-1)%n]!=v[j%n]){
            ct++;
            // for(int l=i;l<=j;++l)cout<<v[l%n]<<" ";line;
            i++;
        
        }  
   else if(v[(j-1)%n]!=v[j%n]){j++;}
     else {i=j;j++;}       
    }
return ct;
    }
};