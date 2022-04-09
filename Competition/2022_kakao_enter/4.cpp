#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxDiff = -1;
vector<int> apeach(11, 0);
vector<int> lion(11, 0);
vector<int> answer(11, 0);
int N;

void calculate() {
    int lionScore=0;
    int apeachScore=0;
    for (int i=0; i<=10; i++) {
        if (lion[i] == 0 && apeach[i] == 0) continue;
        if (lion[i] > apeach[i]) {
            lionScore += 10 - i;
        } else {
            apeachScore += 10 - i;
        }
    }
    int diff = lionScore - apeachScore;
    if (diff > 0) {
        if (maxDiff == -1 || maxDiff <= diff) {
            if (maxDiff == diff) {
                reverse(answer.begin(), answer.end());
                reverse(lion.begin(), lion.end());
                if (answer < lion) {
                    for (int i=0; i<=10; i++) {
                        answer[i] = lion[i];
                    }   
                }
                reverse(answer.begin(), answer.end());
                reverse(lion.begin(), lion.end());
            } else {
                maxDiff = diff;   
                for (int i=0; i<=10; i++) {
                    answer[i] = lion[i];
                }
            }
        }
    }
}

void dfs(int index, int arrowCnt) {
    if (arrowCnt <= 0) {
        calculate();
        return;
    }
    if (index == 10) {
        lion[index] += arrowCnt;
        calculate();
        lion[index] -= arrowCnt;
        return;
    } 
    
    if (apeach[index] + 1 <= arrowCnt) {
        lion[index] = apeach[index] + 1;
        dfs(index+1, arrowCnt-lion[index]);
    }

    lion[index] = 0;
    dfs(index+1, arrowCnt);    
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    for (int i=0; i<=10; i++) {
        apeach[i] = info[i];
    }
    
    dfs(0, n);

    if (maxDiff == -1) {
        answer.clear();
        answer.push_back(-1);
    }
        
    return answer;
}