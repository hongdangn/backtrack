#include <bits/stdc++.h> 
#define MAX_VAL 1000000009
using namespace std;

int n, k, q; // k: num trucks, q: capacity, n: num cities
int d[13];
int c[13][13];
int x[13], y[13]; // y[i]: first city which the truck come to, x[i] - next city of i
int visited[13];
int load[6];
int numSegments, numUsedVehicles;
int minRoute = MAX_VAL, curRoute;
int min_val = MAX_VAL;

bool trueCity(int vehicle, int city) {
	if (city == 0) return true;
	if (visited[city]) return false;
	
	if (load[vehicle] + d[city] <= q) return true;
	return false;
}

void tryCity(int city, int vehicle) {
	if (!city) {
		if (vehicle < k) tryCity(y[vehicle + 1], vehicle + 1); 
		return;
	}
	
	for (int i = 0; i <= n; i++) {
		if (trueCity(vehicle, i)) {
			x[city] = i;
			visited[i] = 1; numSegments += 1;
			load[vehicle] += d[i]; curRoute += c[city][i];
			
			if (i != 0) {
				if (curRoute + min_val * (numUsedVehicles + n - numSegments) <= minRoute) {
					tryCity(i, vehicle);
				} 
			} else {
				if (vehicle == k) {
					if (numUsedVehicles + n == numSegments && curRoute < minRoute) minRoute = curRoute;
				} else tryCity(y[vehicle + 1], vehicle + 1);
			}
			
			visited[i] = 0; numSegments -= 1;
			load[vehicle] -= d[i]; curRoute -= c[city][i];
		}
	}
}

void tryFirstCity(int vehicle) {
	int city = 0;
	if (vehicle) {
		if (y[vehicle - 1]) city = y[vehicle - 1] + 1; 
	}
	
	for (int i = city; i <= n; i++) {
		if (trueCity(vehicle, i)) {
			
			y[vehicle] = i; visited[i] = 1;
			curRoute += c[0][i];
			
			if (i > 0) {
				load[vehicle] += d[i];
				numSegments++;
			}
			
			if (vehicle < k) tryFirstCity(vehicle + 1);
			else {
				numUsedVehicles = numSegments;
				tryCity(y[1], 1);
//				for (int l = 1; l <= k; l++) cout << y[l] << " ";
//				cout << "\n";
			} 
			
			load[vehicle] -= d[i]; visited[i] = 0;
			curRoute -= c[0][i];
			if (i > 0) numSegments--;
		}
	}
}

int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] && c[i][j] < min_val) min_val = c[i][j];
        }
    }

    tryFirstCity(1);
    cout << minRoute;
    return 0;
}

