#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string.h>


using namespace std;

int N, K;
int ans = -1;

int visit[100001];
int t[100001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    memset(visit, -1, sizeof(visit));
    memset(t, -1, sizeof(t));

    // 같은 경로라도 방문이 가능해야됌!!
    // 방법의수 visit[][] = visit[][] + 1;
    // 몇초에 해당 경로에 도착했는지가 중요할거같음

    queue<int> q;
    q.push(N);
    visit[N] = 1;
    t[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : {cur-1, cur+1, cur*2}) {
            if (next > 100000 || next < 0) continue;
            if (visit[next] == -1) {
                t[next] = t[cur]+1;
                visit[next] = visit[cur];
                q.push(next);
            } else if (t[next] == t[cur]+1) {
                visit[next] += visit[cur];
            }
        }
    }
    
    cout << t[K] << endl;
    cout << visit[K] << endl;
    return 0;
}
