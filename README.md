# 程序功能：
1. 可用于命令或一些函数等的助记
2. 关键词查询录入过的数据( 支持多个关键词查询 )

# 使用方法
1. 编译 gcc Record.c -o Record
2. 运行 ./Record [option] [Message]

# 示例
1. 录入信息: C/strstr() -- 提取文字中的字符串 -- strstr(str, KeyWord) -- #include <string.h>
* $ ./Record -n "C/strstr() -- 提取文字中的字符串 -- strstr(str, KeyWord) -- #include <string.h>"

2. 查询
* $ ./Record -c "strstr"
* $ ./Record -c "提取 字符串"   #关键词间以空格区分

3. 列出已录入信息和帮助
* $ ./Record -l
* $ ./Record -h
