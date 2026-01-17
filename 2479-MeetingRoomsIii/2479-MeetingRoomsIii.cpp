// Last updated: 1/17/2026, 12:29:00 PM
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    
        sort(meetings.begin(), meetings.end());

        vector<int> count(n, 0);

        // free rooms by index
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        // used rooms by end time
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > usedRooms;

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

            // free rooms that finished
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                freeRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                usedRooms.push({end, room});
                count[room]++;
            } else {
                auto [time, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({time + (end - start), room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans])
                ans = i;
        }

        return ans;
 
    }
};