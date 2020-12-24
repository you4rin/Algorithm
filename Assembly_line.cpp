#include<cstdio>
int a[102],b[102];
int t[2][102];
int dp[2][102];
int path[2][102];

void print(int idx,int n){
	if(!n)return;
	print(path[idx][n],n-1);
	printf("%d %d\n",idx+1,n);
}

int main(){
	int n;
	scanf("%d",&n);
	scanf("%d %d",a,b);
	scanf("%d %d",a+n+1,b+n+1);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	for(int i=1;i<n;++i)scanf("%d",t[0]+i);
	for(int i=1;i<n;++i)scanf("%d",t[1]+i);
	dp[0][1]=a[0]+a[1];
	dp[1][1]=b[0]+b[1];
	path[0][1]=0,path[1][1]=1;
	for(int i=2;i<=n;++i){
		if(dp[0][i-1]+a[i]>dp[1][i-1]+a[i]+t[1][i-1]){
			path[0][i]=1;
			dp[0][i]=dp[1][i-1]+a[i]+t[1][i-1];
		}
		else{
			path[0][i]=0;
			dp[0][i]=dp[0][i-1]+a[i];
		}
		if(dp[1][i-1]+b[i]>dp[0][i-1]+b[i]+t[0][i-1]){
			path[1][i]=0;
			dp[1][i]=dp[0][i-1]+b[i]+t[0][i-1];
		}
		else{
			path[1][i]=1;
			dp[1][i]=dp[1][i-1]+b[i];
		}
	}
	if(dp[0][n]+a[n+1]>dp[1][n]+b[n+1]){
		dp[0][n+1]=dp[1][n+1]=dp[1][n]+b[n+1];
		path[0][n+1]=path[1][n+1]=1;
	}
	else{
		dp[0][n+1]=dp[1][n+1]=dp[0][n]+a[n+1];
		path[0][n+1]=path[1][n+1]=0;
	}
	printf("%d\n",dp[0][n+1]);
	print(path[0][n+1],n);
}