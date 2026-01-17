// Last updated: 1/17/2026, 12:25:35 PM
#include <bits/stdc++.h>
using namespace std;

class Router {
    int sz;
    queue<tuple<int,int,int>> q;
    unordered_set<string> m; 
    unordered_map<int, vector<int>> current_count;

    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        sz = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (m.count(key)) return false;

        if ((int)q.size() == sz) {
            auto old = q.front(); q.pop();
            auto [os, od, ot] = old;
            m.erase(makeKey(os, od, ot));

            auto &vec = current_count[od];
            auto it = lower_bound(vec.begin(), vec.end(), ot);
            if (it != vec.end() && *it == ot) vec.erase(it);
        }

        q.push({source, destination, timestamp});
        m.insert(key);

        auto &vec = current_count[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto cur = q.front(); q.pop();
        auto [s, d, t] = cur;
        m.erase(makeKey(s, d, t));

        auto &vec = current_count[d];
        auto it = lower_bound(vec.begin(), vec.end(), t);
        if (it != vec.end() && *it == t) vec.erase(it);

        return {s, d, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = current_count[destination];
        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);
        return high - low;
    }
};
