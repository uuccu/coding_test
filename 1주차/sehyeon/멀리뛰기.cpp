#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n)
{
  long long answer = 0;
  long long fib[2001] = {
      0,
  };
  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i < 2001; i++)
  {
    fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
  }
  answer = fib[n];
  return answer;
}