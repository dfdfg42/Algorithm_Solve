#include <iostream>
#include <cstdio>
 
using namespace std;
 
int a[100010];
int b[100010];
int ab[100010];
 
int lis[100010];
 
int _lower_bound(int start, int end, int target)
{
    int mid;
 
    while (start < end)
    {
        mid = (start + end) / 2;
 
        if (lis[mid] < target)
            start = mid + 1;
 
        else
            end = mid;
    }
 
    return end + 1;
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int pos;
        scanf("%d", &pos);
 
        a[pos - 1] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        b[i]--;
 
        ab[i] = a[b[i]];
    }
 
    int pArr = 1;
    int pLis = 0;
    
    lis[0] = ab[0];
 
    while (pArr < n)
    {
        if (lis[pLis] < ab[pArr])
            lis[++pLis] = ab[pArr];
 
        else
        {
            int ans = _lower_bound(0, pLis, ab[pArr]);
            lis[ans - 1] = ab[pArr];
        }
 
        pArr++;
    }
 
    printf("%d", pLis + 1);
    return 0;
}