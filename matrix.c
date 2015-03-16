#include"classm.h"


/*void multiplicate(Matrix odin, Matrix dva)
	{
	int rasm, i,j;
	int **tri;
	rasm=odin.Rasmer();
	tri=(int**)malloc(rasm*sizeof(int));
	for(i=0;i<rasm;i++)
		tri[i]=(int*)malloc(rasm*sizeof(int));
	tri=odin*dva;
	for (i=0;i<rasm;i++){
		for(j=0;j<rasm;j++)
			printf("%d ", tri[i][j]);
		printf("\n");};
	}
void sum(Matrix odin, Matrix dva)
	{
	int rasm, i,j;
	int **tri;
	rasm=odin.Rasmer();
	tri=(int**)malloc(rasm*sizeof(int));
	for(i=0;i<rasm;i++)
		tri[i]=(int*)malloc(rasm*sizeof(int));
	tri=odin+dva;
	for (i=0;i<rasm;i++){
		for(j=0;j<rasm;j++)
			printf("%d ", tri[i][j]);
		printf("\n");};
	}*/
int main(){
	int i,j;
	Matrix odin;
	odin[1][1]=10;
	odin.PrintTable();
	return(0);
};
