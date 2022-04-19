#include <iostream>
#include <vector>
#include <cmath>

// MODULAR 연산

using namespace std;
int A, B, C;

long long go(int A, int B, int C) {
    if (B == 0) return 1;
    if (B == 1) return A % C;
    
    long long t = go(A, B/2, C); 
    
    if (B % 2 == 0) {
        return t * t % C;
    } else {
        return ((t * t % C) * A) % C;
    }
}

int main(void) {
    cin >> A >> B >> C;
    cout << go(A, B, C) << endl;
    
    return 0;
}