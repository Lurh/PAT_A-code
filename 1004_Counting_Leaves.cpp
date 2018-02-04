#include <iostream>
#include <queue>
#include <string>
#define MAX 200
using namespace std;

int id2num(string id)
{
	int num=0;
	for(int i=0;i<id.length();i++)
		num=num*10+id[i]-'0';
	return num;//(id[0]-'0')*10+(id[1]-'0');
}
struct node{
	int id;
	int son_num,level;
	node *son_node[MAX];
	
	node()
	{
		id = 0;
		son_num=-1;
		level=-1;
		for(int i=0;i<MAX;i++)
			son_node[i]=NULL;
	}
	node(int id)
	{
		this->id = id;
		son_num=0;
		level=-1;
		for(int i=0;i<MAX;i++)
			son_node[i]=NULL;
	}
};
node *node_queue[MAX];
bool has_father[MAX];
int num_leaf[MAX];
queue<node*> search_queue;
int max_level=-1;

void bfs(node *root)
{
	int i;
	node *now;
	while(!search_queue.empty())
	{	
		now = search_queue.front();
		max_level = now->level;
		if(now->son_num==0)
			num_leaf[now->level]++;
		for(i=0;i<now->son_num;i++)
		{
			now->son_node[i]->level=now->level+1;
			search_queue.push(now->son_node[i]);
		}
		search_queue.pop();		
	}
}

int main()
{
	int i,j,N,M,K;
	string father_id,son_id;
	node *person,*tmp_son,*father;
	int tmp_id;
	for(i=0;i<MAX;i++)
	{
		node_queue[i]=NULL;
		has_father[i]=false;
		num_leaf[i]=0;
	}
		
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		cin>>father_id>>K;
		tmp_id = id2num(father_id);
		if(node_queue[tmp_id]==NULL)
		{
			person = new node(tmp_id);
			person->son_num=K;
			node_queue[tmp_id] = person;
		}
		else
		{
			person = node_queue[tmp_id];
			person->son_num=K;
		}
			
		
		for(j=0;j<K;j++)
		{
			cin>>son_id;
			tmp_id = id2num(son_id);
			has_father[tmp_id]=true;
			if(node_queue[tmp_id]==NULL)
			{
				tmp_son = new node(tmp_id);
				node_queue[tmp_id] = tmp_son;
				person->son_node[j] = tmp_son;
			}
			else
				person->son_node[j] = node_queue[tmp_id];
		}
	}
	for(i=1;i<=N;i++)
		if(has_father[i]==false)
		{
			father=node_queue[i];
			break;
		}
	father->level=0;
	search_queue.push(father);
	bfs(father);
	
	cout<<num_leaf[0];
	for(i=1;i<=max_level;i++)
	cout<<" "<<num_leaf[i];
	cout<<endl;
	for(i=1;i<=N;i++)
	delete node_queue[i];
	return 0;
}
