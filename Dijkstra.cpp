#include<cstdio>
#include<queue>
#include<vector>
#define inf 1e9

using namespace std;

vector<pair<int,int> > edge[5001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int dist[5001];

int main(){
	int n,m,s,e,w,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)dist[i]=(i==1?0:inf);
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&s,&e,&w);
		edge[s].push_back({e,w});
	}
	pq.push({0,1});
	while(!pq.empty()){
		pair<int,int>a=pq.top();
		pq.pop();
		for(vector<pair<int,int> >::iterator it=edge[a.second].begin();it!=edge[a.second].end();++it){
			if(dist[it->first]>dist[a.second]+it->second){
				dist[it->first]=dist[a.second]+it->second;
				pq.push({dist[it->first],it->first});
			}
		}
	}
	for(int i=1;i<=n;++i)ans=(ans>dist[i]?ans:dist[i]);
	printf("%d\n",ans);
}