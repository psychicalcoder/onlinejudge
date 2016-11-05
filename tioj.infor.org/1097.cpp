#include <cstdio>
#include <algorithm>
using namespace std;

int d[2][5005];

int main() {
	int m,n,t,mx;
	while(scanf("%d%d",&m,&n)==2&&m&&n){
		mx=0;
		for(int i=0;i<n;i++) {
			scanf("%d",&t);
			d[0][i]=t==2?0:1;
			if(t!=2)mx=1;
		}
		for(int i=1;i<m;i++){
			scanf("%d",&t);
			d[1][0]=t==2?0:1;
			for(int j=1;j<n;j++){
				scanf("%d",&t);
				if(t==2)d[1][j]=0;
				else {
					d[1][j]=min(d[0][j-1],min(d[0][j],d[1][j-1]))+1;
					mx=max(d[1][j],mx);
				}
			}
			for(int i=0;i<n;i++) 
			    d[0][i]=d[1][i];
		}
		printf("%d\n",mx*mx);
	}
	return 0;
}