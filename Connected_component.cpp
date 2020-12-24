#include <cstdio>
#include <vector>

using namespace std;

struct Node{
	bool visit;
	vector<int> v;
};

Node arr[1001];

void dfs(int x){
	for(vector<int>::iterator it=arr[x].v.begin();it!=arr[x].v.end();++it){
		if(!arr[*it].visit){
			arr[*it].visit=true;
			dfs(*it);
		}
	}
}

int main(){
	int n,m,s,e,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d %d",&s,&e);
		arr[s].v.push_back(e);
		arr[e].v.push_back(s);
	}
	for(int i=1;i<=n;++i)arr[i].visit=false;
	for(int i=1;i<=n;++i){
		if(!arr[i].visit){
			ans++;
			dfs(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}