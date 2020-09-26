#include<cstdio>

int heap[100001];

int main(){
	int n,k,tmp,idx,cnt=0,maxidx;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&tmp);
		idx=i;
		heap[idx]=tmp;
		while(heap[idx]>heap[idx/2]&&idx>1){
			tmp=heap[idx];
			heap[idx]=heap[idx/2];
			heap[idx/2]=tmp;
			idx/=2;
		}
		++cnt;
	}
	for(int i=1;i<=k;++i){
		printf("%d ",heap[1]);
		idx=1;
		heap[idx]=heap[cnt--];
		while(1){
			if(idx*2>cnt)break;
			if(idx*2==cnt)maxidx=idx*2;
			else maxidx=(heap[idx*2]>heap[idx*2+1]?idx*2:idx*2+1);
			if(heap[idx]>heap[maxidx])break;
			else{
				tmp=heap[idx];
				heap[idx]=heap[maxidx];
				heap[maxidx]=tmp;
				idx=maxidx;
			}
		}
	}
	printf("\n");
	for(int i=1;i<=cnt;++i)printf("%d ",heap[i]);
	return 0;
}