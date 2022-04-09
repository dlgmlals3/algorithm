#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void permutation() {
    string v = "12345";
    sort(v.begin(), v.end());
    do {
        cout << v << '\n';
    } while (next_permutation(v.begin(), v.end()));
}

void combination() { 
    int N = 3;
    for (int i=0; i<(1<<N) ; i++) {
        long long sum = 0;
        string str;
        for (int j=0; j<N; j++) {
            if (i & (1 << j)) {
                str.push_back('1');
            } else {
                str.push_back('0');
            }
        }
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
}
int main(void) {
    //permutation();
    combination();
    return 0;
}
