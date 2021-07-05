#include "print.h"
// vscode编译多个源文件，打开settings.json文件，找到executorMap设置项，在其中添加
// "c":"cd $dir && gcc *.c -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
int main(void){
    printHello();
    return 0;
}