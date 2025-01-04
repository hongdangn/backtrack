#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, a[1000001];
int res;

void merge_and_count(int start, int mid, int endd) {
    vector<int> tmp;
    
    int left = start, right = mid + 1;
    
    while (left <= mid && right <= endd) {
        if (a[left] <= a[right]) {
            tmp.push_back(a[left]);
            left++;
        
        } else {
            res = (res + mid - left + 1) % MOD;
            tmp.push_back(a[right]);
            right++;
        }
    }
    
    while (left <= mid) {
        tmp.push_back(a[left]);
        left++;
    }
    
    while (right <= endd) {
        tmp.push_back(a[right]);
        right++;
    }
    

    for (int i = start; i <= endd; i++) {
        a[i] = tmp[i - start];
    }
}

void sort_and_count(int start, int endd) {
    if (start == endd) return;
    int mid = (start + endd) / 2;
    
    sort_and_count(start, mid);
    sort_and_count(mid + 1, endd);
    
    merge_and_count(start, mid, endd);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort_and_count(0, n - 1);
    cout << res;

    return 0;
}

