# 程序功能：
1. 可用于命令或一些函数等的助记
2. 关键词查询录入过的数据( 支持多个关键词查询 )

# 使用方法
## C语言版本
0. 注意编译使用前请先将11行里的BakFilePath修改成你自己的文件路径
1. 编译 gcc Record.c -o Record
2. 运行 ./Record [option] [Message]
3. 将编译生成的Record复制到/usr/bin/rc, 重新启动终端即可在任意地方通过rc调用程序($ sudo cp ./Record /usr/bin/rc)  

## Python版本
0. 同样需要修改存储文件BakFilePath(第9行)
1. 直接用命令 python3 Record.py [option] [Message]运行
3. 录入, 查询, 列出功能仿造以下C语言版本示例即可 

# 示例
1. 录入信息: C/strstr() -- 提取文字中的字符串 -- strstr(str, KeyWord) -- #include <string.h>
* $ rc -n "C/strstr() -- 提取文字中的字符串 -- strstr(str, KeyWord) -- #include <string.h>"  


2. 查询
* $ rc -c "strstr"
* $ rc -c "提取 字符串"   #关键词间以空格区分  


3. 列出已录入信息和帮助
* $ rc -l
* $ rc -h

4. 打开记录文件
* $ rc -o
