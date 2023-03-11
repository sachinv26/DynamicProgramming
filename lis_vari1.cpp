// minimum deletions to make a array sorted
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(int arr[], int n)
    {
        int lis[n];
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
        int maxi = lis[0];
        for (int i = 0; i < n; i++)
        {
            maxi = max(lis[i], maxi);
        }

        return n - maxi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minDeletions(arr, n) << "\n";
    }
    return 0;
}
