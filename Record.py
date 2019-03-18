#!usr/bin/env python3
#-*-coding:utf-8-*-

__author__ = 'Green'

import sys
import os

BakFilepath = '/home/magnolia/Dropbox/Backup/HelpMsg'

class error(Exception):
    def __init__(self, ErrorInfo):
        super().__init__(self) 
        self.errorinfo = ErrorInfo

    def __str__(self):
        return self.errorinfo

def PrintHelpMsg():
    print('Usage: python  %s [option] [Message]' % sys.argv[0])
    print()
    print('Example: [python %s -n "String"] <Insert "String" into BakFilepath' % sys.argv[0])
    print('\t [python %s -c "string1 string2"]' % sys.argv[0], end='')
    print('  <search each line in BakFilepath which contain strign1 & string2>')
    print('\t [python %s -l ] <List all lines in BakFilepath>' % sys.argv[0])
    print('\t [python %s -h] <Print this help messages>' % sys.argv[0])
    print()
    print('Note: commands are between []')


def checkStr():
    if not os.path.exists(BakFilepath):
        print("File doesn't exist")
        sys.exit()

    else:
        try:
            sys.argv.remove('-c')
        except ValueError as ve:
            pass
        
        found = 0

        with open(BakFilepath, "r") as f:
            for buf in f.readlines():
                args =  sys.argv[1].split(' ')
                flag = 1
                for x in args:
                    if buf.find(x) == -1:
                        flag = 0; break
                if flag:
                    found = 1
                    print(buf, end='')
    if not found:
        print('Not found')

def newLines():
    with open(BakFilepath, 'a+') as f:
        sys.argv.remove('-n')
        f.write(sys.argv[1] + '\n')
        print(sys.argv[1])
        

def listAll():
    sys.argv[1] = '\n'
    checkStr()


def main():
    flag = 0
    for arg in argv:
        if arg[0] == '-':

            flag = 1

            if len(arg) > 2:
                raise error('Error input parameter')
            if arg[1] in Funcdict:
                Funcdict[ arg[1] ]()
    if not flag:
        print('Need arguments')


if __name__ == '__main__':

    argv = sys.argv

    #构建参数和函数的对应关系
    Funcdict = { 'h':PrintHelpMsg,
                 'l':listAll, 
                 'n':newLines,
                 'c':checkStr }
    main()

