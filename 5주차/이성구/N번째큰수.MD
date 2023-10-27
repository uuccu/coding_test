https://www.acmicpc.net/problem/2075

```c++
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;


int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i = 0; i <n * n;i++){
        int x;
        cin>>x;
        if( i >= n && x > pq.top()){
            pq.pop();
            pq.push(x);
        }else if(i < n){
            pq.push(x);
        }
    }
    cout<<pq.top();
}
```