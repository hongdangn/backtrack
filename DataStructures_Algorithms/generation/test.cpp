#include <stdio.h>

#define MAX_N 101

int n;

void print_sol(int a[MAX_N], int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }

    for (int val = 1; val <= 2; val++)
    {
        if (a[idx] == 0 || a[idx] == val)
        {
            int originalValue = a[idx];
            a[idx] = val;
            print_sol(a, idx + 1);
            a[idx] = originalValue; // Backtrack to restore the array
        }
    }
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[MAX_N];

    printf("Enter the array elements (0, 1, or 2): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("All combinations:\n");
    print_sol(a, 0);

    return 0;
}

