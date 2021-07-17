// 输入共n+1行。
// 第一行包含用空格分隔的三个整数 n、x和y，表示检测点总数和市民所在位置。
// 第二行到第 n+1行依次输入n个检测点的坐标。包含用空格分隔的两个坐标整数

// 输出共三行，按距离从近到远，依次输出距离该市民最近的三个检测点编号。

#include<stdio.h>
#include<math.h>
# define MAX 10000
int main(void){
    int n,x,y,j;//输入格式
    int flag=1;
    scanf("%d%d%d",&n,&x,&y);
    int s[200][2];
    int a[3];//s放坐标，a储存三个最小距离
    float t[200];//n个坐标对应n个距离
    for(int i=0;i<n;i++){
        scanf("%d%d",&s[i][0],&s[i][1]);//输入坐标
    }

    for(int i=0;i<n;i++){
        t[i]=pow((x-s[i][0]),2)+pow((y-s[i][1]),2);//计算距离
    }

    // 注释没有成功，但是思路应该是对的，也就是三次循环距离数组，每次找到最小值的下标，把距离值变成一个很大的值继续遍历
    // for(int i=0;i<3;i++){//找三个
    //     float min=t[0];
    //     for(j=0;j<n;j++){          
    //         if(t[j]<min){
    //             flag++;
    //             min=t[j];//循环一遍，找到最小值，赋给a[i]
    //         }
    //         // printf("%f",min);       
    //    }      
    //     // printf("%d",flag);
    //    a[i]= flag;//找到的编号必定在其中
    //    t[flag-1]= MAX;//将t[flag]变成一个很大的值     
    // }
    
    for(int i=0;i<3;i++)
	{
		j=0;
		for(;t[j]==-1;j++) ;
		for(int k=j+1;k<n;k++){
			if(t[k]==-1) continue;
			if(t[k]<t[j]) j=k;
		}
	a[i]=j+1;
	t[j]=-1;
	}

    //输出
    for(int i=0;i<3;i++){
       printf("%d\n",a[i]); 
    }
	
    return 0;
}