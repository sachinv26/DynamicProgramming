#include <bits/stdc++.h>
using namespace std;

int LDS(int arr[], int n)
{
    int lds[n];
    for (int i = 0; i < n; i++)
    {
        lds[i] = 1;
    }

    for (int i = n - 2; i > 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int res = lds[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, lds[i]);
    }

    return res;
}

int main()
{
    int arr[] = {1,11,2,10,4,5,2,1};
    int n = 8;
    cout << LDS(arr, n);
    return 0;
}