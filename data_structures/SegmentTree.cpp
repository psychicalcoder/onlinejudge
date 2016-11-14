#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000005;

int seg[maxn*2-1];
int n;

void init(int N) {
    n = 1;
    while(n < N) n*=2;
    fill(seg, seg+(2*n-1), INT_MAX);
}

//update value[p]=x;
void update(int x, int p) {
    p += n-1;
    seg[p] = x;
    while(p > 0 && seg[(p-1)/2] > seg[p]) {
        seg[(p-1)/2] = seg[p];
        p = (p-1)/2;
    }
}

//call query(a, b ,0, 0, n);
int query(int a, int b, int k, int l, int r) {
    if(r <= a || l >= b) return INT_MAX;
    if(a <= l && b >= r) return seg[k];
    else {
        int v1 = query(a, b, k*2+1, l, (l+r)/2);
        int v2 = query(a, b, k*2+2, (l+r)/2, r);
        return min(v1, v2);
    }
}

//demo
int main() {
    int a[] = {1,7,2,6,4,1,9,3,18,0,-2};
    init(11);
    for(int i = 0; i < 11; i++) {
        update(a[i], i);
        printf("%d ", a[i]);
    }
    putchar('\n');
    int l, r;
    while(scanf("%d %d", &l, &r) == 2 && l+r) {
        printf("Min [%d,%d) %d\n", l, r, query(l, r, 0, 0, n));
    }
    return 0;
}