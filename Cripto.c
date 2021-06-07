/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ernani
 *
 * Created on 4 de Junho de 2021, 18:16
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 // retornar o maximo lucro
    
int  maxLucro(int  a, int  b) 
{ 
	if(a>b)
	{	
	return a;	
	}else
	{
	return b;	
	}	
}

int  criptomoedas(int  Orcamento, int  ct[], int  val[], int  n)
{
   int  i, c;
   int  OEscolhaMax[n+1][Orcamento+1];
   for (i = 0; i <= n; i++)
   {
       for (c = 0; c <= Orcamento; c++)
       {
           if (i==0 || c==0)
               OEscolhaMax[i][c] = 0;
           else if (ct[i-1] <= c)
                 OEscolhaMax[i][c] = maxLucro(val[i-1] + OEscolhaMax[i-1][c-ct[i-1]],  OEscolhaMax[i-1][c]);
           else
                 OEscolhaMax[i][c] = OEscolhaMax[i-1][c];
       }
   }
   return OEscolhaMax[n][Orcamento];
}
	 

int  main(int  argc, char * argv[]){
    int  num_items;
    int  orcamento;
    char ** nome;
    int  * custo;
    int  * lucro;
    
    scanf("%d %d\n", &num_items, &orcamento);
    
    //vou indexar em [1..n] pois isso facilita os casos bases
    nome  = (char**)  malloc(sizeof(char*) * num_items+1);
    custo = (int *)  malloc(sizeof(int ) * num_items+1);
    lucro = (int *)  malloc(sizeof(int ) * num_items+1);
    
    //Lendo a entrada para cada vertice
    for(int  i = 1; i <= num_items; i++){
        nome[i] = (char*)  malloc(sizeof(char) * 20);
        fgets(nome[i], 20, stdin);
        scanf("%d %d\n", &(custo[i]), &(lucro[i]));
    }
    // print  nome todo
    
    printf("%d, %d", num_items, orcamento);
    printf("\n");
  	for(int  i = 1; i <= num_items; i++){
        printf("%s", nome[i]);
        printf("%d, %d \n \n", custo[i], lucro[i]);
      
 	}
    
    printf("\n Valor Maximizado = %d", criptomoedas(orcamento, custo, lucro, num_items));

    
    
    for(int  i = 1; i <= num_items; i++) free(nome[i]);
    free(custo); free(lucro); free(nome);
    
    fflush(stdin);
    
    return 0;
}
