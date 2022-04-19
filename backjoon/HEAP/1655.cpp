#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
vector<int> ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        
        if (maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);            
        } else {
            minHeap.push(num);
        }

        // alwayas keep maxHeap count == minHeap count + 1 
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
    return 0;
}