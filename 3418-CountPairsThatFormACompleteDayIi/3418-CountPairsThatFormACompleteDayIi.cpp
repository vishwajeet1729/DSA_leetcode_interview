// Last updated: 1/17/2026, 12:27:24 PM
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
          
      unordered_map<long long, long long> remainder_count;
    long long pair_count = 0;

    for (long long hour : hours) {
        int remainder = hour % 24;
       long long complement = (24 - remainder) % 24;
        pair_count += remainder_count[complement];
        remainder_count[remainder]++;
    }

    return pair_count;
        
    }
};