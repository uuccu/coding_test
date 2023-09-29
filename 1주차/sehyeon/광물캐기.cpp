#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
  int answer = 0;
  int cnt = 0;
  for (auto i : picks)
    cnt += i;
  if (minerals.size() > cnt * 5)
    minerals.erase(minerals.begin() + (cnt * 5), minerals.end());

  priority_queue<char> min;
  priority_queue<string> sort_minerals;

  for (int i = 0; i < minerals.size(); i++)
  {
    if (minerals[i] == "diamond")
      min.push('a');
    else if (minerals[i] == "iron")
      min.push('b');
    else
      min.push('c');
    if (i % 5 == 4 || i == minerals.size() - 1)
    {
      while (min.size() < 5)
        min.push('d');
      string str = "";
      while (!min.empty())
      {
        str += min.top();
        min.pop();
      }
      sort_minerals.push(str);
    }
  }

  for (int i = 0; i < picks.size(); i++)
  {
    while (picks[i]-- && !sort_minerals.empty())
    {
      string tmp = sort_minerals.top();
      if (i == 0)
      {
        for (int j = 0; j < tmp.length(); j++)
          if (tmp[j] != 'd')
            answer++;
      }
      else if (i == 1)
      {
        for (int j = 0; j < tmp.length(); j++)
        {
          if (tmp[j] == 'a')
            answer += 5;
          else if (tmp[j] != 'd')
            answer++;
        }
      }
      else
      {
        for (int j = 0; j < tmp.length(); j++)
        {
          if (tmp[j] == 'a')
            answer += 25;
          else if (tmp[j] == 'b')
            answer += 5;
          else if (tmp[j] == 'c')
            answer++;
        }
      }
      sort_minerals.pop();
    }
  }

  return answer;
}