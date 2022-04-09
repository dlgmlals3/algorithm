#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<vector<int>> v(1001, vector<int>(1001, 0));
int cnt_btn[1001];
int button = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		button++;
		int L, R, B, T;	
		cin >> L >> R >> B >> T;
		for (int i=L; i<=R; i++) {
			for (int j=B; j<=T; j++) {
				v[i][j] = button;
			}
		}		
	}
	
	for (int i=0; i<M; i++) {
		int y, x;
		cin >> x >> y;
		cnt_btn[v[x][y]]++;
	}
	if (button == 0) return 0;
	
	for (int i=1; i<=button; i++) {
		cout << "Button #" << i << ": " << cnt_btn[i] << '\n';
	}
	return 0;
}