// Last updated: 1/17/2026, 12:28:05 PM
class Solution {
    
public:
    int solve(int x, int y, vector<int> &dp){
        
    if(x <= y) return y - x;
        
    if(dp[x] != -1) return dp[x];
     
    //case 1
    int res = abs(x - y);                                 
    
    //case 2
    res = min(res, 1 + x%5 + solve(x/5, y, dp));              
    
    //case 3
    res = min(res, 1 + (5 - x%5) + solve(x/5 + 1, y, dp));    
    
    //case 4
    res = min(res, 1 + x%11 + solve(x/11, y, dp));            
    
    //case 5
    res = min(res, 1 + (11 - x%11) + solve(x/11 + 1, y, dp)); 
        
    return dp[x] = res;
}
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        
        vector<int> dp(10001, -1);
        return solve(x, y, dp);  
    }
};