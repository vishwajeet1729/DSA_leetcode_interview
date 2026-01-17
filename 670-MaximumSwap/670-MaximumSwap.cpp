// Last updated: 1/17/2026, 12:32:22 PM
class Solution {
public:
    int maximumSwap(int n) {
           
        

         vector<int>v;
         while(n){
               int r=n%10;
               n=n/10;
               v.push_back(r);        
         }
         reverse(v.begin(),v.end());

         for(int i=0;i<v.size();++i){
               int ind=i;
               for(int j=i+1;j<v.size();++j){
                    if(v[j]>=v[ind]){
                           ind=j;
                    }

               }
               if(ind!=i&&v[ind]!=v[i]){
                swap(v[i],v[ind]);break;
               }
               
         }

          string re="";
          for(int i=0;i<v.size();++i)re+=(v[i]+'0');
       
       return stoi(re);

          

    }
};