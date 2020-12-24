#include<cstdio>
#include<queue>

using namespace std;

int arr[1001];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;

int Find(int x){
	return arr[x]=(arr[x]==x?arr[x]:Find(arr[x]));
}

void Union(int x,int y){
	if(Find(x)!=Find(y))arr[Find(x)]=Find(y);
}

int main(){
	int n,m,cnt=1,s,e,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)arr[i]=i;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&s,&e,&w);
		if(s>e)pq.push({w,{e,s}});
		else pq.push({w,{s,e}});
	}
	printf("%d\n",n-1);
	while(cnt!=n){
		pair<int,pair<int,int> > a = pq.top();
		pq.pop();
		if(Find(a.second.first)!=Find(a.second.second)){
			Union(a.second.first,a.second.second);
			cnt++;
			printf("%d %d %d\n",a.second.first,a.second.second,a.first);
		}
	}
}