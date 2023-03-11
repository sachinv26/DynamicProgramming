#include <bits/stdc++.h>
using namespace std;

int lbs(int arr[], int n)
{
    int lis[n];
    int lds[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        lds[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int res = lis[0] + lds[0] - 1;
    for (int i = 1; i < n; i++)
    {
        if (lis[i] + lds[i] - 1 > res)
        {
            res = lis[i] + lds[i] - 1;
        }
    }

    return res;
}

int main()
{
    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = 8;
    cout << lbs(arr, n);
    return 0;
}