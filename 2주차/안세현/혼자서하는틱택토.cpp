#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int o_cnt = 0;
    int x_cnt = 0;
    int winO = 0;
    int winX = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O')
                o_cnt++;
            else if (board[i][j] == 'X')
                x_cnt++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'O')
                winO = 1;
            else if (board[i][0] == 'X')
                winX = 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'O')
                winO = 1;
            else if (board[0][1] == 'X')
                winX = 1;
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O')
            winO = 1;
        else if (board[0][0] == 'X')
            winX = 1;
    }
    
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if (board[1][1] == 'O')
            winO = 1;
        else if (board[1][1] == 'X')
            winX = 1;
    }
    
        
    if (o_cnt < x_cnt) // O의 개수 < x의 개수 이면 0
        return 0;
    if (o_cnt == 0 && x_cnt == 0) // 시작 전이면 true
        return 1;
    if (o_cnt > x_cnt + 1)
        return 0;
    
    
    if (winX == winO && winO > 0) // 둘이 동시에 이길 수 없음
        return 0;
    if (winX == 1 && winO == 0 && o_cnt == x_cnt) // X가 이기고 O가 졌을때, 두 개수 같음
        return 1;
    if (winO == 1 && winX == 0 && o_cnt == x_cnt + 1) // O가 이기고 X는 졌을 때, O가 X보다 한개 많음
        return 1;
    if (winX == winO && winO == 0)
        return 1;

    return 0;
}
