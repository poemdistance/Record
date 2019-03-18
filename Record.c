#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LEN ( 1024 * 4 )
#define Space ( ' ' )
typedef void (*Func)(FILE *, char *);

/*逐行读取匹配字符串，若包含输入的str，则打印出来*/
void 
check(FILE *fptr, char *str)
{
    char buf[ MAX_LEN ];
    char *p = NULL;
    char *start = NULL;
    char *end = NULL;
    int flag = 1;
    char tmp[ MAX_LEN ];
    char *EndAddr = 0;

    /*去除str末尾可能存在的空格*/
    p = str;
    while(*++p != '\0');
    if(*(p-1) == Space) {
        while(*--p == Space);
        *(p+1) = '\0';
    }

    strcpy(tmp, str);
    EndAddr = strlen(str) + str;

    while( fgets(buf, MAX_LEN, fptr) != NULL )
    {
        flag = 1;
        p = strcpy(str, tmp);
        while( end !=  EndAddr)
        {
            /*提取需匹配的关键字*/
            while( *( start = p++ ) == Space);
            while( *(end = p) != Space &&  *p++);
            *end = '\0';
            p = end + 1;

            if( strstr(buf, start) == NULL) {
                flag = 0;
                break;
            }
        }

        if( flag == 1 )
            printf("%s", buf);

        end = NULL;
        memset(buf, 0,  MAX_LEN);
    }
}

/*以行的形式将字符串str写入文件*/
void
new(FILE *fptr, char *str)
{
    printf("%s\n", str);
    fputs(str, fptr);
    fputs("\n", fptr);
}

/*print error message and exit*/
void error(char *str)
{
    printf("%s\n", str);
    exit(1);
}

/*提取输入的字符串，返回需要调用的函数*/
void 
GetStr( Func func, char *buf, char *str, int argc, FILE *fptr)
{
    if( argc < 3 )
        error("Lack of Message");
    strcpy( buf, str);
    func(fptr, buf);
}

Func GetHelpMsg(char *cmd)
{
    printf("Usage: command [option] [message]\n");
    printf("Example: [%s -n \"ls -- 列出文件列表 -- ls -lh\"]  : <Insert new line into your file>\n", cmd);
    printf("\t [%s -c \"列出 文件\"] :  <Search Messages which contain \'列出 & 文件\'>\n", cmd);
    printf("\t [%s -h]: <Print this help messages>\n", cmd);
    printf("\t [%s -l]: <List all messages in your file>\n", cmd);

    printf("\nNote: command are between []\n");
    exit(0);
    return NULL;
}

/*提取以‘-’开始的参数，不支持混合参数*/
void
extract_argv(int argc, char **argv, char *buf, FILE *fptr)
{
    for(int i=1; i<argc; i++)
    {
        if(argv[i][0] == '-' 
                && strlen( argv[i] ) == 2)
            switch(argv[i][1])
            {   
                case 'c': 
                    GetStr(check, buf, argv[argc-i], argc, fptr);

                case 'n':
                    GetStr(new, buf, argv[argc-i], argc, fptr);

                case 'l':
                    check(fptr, strcpy(buf, "\n")) ;

                case 'h':
                    GetHelpMsg(argv[0]);

                default:   error("Input error <switch>");
            }
    }
    error("Input error <after for loop>");
}

int main(int argc, char **argv)
{
    //printf("cmd/func     effect     example\n");

    if(argc < 2) {
        printf("Need arguments\n");
        return 0;
    }

    if(argc > 3) {
        printf("Error: too many Messages\n\n");
        GetHelpMsg(argv[0]);
        return 0;
    }

    /*请将下面的文件路径修改成你需要存放的地方*/
    char BakFilePath[] = "/home/magnolia/Dropbox/Backup/HelpDb";

    FILE *fptr = NULL;
    fptr = fopen(BakFilePath, "a+");
    assert( fptr != NULL );

    char buf[ MAX_LEN ];

    extract_argv(argc, argv, buf, fptr);

    fclose(fptr);

    return 0;
}
