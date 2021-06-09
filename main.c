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
    
unsigned int  maxLucro(unsigned int  a, unsigned int  b) 
{ 
	if(a>b)
	{	
	return a;	
	}else
	{
	return b;	
	}	
}

unsigned int  criptomoedas(unsigned int  Orcamento, unsigned int  ct[], unsigned int  val[], unsigned int  n)
{
   unsigned int  i, c;
   int (*OEscolhaMax)[Orcamento+1] = malloc(sizeof(int[n+1][Orcamento+1]));
   //unsigned int  OEscolhaMax[n+1][Orcamento+1];
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
	 

int  main( int  argc, char * argv[]){
    unsigned int  num_items;
    unsigned int  orcamento;
    char ** nome;
    unsigned int  * custo;
    unsigned int  * lucro;
    
    scanf("%d %d\n", &num_items, &orcamento);
    
    //vou indexar em [1..n] pois isso facilita os casos bases
    nome  = (char**)  malloc(sizeof(char*) * num_items+1);
    custo = (unsigned int *)  malloc(sizeof(unsigned int ) * num_items+1);
    lucro = (unsigned int *)  malloc(sizeof(unsigned int ) * num_items+1);
    
    //Lendo a entrada para cada vertice
    for(unsigned int  i = 1; i <= num_items; i++){
        nome[i] = (char*)  malloc(sizeof(char) * 20);
        fgets(nome[i], 20, stdin);
        scanf("%d %d\n", &(custo[i]), &(lucro[i]));
    }
    // prunsigned int  nome todo
     /* 
    prunsigned intf("%d, %d", num_items, orcamento);
    prunsigned intf("\n");
  	for(unsigned int  i = 1; i <= num_items; i++){
        prunsigned intf("%s", nome[i]);
        prunsigned intf("%d, %d \n \n", custo[i], lucro[i]);
      
 	}
 	*/
     
    printf("%d", criptomoedas(orcamento, custo, lucro, num_items));

    
    
    for(unsigned int  i = 1; i <= num_items; i++) free(nome[i]);
    free(custo); free(lucro); free(nome);
    
    fflush(stdin);
    
    return 0;
}
