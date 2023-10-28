#include <string>
#include <vector>

using namespace std;

long long max(long long a, long long b) {
    if (a > b)
        return a;
    return b;
}

long long get_max(vector<int> seq) {
    long long res = seq[0];
    long long dp[500001] = {0, };
    
    dp[0] = seq[0];
    for (int i = 1; i < seq.size(); i++) {
        dp[i] = max(dp[i - 1] + seq[i], seq[i]);
        if (res < dp[i])
            res = dp[i];
    }
    return res;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    for (int i = 0; i < sequence.size(); i++) {
        sequence[i] = i % 2 == 0 ? sequence[i] : sequence[i] * (-1);
    }
    long long a = get_max(sequence);
    for (int i = 0; i < sequence.size(); i++) {
        sequence[i] *= -1;
    }
    long long b = get_max(sequence);
    answer = max(a, b);
    return answer;
}