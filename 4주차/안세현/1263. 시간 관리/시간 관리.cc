#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  vector<pair<int, int>> ts;
  cin >> N;
  while (N--)
  {
    int s;
    int t;
    cin >> t >> s;
    ts.push_back({s, t});
  }
  sort(ts.rbegin(), ts.rend());
  int time = ts.front().first;
  for (auto a : ts)
  {
    while (time > a.first)
      time--;
    time -= a.second;
  }
  if (time >= 0)
    cout << time << endl;
  else
    cout << -1 << endl;
  return 0;
}