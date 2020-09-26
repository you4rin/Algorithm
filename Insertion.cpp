#include<cstdio>

int arr[30001];

void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",arr+i);
	for(int i=1;i<n;++i){
		for(int j=i-1;j>=0;--j){
			if(arr[j+1]>arr[j])swap(arr+j+1,arr+j);
			else break;
		}
	}
	for(int i=0;i<n;++i)printf("%d\n",arr[i]);
	return 0;
}