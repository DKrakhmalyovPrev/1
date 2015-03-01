#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "book.h"

class Sobranie{
	public:
		Sobranie(){
			printf("Введите название собрания сочинений\n");
			scanf("%s", Name);
			printf("Введите автора\n");
			scanf("%s", Avtor);
			printf("Введите число томов\n");
			scanf("%i", &toma);
		};
		void Addbook(){
			Books=(Book*)malloc(toma*sizeof(Book));	
			for(int i=0;i<toma;i++){
				Book b;
				Books[i] = b;
			};
		};
		

int year, toma, i,j,k,l; char c;
char Avtor[30];
char Name[30];
Book *Books;
};

int main(){
	Sobranie odin;
	odin.Addbook();
	return(0);
};
