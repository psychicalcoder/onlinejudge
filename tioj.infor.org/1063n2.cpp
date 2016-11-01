#include <cstdio>
#include <cstring>
using namespace std;

struct P {
	int p,h;
	P(){}
	P(int x, int y) {
		p=x,h=y;
	}
};

int d[205][205];

int main() {
	int m,n,t;
	scanf("%d%d",&m,&n);
	memset(d,0,sizeof(d));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			d[i][j]=t==1?d[i-1][j]+1:0;
		}
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		P s[205];
		s[0] = P(0,0);
		int top = 0;
		for(int j=1;j<=n+1;j++){
			while(d[i][j]<s[top].h){
				int k=s[top].h*(j-s[top].p);
				if(ans<k)ans=k;
				top--;
			}
			if(d[i][j]>s[top].h){
			    for(int z=s[top].h+1;z<=d[i][j];z++)
				    s[++top]=P(j,z);
		    }
	    }
	}
	printf("%d\n",ans);
	return 0;
}

	return 0;
}