// Last updated: 1/17/2026, 12:25:22 PM
class Solution {
public:
    long long maxProfit(vector<int>& price, vector<int>& strategy, int k) {
        //   vector<int> price = {5,4,3};
    int n = price.size();

    // vector<int> strategy = {1,1,0};

    long long total_profit = 0;
    vector<long long> prefix_sum(n, 0);
    prefix_sum[0] = price[0] * strategy[0];
    total_profit+=strategy[0]*price[0];
    for (int i = 1; i < n; ++i)
    {
        prefix_sum[i] = price[i] * strategy[i] + prefix_sum[i - 1];
        total_profit = total_profit + strategy[i] * price[i];
    }
    // int k = 2;

    /*
       0 1 2 3 4 5
       s     e

    */

    vector<long long>price_prefix(n,0);
    price_prefix[0]=price[0];
    for(int i=1;i<n;++i)price_prefix[i]=price[i]+price_prefix[i-1];
    long long ans = total_profit;
    for (int i = k - 1; i < n; i += 1)
    {

        int start = i - k + 1;
        int end = i;
        int mid = start +k / 2;
        // cout << start << " " << end << " " << mid << endl;

        long long temp = total_profit;
         
        if (start == 0)
            temp -= (prefix_sum[end]);
        else
            temp -= (prefix_sum[end] - prefix_sum[start - 1]);
        if (mid == 0)
            temp += price_prefix[end]-price_prefix[0];
        else
             temp += price_prefix[end] - price_prefix[mid - 1];
        ans = max(ans, temp);
        // cout<<ans<<endl;
    }

    // cout << ans << endl;
    return ans;
    }
};