#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
  vector<int> answer;

  for (int i = 0; i < numbers.size(); i++)
  {
    int now = numbers[i];
    int ans = -1;
    for (int j = i + 1; j < numbers.size(); j++)
    {
      if (numbers[j] <= now)
        continue;
      else
      {
        ans = numbers[j];
        break;
      }
    }
    numbers[i] = ans;
  }

  return numbers;
}

// TC 20~23 시간초과