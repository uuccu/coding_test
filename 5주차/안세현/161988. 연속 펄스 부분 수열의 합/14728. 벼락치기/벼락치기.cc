#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct study
{
  int time;
  int score;
};

bool compare(study a, study b)
{
  return a.time < b.time;
}

int main()
{
  int N, T;
  cin >> N >> T;
  vector<study> v(N + 1);
  int dp[104][10004] = {
      0,
  };

  for (int i = 1; i <= N; i++)
  {
    study st;
    cin >> st.time >> st.score;
    v[i] = st;
  }
  sort(v.begin() + 1, v.end(), compare);

  int answer = 0;
  int start = v[1].time;
  for (int i = 1; i <= N; i++)
  {
    for (int time = start; time <= T; time++)
    {
      if (v[i].time > time)
        dp[i][time] = dp[i - 1][time];
      else
        dp[i][time] = max(dp[i - 1][time], dp[i - 1][time - v[i].time] + v[i].score);
      answer = max(dp[i][time], answer);
    }
  }
  cout << answer << endl;
  return 0;
}