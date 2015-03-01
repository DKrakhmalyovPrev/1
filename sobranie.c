#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "book.h"

class Sobranie{
	public:
		Sobranie(){
			c='a';
			i=0;
			printf("Введите название собрания сочинений\n");
			Name=(char*)malloc(30*sizeof(char));
			while(c!='\n'){ 
				scanf("%c", &c);
				Name[i]=c;
				i++;
			};
			c='a';
			i=0;
			printf("Введите автора\n");
			Avtor=(char*)malloc(30*sizeof(char));
			while(c!='\n'){ 
				scanf("%c", &c);
				Avtor[i]=c;
				i++;
			};	
			printf("Введите число томов\n");
			scanf("%i", &toma);
			c='a';
			i=0;
		};
		void Addbook(){
			Books=(Book*)malloc(toma*sizeof(Book));	
			for(int i=0;i<toma;i++){
				Book b;
				Books[i] = b;
			};
		};
		

int year, toma, i,j,k,l; char c;
char *Avtor;
char *Name;
Book *Books;
};

int main(){
	Sobranie odin;
	odin.Addbook();
	return(0);
};
