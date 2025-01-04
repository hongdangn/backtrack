#include <bits/stdc++.h>
#include <vector>
using namespace std; 

stack<char> s;
string str;
int num_left_par;

int is_left_par(char c) {
	if (c == '(' || c == '{' || c == '[') return 1;
	return 0;
}

int is_true_pair(char c1, char c2) {
	if (c1 == '(') {
		if (c2 != ')') return 0;
		else if (c2 == ')') return 1;
		
	} else if (c1 == '[') {
		if (c2 != ']') return 0;
		else if (c2 == ']') return 1;
		
	} else if (c1 == '{') {
		if (c2 != '}') return 0;
		else if (c2 == '}') return 1;
	}
}

int main() {
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		
		if (is_left_par(str[i])) {
			s.push(str[i]);
		
		} else {
			if (s.empty()) {
				cout << 0;
				return 0;
			} else if (is_true_pair(s.top(), str[i])) s.pop();
			else {
				cout << 0;
				return 0;
			}
		}
	}
	
	if (!s.empty()) cout << 0;
	else cout << 1;
	return 0;
}

