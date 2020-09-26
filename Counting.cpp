#include<cstdio>
int arr[100001];
int q[100001][2];

int main(){
	int n,m,k,tmp;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;++i)scanf("%d %d",&q[i][0],&q[i][1]);
	for(int i=0;i<n;++i){
		scanf("%d",&tmp);
		arr[tmp]+=1;
	}
	for(int i=2;i<100001;++i)arr[i]+=arr[i-1];
	for(int i=0;i<k;++i)printf("%d\n",arr[q[i][1]]-arr[q[i][0]-1]);
	return 0;
}