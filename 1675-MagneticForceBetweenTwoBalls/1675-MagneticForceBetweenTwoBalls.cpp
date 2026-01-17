// Last updated: 1/17/2026, 12:30:28 PM
class Solution {
public:


  bool check(vector<int> &v, int mid, int k)
{
    int ct = 1;
    int prev = v[0];
    for (int i = 1; i < v.size(); ++i)
    {

        if (v[i] - prev >= mid)
        {
            ct++;
            prev = v[i];
        }
    }

    return ct >= k;
}

    int maxDistance(vector<int>& v, int k) {
         sort(v.begin(), v.end());

        int l = 1, h = *max_element(v.begin(), v.end());

        while (l < h)
        {

            int mid = (l + h + 1) / 2;
            if (check(v, mid, k))
                l = mid;
            else
                h = mid - 1;
        }
        // cout << l << endl;
        return l;
    }
    
};