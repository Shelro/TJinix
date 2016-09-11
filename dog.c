#include "stdio.h"
#include "string.h"

#define BUF_SIZE 512

int write_dog(char *filename, char *content)//write
{
   int ret = 0,i=0;
   char bufb[BUF_SIZE];
   for(int i=0;i<BUF_SIZE;i++){bufb[i]=' ';}
   int fd = open(filename, O_RDWR);
	if (fd == -1) {
		printf("failed to open %s\n", filename);
		return 1;
	}
        /*close(fd);
        unlink(filename);*/
	int n = write(fd, content, strlen(content));
        for(i=strlen(content);i<BUF_SIZE;i++){bufb[i]=' ';}
        write(fd,bufb,BUF_SIZE);
	if (n != strlen(content)) {
		printf("failed to write to %s\n", filename);
		close(fd);
		return 2;
	}
        /*int fd2 = open(filename, O_CREAT | O_RDWR | O_TRUNC);
	if (fd2 == -1) {
		printf("failed to open %s\n", filename);
		return -1;
	}

	int n = write(fd2, content, strlen(content));

        if (n != strlen(content)) {
		printf("failed to write to %s\n", filename);
		close(fd2);
		return 2;
	}
*/
	close(fd);
   return ret;
}

int main(int argc, char* argv[])
{
   int ret=0;
   char con[BUF_SIZE*4];
   if(argc==1) printf("Please enter file name and content.");
   else{
       printf("Please enter content:");
       read(0, con, BUF_SIZE);
       if((ret=write_dog(argv[1],con))!=0){
            printf("Exiting with error code:%d\n",ret);
      }
      else printf("Write sucessfully!\n");
      return ret;
   }
}
