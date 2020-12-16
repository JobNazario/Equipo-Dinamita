/******************************************************************************

buscaminas
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void minas(char BM[10][10]);
void despliega(char arr[10][10]);
int checaMinas(char bm[10][10], int j, int i);  //-1
int main()
{
    char BM[10][10]={{0}};
    int renglon,columna;
    
    srand(time(NULL));
    minas(BM);
    do{
        despliega(BM);
        printf("en cuál renglón?");
        scanf("%i",&renglon);
        printf("En cual columna?");
        scanf("%i",&columna);
        
        if(checaMinas(BM,renglon,columna)==-1)
           {
               printf("Booom");
               break;
           }
    }while(1); //TRUE
 

    return 0;
}
int checaMinas(char bm[10][10], int j, int i)
{
    int contar =0;
    if(bm[j][i]=='*')
     return-1;
    if(bm[j-1][i]=='*')
        contar++;
    if(bm[j-1][i+1]=='*')
        contar++;
    if(bm[j][i-1]=='*')
        contar++;
    if(bm[j][i+1]=='*')
        contar++;
    if(bm[j+1][i-1]=='*')
        contar++;
    if(bm[j+1][i]=='*')
        contar++;
    if(bm[j+1][i+1]=='*')
        contar++;
    bm[j][i]=contar;
    
}
void despliega(char arr[10][10]) // interfas 
{
     int i, j;
    for(j=0;j<10;j++)
    {
        for(i=0;i<10;i++)
        {
            if(arr[j][i]=='*')
                printf("0");//minas
            else 
                printf("%i",arr[j][i]);
        }
        puts("");
    }
}
void minas(char BM[10][10])  // pone minas Booom
{
    char minitas=0, x, y; 
    do{
      x=rand()%8+1; //protege los margenes de error 
      y=rand()%8+1;
    
    if (BM[x][y]==0)  // cambia por el do
        {
            BM[x][y]='*';
            minitas++;
        }
    
    }while(minitas<5); 
}