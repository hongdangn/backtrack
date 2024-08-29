#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[10]; // x[i]: number of teachers can teach course i
int y[10][10]; // y[i][j] is the teacher who teaches course i
int a[10][10]; 
int course[10];
int assigned[10][10]; // assigned[i][j] is the courses assigned to teacher i
int num_assigned[10]; // number of courses is assigned to teacher i

void print_sol() {
	for (int i = 1; i <= m; i++) {
		cout << "Courses of teacher " << i << ": ";
		for (int j = 1; j <= n; j++) {
			if (course[j] == i) cout << j << ", ";
		}
		cout << "\n";
	}
	cout << "--------------------------\n";
} 

bool check(int course, int i) {
	int teacher = y[course][i];
	if (!num_assigned[teacher]) return true;
	
	for (int j = 0; j < num_assigned[teacher]; j++) {
		if (a[assigned[teacher][j]][course]) return false;
	}
	
	return true;
}

// assign course k to teacher
void Try(int cse) {
	for (int i = 0; i < x[cse]; i++) {
		if (check(cse, i)) {
			int teacher = y[cse][i];
			course[cse] = teacher;
			assigned[teacher][num_assigned[teacher]++] = cse;
			
			if (cse == n) print_sol();
			else Try(cse + 1);
			
			assigned[teacher][--num_assigned[teacher]] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> x[i];
    	for (int j = 0; j < x[i]; j++) cin >> y[i][j];
	}
	
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
		}
	}
	
	Try(1);
}
