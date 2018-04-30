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

   char b1[1024], b[16];
   memset(b1, 0, sizeof(b1));
   memset(b, 0, 16);
   int r1 = read(fd, b, 16);
   printf("1%s\n", b);
   close(fd);
   for(i=0;i<16;i++)
	{
		b1[i] = b[i];
	}
   int d = open("/dev/lkm_example", O_RDWR);
   char b2[] = "hello World! Just testing!";
	for(i=0;i<strlen(b2);i++)
	{
		b1[i+16] = b2[i];
	}
	printf("Array :- %s",b1);
	int r = write(d, b1, 42);
   /*char b3[] = "hahahahahahahaha";
   r = write(d, b2, sizeof(b2));
   r = write(d, b3, sizeof(b3));*/
   char *b3;
   memset(b3,0,sizeof(b1));
   r = read(d, b3,42);
   printf("%s\n", b1);
   printf("%s\n", b);
   printf("The string is :-%s cool %d",b3,r);
   close(d);

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
