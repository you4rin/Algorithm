#include<cstdio>
#define inf (int)(1e9+7)
int A[100001],B[100001];
int L[100001],R[100001];

void Merge(int* arr,int s,int m,int e){
	int n1=m-s+1,n2=e-m;
	for(int i=0;i<n1;++i)L[i]=arr[s+i];
	for(int i=0;i<n2;++i)R[i]=arr[m+i+1];
	L[n1]=R[n2]=inf;
	for(int i=s,j=0,k=0;i<=e;++i){
		if(L[j]<R[k])arr[i]=L[j++];
		else arr[i]=R[k++];
	}
}

void MergeSort(int* arr,int s,int e){
	if(s<e){
		int m=(s+e)/2;
		MergeSort(arr,s,m);
		MergeSort(arr,m+1,e);
		Merge(arr,s,m,e);
	}
}

int main(){
	int n,m,cnt=0,apos=0,bpos=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",A+i);
	for(int i=0;i<m;++i)scanf("%d",B+i);
	MergeSort(A,0,n-1);
	MergeSort(B,0,m-1);
	while(apos<n&&bpos<m){
		if(A[apos]>B[bpos])++bpos;
		else if(A[apos]<B[bpos])++apos;
		else{
			++cnt,++apos,++bpos;
		}
	}
	printf("%d",cnt);
	return 0;
}