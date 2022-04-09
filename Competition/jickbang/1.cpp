#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
	string str;
	cin >> str;
	vector<char> big;
	vector<char> middle;
	vector<char> small;
	bool ok = true;
	
	for (int i=0; i<str.length(); i++) {
		if (str[i] == '[') {
			big.push_back(str[i]);
		} else if (str[i] == ']') {
			if (big.size() < 0) {
				ok = false;
				break;
			}
			big.pop_back();
		} else if (str[i] == '{') {
			middle.push_back(str[i]);
		} else if (str[i] == '}') {
			if (middle.size() < 0) {
				ok = false;
				break;
			}
			middle.pop_back();
		} else if (str[i] == '(') {
			small.push_back(str[i]);
		} else if (str[i] == ')') {
			if (small.size() < 0) {
				ok = false;
				break;
			}
			small.pop_back();
		}
	}
	if (!ok) {
		cout << "False" << endl;
	} else if (big.size() == 0 && middle.size() == 0 && small.size() == 0) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}

	
	return 0;
}