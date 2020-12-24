//2019027001_¹®¼®¿ø_11802
#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct huffman_tree{
	string contents;
	int size;
	struct huffman_tree* left;
	struct huffman_tree* right;
};

pair<int,huffman_tree*> final_tree;
priority_queue<pair<int,huffman_tree*>, vector<pair<int,huffman_tree*> >, greater<pair<int,huffman_tree*> > > pq;

int ans;

void dfs(huffman_tree* p, int level){
	if(p->left){
		dfs(p->left,level+1);
		dfs(p->right,level+1);
		return;
	}
	ans+=level*p->size;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, size, tmp, bits=0,tot;
	string s;
	cin>>n;
	for(tmp=n-1; tmp; tmp=tmp>>1)bits++;
	if(n==1)bits++;
	for(int i=0;i<n;++i){
		huffman_tree* a=new huffman_tree;
		cin>>s>>size;
		a->size=size;
		a->contents=s;
		a->left=NULL;
		a->right=NULL;
		pq.push({size,a});
	}
	cin>>tot;
	cout<<tot*bits<<'\n';
	while(pq.size()!=1){
		pair<int,huffman_tree*> l,r;
		l=pq.top();pq.pop();
		r=pq.top();pq.pop();
		huffman_tree* p=new huffman_tree;
		p->left=l.second;
		p->right=r.second;
		p->size=l.first+r.first;
		pq.push({p->size,p});
	}
	final_tree=pq.top();pq.pop();
	dfs(final_tree.second,0);
	cout<<ans;
}