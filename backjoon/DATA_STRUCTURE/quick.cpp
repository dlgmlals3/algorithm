#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int start, int end) {
    int l = start, r = end;
    int pivot = arr[(start + end) / 2];
    int temp;
	  
    while (l <= r)
    {
        while (arr[l] < pivot) l++;
        while (arr[r] > pivot) r--;
		          
        if (l <= r) {
            swap(arr[l], arr[r]);   
            l++; r--; 
        }
    } 
    if (start < r) quickSort(arr, start, r);
    if (l < end) quickSort(arr, l, end);
}

int main(void) {
    int N;
    cin >> N;
    vector<int> v(N, 0);
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v[i] = num;
    }
    quickSort(v, 0, v.size()-1);
    for (auto i : v) {
        cout << i << endl;
    }
    

    return 0;
}