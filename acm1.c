#include<stdio.h>
#define MAXSIZE 100

//�������ṹ��
typedef struct Node{
	char data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree; 

//��չ�������д���������
BiTree create(){
	BiTree s;
	char ch;
	ch = getchar();
	if(ch == '#')
	{
		return NULL;		 
	}
	else{
		s = malloc(sizeof(BiTNode));
		s->data = ch;
		s->lChild = create();
		s->rChild = create();
		return s;
	}
}

//����ݹ����
void preOrder(BiTree root)
{
	if(root != NULL)
	{
		printf("%c",root->data);
		preOrder(root->lChild);
		preOrder(root->rChild);
	}
} 
 
 //����ݹ����
void inOrder(BiTree root)
 {
 	if(root != NULL)
 	{
 		inOrder(root->lChild);
 		printf("%c",root->data);
 		inOrder(root->rChild);
	}
} 
  
  //����ݹ����
void postOrder(BiTree root)
  {
  	if(root != NULL)
  	{
  		postOrder(root->lChild);
  		postOrder(root->rChild);
  		printf("%c",root->data);
	}
} 

//���Ҷ�ӽ��ĸ��� 
int printNum0(BiTree root)
{
	int nl,nr;
	if(root == NULL)
		return 0;
	if(root->lChild == NULL && root->rChild == NULL)
		return 1;
	nl = printNum0(root->lChild);
	nr = printNum0(root->rChild);
	return (nl+nr);
}
//���Ҷ�ӽ������
void printData(BiTree root)
{
	if(root == NULL)
		return;
	if(root->lChild ==NULL && root->rChild == NULL)
		printf("%c",root->data);
	printData(root->lChild);
	printData(root->rChild);
 } 
int n = 0;
//�����Ϊ1�Ľ��ĸ���
int printNum1(BiTree root)
{
	int nl,nr;
	if(root == NULL)
		return 0;
	if(root->lChild == NULL && root->rChild != NULL || root->lChild !=NULL && root->rChild == NULL)
		n++;
	printNum1(root->lChild);
	printNum1(root->rChild);
	return n;
}
int m = 0;
//�����Ϊ2�Ľ��ĸ���
int printNum2(BiTree root)
{
	int nl,nr;
	if(root ==NULL)
		return 0;
	if(root->lChild && root->rChild)
		m++;
	printNum2(root->lChild);
	printNum2(root->rChild);
	return m;
 } 
 
 int h = 1;
 //����ֵ����ʽ���
void printValue(BiTree root , int h)
{
	if(root != NULL)
	{
		printf("(%c,%d)",root->data,h);
	}
	if(root->lChild != NULL ||root->rChild !=NULL){
	
	printValue(root->lChild , h+1);
	printValue(root->rChild , h+1);
}
  }  

//����״��ӡ������
void printTree(BiTree root , int h)
{	int i;
	if(root == NULL)
		return;
	printTree(root->rChild , h+1);
	for(i = 0;i<h; i++)
	{
		printf(" ");
	}
	printf("%c\n",root->data);
	printTree(root->lChild , h+1);
 } 
 
void main(){
   	BiTree root;
   	root = create();
//   	printTree(root , 1);
   	//ǰ�����
//	preOrder(root);
//	printf("\n"); 
//	 �������
//	inOrder(root);
//	printf("\n");
//	�������
//	postOrder(root); 

//	int n0,n1,n2;
//	n0 = printNum0(root);
//	n1 = printNum1(root);
//	n2 = printNum2(root);
//	printf("%d %d %d\n",n0,n1,n2);
//	printData(root);

//	printValue(root ,h);
}
