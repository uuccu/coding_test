#include <iostream>
#include <vector>
#include <map>

using namespace std;

int chess[504][504];
int balls[504][504];
int r, c;

void printBalls()
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << balls[i][j] << " ";
    }
    cout << "\n";
  }
}

vector<int> check(int i, int j)
{
  map<int, pair<int, int>> mp;
  for (int a = i - 1; a <= i + 1; a++)
  {
    if (a < 0 || a >= r)
      continue;
    for (int b = j - 1; b <= j + 1; b++)
    {
      if (b < 0 || b >= c)
        continue;
      mp.insert({chess[a][b], {a, b}});
    }
  }
  vector<int> res;
  res.push_back(mp.begin()->second.first);
  res.push_back(mp.begin()->second.second);
  return res;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> r >> c;

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> chess[i][j];
      balls[i][j] = 1;
    }
  }

  while (1)
  {
    int move = 0;
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        vector<int> moveIndex = check(i, j);
        while (!(moveIndex[0] == i && moveIndex[1] == j) && balls[i][j] != 0)
        {
          balls[moveIndex[0]][moveIndex[1]]++;
          balls[i][j]--;
          move++;
          moveIndex = check(i, j);
        }
      }
    }
    if (move == 0)
      break;
  }

  printBalls();
  return 0;
}
