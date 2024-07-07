#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>


extern int errno;

int main(){
	char send[128] = {0};
	char recv[128] = {0};
	char *test=NULL;
	int server_fd,ret;
	
	struct sockaddr_in server_address;
    	bzero(&server_address,sizeof(struct sockaddr_in));
	server_fd = socket(AF_INET,SOCK_STREAM,0);	

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(8888);

	server_fd = socket(AF_INET,SOCK_STREAM,0);
	ret = connect(server_fd,(struct sockaddr *)&server_address,sizeof(server_address));
	if(-1 == ret){
		printf("connected failed !\r\n");
		printf("return:%d\n",ret);
		fprintf(stderr, "Value of error: %d\n", errno);
		fprintf(stderr, "ERROR: %s\n", strerror(errno));
		return -1;
	}else{
		printf("Connected success.\n");
		ret = read(server_fd, recv,sizeof(recv));

		if(-1 == ret){
			printf("read fail!\r\n");
			printf("return:%d\n",ret);
			fprintf(stderr, "Value of error: %d\n", errno);
			fprintf(stderr, "ERROR: %s\n", strerror(errno));
			return -1;
		}else{
		  	printf("[Server]: %s\n", recv);
		}
		
	}
	do{	
		memset(recv,0,sizeof(recv));
		printf("Waiting for server...\n");
		ret = read(server_fd, recv,sizeof(recv));

		if(-1 == ret){
			printf("read fail!\r\n");
			printf("return:%d\n",ret);
			fprintf(stderr, "Value of error: %d\n", errno);
			fprintf(stderr, "ERROR: %s\n", strerror(errno));
			return -1;
		}else{
		  	printf("[Server]: %s\n", recv);
		}
		
		printf("Please enter what what you want to send:\n");
		//scanf("%s",send);
		gets(send);		
		ret = write(server_fd,send,strlen(send));
		
		if(-1 == ret){
			printf("Write fail!\r\n");
			printf("return:%d\n",ret);
			fprintf(stderr, "Value of error: %d\n", errno);
			fprintf(stderr, "ERROR: %s\n", strerror(errno));
			return -1;
		}else{
			printf("Send success.\n");		
		}
		memset(send,0,sizeof(send));
		memset(recv,0,sizeof(recv));
	}while(1);
	printf("Connection terminated.\n");
	
	return 0;
}
