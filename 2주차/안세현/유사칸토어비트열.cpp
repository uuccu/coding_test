#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isOne(long long k) {
    if (k < 5 && k != 2) return true; // 11011 중, 가운데 0 이 아닐 때, 그리고 00000 세트가 아닐 때는 true
    if (k % 5 == 2) return false;

    return isOne(k / 5);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    l--; r--;
    for (long long i = l; i <= r; i++) {
        if (isOne(i)) answer++;
    }
    return answer;
}

