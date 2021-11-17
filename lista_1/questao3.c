#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void acha_resultado(int numero);

int main(){
  int numero; //Declara o numero a ser checado

  scanf("%d", &numero); //Recebe o numero a ser checado
 
  acha_resultado(numero); //Chama a funcao que acha os fatores primos

  return 0;
}

void acha_resultado(int numero){
  
  int *solucao =(int *)calloc(1, sizeof(int)); //Inicia um array dinamico para armazenar os resultados
  if(solucao==NULL){ //Checa problemas de memoria
    printf("Sem memoria\n");
    exit(1);
  }
  int tamanho_solucao = 1; //Guarda o tamanho do array

  for (int i = 2; i < numero/2 + 1; i++) { //Procura divisores NAO primos do numero
    if ((numero % i) == 0){ 
      solucao = (int *) realloc(solucao, sizeof(int)*(tamanho_solucao+1)); //Aumenta o tamanho do array para adicionar um novo resultado
      if(solucao==NULL){ //Checa problemas de memoria
        printf("Sem memoria\n");
        exit(1);
        }
      solucao[(tamanho_solucao++)-1] = i; //Armazena o novo resultado 
      }
    }

  for (int i = tamanho_solucao-2 ; i > 0; i--) { //Procura por divisores primos, ou seja, que nao serao divididos pelos outros divisores
    for (int j = 0; j < i ; j++) 
      if(i!=j && solucao[i] % solucao[j]==0)
        solucao[i]=1;  //Caso o divisor nao seja primo, coloca-se 1 no seu lugar 
    }
  
  for (int i = 0; i < tamanho_solucao-1; i++) 
    if (solucao[i]!=1) //Printa todos os divisores primos, ou seja, que sao diferentes de 1 
      printf("%d\n", solucao[i]);  
  }


