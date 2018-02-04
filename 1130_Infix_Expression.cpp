#include <iostream>
#include <vector>
using namespace std;
struct node {
    string val;
    int left, right;
};
vector<node> v;
int n, root = 1;
string dfs(int index) {
    if (index == -1) return "";
    if (v[index].right != -1) {
        v[index].val = dfs(v[index].left) + v[index].val + dfs(v[index].right);
        if (index != root) v[index].val = '(' + v[index].val + ')';
    }
    return v[index].val;
}
int main() {
    cin >> n;
    v.resize(n + 1);
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].val >> v[i].left >> v[i].right;
        if (v[i].left != -1) visit[v[i].left] = true;
        if (v[i].right != -1) visit[v[i].right] = true;
    }
    while (visit[root] == true) root++;
    cout << dfs(root) << endl;
    return 0;
}

/*#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#define MAX 25
using namespace std;

struct node{
	string ch;
	node *left,*right,*parent;
	node()
	{
		ch = "",left = NULL,right = NULL,parent = NULL;
	}
};

vector<string> seq;
int count=0;

void dfs(node *root,bool isleft)
{
	string tmp,tmp2;
	if(root->left!=NULL)
		dfs(root->left,1);
	if(root->left==NULL&&isleft)
		seq.push_back("("),count++;
	if(!seq.empty())
	tmp = seq.at(seq.size()-1);
	tmp2 = root->ch;
	if(!seq.empty())
		if(tmp!="("&&tmp!=")")
			if(tmp[0]<'0'&&tmp2[0]<'0')
				seq.push_back("("),count++;
	
	seq.push_back(root->ch);
	
	if(root->right==NULL&&!isleft)
		while(count!=0)
		seq.push_back(")"),count--;
	if(root->right!=NULL)
		dfs(root->right,0);
	return;
}

int main()
{
	int N,i,j,n1,n2;
	string ch;
	node *leaf[MAX],*tmp,*root=NULL;
	vector<string> ans;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		leaf[i]=new node;
	for(i=1;i<=N;i++)
	{
		tmp = leaf[i];
		cin>>ch;
		scanf("%d %d",&n1,&n2);
		tmp->ch=ch;
		if(n1!=-1)
			tmp->left=leaf[n1],leaf[n1]->parent=tmp;
		if(n2!=-1)
			tmp->right=leaf[n2],leaf[n2]->parent=tmp;
		//scanf("%c",&ch);
	}
	for(i=1;i<=N;i++)
		if(leaf[i]->parent==NULL)
		{
			root=leaf[i];
			break;
		}
	dfs(root,0);
	for(i=0;i<seq.size();i++)
		cout<<seq.at(i);
	//	printf("%c",seq.at(i));
	printf("\n");
	return 0;
}*/
