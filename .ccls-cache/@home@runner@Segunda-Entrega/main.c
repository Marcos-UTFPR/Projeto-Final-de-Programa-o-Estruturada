#include <stdio.h>

int main(void) {
  float PreçoGasolina;
  int TamanhoFila;
  printf("Autor do Programa: Marcos Vinícius Ribeiro da Silva\n\n");
  printf("Função do Programa: simular o funcionamento de um posto de \ncombustível de pequeno porte\n\n\n");
  printf("Por favor, informe o preço do litro da gasolina comum:");
  scanf("%f",&PreçoGasolina);
  printf("Informe o tamanho máximo da fila de automóveis:");
  scanf("%d",&TamanhoFila);
  int OpcaoMenu;
  int OpcaoRelatorio;
  printf("\n Selecione uma das seguintes opções:\n");
  printf("1-Adicionar um carro na fila\n");
  printf("2-Abastecimento\n");
  printf("3-Exibir carros na fila de espera\n");
  printf("4-Relatórios\n");
  printf("5-Encerrar\n");
  scanf("%d",&OpcaoMenu);
  switch (OpcaoMenu){
    case 1:
      printf(" *Carro adicionado");
      break;
    case 2:
      printf(" *Carro abastecido");
      break;
    case 3:
      printf(" *Lista de carros na fila de espera");
      break;
    case 4:
      printf("\n Selecione um dos seguintes relatórios:\n");
      printf("1-Quantidade de litros vendidos\n");
      printf("2-Valor total arrecadado\n");
      printf("3-Quantidade de carros atendidos\n");
      printf("4-Quantidade de combustível restante no tanque\n");
      printf("5-Gerar arquivo para impressão\n");
      printf("6-Voltar ao menu anterior (Encerra o programa nessa versão)\n");
      scanf("%d",&OpcaoRelatorio);
        switch (OpcaoRelatorio){
          case 1:
            printf(" *Litros vendidos = 0");
            break;
          case 2:
            printf(" *Valor total arrecadado = 0");
            break;
          case 3:
            printf(" *Carros atendidos = 0");
            break;
          case 4:
            printf(" *Litros restantes = 200 litros");
            break;
          case 5:
            printf(" *Arquivo para impressão:");
            printf("\n *Litros vendidos = 0");
            printf("\n *Valor total arrecadado = 0");
            printf("\n *Carros atendidos = 0");
            printf("\n *Litros restantes = 200 litros");
            break;
          case 6:
            printf("\t\t\t-Programa encerrado-");
            break;
          default: printf("Comando incorreto-Programa encerrado");
        }
      break;
    case 5:
      printf("\t\t\t-Programa encerrado-");
      break;
    default: printf("Comando incorreto-Programa encerrado");
  }
  return 0;
}