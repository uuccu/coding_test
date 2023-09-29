https://school.programmers.co.kr/learn/courses/30/lessons/42895

DP

```c++
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
map<int,int> m;
int solution(int N, int number) {
    for(int i=1;i<=8;i++)
    {
        string tmp="";
        for(int j=0;j<i;j++)
            tmp+=(N+'0');
        m[stoi(tmp)]=i;
    }
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({N,1});
    while(!q.empty())
    {
        int nx=q.front().X;
        int lev=q.front().Y;
        q.pop();
        if(lev>=10)
            continue;
        if(nx==number)
            return lev;
        for(int i=0;i<4;i++)
        {
            int a=nx;
            int b=N;
            if(i==0)
            {
                if(m[a+b]==0)
                {
                    m[a+b]=lev+1;
                    q.push({a+b,lev+1});
                }
            }
            else if(i==1)
            {

                if(m[a-b]==0)
                {
                    m[a-b]=lev+1;
                    q.push({a-b,lev+1});
                }
            }
            else if(i==2)
            {

                if(m[a*b]==0)
                {
                    m[a*b]=lev+1;
                    q.push({a*b,lev+1});
                }
            }
            else
            {
                if(b!=0&&m[a/b]==0)
                {
                    m[a/b]=lev+1;
                    q.push({a/b,lev+1});
                }
            }
        }
    }
    return -1;
}
```
