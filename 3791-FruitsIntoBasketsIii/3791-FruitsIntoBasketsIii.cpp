// Last updated: 1/17/2026, 12:25:48 PM
class Solution {
public:
   int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        deque<int> queue;
        for (int n : baskets) {
            queue.push_back(n);
        }

        int maxB = *max_element(baskets.begin(), baskets.end());

        for (int fruit : fruits) {
            if (fruit > maxB) {
                continue; // Skip fruits that cannot be placed in any basket
            }

            vector<int> res;
            while (!queue.empty() && queue.front() < fruit) {
                res.push_back(queue.front());
                queue.pop_front();
            }

            if (!queue.empty() && queue.front() >= fruit) {
                queue.pop_front();
            }

            while (!res.empty()) {
                queue.push_front(res.back());
                res.pop_back();
            }
        }

        return queue.size();
    }
};