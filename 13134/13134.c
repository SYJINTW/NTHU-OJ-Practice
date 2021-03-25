#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	char *c;
	struct _Node *nxt;
	struct _Node *lst;
}Node;

Node *NodeList[100005], *temp;
int n, a, b, c, t;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n+1; i++)
	{
		scanf("%d", &a);
		NodeList[i] = (Node*)malloc(sizeof(Node));
		NodeList[i]->nxt = NULL;
		NodeList[i]->lst = NULL;
		// Run if a != 0
		if(a)
		{
			NodeList[i]->nxt = (Node*)malloc(sizeof(Node));
			NodeList[i]->nxt->c = (char*)malloc(sizeof(char)*(a+1));
			NodeList[i]->nxt->nxt = NULL;
			NodeList[i]->lst = NodeList[i]->nxt;
			scanf("%s", NodeList[i]->nxt->c);
		}
	}
	// Change
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d",&c,&a,&b);
		// a move to the front of b
		if(c==1 && NodeList[a]->nxt)
		{
			if(NodeList[b]==NULL) NodeList[b]->lst = NodeList[a]->lst;
			NodeList[a]->lst->nxt = NodeList[b]->nxt;
			NodeList[b]->nxt = NodeList[a]->nxt;
			NodeList[a]->nxt = NULL;
			NodeList[a]->lst = NULL;
		}
		// a move to the end of b
		if(c==2 && NodeList[a]->nxt)
		{
			if(NodeList[b])
			{
				// b have string
				NodeList[b]->lst->nxt = NodeList[a]->nxt;
				NodeList[b]->lst = NodeList[a]->lst;
				NodeList[a]->nxt = NULL;
				NodeList[a]->lst = NULL;
			}
			else
			{
				// b don't have string
				NodeList[b]->nxt = NodeList[a]->nxt;
				NodeList[b]->lst = NodeList[a]->lst;
				NodeList[a]->nxt = NULL;
				NodeList[a]->lst = NULL;
			}
		}
		if(c==3)
		{
			temp = NodeList[a]->nxt;
			NodeList[a]->nxt = NodeList[b]->nxt;
			NodeList[b]->nxt = temp;

			temp = NodeList[a]->lst;
			NodeList[a]->lst = NodeList[b]->lst;
			NodeList[b]->lst = temp;
		}

	}


	// Output
	for(int i = 1; i < n+1; i++)
	{
		if(NodeList[i]->nxt != NULL)
		{
			temp = NodeList[i]->nxt;
			while(temp!=NULL)
			{
				printf("%s", temp->c);
				temp = temp->nxt;
			}
		}
		printf("\n");
	}
}
