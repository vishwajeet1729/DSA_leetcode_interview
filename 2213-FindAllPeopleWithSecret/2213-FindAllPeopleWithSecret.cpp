// Last updated: 1/17/2026, 12:29:44 PM
class Solution {
public:
// #include <bits/stdc++.h>
// using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }
};

int main() {

    int n = 6;
    vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    int firstPerson = 1;

    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) {
             return a[2] < b[2];
         });

    DSU dsu(n);
    dsu.unite(0, firstPerson);

    int i = 0;
    while(i < meetings.size()) {
        int time = meetings[i][2];
        vector<int> persons;

        int j = i;
        while(j < meetings.size() && meetings[j][2] == time) {
            dsu.unite(meetings[j][0], meetings[j][1]);
            persons.push_back(meetings[j][0]);
            persons.push_back(meetings[j][1]);
            j++;
        }

        for(int p : persons) {
            if(dsu.find(p) != dsu.find(0)) {
                dsu.parent[p] = p;
            }
        }

        i = j;
    }

    for(int i = 0; i < n; i++) {
        if(dsu.find(i) == dsu.find(0))
            cout << i << " ";
    }
    return 0;
}

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        //   int n = 6;
    // vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    //  firstPerso;

    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) {
             return a[2] < b[2];
         });

    DSU dsu(n);
    dsu.unite(0, firstPerson);

    int i = 0;
    while(i < meetings.size()) {
        int time = meetings[i][2];
        vector<int> persons;

        int j = i;
        while(j < meetings.size() && meetings[j][2] == time) {
            dsu.unite(meetings[j][0], meetings[j][1]);
            persons.push_back(meetings[j][0]);
            persons.push_back(meetings[j][1]);
            j++;
        }

        for(int p : persons) {
            if(dsu.find(p) != dsu.find(0)) {
                dsu.parent[p] = p;
            }
        }

        i = j;
    }
vector<int>ans;
    for(int i = 0; i < n; i++) {
        if(dsu.find(i) == dsu.find(0))
            ans.push_back(i);
    }
    return ans;
    }
};