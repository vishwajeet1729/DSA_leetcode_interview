// Last updated: 1/17/2026, 12:28:43 PM
class Solution {
public:
    int getCommon(vector<int>& v1, vector<int>& v2) {
        //o(n)
        int ans=-1;
    sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int i=0,j=0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i]==v2[j]){
            ans=v1[i];
                break;
            }
            if(v1[i]<v2[j])i++;
            else j++;
        }
        return ans;
    }
};