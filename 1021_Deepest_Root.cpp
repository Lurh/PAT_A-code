#include <iostream>
#include <vector>
#include <queue>
#define MAX 10000
using namespace std;

bool has_visit[MAX+1];
bool isroot[MAX+1];
int max_len;
bool can;
struct node{
	int num;
	vector<node*> edge; 
	int depth;
	node()
	{
		num = 0;
		depth = 0;
	}
	node(int id)
	{
		num = id;
		depth = 0;
	}
};
node* deepest;
bool bfs(node* root,int N)
{
	queue<node*> graph;
	node* tmp;
	int i;
	graph.push(root);
	has_visit[root->num]=true; 
	while(!graph.empty())
	{
		tmp = graph.front();
		for(i=0;i<tmp->edge.size();i++)
			if(has_visit[tmp->edge[i]->num]==false)
			{
				graph.push(tmp->edge[i]);
				has_visit[tmp->edge[i]->num]=true;
			}
		graph.pop();
	}
	for(i=1;i<=N;i++)
		if(has_visit[i]==false)
			return false;
	return true;
}

void dfs(node* root,int depth, int N)
{
	bool done=true;
	depth++;
	for(int i=0;i<root->edge.size();i++)
		if(has_visit[root->edge[i]->num]==false)
		{
			done = false;
			break;
		}
	if(done)
	{
		if(max_len<=depth)
		{
			max_len =depth;
			deepest = root;
			root->depth = depth;
		}
		return;
	}
	for(int i=0;i<root->edge.size();i++)
		if(has_visit[root->edge[i]->num]==false)
		{
			has_visit[root->edge[i]->num]=true;
			dfs(root->edge[i],depth,N);
			has_visit[root->edge[i]->num]=false;
		}
			
	depth--;
	return;
}

int main()
{
	int N,i,j,n1,n2;
	node* q[MAX+1],tmp;
	cin>>N;
	max_len = 0;
	for(i=0;i<=N;i++)
	{
		q[i] = new node(i);
		has_visit[i]=false;
		isroot[i] = false;
	}
	for(i=1;i<N;i++)
	{
		cin>>n1>>n2;
		q[n1]->edge.push_back(q[n2]);
		q[n2]->edge.push_back(q[n1]);
	}
	bool iswhole;
	iswhole = bfs(q[1],N);
	if(iswhole)
	{
		
		for(i=1;i<=N;i++)
			has_visit[i] = false;
		has_visit[q[1]->num]=true;
		dfs(q[1],0,N);
		for(i=1;i<=N;i++)
		{
			if(q[i]->depth==max_len)
			{
				isroot[q[i]->num]=true;
				has_visit[q[i]->num]=true;
				for(j=1;j<=N;j++)
					has_visit[j] = false;
				dfs(q[i],0,N);
			}
		 }
		for(i=1;i<=N;i++)
		{
			if(q[i]->depth==max_len)
				isroot[q[i]->num]=true;
		}
		for(i=1;i<=N;i++)
			if(isroot[i])
				cout<<i<<endl;
	}
	else
	{
		int num = 1;
		for(i=1;i<N;i++)
		{
			if(has_visit[i]==false)
			{
				iswhole = bfs(q[i],N);
				num++;
			}	
		}
		cout<<"Error: "<<num<<" components"<<endl;
		return 0;
	}
}
