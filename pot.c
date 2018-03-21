#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int pierwsza(int);

void main(int argc, char* argv[]) { 
int count = 0;
int i;
int p;
//printf("poczatek: %d\n", atoi(argv[1]));
//printf("koniec: %d\n", atoi(argv[2]));
  for(i = atoi(argv[1]); i<atoi(argv[2]); ++i){
	p = pierwsza(i);
	if(p){
	  ++count;
	}
  } 

  exit(count); 
} 

int pierwsza(int n) 
// Funkcja zwraca 1 gdy n jest liczba pierwsza 0 gdy nie                                   
{ int i,j=0; 
  for(i=2;i*i<=n;i++) { 
    if(n%i == 0) return(0) ; 
 } 
 return(1); 
} 
