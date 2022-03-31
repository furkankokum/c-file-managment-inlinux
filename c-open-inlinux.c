#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        if(argc!=3){
            printf("Bir dosya ismi ve aranacak karakter vermelisiniz.\n");
            exit(-1);
        }
  int n;
  int fd= open(argv[1], O_RDONLY);
  char buf[1];
  int word=0;
  int ctr=0;
  char harf=argv[2][0];
  while(n= read(fd,buf,sizeof(buf)))>0)
  {
  if(buf[0] == harf)
          ctr=1;
  if(ctr == 1 && (buf[0] == " " || buf[0] == ".")){
    word++;
    ctr=0;
  }
  }
  printf("Dosyada %c harfi iceren %d kelime bulunmaktadır.\n",harf,word);
  close(fd);
  return 0;
}
