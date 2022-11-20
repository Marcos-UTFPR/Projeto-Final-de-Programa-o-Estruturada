#include <stdio.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

int main(void) {
  float precogasolina = 0;
  int tamanhofila = 0;
  printf(" -Autor do Programa: Marcos Vinícius Ribeiro da Silva\n\n");
  printf(" -Função do Programa: simular o funcionamento de um posto de \ncombustível de pequeno porte, com uma bomba apenas e que \nsó trabalha com um combustível: gasolina comum.\n\n\n");
  printf("Por favor, informe o preço do litro da gasolina comum (em reais)");
  printf("\n"GRN"(Atenção! Por favor, digite o valor usando ponto e não vírgula!): "WHT);
  scanf("%f",&precogasolina);
  printf("\nInforme o tamanho máximo da fila de automóveis: ");
  scanf("%d",&tamanhofila);
  int opcaomenu = 0;
  int opcaorelatorio = 0;
  while (opcaomenu != 5){     //Laço de repetição do Menu Principal
    system("clear");
    printf(BLU"\n-----------------MENU PRINCIPAL------------------------");
    printf(WHT"\n\n Selecione uma das seguintes opções:\n1-Adicionar um carro na fila\n2-Abastecimento\n3-Exibir carros na fila de espera\n4-Relatórios\n5-Encerrar\n");
    scanf("%d",&opcaomenu);
    switch (opcaomenu){
      case 1:
        printf(GRN"\n *Carro adicionado"WHT);
        break;
      case 2:
        printf(GRN"\n *Carro abastecido"WHT);
        break;
      case 3:
        printf(GRN"\n *Lista de carros na fila de espera"WHT);
        break;
      case 4:
        while (opcaorelatorio != 6){ //Laço de repetição do submenu Relatórios
          printf(BLU"\n-----------------MENU RELATÓRIOS------------------------");
          printf(WHT"\n\n Selecione um dos seguintes relatórios:\n");
          printf("1-Quantidade de litros vendidos\n");
          printf("2-Valor total arrecadado\n");
          printf("3-Quantidade de carros atendidos\n");
          printf("4-Quantidade de combustível restante no tanque\n");
          printf("5-Gerar arquivo para impressão\n");
          printf("6-Voltar ao menu anterior\n");
          scanf("%d",&opcaorelatorio);
            switch (opcaorelatorio){
              case 1:
                printf("\n *Litros vendidos = 0");
                break;
              case 2:
                printf("\n *Valor total arrecadado = 0");
                break;
              case 3:
                printf("\n *Carros atendidos = 0");
                break;
              case 4:
                printf("\n *Litros restantes = 200 litros");
                break;
              case 5:
                printf("\n *Arquivo para impressão: \n *Litros vendidos = 0\n *Valor total arrecadado = 0\n *Carros atendidos = 0\n *Litros restantes = 200 litros");
                break;
              case 6: 
                break;
              default: printf(RED"\n Comando incorreto-Escolha uma das opções informadas\n");
            }
         }
        opcaorelatorio = 0;
        break;
      case 5:
        printf(CYN"\n\t\t\t-Programa encerrado-");
        break;
      default: printf(RED"\n Comando incorreto-Escolha uma das opções informadas\n");
    }
    getchar();
    getchar();
  }
  return 0;
}