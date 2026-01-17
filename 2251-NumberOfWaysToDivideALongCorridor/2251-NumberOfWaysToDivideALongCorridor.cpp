// Last updated: 1/17/2026, 12:29:35 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;

        long long ways = 1;
        int seatCount = 0;
        int prevSeat = -1;

        int totalSeats = 0;
        for (char c : corridor)
            if (c == 'S') totalSeats++;

        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seatCount++;

                if (seatCount > 2 && seatCount % 2 == 1) {
                    int plantsBetween = i - prevSeat - 1;
                    ways = (ways * (plantsBetween + 1)) % MOD;
                }

                prevSeat = i;
            }
        }

        return ways;
    }
};
