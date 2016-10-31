#include <cstdio>
#include <cstring>
using namespace std;

struct P {
	int p,h;
	P(){}
	P(int x, int y) {
		p=x,h=y;
	}
} s[205];

int d[205][205];

int main() {
	int m,n,t;
	memset(d,0,sizeof(d));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			d[i][j]=t==1?d[i-1][j]+1:0;
		}
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		s[0] = P(0,0);
		int top = 0;
		for(int j=1;j<=n+1;j++){
			if(d[i][j]>s[top].h){
				s[++top]=P(j,d[i][j]);
			}
			else if(d[i][j]<s[top].h){
				while(d[i][j]<s[top].h){
				    int k=s[top].h*(j-s[top].p);
				    if(ans<k)ans=k;
				    top--;
				    if(s[top].h<d[i][j])
				        s[++top]=P(j,d[i][j]);
				}
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}