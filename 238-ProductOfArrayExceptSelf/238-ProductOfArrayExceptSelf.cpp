// Last updated: 1/17/2026, 12:33:14 PM
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        long long int product = 1;
        int zero = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                zero++;
                continue;
            }
            product *= nums[i];
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0 && zero == 1)
                result.push_back(product);
            else
            {
                if (nums[i] == 0 && zero > 1)
                    result.push_back(0);
                else
                {
                    if (zero > 0)
                        result.push_back(0);
                    else
                        result.push_back(product / nums[i]);
                }
            }
            // result.push_back(product/nums[i]);
        }
        return result;
    }
};