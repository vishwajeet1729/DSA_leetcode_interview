// Last updated: 1/17/2026, 12:32:40 PM
class Solution {
public:
int merge(int left,int mid,int right,vector<int>&v){
         int ct=0;
         int j=mid+1;
         for(int i=left;i<=mid;++i){
             while(j<=right&&2LL*v[j]<v[i])j++;
             ct+=j-(mid+1);
         }

         vector<int> temp;
         int i = left, k = mid + 1;
 
         while (i <= mid && k <= right) {
             if (v[i] <= v[k]) temp.push_back(v[i++]);
             else temp.push_back(v[k++]);
         }
         while (i <= mid) temp.push_back(v[i++]);
         while (k <= right) temp.push_back(v[k++]);
          for (int i = left; i <= right; i++) v[i] = temp[i - left];
         return ct;

}

int ans=0;
int divide(int left,int right,vector<int>&v){
        if(left>=right)return 0;
    int mid=(left+right)/2;
    divide(left,mid,v);
    divide(mid+1,right,v);
     ans+=merge(left,mid,right,v);
    
     return ans;
}

  int reversePairs(vector<int>& v) {
  multiset<long long> s;
 return divide(0,v.size()-1,v);
}

};