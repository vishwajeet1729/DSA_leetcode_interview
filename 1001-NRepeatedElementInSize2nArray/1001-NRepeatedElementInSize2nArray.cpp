// Last updated: 1/17/2026, 12:31:39 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
         for (int k = 1; k <= 3; ++k)
            for (int i = 0; i < A.size()- k; ++i)
                if (A[i] == A[i+k])
                    return A[i];
        
        return 0;
    }
};