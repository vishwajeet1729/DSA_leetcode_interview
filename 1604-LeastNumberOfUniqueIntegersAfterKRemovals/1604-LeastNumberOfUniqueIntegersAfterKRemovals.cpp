// Last updated: 1/17/2026, 12:30:38 PM
class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& v, int k) {
        std::map<int, int> m;
        int n = v.size();
        for (int i = 0; i < n; i++)
            m[v[i]]++;

        std::vector<std::pair<int, int>> re;
        for (auto it = m.begin(); it != m.end(); it++)
            re.push_back({it->second, it->first});

        std::sort(re.begin(), re.end());

        int x = 0;
        for (int i = 0; i < re.size(); i++) {
            int p = re[i].first;
            if (p <= k) {
                k -= p;
                x++;
            } else {
                break;
            }
        }

        return re.size() - x;
    }
};