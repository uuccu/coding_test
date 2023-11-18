https://school.programmers.co.kr/learn/courses/30/lessons/92335
구현, 파싱

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string target;
bool isPrime(ll x)
{
    if(x==0||x==1)
        return false;
    if(x==2||x==3)
        return true;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
string convert()
{
    int tmp=n;
    int len=0;
    while(1)
    {
        if(pow(k,len)<=n&&pow(k,len+1)>n)
        {
            break;
        }
        len++;
    }
    len++;
    string s="";
    int i=len-1;
    while(tmp!=0)
    {
        int t1=tmp/((int)pow(k,i)); //나머지
        s+=(t1+'0');
        tmp=tmp%((int)pow(k,i));
        i--;
    }
    return s;
}
int sol(){
    int len=target.length();
    int ans=0;
    string str="";
    for(int i=0;i<len;i++)
    {
        if(target[i]=='0')
        {
            if(str.length()==0)
                continue;
            if(isPrime(stol(str)))
                ans++;
            str="";
        }
        else
            str+=target[i];
    }
    if(str.length()>0)
    {
        if(isPrime(stol(str)))
            ans++;
    }

    return ans;
}
int solution(int N, int K) {
    n=N;
    k=K;
    target=convert();
    int ans=sol();
    return ans;
}
```
