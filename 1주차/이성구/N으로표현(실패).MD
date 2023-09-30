https://kim519620.tistory.com/entry/N%EC%9C%BC%EB%A1%9C-%ED%91%9C%ED%98%84-feat-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-42895%EB%B2%88

https://school.programmers.co.kr/learn/courses/30/lessons/42895
``` c++
using namespace std;
int make_number(const int& N, const int& count) {
	int ret = 0;
	for (int i = 0; i < count; ++i)
		ret += N * pow(10, i);
	return ret;
}
int solution(int N, int number) {
	vector<int>dp[9];
	// 1자릿수
	dp[1].push_back(make_number(N, 1));
	for (int i = 0; i < dp[1].size(); ++i)
		if (number == dp[1][i])
			return 1;
	// 2자릿수 ~ 8자릿수
	for (int x = 2; x <= 8; ++x) {
		dp[x].push_back(make_number(N, x));
		for (int i = 1; i < x; ++i)
			for (auto& j : dp[i]) {
				if (j == 0)			continue;	// 0인 경우, 계산에 의미가 없음 (나눗셈 연산 문제 포함)
				for (auto& k : dp[x - i])
				{
					if (k == 0)		continue;	// 0인 경우, 계산에 의미가 없음 (나눗셈 연산 문제 포함)
					dp[x].push_back(j * k), dp[x].push_back(j / k), dp[x].push_back(j + k), dp[x].push_back(j - k);
				}
			}
		for (int i = 0; i < dp[x].size(); ++i)
			if (number == dp[x][i])
				return x;
	}
	// 9자릿수 이상
	return -1;
}
```