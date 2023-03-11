#include <bits/stdc++.h>
using namespace std;

int ceilIDX(int tail[], int l, int r, int key)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return r;
}

int LIS(int arr[], int n)
{
    int tail[n];
    tail[0] = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[i] = arr[i];
            len++;
        }
        else
        {
            int c = ceilIDX(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

int main()
{
    int arr[] = {3, 10, 20, 4, 6, 7};
    int n = 6;
    cout << LIS(arr, n);
    return 0;
}