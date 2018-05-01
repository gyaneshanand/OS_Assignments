#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
   int fd;
   int i;
   fd = open("/dev/urandom", O_RDONLY);

   char b1[1024], b[106],b3[100];
   
   memset(b1, 0, sizeof(b1));
   memset(b, 0, sizeof(b));
   memset(b3, 0, sizeof(b3));

   int bl = read(fd, &b, 16*sizeof(char));

   printf("Array :- %s and size =%d \n",b,bl);

   strcpy(b,"laudalassanchutt\0");
   printf("poorana b %s\n", b);
   close(fd);
   for(i=0;i<16;i++)
	{
		b1[i] = b[i];
	}
   char b2[] = "1234567890123456";
   for(i=0;i<strlen(b2);i++)
   {
      b1[i+16] = b2[i];
   }

   int d = open("/dev/lkm_example", O_RDWR);
  
	
	int r = write(d, b1, 32);
   /*
   r = write(d, b2, sizeof(b2));
   r = write(d, b3, sizeof(b3));*/
   
   printf(" ye  b1 : %s \n", b1);
   int r2 = read(d, b3,1024);
   close(d);
   printf(" ye doosra b1 : %s \n", b1);
   printf("b : %s \n", b);
   printf("The strinjgg is :-%s cool %d\n",b3,r);
   

   /*FILE *fptr;
   fptr = fopen("key.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fprintf(fptr,"%s", b2);
   fclose(fptr);
   fptr = fopen("data.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fprintf(fptr,"%s", b1);
   fclose(fptr);*/
   return 0;
}
