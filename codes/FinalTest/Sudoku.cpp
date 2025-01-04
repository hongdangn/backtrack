//C++ 
#include <bits/stdc++.h> 
using namespace std;

int row[10][10], col[10][10];
int x[4][4][10];
int inp[10][10];
int out[10][10];
int res;

void print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << out[i][j] << " ";
		}
		cout << "\n";
	} 
}

void Try(int r, int c) {
	if (inp[r][c]) {
        if (r == 9 && c == 9) {
        	res++;
        	cout << res << "\n";
		} else if (r < 9) Try(r + 1, c);
        else Try(1, c + 1);   
		return;     	
	}
	
    for (int i = 1; i <= 9; i++) {
        if (!inp[r][c] && !row[r][i] && !col[c][i] 
            && !x[(r - 1)/3][(c - 1)/3][i]) {
            
            out[r][c] = i;
            row[r][i] = 1; col[c][i] = 1; x[(r - 1)/3][(c - 1)/3][i] = 1;
            if (r == 9 && c == 9) {
            	res++;
			}
            else if (r < 9) Try(r + 1, c);
            else Try(1, c + 1);
            
            row[r][i] = 0; col[c][i] = 0; x[(r - 1)/3][(c - 1)/3][i] = 0;            
        }
    }
}

int main() 
{ 
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> inp[i][j];
            if (inp[i][j]) {
                row[i][inp[i][j]] = 1;
                col[j][inp[i][j]] = 1;
                x[(i - 1)/3][(j - 1)/3][inp[i][j]] = 1;
            }
        }
    }
    
    Try(1, 1);
    cout << res;
}

