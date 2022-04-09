#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

void useMinMaxHeap() {
    // Always keep maxHeap count == minHeap count + 1 
    int num;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    if (maxHeap.empty() || maxHeap.top() > num) {
        maxHeap.push(num);            
    } else {
        minHeap.push(num);
    }
    
    while (!minHeap.empty() && maxHeap.size() <= minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    while (!maxHeap.empty() && maxHeap.size() > minHeap.size()+1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    cout << maxHeap.top() << '\n';
}

void test() {
    // default max Heap
    priority_queue<int> default_q;
    // 가장 작은 값은 반환 1, 2, 3, 4
    priority_queue<int, vector<int>, greater<int>> min_q;
    // 가장 큰 값을 반환 4, 3, 2, 13
    priority_queue<int, vector<int>, less<int>> max_q;
    default_q.push(1);default_q.push(2);default_q.push(3);default_q.push(4);
    min_q.push(1);min_q.push(2);min_q.push(3);min_q.push(4);
    max_q.push(1);max_q.push(2);max_q.push(3);max_q.push(4);

    while (!default_q.empty()) {
        cout << default_q.top() << ' ';
        default_q.pop();
    } cout << '\n';
    
    while (!min_q.empty()) {
        cout << min_q.top() << ' ';
        min_q.pop();
    } cout << '\n';
    
    while (!max_q.empty()) {
        cout << max_q.top() << ' ';
        max_q.pop();
    } cout << '\n';
}

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first > b.first) {    
            return true;
        } else if (a.first == b.first && a.second > b.second) {
            return true;
        }
        return false;
    }
};

struct compareTuple {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        int a1, a2, a3;
        int b1, b2, b3;
        tie(a1, a2, a3) = a;
        tie(b1, b2, b3) = b;
        if (a2 > b2) {
            return true;
        }
        return false;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push(make_pair(5, 1));
    q.push(make_pair(4, 1));
    q.push(make_pair(3, 1));
    while (!q.empty()) {
        cout << q.top().first << " " << q.top().second << endl;
        q.pop();
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compareTuple> qt;
    qt.push(make_tuple(1, 6, 3));
    qt.push(make_tuple(1, 2, 3));
    qt.push(make_tuple(1, 4, 3));
    while (!qt.empty()) {
        int a, b, c;
        tie(a, b, c) = qt.top();
        qt.pop();
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}