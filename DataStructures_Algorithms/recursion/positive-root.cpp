#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int num_vars, sum;
int var[101];

void print() {
	for (int i = 0; i < num_vars; i++) {
		cout << var[i] << " ";
	}
	cout << "\n";
}

void get_val(int id, int sum) {
	for (int i = 1; i <= sum; i++) {
		var[id] = i;
		
		if (id == num_vars - 1) {
			if (var[id] == sum) print();
		} else if (sum - var[id] > 0) {
			get_val(id + 1, sum - var[id]);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num_vars >> sum;
    get_val(0, sum);
}
