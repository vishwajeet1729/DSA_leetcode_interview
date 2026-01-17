// Last updated: 1/17/2026, 12:26:34 PM
class Solution {
public:
int top_x(set<pair<int, int>,greater<pair<int,int>>> s, int x)
{

    int sum = 0;
    auto it = s.begin();
    for (auto i = 0; i < x&& it != s.end(); it++, i++)
    {
        sum += (it->first * it->second);
    }
    return sum;
}
    vector<int> findXSum(vector<int>& v, int k, int x) {
        //    int x=2, k=6;
    // vector<int> v = {1,1,2,2,3,4,2,3};

    int n = v.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < k; ++i)
    {
        freq[v[i]]++;
    }

    set<pair<int, int>,greater<pair<int,int>>> s;
    for (auto it : freq)
    {
        s.insert({it.second, it.first});
    }

    vector<int> ans;
            int sum = top_x(s, x);

            ans.push_back(sum);
    for (int i = 1; i <=n-k ; ++i)
    {
        int out = v[i - 1], in = v[i + k-1];
        s.erase({freq[out], out});

        freq[out]--;
       
        if (freq[out] > 0)
        {
            s.insert({freq[out],out});
        }
        else {
            freq.erase(out);
        }
         
        if(freq.find(in)!=freq.end()){
            s.erase({freq[in],in});
            freq[in]++;
            s.insert({freq[in],in});

        } 
        else {
            freq[in]++;
            s.insert({freq[in],in});
        }
                ans.push_back(top_x(s,x));
             
    }
    // for(auto it:ans)cout<<it<<' ';
    return ans;
    }
};