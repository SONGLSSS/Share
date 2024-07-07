#include<stdio.h>  
#include<unistd.h>  
#include<stdlib.h>  
 void main() 
 {
    int   fd[2]    = {0};
    pid_t pid      = 0;
    char buf[100]  = {0};

    char string_data[100] = "父亲你在吃火锅吗？"；
    
    pipe(fd); //创建无名管道
    
    pid = fork(); //创建子进程
    
    if (pid == 0){
        close(fd[0]);
        write(fd[1], string_data, strlen(string_data));
        exit(0);
    }else if (pid > 0){
        close(fd[1]);
        read(fd[0], buf, strlen(string_data));
        printf("我是父亲进程，我收到了来自儿子的数据：%s/n",buf);
    }else{
    	printf("创建进程失败\n!");
    }
    exit(0);  
}

