class Solution {
public:
    void sortColors(vector<int>& v) {
             
        int n=v.size();
     for(int i=0;i<n;++i){
         if(v[i]==0){
            int j=i;
            while(j!=0){
                swap(v[j],v[j-1]);j--;
            }
         }
     }
     int ind=0;
     for(int i=0;i<n;++i){
        if(v[i]!=0){
            ind=i;break;
        }
     }
     for(int i=ind;i<n;++i){
          if(v[i]==1){
            int j=i;
            while(j!=ind){
                swap(v[j],v[j-1]);j--;
            }
          }    

     }

    //  for(auto it:v)cout<<it<<" ";line;
// return v;
           


    }
};