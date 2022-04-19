#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
map<int, int> card;
vector<int> cards;
    
void ans_1() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        card[num]++;
    }    
    cin >> M;
    for (int i=0; i<M; i++) {
        int num;
        cin >> num;
        cout << card[num] << " ";
    }
    cout << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        cards.push_back(num);
    }    
    sort(cards.begin(), cards.end());

    cin >> M;
    for (int i=0; i<M; i++) {
        int num;
        cin >> num;
        auto lower_itr = lower_bound(cards.begin(), cards.end() , num);
        auto upper_itr = upper_bound(cards.begin(), cards.end(), num);
        cout << upper_itr - lower_itr << '\n';
    }
    return 0;
}