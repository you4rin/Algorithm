#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct Node{
	bool visit;
	bool end;
	int indeg;
	vector<int> v;
};

bool flag=false;
Node arr[1001];
stack<int> ans;

void dfs(int x){
	sort(arr[x].v.begin(),arr[x].v.end());
	for(vector<int>::iterator it=arr[x].v.begin();it!=arr[x].v.end();++it){
		arr[*it].indeg--;
		if(arr[*it].visit&&!arr[*it].end){
			flag=true;
		}
		if(!arr[*it].visit){
			arr[*it].visit=true;
			dfs(*it);
		}
	}
	ans.push(x);
	arr[x].end=true;
}

int main(){
	int n,m,s,e;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		arr[i].visit=false;
		arr[i].end=false;
		arr[i].indeg=0;
	}
	for(int i=0;i<m;++i){
		scanf("%d %d",&s,&e);
		arr[s].v.push_back(e);
		arr[e].indeg++;
	}
	for(int i=1;i<=n;++i){
		if(!arr[i].visit){
			arr[i].visit=true;
			dfs(i);
		}
	}
	if(flag)printf("0\n");
	else{
		printf("1\n");
		for(int i=0;i<n;++i){
			printf("%d ",ans.top());
			ans.pop();
		}
		printf("\n");
	}
}