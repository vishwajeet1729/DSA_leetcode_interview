// Last updated: 1/17/2026, 12:32:11 PM
class Solution {
public:

   bool check(int num,int x){
      return x>=num;
   }
    int search(vector<int>& v, int x) {
            int l = 0, h = v.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (v[mid] == x) return mid;  
            else if (v[mid] < x) l = mid + 1; 
            else h = mid - 1;                
        }

        return -1; 
    }
};