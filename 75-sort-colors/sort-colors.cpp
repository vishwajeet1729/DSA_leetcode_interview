class Solution {
public:
    void sortColors(vector<int>& v) {
        int n=v.size();
      
int i=0,j=0,k=n-1;

  while(j<=k){
        
    if(v[j]==1)j++;
    else if(v[j]==2){
           swap(v[j],v[k]);
           k--;
    }
    else {
        swap(v[j],v[i]);
        i++;j++;
    }

  }
    }
};