#include <map>
#include <string>
#include <vector>

class Solution
{
public:
  int countDistinct(vector<int> &nums, int k, int p)
  {
    map<string, int> subArr;
    for (int i = 0; i < nums.size(); i++)
    {
      int currentKSize = 0;
      string tmp = "";
      for (int j = i; j < nums.size(); j++)
      {
        if (nums[j] % p == 0)
          currentKSize++;
        tmp += nums[j] + ',';
        if (currentKSize > k)
        {
          break;
        }
        subArr.insert({tmp, j});
      }
    }
    return subArr.size();
  }
};