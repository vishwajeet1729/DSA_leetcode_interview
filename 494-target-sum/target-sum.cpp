class Solution {
public:
int ct = 0; 
int target;

void rec(int ind, vector<int>& v, int 
sum) {
    int n = v.size();
    
    if (ind == n) {
        if (sum == target) ct++;
        return;
    }

    rec(ind + 1, v, sum + v[ind]);

    rec(ind + 1, v, sum - v[ind]);
}

    int findTargetSumWays(vector<int>& nums, int ta) {
          
          target=ta;
          rec(0,nums,0);
          return ct;
    }
};