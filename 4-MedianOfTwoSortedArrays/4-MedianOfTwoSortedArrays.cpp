// Last updated: 1/17/2026, 12:35:29 PM
#define ll long long
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

        if (a.size() > b.size()) {
            return findMedianSortedArrays(b, a);
        }

        int n1 = a.size(), n2 = b.size();
        int l = 0, r = n1;
        int total = n1 + n2;
        int half = (total + 1) / 2;

        while (l <= r) {
            int midA = (l + r) / 2;
            int midB = half - midA; 

            int leftA = (midA == 0) ? INT_MIN : a[midA - 1];
            int rightA = (midA == n1) ? INT_MAX : a[midA];
            
            int leftB = (midB == 0) ? INT_MIN : b[midB - 1];
            int rightB = (midB == n2) ? INT_MAX : b[midB];

            if (leftA <= rightB && leftB <= rightA) {
                if (total % 2 == 1) {
                    return (double)max(leftA, leftB);
                } else {
                    return (double)(max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }
            }
            else if (leftA > rightB) {
                r = midA - 1;
            }
            else {
                l = midA + 1;
            }
        }

        return 0.0;
    }
};
