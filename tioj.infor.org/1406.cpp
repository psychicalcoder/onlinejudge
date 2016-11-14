#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

int n;
LL p[maxn], v[maxn];

bool test(LL m) {
    LL f = 0;
    for(int i = 0; i < n; i++) {
        //f is true if f > 0 || f < 0
        if(f) f -= p[i]-p[i-1];
        f += v[i]-m;
    }
    return f>=0;
}

int main() {
    while(scanf("%d", &n) == 1) {
        LL l = LLONG_MAX, r = -1, m;
        for(int i = 0; i < n; i++) {
            scanf("%lld%lld", p+i, v+i);
            if(v[i]>r) r = v[i];
            if(v[i]<l) l = v[i];
        }
        while(l!=r) {
            m = (l+r+1)/2;
            if(test(m)) l = m;
            else r = m-1;
        }
        printf("%lld\n", r);
    }
    return 0;
}