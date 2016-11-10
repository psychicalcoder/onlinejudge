#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<double, vector<double>, greater<double> > q;

int main() {
    int n;
    char cmd[5];
    double f;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %lf", cmd, &f);
        q.push(f);
    }
    double ans = 0, a, b;
    while(n >= 2) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        ans += a+b;
        q.push(a+b);
        n--;
    }
    printf("%.2f\n", ans);
    return 0;
}