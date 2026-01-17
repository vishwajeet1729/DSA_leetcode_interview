// Last updated: 1/17/2026, 12:35:06 PM
class Solution {
public:
    int searchInsert(vector<int>& v, int x) {
         int l = 0, h = v.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (v[mid] == x) return mid;
            else if (v[mid] < x) l = mid + 1; 
            else h = mid - 1;                
        }

        return l; 
    }
};