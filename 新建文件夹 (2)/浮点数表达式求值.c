#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include"conio.h" 
typedef struct str{
	char *ch;
	int length;
}String;
typedef struct c{
	double t;
	struct c *next;
}*Linklist,Lnode;
typedef struct s{
	char ch;
	struct s *next;
}*arraylist,array;
int retu(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '(':
		case ')':return 0;			
	}
}
void init(String *s,int length)
{
	s->ch=(char *)malloc(sizeof(char)*(length+1));
	printf("请输入你想求的表达式:");
	getchar();
	gets(s->ch);
	s->length=strlen(s->ch);
} 
Linklist creat()
{
	Lnode *t=(Linklist)malloc(sizeof(Lnode));
	t->next=NULL;
	return t;
}
arraylist creat1()
{
	arraylist t=(arraylist)malloc(sizeof(array));
	t->next=NULL;
	return t;
}
int isempty(Linklist head)
{
	if(!head->next)return 1;
	
	return 0;
}
int empty(arraylist head)
{
	if(!head->next)return 1;
	return 0;
}
void push(char ch1,arraylist head)
{
	array *p=(arraylist)malloc(sizeof(array));
	p->ch=ch1;
	p->next=head->next;
	head->next=p;
}
void push1(double t1,Linklist head)
{
	Lnode *p=(Linklist)malloc(sizeof(Lnode));
	p->t=t1;
	p->next=head->next;
	head->next=p;
}
char gettop(arraylist head)
{
	if(head->next)return head->next->ch;
}
float pop(Linklist head)
{
	Lnode *p=head->next;
	float c=p->t;
	head->next=p->next;
	free(p);
	return c;
}
char pop1(arraylist head)
{
	array *p=head->next;
	char c=p->ch;
	head->next=p->next;
	free(p);
	return c;
}
void change(double t,double t1,char ch,double *result)
{
	switch(ch)
	{
		case '+':{
			*result=t+t1;
			break;
		}
		case '-':{
			*result=t1-t;
			break;
		}
		case '*':{
			*result=t1*t;
			break;
		}
		case '/':{
			*result=t1/t;
			break;
		}
		case '%':{
			*result=(int)t1%(int)t;
			break;
		}
	}
}
int issu(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':return 1;
		default:return 0;
	}
}
double process(String s)
{
	Linklist head=creat();
	arraylist head1=creat1();
	int i;
	for(i=0;i<s.length;i++)
	{
		if((empty(head1)&&isempty(head)&&s.ch[i]=='-')||(s.ch[i-1]=='('&&s.ch[i]=='-'))
		{
			double t=0;
			i++;
			int flag=0;
			int t2=-1;
			double t1=0;
			while(s.ch[i]=='.'||isdigit(s.ch[i])&&i<s.length)
			{
				if(s.ch[i]=='.')
					flag=1;
				else if(flag)
				{
					t1+=(s.ch[i]-48)*pow(10,t2);
					t2--;
				}
				else
				{
					t=t*10+s.ch[i]-48;
				}
				i++;
			}
			t+=t1;
			t=-t;
			i--;
			push1(t,head);
		}
		else if(s.ch[i]=='#')
		{
			double t=0;
			double t1=0;
			int flag=0;
			int t2=-1;
			i++;
			while(s.ch[i]=='.'||isdigit(s.ch[i])&&i<s.length)
			{
				if(s.ch[i]=='.')
					flag=1;
				else if(flag)
				{
					t1+=(s.ch[i]-48)*pow(10,t2);
					t2--;
				}
				else
				{
					t=t*10+s.ch[i]-48;
				}
				i++;
			}
			t+=t1;
			double t3=sqrt(t);
			push1(t3,head);
			i--;
		} 
		else if(s.ch[i]=='^')
		{
			double t=pop(head);
			int t1=0;
			i++;
			while(isdigit(s.ch[i]))
			{
				t1=t1*10+s.ch[i]-48;
				i++;
			}
			i--;
			t=pow(t,t1);
			push1(t,head);
		}
		else if(empty(head1)&&issu(s.ch[i]))
		{
			push(s.ch[i],head1);
		}
		else if(s.ch[i]=='(')
			push(s.ch[i],head1);
		else if(s.ch[i]==')')
		{
			double result=0;
			char t5=pop1(head1);
			while(t5!='(')
			{
				double t3=pop(head);
				double t4=pop(head);
				change(t3,t4,t5,&result);
				push1(result,head);
				t5=pop1(head1);
			}
		}
		else if(issu(s.ch[i]))
		{
			char t=gettop(head1);
			int t1=retu(t);
			int t2=retu(s.ch[i]); 
			if(t2>t1)push(s.ch[i],head1);
			else
			{
				char t5=pop1(head1);
				double t3=pop(head);
				double result=0;
				double t4=pop(head);
				change(t3,t4,t5,&result);
				push1(result,head);
				push(s.ch[i],head1);
			}
		}
		else if(isdigit(s.ch[i]))
		{
			double t=s.ch[i]-48;
			i++;
			int flag=0;
			int t2=-1;
			double t1=0;
			while(s.ch[i]=='.'||isdigit(s.ch[i])&&i<s.length)
			{
				if(s.ch[i]=='.')
					flag=1;
				else if(flag)
				{
					t1+=(s.ch[i]-48)*pow(10,t2);
					t2--;
				}
				else
				{
					t=t*10+s.ch[i]-48;
				}
				i++;
			}
			t+=t1;
			i--;
			push1(t,head);
		}
		else
		{
			printf("输入表达式格式错误，请重新输入\n");
			return 0.0;
		}
	}
	while(!isempty(head)&&!empty(head1))
	{
		double t1=pop(head);
		char t2=pop1(head1);
		double t3=pop(head);
		double result=0;
		change(t1,t3,t2,&result);
		push1(result,head);
	}
	return head->next->t;
}
int main()
{
	system("color a2");
	system("color 2");
	printf("\t\t\t\t\t------欢迎进入计算器模式----------\n");
	printf("\t\t\t输入1进入求值界面输入2退出计算器模式,为了方便起见用^代表幂次符号,用#代表根号:\n");
	int t;
	scanf("%d",&t);
	while(1)
	{
		switch(t)
		{
			case 1:{
				int length;
				String s;
				printf("请输入你可能输入表达式的最大长度:");
				scanf("%d",&length);
				init(&s,length);
				double t=process(s);
				if(t==(int)t)printf("\n输出结果%d\n",(int)t);
				else printf("\n输出结果%.3lf\n",t);
				free(s.ch);              /*释放内存*/ 
				break;
			}
			case 2: exit(0);
			default:printf("您输入了无效的指令,请重新输入\n");break;
		}	
		printf("\t\t\t\t\t输入1进入求值界面输入2退出计算器模式:\n");
		scanf("%d",&t);
	} 
}
