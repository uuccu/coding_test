#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(string s)
{
  string answer = "";
  priority_queue<int> q;
  string str = "";

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
    {
      q.push(stoi(str));
      i++;
      str = "";
    }
    str += s[i];
  }
  q.push(stoi(str));
  int max = q.top();
  while (q.size() != 1)
    q.pop();
  int min = q.top();
  answer = to_string(min) + " " + to_string(max);
  return answer;
}