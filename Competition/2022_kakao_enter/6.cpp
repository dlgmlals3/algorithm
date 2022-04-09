#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N;
int M;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    
    vector<vector<int>> board2(1002, vector<int>(1002, 0));
    
    for (int i=0; i<skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
                
        if (type == 1) degree *= -1;
        board2[r1][c1] += degree;
        board2[r2+1][c2+1] += degree;
        board2[r1][c2+1] -= degree;
        board2[r2+1][c1] -= degree;
    }
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=M; j++) {
            board2[i][j] += board2[i-1][j]; 
        }
    }
    for (int i=0; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            board2[i][j] += board2[i][j-1]; 
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            board[i][j] += board2[i][j];
            if (board[i][j] > 0) {
                answer++;
            }
        }
    }
    
    return answer;
}