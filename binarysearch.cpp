#include<bits/stdc++.h>
using   namespace   std;
int n, k, a[10001];
int  Binary_search(int arr[], int left, int right, int target)
{
    if(right >= left)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            return Binary_search(arr, left, mid, target);
        }
        else
        {
            return Binary_search(arr, mid, right, target);
        }
    }
    return -1;
}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int result = Binary_search(a, 1, n, k);
    cout << result;
}
