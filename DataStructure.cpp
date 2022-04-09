#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void stringApi() {
    string str;
    cout << "String API" << endl;
    // push
    str.push_back('1'); str.push_back('2'); str.push_back('3');
    str.push_back('4'); str.push_back('5');
    cout << "1. " << str << endl;
    // pop
    str.pop_back(); str.pop_back(); str.pop_back();
    cout << "2. " << str << endl;
    str.clear();

    // insert
    str.insert(str.begin(), '1');
    str.insert(1, "234");
    cout << "3. " << str << endl;
    
    // delete (startIndex, count)
    str.erase(1, 3); 
    cout << "4. " << str << endl;

    // find & replace
    str = "12345678";
    size_t index = str.find('1');
    if (index != string::npos) {
        cout << "5. " << index << endl;
        str.replace(index, 4, "blue");
        cout << "6. " << str << endl;   
    }
    string a = "123";
    string b = "456";
    string c = a + b;
    cout << "7. " << c << endl;
    cout << "8. length : " << c << " " << c.length() << endl; // size is memory size...
}

void stringApi2() {
    // substr (index >=, count <)
    string records[] = {"11:00 1234 no_problem", "12:30 5678 what is it?"};

    for (string r : records) {
        string h = r.substr(0, 2);
        string m = r.substr(3, 2);
        string carNum = r.substr(6, 4);
        string inout = r.substr(11, r.length()-11+1);
        
        int time = atoi(h.c_str()) * 60 + atoi(m.c_str());
        cout << "time : " << time << " " << "number : " << carNum << " inout : " << inout << endl;
    }

    // 정렬 후 중복제거 
    vector<string> v={"456", "123", "456", "357", "888", "999", "888"};
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end()); // start index ~ end index remove
    v.erase(last, v.end());

    for (auto item : v) {
        cout << item << " ";
    } 
}

int main() {
    stringApi();
    stringApi2();
    
    return 0;
}