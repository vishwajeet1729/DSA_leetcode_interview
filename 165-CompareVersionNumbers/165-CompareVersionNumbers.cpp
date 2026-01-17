// Last updated: 1/17/2026, 12:33:45 PM
class Solution {
public:
     int compareVersion(std::string version1, std::string version2) {
        // Pointers for iterating through each version string.
        int i = 0;
        int j = 0;
        int n1 = version1.length();
        int n2 = version2.length();
        
        // Loop as long as there are revisions to process in either string.
        while (i < n1 || j < n2) {
            int num1 = 0;
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            int num2 = 0;
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2) {
                return -1;
            }
            if (num1 > num2) {
                return 1;
            }

       
            i++;
            j++;
        }
                return 0;
    }
};