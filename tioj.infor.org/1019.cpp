#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll ABS(ll x) {
	return x>=0?x:-x;
}

ll a[1003],d[1003];
int cases,n;

int main() {
	scanf("%d",&cases);
	d[0]=d[1]=0;
	for(int k=0;k<cases;k++){
		scanf("%d",&n);
		for(int r=1;r<=n;r++) scanf("%lld",a+r);
	    d[2]=ABS(a[2]-a[1]);
	    for(int i=3;i<=n;i++){
		    d[i]=min(d[i-1]+ABS(a[i]-a[i-1]),
		             d[i-2]+ABS(a[i]-a[i-2]));
	    }
	    printf("%lld\n",d[n]);
	}
    return 0;
}