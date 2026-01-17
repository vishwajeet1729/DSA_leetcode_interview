// Last updated: 1/17/2026, 12:25:32 PM
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> answer(n, numeric_limits<int>::max());
        
        // Start by swapping with the first person
        int minCost = cost[0];
        answer[0] = cost[0];
        
        for (int i = 1; i < n; i++) {
            minCost = min(minCost, cost[i]); // Keep track of the minimum cost seen so far
            answer[i] = minCost; // We can reach this position at the lowest encountered cost
        }
        
        return answer;
    }
};