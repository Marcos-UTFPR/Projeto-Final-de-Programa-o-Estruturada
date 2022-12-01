#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLK "\e[0;30m" 
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"


float Validacao (){ //Função usada na validação do preço do combustível e do tamanho da fila
  float validacao1 = 0; //Variável genérica para a validação
  scanf("%f",&validacao1);
  while (validacao1 <= 0){
    printf(RED"\nValor negativo ou nulo informado - Por favor, informe um valor \npositivo\n\n" WHT "Informe um valor válido: ");
    scanf("%f",&validacao1);
  }
  return(validacao1);
}


void RelatorioTanque (float combustivel) { //Subrotina usada para cor dinâmica no relatório de litros restantes no tanque de gasolina
  if (combustivel >= 150){
                  printf(" *Gasolina restante no tanque = " GRN "%.2f" WHT"/200 litros",combustivel);
                } 
                else { 
                  if (combustivel >= 100){
                    printf(" *Gasolina restante no tanque = " CYN"%.2f" WHT"/200 litros",combustivel);
                  }
                  else{
                    if (combustivel >= 50){
                      printf(" *Gasolina restante no tanque = " MAG "%.2f" WHT"/200 litros",combustivel);
                    }
                    else {
                      if (combustivel >= 10){
                        printf(" *Gasolina restante no tanque = " YEL"%.2f" WHT "/200 litros",combustivel);
                      }
                      else {
                        printf(" *Gasolina restante no tanque = " RED "%.2f" WHT "/200 litros",combustivel);
                      }
                    }
                  }
                }
}


void flush_in(){ //Limpa o buffer do teclado
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}