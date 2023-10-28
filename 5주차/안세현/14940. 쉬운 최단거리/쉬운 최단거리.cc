#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int graph[1001][1001];
int visit[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int a, int b)
{
  queue<pair<int, int>> q;
  q.push({a, b});

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (graph[nx][ny] == 0 || graph[nx][ny] == 2)
        continue;
      if (graph[nx][ny] == 1 && visit[nx][ny] == -1)
      {
        visit[nx][ny] = visit[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  pair<int, int> endPoint;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      visit[i][j] = -1;
      cin >> graph[i][j];
      if (graph[i][j] == 2)
      {
        endPoint.first = i;
        endPoint.second = j;
        visit[i][j] = 0;
      }
    }
  }
  bfs(endPoint.first, endPoint.second);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (graph[i][j] == 0)
        cout << 0 << " ";
      else
        cout << visit[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}