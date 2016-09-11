#include "stdio.h"
#include "string.h"

#define BUF_SIZE 512

int calculate(char *content)
{
   int ret = 0,i=0,size=0;
   char buf1[BUF_SIZE];
   char buf2[BUF_SIZE];
   int num1=0,num2=0;
   int c = -1;
   size = strlen(content);
   for(;i<BUF_SIZE;i++,content++){
       if((*content)=='+')  
       {
          c=0;
          content++;
          break;
       }
       else if((*content)=='-')  
       {
          c=1;
          content++;
          break;
       }
       else if((*content)=='*')  
       {
          c=2;
          content++;
          break;
       }
       else if((*content)=='/')  
       {
          c=3;
          content++;
          break;
       }
       buf1[i]=*content;
   }
   int j=i+1;
   for(int k=0;j<size;k++,j++,content++){
      buf2[k]=*content;
   }
   j=size-1-i;
   for(int k=0;k<i;k++){
      num1 = num1*10 + (buf1[k] - 48);
   }
   for(int k=0;k<j;k++){
      num2 = num2*10 + (buf2[k] - 48);
   }
   switch(c){
         case 0 : ret = num1 + num2; printf("%d\n",ret);break;
         case 1 : ret = num1 - num2; printf("%d\n",ret);break;
         case 2 : ret = num1 * num2; printf("%d\n",ret);break;
         case 3 : ret = num1 / num2; printf("%d\n",ret);break;
         default : printf("Wrong equation!");
         }
   return ret;
}

int main(int argc, char* argv[])
{
   int ret=0;
   if((ret=calculate(argv[1]))<0){
       printf("Exiting with error code:%d\n",ret);
   }
   else printf("calculate sucessfully!\n");
   return ret;
}
