#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
int N;
int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N;
    float ans = 0;
    vector<pair<int, int>> v;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    
    for (int i=0; i<N-3; i++) {
        int x = v[i].first;
        int y = v[i].second;
        for (int j=i+1; j<N-2; j++) {
            int x1 = v[j].first;
            int y1 = v[j].second;        
            for (int k=j+1; k<N-1; k++) {
                int x2 = v[k].first;
                int y2 = v[k].second;
                for (int l=k+1; l<N; l++) {
                    int x3 = v[l].first;
                    int y3 = v[l].second;
                    float dist1 = sqrt(pow(abs(x-x1), 2) + pow(abs(y-y1), 2));
                    float dist2 = sqrt(pow(abs(x1-x3), 2) + pow(abs(y1-y3), 2));       
                    float dist3 = sqrt(pow(abs(x2-x3), 2) + pow(abs(y2-y3), 2));
                    float dist4 = sqrt(pow(abs(x-x2), 2) + pow(abs(y-y2), 2));
                    
                    float dist5 = sqrt(pow(abs(x-x3), 2) + pow(abs(y-y3), 2));
                    float dist6 = sqrt(pow(abs(x1-x2), 2) + pow(abs(y1-y2), 2));

                    if (dist1 == dist2 && dist1 == dist3 && dist1 == dist4) {
                        if (dist5 == dist6) {
                            ans = max(ans, dist1 * dist1);
                        }
                    }
                }    
            }
        }
    }

    printf("%.2f", ans);

    return 0;
}