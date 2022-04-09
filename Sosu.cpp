#include <iostream>
#include <vector>
using namespace std;

// 아리스토의 체
void aristoche() {
    int target = 100;
    vector<bool> isSosu(target, true);
    isSosu[0] = false;
    isSosu[1] = false;
    for (int i=2; i<=target; i++) {
        for (int j=i*i; j<=target; j+=i) {
            isSosu[j] = false;
        }
    }
    
    for (int i=2; i<=target; i++) {
        if (isSosu[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(void) {
    aristoche();
    return 0;
}