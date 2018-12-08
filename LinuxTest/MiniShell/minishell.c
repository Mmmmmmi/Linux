/*  这是一个迷你shell的程序
 *      1. 不断的等待接收键盘的输入（字符串）
 *      2. 解析字符串
 *          1. 是否有重定向符号
 *          2. 解析命令
 *      2. 创建子进程
 *      3. 程序替换
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main()
{
    while(1) {
        printf("minishell: ");
        fflush(stdout);
        char cmd[1024] = {0};
        if (scanf("%[^\n]%*c", cmd) != 1) {
            getchar();
        }

        if (fork() == 0) {
            //子进程程序替换 ls -l -a
            //int execvp(const char *file, char *const argv[]);
            //
            // ls -l >>   test.txt
            char *ptr = cmd;
            int is_redirect = 0;
            char *file = NULL;
            while(*ptr != '\0') {
                if (*ptr == '>') {
                    is_redirect++;
                    *ptr = '\0';
                    ptr++;
                    if (*ptr == '>') {
                        is_redirect++;
                        *ptr = '\0';
                        ptr++;
                    }
                    while(isspace(*ptr) && *ptr != '\0'){
                        ptr++;
                    }
                    file = ptr;
                }
                ptr++;
            }
            umask(0);
            int fd;
            if (is_redirect == 1) {
                fd = open(file, O_CREAT|O_WRONLY|O_TRUNC, 0664);
                dup2(fd, 1);
            }else if (is_redirect == 2) {
                fd = open(file, O_CREAT|O_WRONLY|O_APPEND, 0664);
                dup2(fd, 1);
            }

            //ls      -l   -a  
            ptr = cmd;
            char *argv[32] = {NULL};
            int argc = 0;
            while(*ptr != '\0'){
                if (!isspace(*ptr)) {
                    argv[argc] = ptr;
                    argc++;
                    //在这里必须判断是否字符串结尾
                    while(!isspace(*ptr) && *ptr != '\0') {
                        ptr++;
                    }
                }
                if (isspace(*ptr)) {
                    *ptr = '\0';
                    ptr++;
                    continue;
                }
            }
            execvp(argv[0], argv);
            exit(0);
        }
        //能够走下来就是父进程，父进程要等待子进程退出，
        //避免产生僵尸进程
        wait(NULL);
    }
    return 0;
}
