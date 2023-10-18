```c++
https://www.acmicpc.net/problem/1253
int main() {
    int n;
    cin>>n;
    map<int,int> s;
    vector<int> v(n);

    int zeroCnt = 0;
    for(auto &x: v){
        cin>>x;
        if(x == 0)zeroCnt++;
        if(s.find(x) != s.end()){
            s[x]++;
        }else{
            s.insert({x,1});
        }

    }

    map<int,int> ans;
    for(int i = 0; i< v.size(); i++){
        for(int j = i + 1; j< v.size(); j++){
            int sum = v[i] + v[j];
            if(zeroCnt <= 2 ){
                if(v[i] ==0 && v[j] == 0)continue;
                if(v[i] == 0){
                    if(s[v[j]] <= 1 )continue;
                }if(v[j] == 0){
                    if(s[v[i]]<=1)continue;
                }
            }
            if(s.find(sum) != s.end()){
                ans.insert({sum,s[sum]});
            }
        }
    }
    int cnt = 0;
    for(auto & an : ans){
        cnt += an.second;
    }
    cout<<cnt;
}
```