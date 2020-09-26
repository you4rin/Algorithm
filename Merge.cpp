#include<cstdio>
#define inf (int)(-1e9-7)

int arr[100001];
int L[100001],R[100001];

void Merge(int s,int m,int e){
	int n1=m-s+1,n2=e-m;
	for(int i=0;i<n1;++i)L[i]=arr[s+i];
	for(int i=0;i<n2;++i)R[i]=arr[m+i+1];
	L[n1]=R[n2]=inf;
	for(int i=s,j=0,k=0;i<=e;++i){
		if(L[j]>R[k])arr[i]=L[j++];
		else arr[i]=R[k++];
	}
}

void MergeSort(int s,int e){
	if(s<e){
		int m=(s+e)/2;
		MergeSort(s,m);
		MergeSort(m+1,e);
		Merge(s,m,e);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",arr+i);
	MergeSort(0,n-1);
	for(int i=0;i<n;++i)printf("%d\n",arr[i]);
}