#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char* argv[]){ 
  int pid,status,i, j, total; 
  time_t times, timee, time;
  char str[16];
  char str2[16];
  int st, en;
  st = atoi(argv[1]);
  en = atoi(argv[2]);
  int ct = (int)((en - st)/atoi(argv[3]));
 times = time(NULL);
 for(i=0; i<atoi(argv[3]); ++i){
  if((pid = fork()) == 0) { /* Proces potomny pot ---*/  
	sprintf(str, "%d\0", st+(i*ct)); 
	if(i+1 == atoi(argv[3])){
	  sprintf(str2, "%d\0", en+1);	
	}else{	 
	sprintf(str2, "%d\0", st+(i*ct)+ct);
	}
	 execl("./pot","pot", str, str2,NULL); 
  }   
 }

total = 0;
 for(i=0; i<atoi(argv[3]); ++i){
      pid = wait(&status);
      printf("Proces %d zakończony status: %d\n",pid,status/256);
      total += (int)(status/256); 
 } 
 timee = time(NULL);
 time = timee - times;
 printf("liczb pierwszych w przedziale: %d\n czas: %d\n", total, time);
} 
