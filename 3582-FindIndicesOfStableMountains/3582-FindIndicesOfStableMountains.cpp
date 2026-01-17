// Last updated: 1/17/2026, 12:26:38 PM
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
           
          vector<int> ss;

    for (int i = 1; i < height.size(); ++i) {
        if (height[i-1] > threshold) {
            ss.push_back(i);
        }
    }

    return ss;
          
    }
};