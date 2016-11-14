#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL> > q;
int main() {
    LL n, x;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        q.push(x);
    }
    LL ans = 0, a, b;
    while(n >= 2) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        ans += a+b;
        q.push(a+b);
        n--;
    }
    printf("%lld\n", ans);
    return 0;
}