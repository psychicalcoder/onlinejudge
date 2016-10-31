#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[1001],s[1001],d[1001][1001];

int sum(int l, int r){
	if(l==0)return s[r];
	return s[r]-s[l-1];
}

int _dp(int l, int r) {
	return sum(l, r)-d[l][r];
}

int main(){
	scanf("%d",&n);
	memset(d,-1,sizeof(d));
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		d[i][i]=a[i];
		s[i]=i==0?a[i]:s[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			d[j][i]=max(_dp(j+1,i)+a[j],_dp(j,i-1)+a[i]);
		}
	}
	printf("%d %d\n",d[0][n-1],_dp(0,n-1));
	return 0;  
}