// Last updated: 1/17/2026, 12:25:34 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a=abs(z-x);
        int b=abs(z-y);
        if(a>b)return 2;
        else if(a<b)return 1;
        else return 0;
    }
};