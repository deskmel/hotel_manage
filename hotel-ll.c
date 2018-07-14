#include <stdio.h>
#include "hotel.h"
#include <malloc.h>
#include <string.h>
PNode createlist()
{
	int len;
	char content[30];
	PNode Phead = (PNode) malloc(sizeof(Node));
	if (Phead==NULL)
	{
		printf("Failed to allocate the space !\n");
		exit(-1);
	}
	PNode PTail = Phead;
	PTail->next=NULL;
	return Phead;
}
void addnode(PNode n,char content[30])
{

	PNode newNode=(PNode) malloc(sizeof(Node));
	strcpy(newNode->content,content);
	newNode->next=n->next;
	n->next=newNode;
}
void deleteNode(PNode n)
{
	if (!n)
	{
		return;
	}
	if (n->next!=NULL)
	{
		PNode q=n->next;
		n->next=q->next;
	}
}
PNode searchNode(PNode head,const char *value,int len)
{
	PNode p=head->next;
	while (p!=NULL)
	{
		bool flag=true;
		for (int i=0;i<len;i++)
		{
			if (value[i]!=p->content[i])
			{
				flag=false;
				break;
			}
		}
		if (flag)
			return p;
		p=p->next;
	}
	return NULL;
}