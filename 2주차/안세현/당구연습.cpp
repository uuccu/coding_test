#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int pow(int a)
{
    return a * a;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (auto ball : balls)
    {
        if (startX == ball[0]) { // 시작과 목표의 X좌표가 같을때
            int w = m - startX > startX ? startX : m - startX;
            int h = abs(startY - ball[1]);
            int len = pow(2 * n - startY - ball[1]) < pow(2 * w) + pow(h) ? pow(2 * n - startY - ball[1]):pow(2 * w) + pow(h);
            answer.push_back(len);
        } else if (startY == ball[1]) { // 시작과 목표의 Y좌표가 같을 때
            int h = n - startY > startY ? startY : n - startY;
            int w = abs(startX - ball[0]);
            int len = pow(2 * m - startX - ball[0]) < pow(2 * h) + pow(w) ? pow(2 * m - startX - ball[0]):pow(2 * h) + pow(w);
            answer.push_back(len);
        } else { // x, y 둘다 다를 때
            int h = abs(startY - ball[1]);
            int w = startX + ball[0] < m - startX + m - ball[0] ? startX + ball[0] : m - startX + m - ball[0];
            int min = h*h + w*w;
            w = abs(startX - ball[0]);
            h = n - startY + n - ball[1] < startY + ball[1] ? n - startY + n - ball[1] : startY + ball[1];
            min = min > h*h + w*w ? h*h + w*w : min;
            answer.push_back(min);
        }
    }
    return answer;
}
