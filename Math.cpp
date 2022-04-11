#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    float v1 = pow(3.1, 2); // 제곱근
    float v2 = sqrt(4.1); // 루트
    cout << v1 << " " << v2 << endl;

    // 2째짜리 까지 올림
    cout << "ceiling : " << ceil(v2 * 100) / 100 << endl; 
    // 2째짜리 까지 반올림
    cout << "round : " << round(v2 * 100) / 100 << endl; 
    // 2째짜리 까지 버림
    cout << "floor : " << floor(v2 * 100) / 100 << endl; 
    return 0;
}