class Solution {
public:
    int minimumIndex(vector<int>& v) {
           int n=v.size();
    map<int,int>left,right;

    for(int i=0;i<n;++i)right[v[i]]++;
int ans=-1;
    for(int i=0;i<n;++i){
        left[v[i]]++;
        right[v[i]]--;
        int leftSize=i+1;
        int rightSize=n-i-1;
        if(left[v[i]]>leftSize/2&&right[v[i]]>rightSize/2){
            ans=i;
            break;
        }
        
    }
    // cout<<ans<<endl;
return ans;
    }
};