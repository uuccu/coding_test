#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    // priority_queue<pair<int, int>> qu;
    int sum = 0;
    
    for (int i = 0; i < k; i++) {
        sum += stones[i];
    }
    
    int min = sum;
    answer = stones[0];
    
    for (int i = 1; i <= stones.size() - k; i++) {
        sum -= stones[i-1];
        sum += stones[i + k - 1];
        if (min > sum) {
            min = sum;
            answer = *max_element(stones.begin() + i, stones.begin() + i + k);
        } else if (min == sum) {
            if (*max_element(stones.begin() + i, stones.begin() + i + k) < answer)
                answer = *max_element(stones.begin() + i, stones.begin() + i + k);
        }
    }
    return answer;
}
