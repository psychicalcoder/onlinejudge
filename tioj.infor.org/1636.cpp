#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for(ll i = 0; i < n; i++)
        scanf("%lld", a+i);
    ll sum, ans, val, num;
    ans = sum = a[0];
    for(ll i = 1; i < n && k >= i; i++) {
        sum += a[i];
        val = sum;
        num = k - i;
        val += a[i-1]*((num+1)/2) + a[i]*(num/2);
        if (val > ans) ans = val;
    }
    if(n==1)
        printf("%lld\n",((k+1)/2)*a[0]);
    else 
        printf("%lld\n", ans);
    return 0;
}