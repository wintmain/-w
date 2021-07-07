// 输入一个字符串式子
// 包含数字和字符，数字在0-9之内，字符不限但不能为‘#’
// 输出数字个字符，依次排列
// 例如输入1a2b3c#，输出a bb ccc #

#include<stdio.h>
int main(void){
    char ch,nch;
    int count,k;
    printf("请输入一个字符串，以#结尾。\n");
    scanf("%c",&ch);
    while (ch!='#')
    {   
        /* code */
        if (ch>='0' && ch<='9')
        {
            /* code */
            count = ch-'0';
            scanf("%c",&nch);
            for(k=0;k<count;k++){
                printf("%c",nch);
            }
        }
        else{
            printf("%c",ch);
        }
        printf(" ");
        scanf("%c",&ch);
        
    }
    printf("#\n");
}