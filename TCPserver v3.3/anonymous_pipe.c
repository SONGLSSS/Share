#include<stdio.h>  
#include<unistd.h>  
#include<stdlib.h>  
 void main() 
 {
    int   fd[2]    = {0};
    pid_t pid      = 0;
    char buf[100]  = {0};

    char string_data[100] = "�������ڳԻ����"��
    
    pipe(fd); //���������ܵ�
    
    pid = fork(); //�����ӽ���
    
    if (pid == 0){
        close(fd[0]);
        write(fd[1], string_data, strlen(string_data));
        exit(0);
    }else if (pid > 0){
        close(fd[1]);
        read(fd[0], buf, strlen(string_data));
        printf("���Ǹ��׽��̣����յ������Զ��ӵ����ݣ�%s/n",buf);
    }else{
    	printf("��������ʧ��\n!");
    }
    exit(0);  
}

