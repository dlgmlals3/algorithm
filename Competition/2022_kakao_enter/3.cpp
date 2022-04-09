#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<string, vector<pair<int, string>>> v;
vector<string> carNums; 

vector<int> solution(vector<int> fees, vector<string> records) {   
    for (string r : records) {
        string h = r.substr(0, 2);
        string m = r.substr(3, 2);
        string carNum = r.substr(6, 4);
        string inout = r.substr(11, r.size()-11+1);
        
        int time = atoi(h.c_str()) * 60 + atoi(m.c_str());
        //cout << h << "," << m << "," << carNum << "," << inout << endl;
        
        v[carNum].push_back(make_pair(time, inout));
        carNums.push_back(carNum);
    }
    sort(carNums.begin(), carNums.end());
    carNums.erase(unique(carNums.begin(), carNums.end()), carNums.end());
    vector<int> answer;
    for (string num : carNums) {
        if (v[num].size() % 2 != 0) {
            v[num].push_back(make_pair(60 * 23 + 59, "out"));
        }
        int allTime = 0;
        
        vector<pair<int, string>> l = v[num];
        for (int i = 1; i < v[num].size(); i+=2) {
            allTime += l[i].first - l[i-1].first;
        }
        cout << "allTime : " << allTime << endl;
        int sum = fees[1];
        
        
        if (allTime - fees[0] > 0) {
            int diffTime = allTime - fees[0];
            int nano = diffTime / fees[2];
            if (diffTime % fees[2] != 0) nano++;
            sum += nano * fees[3];
        }
        answer.push_back(sum);
    }
    return answer;
}