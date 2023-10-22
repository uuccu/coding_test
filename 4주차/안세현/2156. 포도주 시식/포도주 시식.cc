#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int wine[10004];
  int dp[10004];
  int answer = 0;

  for (int i = 0; i < N; i++)
    cin >> wine[i];

  if (N <= 3) {
    if (N == 1)
      cout << wine[0] << endl;
    else if (N == 2)
      cout << wine[0] + wine[1] << endl;
    else
      cout << max(wine[0] + wine[1], max(wine[1] + wine[2], wine[0]+wine[2])) << endl;
    return 0;
  }

  dp[0]=  wine[0];
  dp[1] = wine[0] + wine[1];
  dp[2] = max(wine[0] + wine[1], max(wine[1] + wine[2], wine[0]+wine[2]));

  for (int i = 3; i < N; i++) {
    int no_drink = dp[i - 1];
    int drink = max(dp[i - 2] + wine[i], wine[i] + wine[i-1] + dp[i-3]);
    dp[i] = max(no_drink, drink);
  }

  cout << dp[N - 1] << endl;
  return 0;
}