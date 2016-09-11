#include "stdio.h"
#include "string.h"

#define BUF_SIZE 512

int smelly_cat(char *filename)//open&read
{
   char buf[BUF_SIZE];
   int n_read = 0;
   int ret = 0;
   
   int fd = open(filename, O_RDWR);
   if(fd == -1){
      printf("Failed to open file: %s\n", filename);
      return -1;
   }
   
   for(;;){
      n_read=read(fd,buf,BUF_SIZE);
      if((n_read<0)||(n_read>BUF_SIZE)){ /*error*/
         ret=-2;
         break;
      }
      write(1,buf,n_read);
      if(n_read<BUF_SIZE){  /*finish*/
         break;
      }
   }
   printf("\n");
   
   close(fd);
   return ret;
}

int move_cat(char *filename)//create&write
{
   char bufw[] = "This file is balnk!";
   int ret = 0;
   
   int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC);
	if (fd == -1) {
		printf("failed to open %s\n", filename);
		return 1;
	}

	int n = write(fd, bufw, strlen(bufw));
	if (n != strlen(bufw)) {
		printf("failed to write to %s\n", filename);
		close(fd);
		return 2;
	}

	close(fd);
   return ret;
}

int main(int argc, char* argv[])
{
   int i=0;
   int ret=0,ret2=0;
   for(i=1;i<argc;i++){
      if((ret=smelly_cat(argv[i]))!=0){
         if((ret2 = move_cat(argv[i]))!=0){
            printf("Exiting with error code:%d&%d\n",ret,ret2);
            break;
         }
      }
      return ret;
   }
}
