#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1001],b[1001];
int la,lb;

int compare(int len){
	for(int i=0;i<len;i++){
		if(a[i]!=b[lb-len+i])return 0;
	}
	return 1;
}

int main() {
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	int ans=0;
	for(int i=1;i<=la&&i<=lb;i++){
		if(compare(i))ans=i;
	}
	printf("%d\n",ans);
	return 0;
}