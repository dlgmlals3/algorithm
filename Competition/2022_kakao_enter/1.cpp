#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> singo;
    map<string, vector<string>> v;
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for (string str : report) {
        int loc = str.find(' ');
        string fir = str.substr(0, loc);
        string sec = str.substr(loc+1, str.size());
        //cout << fir << " " << sec << endl;
        singo[sec]++;
        v[fir].push_back(sec);
    }
        
    for (string id : id_list) {
        int cnt = 0;
        for (string child : v[id]) {
            if (singo[child] >= k) {
                cnt++;
            }
        }
        //cout << cnt << endl;
        answer.push_back(cnt);
    }
    

    
    return answer;
}