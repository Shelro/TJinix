#include "stdio.h"
#include "string.h"

#define BUF_SIZE 512

int delete_stuff(char *filename)//open&read
{
   int ret = 0;
   
   int fd = open(filename, O_RDWR);
   if(fd == -1){
      printf("Failed to open file: %s\n", filename);
      return -1;
   }
   
   close(fd);
   int n = unlink(filename);
   if (n ==1 ) {
		printf("failed to delete %s\n", filename);
		return -2;
	}
   return ret;
}
int main(int argc, char* argv[])
{
   int i=0;
   int ret=0;
   for(i=1;i<argc;i++){
      if((ret=delete_stuff(argv[i]))!=0){
            printf("Exiting with error code:%d\n",ret);
            break;
      }
      else printf("delete successfully!\n");
      return ret;
   }
}
