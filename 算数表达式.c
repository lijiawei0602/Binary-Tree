#include<stdio.h>
#include<stdlib.h>
typedef struct stackNode{
	char data;
	struct stackNode *next;
}linkStack;

//������ջ
linkStack *init(){
	linkStack *top = malloc(sizeof(linkStack));
	top->next = NULL;
	return top;
} 

//��ջ
void pushStack(linkStack *top,char x){
	linkStack *s = malloc(sizeof(linkStack));
	s->data = x;
	s->next = top->next;
	top->next = s;
} 

//��ջ
char popStack(linkStack *top){
	linkStack *s;
	char x;
	if(top->next == NULL)
		return NULL;
	s = top->next;
	top->next = s->next;
	x = s->data;
	free(s);
	return x;
}

//ȡ��ջ��Ԫ��
//char topStack(linkStack *top){
//	while(top->next != NULL){
//		top = top->next;
//	}
//	return top->data;
//} 

//��������ַ����е���������������ֿ� 
char* divideString(){
	char s[20][20];
	char a[50];
	int i=1,j=0,x=1,t;
	
	scanf("%s",&a);
	s[0][0] = a[0];

	if(a[0] == '(')
	{	
		while(a[x]){
			if(a[x]>='0' && a[x]<='9' || a[x]=='.'){
				s[i][j] = a[x];
				j++;
			}
			else{
				j = 0;
				s[i][j]= a[x];
				i++;
			}
			x++;
		}
//		for(t=0;t<=i;t++){
//			printf("%s",s[t]);
//		}
		return s;
	}
	
	if(a[0] >='0' && a[0]<= '9')
	{	
		while(a[x]){
			if(a[x] >='0' && a[x]<= '9'|| a[x] == '.'){
				j++;
				s[i-1][j] = a[x];
			}
			else{
				j = 0;
				i++;
				s[i-1][j] = a[x];
			}
			x++;
		}
//		for(t=0;t<i;t++){
//			printf("%s",s[t]);
//		}
		return s;
	}
}

//�Ƚ���������ȼ�
int compare(char a, char b)
{
	if(a == '(' && ( b== '+' || b == '-' || b == '*' || b == '/') )
		return 1;
	if((a == '+' || a== '-') && (b == '*' || b== '/'))
		return 1;
	return 0;
		
} 
void main(){
	linkStack *op = init();	//������ջ
	linkStack *num = init(); //������ջ
	char *s;
	int i=0;
	s = divideString(); 

	double t;
	char x[10];
	char m,n;
	while(*s){
		printf("%c",*s);
		s++;
	}
//	while(*s){
//		if(strlen(*s) == 1 && *s>= '0' && *s<='9')
//			if(i ==0){
//				pushStack(op,*s); 
//			}
//			else{
//				if(compare(op->next->data , *s)){
//					m = popStack(num);
//					n = popStack(num->next);
//					
//					if(*s == "+")
//						t = atof(m) + atof(n);
//					else if(*s == "-")
//						t = atof(m) - atof(n);
//					else if(*s == "*")
//						t = atof(m) * atof(n);
//					else if(*s == "/")
//						t = atof(m) / atof(n); 
//					pushStack(num,itoa(t,x,10));
//				}
//				else{
//					pushStack(op,*s);
//				}
//			}
//		else{
//			pushStack(num,*s);
//		}
//		*s++;
//	}
////	printf("\n%d",t);
//	printf("\n1223");
}
