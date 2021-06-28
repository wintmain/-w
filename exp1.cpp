// 题目
// 输入一行C语言程序，识别出其中的函数调用，输出调用的函数名和实参名。 输入的C语言程序符合下列要求： 
// 1、该行程序是函数体内的一条可执行语句，符合C语言语法要求；
// 2、实参只是简单的变量，不会是常量、表达式、数组元素、结构变量的成员等； 
// 3、该行程序有可能是控制语句，可能的控制结构只有if、for、while三种情况；
// 4、该行程序中有可能有空格等空白符。假设该行程序字符数不超过100。

#include<stdio.h>
#include<string.h>
bool is_illegal(char ch);
bool is_control(char *temp);
void reverse(char *str);
int main(void)
{
	char text[100];
	char temp[100];
	int i,j,x=0;
	gets(text);
	for(i=0;text[i]!='\0';i++){
		if(text[i]=='('){
			for(j=i-1;j>=0;j--){
				if(is_illegal(text[j])==true)
					break;
				if(text[j]!=' ')
					temp[x++]=text[j];
			}
			temp[x]='\0';
			x=0;
			reverse(temp);
			if(is_control(temp)==false){
				printf("%s ",temp);
				for(j=i+1;text[j]!='\0';j++){
					if(text[j]!=' '&&text[j]!=','&&text[j]!=')')
						printf("%c",text[j]);
					else
					if(text[j]==',')
						printf(" ");
					else
					if(text[j]==')'){
						printf(" ");
						break;
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
bool is_illegal(char ch){
	if(ch=='='||ch=='-'||ch=='+'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='&')
		return true;
	else
		return false;
}
bool is_control(char *temp){
	if(strcmp(temp,"if")==0||strcmp(temp,"while")==0||strcmp(temp,"for")==0)
		return true;
	else
		return false;
}
void reverse(char *str){
	int p,q;
	char t;
	p=0,q=strlen(str)-1;
	while(p<q){
		t=str[p],str[p]=str[q],str[q]=t;
		p++;
		q--;
	}
}
