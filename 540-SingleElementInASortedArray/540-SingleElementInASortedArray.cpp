// Last updated: 1/17/2026, 12:32:32 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
          
         int n=v.size();


        int l=0,h=n-1;

        while(l<h){
              
              int mid=(l+h)/2;

              int x=mid;
              x++;
              if((x%2==0&&v[mid]==v[mid-1])||(x%2&&v[mid]==v[mid+1]))l=mid+1;
              else  h=mid;

        }
            //  if((h+1)%2==0)/
return v[l];

    }
};