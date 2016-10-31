#include <cstdio>

int d[95];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	d[0]=1;
	for(int i=1;i<=n;i++){
	    d[i]=d[i-1]<<1;
	}
	for(int i=n;i<=m-1;i++){
		for(int j=0;j<=n;j++){
			d[i+1]+=d[i-j];
		}
	}
	printf("%d\n",d[m]);
	return 0;
}