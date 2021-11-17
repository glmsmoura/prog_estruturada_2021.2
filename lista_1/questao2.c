#include <stdio.h>
#include <math.h>


float *resolve_equacao(int a, int b, int c);

int main(){
  int a, b, c; //Declarando as variaveis da equacao ax^2+bx+c=0

  float *solucao; //ponteiro para o array com a solucao

  scanf("%d %d %d", &a, &b, &c); //Recebendo as variaveis

  solucao = resolve_equacao(a, b, c); //Resolvendo a equacao, recebe um ponteiro para o array solucao

  if (isnan(solucao[0])){ //Checando se existem raizes reais
    printf("Sem raiz!\n"); 
    return 0;
  }

  for (int i = 0; i < 2; i++) { //Printa os resultados
    printf("%f ", solucao[i]);
  }

  printf("\n");
  return 0;
}


float *resolve_equacao(int a, int b, int c){
  float x1, x2, delta; //Declarando as raizes da equacao

  static float solucao[2]; //Declara o array que contera as solucoes

  delta = b*b - 4*a*c; //Define delta

  x1 = (-b + sqrt(delta))/2*a; //Define a solucao 1
  x2 = (-b - sqrt(delta))/2*a; //Define a solucao 2
  
  solucao[0] = x1; solucao[1] = x2; //Passa as solucoes para o array

  return solucao; //Devolve o endereço do array como um ponteiro
}
