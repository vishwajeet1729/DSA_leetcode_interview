//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        if (start == end) return 0; // Already at target

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            pair<int, int> front = q.front();
            int curr = front.first, steps = front.second;
            q.pop();

            for (int num : arr) {
                int next_val = (curr * num) % MOD;
                if (next_val == end) return steps + 1;
                if (visited.find(next_val) == visited.end()) {
                    visited.insert(next_val);
                    q.push({next_val, steps + 1});
                }
            }
        }
        return -1; // Not reachable
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends