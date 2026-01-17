// Last updated: 1/17/2026, 12:27:14 PM
#define INF INT_MAX
class SegmentTree {
public:
    vector<int> tree;
    int n;

    // Constructor
    SegmentTree(vector<int>& arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    // Function to build the Segment Tree
    void build(vector<int>& arr, int node, int start,
               int end)
    {
        if (start == end) {
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);

            // bitwise AND of the children nodes
            tree[node]
                = tree[2 * node + 1] & tree[2 * node + 2];
        }
    }

    // Overloading query function to be used recursively
    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    // query function to get bitwise AND of the range
    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l) {
            return INF;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node + 1, start, mid, l, r);
        int p2 = query(2 * node + 2, mid + 1, end, l, r);

        // bitwise AND operation result
        return p1 & p2;
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& arr, int k) {
          int n = arr.size();
    SegmentTree st(arr);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = n - 1, mid;

        // binary search implementation
        while (r - l > 1) {
            mid = (l + r) / 2;
            if (st.query(i, mid) >= k)
                l = mid;
            else
                r = mid;
        }
        if (l != i - 1)
            ans = min(ans, abs(st.query(i, l) - k));
        ans = min(ans, abs(k - st.query(i, r)));
    }
    return ans;
    }
};