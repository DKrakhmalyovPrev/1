#include <string>

class Book{
	public:
		Book(){
			printf("Введите название книги\n");
			cin >> Name;
			/*printf("Введите автора\n");
			Avtor=(char*)malloc(30*sizeof(char));
			while(c!='\n'){ 
				scanf("%c", &c);
				Avtor[i]=c;
				i++;
			};	
			c='a';
			i=0;
			printf("Введите издательство\n");
			Izdat=(char*)malloc(30*sizeof(char));
			while(c!='\n'){ 
				scanf("%c", &c);
				Izdat[i]=c;
				i++;
			};	
			c='a';
			i=0;
			printf("Введите год публикации\n");
			scanf("%i", &year);
			printf("Введите количество страниц\n");
			scanf("%i", &pages);
			printf("Введите содержание книги\n");
			c='a';
			i=0;
			Soderj=(char*)malloc(300*sizeof(char));
			if(Soderj==NULL){printf("NULL");};
			while(c!='\n'){
				scanf("%c", &c);
				Soderj[i]=c;
				i++;
			};*/
			printf("Данные получены\n");	

};
int year, pages, i,j,k,l; char c;
string Avtor;
string Name;
string Izdat;
string Soderj;
};
