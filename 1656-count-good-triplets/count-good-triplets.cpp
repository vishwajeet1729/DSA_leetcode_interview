class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();  // \U0001f9ed Nami: “Map the length once — don't measure every time!”
        int count = 0;

        for (int i = 0; i < n - 2; ++i) {  // \U0001f5e1️ Zoro: “Skip the last two — they can’t form triplets alone!”
            for (int j = i + 1; j < n - 1; ++j) {
                // \U0001f525 Robin: “Cut the branch early if i and j already fail the ‘a’ test.”
                if (abs(arr[i] - arr[j]) > a) continue;

                for (int k = j + 1; k < n; ++k) {
                    // \U0001f50d Sanji: “Now only test if j-k and i-k conditions hold.”
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        count++;  // \U0001f9e2 Usopp: “Triplet locked in, Captain!”
                    }
                }
            }
        }

        return count;
    }
};