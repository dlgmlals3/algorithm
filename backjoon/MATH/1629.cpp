#include <iostream>

using namespace std;

long long dfs(int a, int b, int c) {
    if (b == 0) return 1;
    if (b == 1) return a%c;
    if (b % 2 == 0){
        long long t = dfs(a, b/2, c);
        return (t * t) % c;
    } else {
        return a * (dfs(a, b-1, c)) % c;
    }
}

long long dfs2(int a, int b, int c) {
    long long ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans *= a;
            ans %= c;
        }
        b /= 2;
        a *= a;
        a %= c;
    }
    return ans;
}

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;
    cout << dfs2(A, B, C) << '\n';
    return 0;
}
