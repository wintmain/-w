// 输入两个浮点数，输出它们中的大数 
#include <stdio.h>
int main(void){
    float x,y,result;
    printf("请输入两个小数（中间以,区分）:\n");
    scanf("%f,%f",&x,&y);
    if(x>y){
        result = x;
        printf("(%f,%f)中较大的数是：%f",x,y,result);
    }
    else if(y>x){
        result = y;
        printf("(%f,%f)中较大的数是：%f",x,y,result);
    }
    else{
        result=x;
        printf("%f和%f一样大",x,y);
    }
    return 0;    
}