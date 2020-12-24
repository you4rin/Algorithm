#include<cstdio>
#include<algorithm>
#define inf 1e9

using namespace std;

int arr[101];
int dp[101];
int len[101];
int rodlist[101];
int cnt=0;

void addlist(int n){
	if(len[n]==n){
		rodlist[cnt++]=n;
		return;
	}
	addlist(n-len[n]);
	rodlist[cnt++]=len[n];
}

int main(){
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",arr+i);
	for(int i=1;i<=n;++i){
		q=-inf;
		for(int j=1;j<=i;++j){
			if(q<arr[j]+dp[i-j]){
				q=arr[j]+dp[i-j];
				len[i]=j;
			}
		}
		dp[i]=q;
	}
	printf("%d\n",dp[n]);
	addlist(n);
	sort(rodlist,rodlist+cnt);
	for(int i=0;i<cnt;++i)printf("%d ",rodlist[i]);
	return 0;
}