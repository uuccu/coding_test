#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
vector<vector<int>> arr;
vector<vector<int>> new_arr;
int current_r = 3;
int current_c = 3;

int t = 0;

void printArr()
{
  cout << "\n=====ARR=====" << endl;
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr[i].size(); j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  cout << "=============" << endl;
}

void fill_zero()
{
  while (arr.size() < current_c)
    arr.push_back({0});
  for (int i = 0; i < current_c; i++)
  {
    while (arr[i].size() < current_r)
      arr[i].push_back(0);
  }
}

void calcR()
{
  map<int, int> numberMap;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  for (int r = 0; r < current_c; r++)
  {
    for (int j = 0; j < arr[r].size(); j++)
    {
      if (arr[r][j] != 0)
      {
        if (numberMap[arr[r][j]])
          numberMap[arr[r][j]]++;
        else
          numberMap[arr[r][j]] = 1;
      }
    }
    for (auto num : numberMap)
      q.push({num.second, num.first});
    numberMap.clear();
    arr[r].clear();
    while (!q.empty())
    {
      arr[r].push_back(q.top().second);
      arr[r].push_back(q.top().first);
      q.pop();
    }
    current_r = current_r < arr[r].size() ? arr[r].size() : current_r;
  }

  fill_zero();
}

void calcC()
{
  map<int, int> numberMap;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

  for (int r = 0; r < current_r; r++)
  {
    for (int c = 0; c < current_c; c++)
    {
      if (arr[c][r] != 0)
      {
        if (numberMap[arr[c][r]])
          numberMap[arr[c][r]]++;
        else
          numberMap[arr[c][r]] = 1;
      }
    }
    for (auto num : numberMap)
      q.push({num.second, num.first});
    numberMap.clear();
    current_c = current_c < q.size() * 2 ? q.size() * 2 : current_c;
    fill_zero();
    int c = 0;
    while (!q.empty())
    {
      arr[c++][r] = q.top().second;
      arr[c++][r] = q.top().first;
      q.pop();
    }
    while (c < current_c)
      arr[c++][r] = 0;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int r, c, k;
  cin >> r >> c >> k;

  for (int i = 0; i < 3; i++)
  {
    arr.push_back({0});
    arr[i].clear();
    for (int j = 0; j < 3; j++)
    {
      int n;
      cin >> n;
      arr[i].push_back(n);
    }
  }

  r--;
  c--;
  while (1)
  {
    if (current_r > c && current_c > r && arr[r][c] == k)
      break;
    if (t > 100)
    {
      t = -1;
      break;
    }
    if (arr.size() >= arr[0].size())
      calcR();
    else
      calcC();
    t++;
  }

  cout << t << endl;
  return 0;
}