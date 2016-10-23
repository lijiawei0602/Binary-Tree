#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a;
	int b;
	struct node *next;
}lNode, *linkList;

linkList create(){
	int n;
	int i=1;
	char t1,t2,t3;
	
	linkList r;
	linkList H = (linkList)malloc(sizeof(lNode));
	H->next = NULL;
	r = H;
	scanf("%d",&n);
	fflush(stdin);
	
	while(i <= n){
		linkList s = (linkList)malloc(sizeof(lNode));
		scanf("%c%d%c%d%c",&t1,&s->a,&t2,&s->b,&t3);
		fflush(stdin);
		
		s->next = r->next; 
		r->next = s;
		r = s;
		
		i++;
	}
	r->next = NULL;
	return H;
} 
//输出
void out(linkList H){
	linkList p = H->next;
	int flag =1;
	while(p)
	{
		if(p->a > 0 && flag != 1)
		{
			printf("+");
		}
		if(p->a != 1 && p->a !=-1)
		{
			printf("%d",p->a);
			if(p->b ==1){
				printf("X");
			}
			if(p->b > 1){
				printf("X^%d",p->b);
			}
//			if(p->b == 0)
//			{
//				printf("1");
//			}
		}
		else{
			if(p->a == 1){
				if(p->b == 0){
					printf("1");
				}
				else if(p->b == 1){
					printf("X");
				}
				else{
					printf("X^%d",p->b);
				}
			}
			if(p->a == -1){
				if(p->b == 0){
					printf("-1");
				}
				else if(p->b == 1){
					printf("-X");
				}
				else{
					printf("-X^%d",p->b);
				}
			}
		}
		p = p->next;
		flag++;
	}
} 
//相加 
linkList add(linkList l1, linkList l2)
{
	linkList p1 = l1->next;
	linkList p2 = l2->next;
	linkList h3,p3,s;
	
	p3 = malloc(sizeof(lNode));
	p3->next = NULL;
	h3 = p3;
	
	while(p1 != NULL && p2 != NULL)
	{
		s = malloc(sizeof(lNode));
		if(p1->b < p2->b)
		{
			s->a = p1->a;
			s->b = p1->b;
			p1 = p1->next;
		}
		else if(p1->b > p2->b)
		{
			s->a = p2->a;
			s->b = p2->b;
			p2 = p2->next;
		}
		else
		{
			s->a = p1->a + p2->a;
			s->b = p1->b;
			p1 = p1->next;
			p2 = p2->next;
		}
		if(s->a != 0)
		{
			s->next = p3->next;
			p3->next = s;
			p3 = s;
		}
		else 
		
			free(s);
	}
	
	while(p1 != NULL)
	{
		s = malloc(sizeof(lNode));
		s->a = p1->a;
		s->b = p1->b;
		p1 = p1->next;
		s->next = p3->next;
		p3->next = s;
		p3 = s; 
	}
	while(p2 != NULL)
	{
		s = malloc(sizeof(lNode));
		s->a = p2->a;
		s->b = p2->b;
		p2 = p2->next;
		s->next = p3->next;
		p3->next = s;
		p3 = s; 
	}
	return h3;
} 

//相减 
linkList sub(linkList l1 , linkList l2){
	linkList h = l2;
	linkList p = l2->next;
	linkList q;
	while(p){
		p->a *= -1;
		p = p->next;
	}
	q = add(l1,h);
	for(p=h->next;p;p=p->next)
	{
		p->a *= -1;
	}
	return q;
}

//求导 
linkList derivative(linkList l1){

	linkList h = l1->next;
	linkList p3,h3,s;
	
	p3 = malloc(sizeof(lNode));
	p3->next = NULL;
	h3 = p3;
	
	while(h != NULL)
	{	s = malloc(sizeof(lNode));
		if(h->b == 0)
		{
			s->a = 0;
			h=h->next;
		}
		else
		{
			s->a = h->a * h->b;
			s->b = h->b - 1;
			h=h->next;
		}
		if(s->a != 0)
		{
			s->next = p3->next;
			p3->next = s;
			p3 = s;
		}
		else
		{
			free(s);
		}
	}
	return h3;
}

//相乘 
linkList mul(linkList l1 , linkList l2){
	linkList H1;
	linkList H2;
	linkList s;
	linkList l3 = malloc(sizeof(lNode));
	l3->next = NULL;
	
	for(H1=l1->next;H1!=NULL;H1=H1->next)
	{
		for(H2=l2->next;H2!=NULL;H2=H2->next)
		{
			s = malloc(sizeof(lNode));
			s->a = H1->a * H2->a;
			s->b = H1->b + H2->b;
			
			s->next = l3->next;
			l3->next = s;
		}
	 }
	 sort(l3)
	 return l3;
}

//排序
linkList sort(linkList H){
	int i,j;
	linkList h1;
	linkList h2;
	
	for(h1=H->next;h1!=NULL;h1=h1->next)
	{
		for(h2=H->next;h2!=NULL;h2=h2->next)
		{
			if(h2->b > h2->next->b){
				i = h2->a;
				h2->a = h2->next->a;
				h2->next->a = i;
				j = h2->b;
				h2->b = h2->next->b;
				h2->next->b = j; 
			}
		}
	}
	return H;
} 
void main(){
	linkList H1 = create();
	linkList H2 = create();
//	while(H1->next !=NULL){
//		printf("%d  ",H1->next->a);
//		H1=H1->next;
//	}
	linkList H = mul(H1,H2);
	out(H);
}
