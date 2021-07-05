// 输入两个2个数，输出他们的乘积
#include<stdio.h>
int main(void){
    int x,y,result;
    printf("请输入两个数(中间以空格结束)：\n");
    scanf("%d%d",&x,&y);
    result = x * y;
    printf("%d * %d = %d",x,y,result);
    return 0;
}