// Last updated: 1/17/2026, 12:27:09 PM
class Solution {
public:
    int numberOfChild(int n, int k) {
       short position = 0;
        short direction = 1; 

        for (short i = 0; i < k; ++i) {
            if (position == 0) {
                direction = 1; 
            } else if (position == n - 1) {
                direction = -1;
            }
            position += direction;
        }

        return position; 
    }
};