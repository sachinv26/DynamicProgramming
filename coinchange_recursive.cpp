#include<bits/stdc++.h>
using namespace std;
int countways(int coins[],int n,int s)
{
    if(s==0)
        return 1;
    if(s<0)
        return 0;
    if(n==0)
        return 0;
    return countways(coins,n,s-coins[n-1]) + countways(coins,n-1,s);
}
int main()
{
    int coins[]={1,2,3};
    int n=3,s=4;
    cout<<countways(coins,n,s);
}