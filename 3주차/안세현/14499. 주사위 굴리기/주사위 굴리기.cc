#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int top = 0;
int bottom = 0;
int front = 0;
int back = 0;
int east = 0;
int west = 0;
int x, y;
int n, m, k;
int map[21][21];

void printMap()
{
  cout << x << " " << y << "========map=========" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << map[i][j] << "  ";
    cout << endl;
  }
  cout << endl;
}

int moveUp()
{
  if (x - 1 < 0)
    return 0;
  int tmp = back;
  back = top;
  top = front;
  front = bottom;
  bottom = tmp;
  x--;
  return 1;
}

int moveDown()
{
  if (x + 1 >= n)
    return 0;
  int tmp = bottom;
  bottom = front;
  front = top;
  top = back;
  back = tmp;
  x++;
  return 1;
}

int moveLeft()
{
  if (y - 1 < 0)
    return 0;
  int tmp = bottom;
  bottom = west;
  west = top;
  top = east;
  east = tmp;
  y--;
  return 1;
}

int moveRight()
{
  if (y + 1 >= m)
    return 0;
  int tmp = top;
  top = west;
  west = bottom;
  bottom = east;
  east = tmp;
  y++;
  return 1;
}

int main(void)
{
  cin >> n >> m >> x >> y >> k;

  vector<int> ret;
  memset(map, 0, sizeof(map));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];

  for (int i = 0; i < k; i++)
  {
    int move;
    cin >> move;
    if (move == 1 && moveRight())
      ret.push_back(top);
    else if (move == 2 && moveLeft())
      ret.push_back(top);
    else if (move == 3 && moveUp())
      ret.push_back(top);
    else if (move == 4 && moveDown())
      ret.push_back(top);
    else
      continue;
    if (map[x][y] == 0)
      map[x][y] = bottom;
    else
    {
      bottom = map[x][y];
      map[x][y] = 0;
    }
    // printMap();
  }

  for (int i = 0; i < ret.size(); i++)
    cout << ret[i] << endl;
  return 0;
}