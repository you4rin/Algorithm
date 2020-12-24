#include<cstdio>
#define inf 1e9

int p[101];
int dp[101][101];
int last[101][101];

void print(int s,int e){
	if(s!=e)printf("( ");
	if(s==e)printf("%d ",s);
	else{
		print(s,last[s][e]);
		print(last[s][e]+1,e);
	}
	if(s!=e)printf(") ");
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;++i)scanf("%d",p+i);
	for(int i=1;i<=n;++i)dp[i][i]=0;
	for(int l=2;l<=n;++l){
		for(int i=1;i<=n-l+1;++i){
			int j=i+l-1;
			dp[i][j]=inf;
			for(int k=i;k<j;++k){
				if(dp[i][j]>dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]){
					dp[i][j]=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
					last[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	print(1,n);
}