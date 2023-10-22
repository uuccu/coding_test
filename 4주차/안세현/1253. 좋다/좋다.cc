#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int answer = 0;
  vector<int> list;
  cin >> n;

  while (n--)
  {
    int num;
    cin >> num;
    list.push_back(num);
  }
  sort(list.begin(), list.end());

  for (int i = 0; i < list.size(); i++)
  {
    int findNum = list[i];
    int start = 0;
    int end = list.size() - 1;
    while (start < end)
    {
      int sum = list[start] + list[end];
      if (sum == findNum)
      {
        if (i != start && i != end)
        {
          answer++;
          break;
        }
        else if (start == i)
          start++;
        else if (end == i)
          end--;
      }
      else if (sum < findNum)
        start++;
      else
        end--;
    }
  }

  cout << answer << endl;
  return 0;
}