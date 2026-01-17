// Last updated: 1/17/2026, 12:30:15 PM
class Solution {
public:
    int maximumGain(string s, int x, int y) {


    int sc1 = 0;
 //   int x, y;
   // cin >> x >> y;
    string ans = "";
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (ans.empty())
            ans += s[i];
        else
        {
            if (ans.back() == 'a' && s[i] == 'b')
            {
                sc1 += x;
                ans.pop_back();
            }
            else
                ans += s[i];
        }
    }
    //  ans = "";
    string demo = ans;
    n = ans.size();
    ans = "";
    for (int i = 0; i < n; ++i)
    {
        if (ans.empty())
            ans += demo[i];
        else
        {
            if (ans.back() == 'b' && demo[i] == 'a')
            {
                sc1 += y;
                ans.pop_back();
            }
            else
                ans += demo[i];
        }
    }
    int sc2 = sc1;
    sc1 = 0;
    ans = "";
    demo = "";
    n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (ans.empty())
            ans += s[i];
        else

        {
            if (ans.back() == 'b' && s[i] == 'a')
            {
                sc1 += y;
                ans.pop_back();
            }
            else
                ans += s[i];
        }
    }
    // ans = "";
    n = ans.size();
    demo = ans;
    ans = "";
    for (int i = 0; i < n; ++i)
    {
        if (ans.empty())
            ans += demo[i];
        else
        {
            if (ans.back() == 'a' && demo[i] == 'b')
            {
                sc1 += x;
                ans.pop_back();
            }
            else
                ans += demo[i];
        }
    }
return max(sc1,sc2);
  ///  cout << max(sc1, sc2) << endl;

    }
};