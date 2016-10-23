#include<stdio.h>
typedef struct Node{
	int id;			//编号 
	int password;	//密码 
	struct Node *next;
}Node;

Node *createList(int n)
{	int i = 1;
	Node *H = malloc(sizeof(Node));
	H->next = H;
	Node *r = H;

	Node *s;

	while(i <= n)
	{	s = malloc(sizeof(Node));
		scanf("%d",&s->password);
		s->id = i;
		
		s->next = r->next;
		r->next = s;
		r = s;
		i++;
	}
	
	r->next = H;
	return H;
}

void search(Node *H, int m){		//报数上限值 
	Node *r = H->next; 		//*pCur 
	Node *t =NULL;		//*pDel
	Node *p = H->next;		//pPrv
	int flag = 1;
	int i;

	while(p->next != H){
		p = p->next;
	}
	while(flag){
		for(i=1; i<m; i++)
		{	p = r;
			r = r->next;
			if(r == H){
				r = H->next;
			}
		}
		if(p == r){
			flag = 0;
		} 
		t = r;						//记录被删除结点 
		p->next = r->next;
//		printf("%d ",r->id);
		
		m = r->password;
		r = r->next;
		if(p == t){
			printf("%d",t->id);
		}
		else
			printf("%d ",t->id);
		free(t);
	}
	H = NULL;
}

void main(){
	int n,password;
	scanf("%d %d",&n,&password);
	Node *H = createList(n);
	search(H , password);
}
