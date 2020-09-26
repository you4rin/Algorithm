#include<cstdio>

int heap[100001];

void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}

int main(){
	int tmp,idx,cnt=0,maxidx;
	while(1){
		scanf("%d",&tmp);
		if(!tmp)break;
		if(tmp==1){
			scanf("%d",&tmp);
			idx=++cnt;
			heap[idx]=tmp;
			while(heap[idx]>heap[idx/2]&&idx>1){
				swap(heap+idx,heap+idx/2);
				idx/=2;
			}
		}
		else if(tmp==2){
			printf("%d ",heap[1]);
			idx=1;
			heap[idx]=heap[cnt--];
			while(1){
				if(idx*2>cnt)break;
				if(idx*2==cnt)maxidx=idx*2;
				else maxidx=(heap[idx*2]>heap[idx*2+1]?idx*2:idx*2+1);
				if(heap[idx]>heap[maxidx])break;
				else{
					swap(heap+idx,heap+maxidx);
					idx=maxidx;
				}
			}
		}
		else if(tmp==3){
			scanf("%d %d",&idx,&tmp);
			if(heap[idx]<tmp){
				heap[idx]=tmp;
				while(heap[idx]>heap[idx/2]&&idx>1){
					swap(heap+idx,heap+idx/2);
					idx/=2;
				}
			}
			else{
				heap[idx]=tmp;
				while(1){
					if(idx*2>cnt)break;
					if(idx*2==cnt)maxidx=idx*2;
					else maxidx=(heap[idx*2]>heap[idx*2+1]?idx*2:idx*2+1);
					if(heap[idx]>heap[maxidx])break;
					else{
						swap(heap+idx,heap+maxidx);
						idx=maxidx;
					}
				}
			}
		}
	}
	printf("\n");
	for(int i=1;i<=cnt;++i)printf("%d ",heap[i]);
	return 0;
}