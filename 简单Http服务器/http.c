#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define IPADDR "127.0.0.1" 	// 	��������IP��ַ
#define PORT 80 			// 	httpĬ�϶˿�Ϊ80 
#define SIZE 100 			//	���ջ������Ĵ�С
//�����׽���
int create_socket(); 

int main()
{
	//��ȡ�������׽��������� 
	int sockfd = create_socket();
	assert(sockfd != -1);
	while (1)
	{
		struct sockaddr_in caddr;
		int len = sizeof(caddr);
		//����������
		int c = accept(sockfd, (struct sockaddr*) & caddr, (socklen_t *)&len);
		//���������������ѭ������
		if (c <= 0) 
		{
			continue;
		}
		char buff[SIZE] = { 0 };
		int n = recv(c, buff, SIZE - 1, 0);
		printf("recv(%d):\%s\n", n, buff);

		//HTTP�����ĵĹ���
		char* s = strtok(buff, " ");
		if (s == NULL)
		{
			close(c);
			continue;
		}
		//�õ�method����
		printf("method:%s\n", s);
		s = strtok(NULL, " ");

		//������תĿ��URL
		char path[128] = { "/home/JZF/Desktop/mycode/http" };
		if (strcmp(s, "/") == 0)
		{
			/���û��Ŀ��URL �򷵻�Ĭ�ϵ�ҳ��
			strcat(path, "/index.html"); 
		}
		else
		{
			//�����Ŀ��URL �������Ŀ��ҳ�淵�� 
			strcat(path, s); 
		}
		//��Ŀ����Դ�ļ�
		int fd = open(path, O_RDONLY);
		//����򿪴��� �򱨳�404�������Ӧ����
		if (fd == -1)
		{
			char err_buff[256] = { "HTTP/1.1 404 Not Found\r\n" };
			strcat(err_buff, "Server: myhttp\r\n");
			strcat(err_buff, "Content-Length: 3\r\n");
			strcat(err_buff, "\r\n");
			strcat(err_buff, "404\r\n");
			
			//�������ķ��ؿͻ���
			send(c, err_buff, strlen(err_buff), 0);
			close(c);
			continue;
		}
		//����ɹ�ʱ����200
		//���ļ�ָ�붨λ���ļ�ĩβ��ȡ�ļ���С�����ص�SEEK_CURָ�룬���ļ��Ĵ�С
		int size = lseek(fd, 0, SEEK_END);
		lseek(fd, 0, SEEK_SET); //�õ��ļ���С����Ҫ���ļ�ָ���û��ļ���ʼλ��
		
		char suc_buff[128] = { "HTTP/1.1 200 OK\r\n" };
		strcat(suc_buff, "Server: myhttp\r\n");
		sprintf(suc_buff + strlen(suc_buff), "Content-Length: %d\r\n", size);
		strcat(suc_buff, "\r\n");
		
		// ���ɹ���200��Ӧ���ķ��͸��ͻ���
		send(c, suc_buff, strlen(suc_buff), 0);
	
		//�ڷ������˽��д�ӡ��Ӧ����
		printf("\nsend:\n%s\n", suc_buff);

		char send_buff[1024] = { 0 };
		//���ͻ����������Դ�ļ����͸��������������ҳ�������������ִ��
		int num = 0;
		while ((num = read(fd, send_buff, 1024)) > 0)
		{
			send(c, send_buff, num, 0);
		}
		close(fd); 		// �ر���Դ�ļ�������fd
		close(c);	 	// �ر������׽���c
	}

}
//�����׽���
int create_socket()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		return -1;
	}
	//���õ�ַ��Ϣ
	struct sockaddr_in saddr;
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = inet_addr(IPADDR);
	//�����׽��� ����ַ��Ϣ�󶨵�������sockfd��
	int res = bind(sockfd, (struct sockaddr*) & saddr, sizeof(saddr));
	if (res == -1)
	{
		return -1;
	}
	//������������
	listen(sockfd, 20);
	//���ش����õ�socket
	return sockfd;
}
