#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool isPrime(long long num) {
    int cnt = 0;
    for (long long i=1; i<=num; i++) {
        if (num % i == 0) {
            cnt++;
        }
    }
    if (cnt == 2) return true;
    return false;
}

int solution(int n, int k) {
    int answer = 0;
    string str="";
    while (n / k != 0) {
        int r = n % k;
        n /= k;
        str.push_back(r + '0');
    }
    str.push_back(n%k + '0');
    
    reverse(str.begin(), str.end());
    //cout << str << endl;
    int ans = 0;
    string word = "";
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '0') {
            //cout << word << " ";
            long long num = atoll(word.c_str());
            if (isPrime(num)) {
                answer++;
            }
            word = "";
        } else {
            word.push_back(str[i]);
        }
    }
    long long num = atoll(word.c_str());
    if (isPrime(num)) {
        //cout << word << endl;
        answer++;
    }
    
    return answer;
}