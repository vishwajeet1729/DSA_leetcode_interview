// Last updated: 1/17/2026, 12:25:18 PM
#include <bits/stdc++.h>
using namespace std;

class ExamTracker {
    vector<pair<int, long long>> exams; // {time, cumulativeScore}
    
public:
    ExamTracker() {
        exams.clear();
    }
    
    void record(int time, int score) {
        long long cumScore = score;
        if (!exams.empty()) cumScore += exams.back().second;
        exams.push_back({time, cumScore});
    }
    
    long long totalScore(int startTime, int endTime) {
        // Binary search for first exam >= startTime
        auto it1 = lower_bound(exams.begin(), exams.end(), make_pair(startTime, 0LL));
        // Binary search for last exam <= endTime
        auto it2 = upper_bound(exams.begin(), exams.end(), make_pair(endTime, LLONG_MAX));
        
        if (it1 == exams.end() || it1 >= it2) return 0;
        
        long long sumEnd = (it2 == exams.begin()) ? 0 : prev(it2)->second;
        long long sumStart = (it1 == exams.begin()) ? 0 : prev(it1)->second;
        
        return sumEnd - sumStart;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
