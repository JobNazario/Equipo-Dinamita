/**************************

buscaminas
***************************/
#include <stdio.h>
#include <stdlib.h>
#include <Mines.h>

uint32 main()
{
    uint8 BM[15][15]={{0}};
    uint32 renglon,columna;
    uint32 nv=0;
    srand(time(NULL));
    nv=menu();
    if(nv!=0)
    {
    minas(BM,nv);
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
    }
    else if(nv=0)
    {
       printf(" ERROR \n");
    }

    return 0;
}
uint32 menu(void)
{ 
    uint32 nv =0;
    uint32 nivel=0;
    printf("nivel a jugar:   \n");
    scanf("%i",&nv);
    if(nv==1)
    {
        nivel=10;
        
    }
    else if (nv==2)
    {
        nivel=20;
        
    }  
    else if (nv==3)
    {
        nivel=30;
        
    }
    else if (nv>3)
    {
        printf(" ERROR \n");
        nivel=0;
    }
    return nivel;
    
}
uint32 checaMinas(uint8 bm[15][15], uint32 j, uint32 i)
{
    uint32 contar =0;
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
void despliega(uint8 arr[15][15]) // interfas 
{
     uint32 i, j;
    for(j=0;j<15;j++)
    {
        for(i=0;i<15;i++)
        {
            if(arr[j][i]=='*')
                printf("0");//minas
            else 
                printf("%i",arr[j][i]);
                
        }
        puts("");
    }
}
void minas(uint8 BM[15][15], uint32 nivel)  // pone minas Booom
{
    uint8 minitas=0, x, y; 
    
    do{
      x=rand()%8+1; //protege los margenes de error 
      y=rand()%8+1;
    
    if (BM[x][y]==0)  // cambia por el do
        {
            BM[x][y]='*';
            minitas++;
        }
    
    }while(minitas<nivel); 
}


