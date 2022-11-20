#include <stdio.h>
#include <string.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

float Validacao (); //Subrotina usada para validação da valores informados

int main(void) {
  float precogasolina = 0;
  float combustivel = 200; //Padrão 200 litros no reservatório
  int tamanhofila = 0; //Controla o tamanho máximo da fila
  int opcaomenu = 0; //Seleção do Menu Principal
  int opcaorelatorio = 0; //Seleção do Submenu Relatórios
  int fila = 0; //Controla a quantidade de carros na fila atualmente
  float litrosabastecer = 0; //Controla quantos litros serão abastecidos
  int carrosatendidos = 0; //Registra quantos carros foram atendidos
  float lucro = 0; //Registra quanto dinheiro foi ganho até o momento
  float litrosvendidos = 0; //Registra quantos litros foram vendidos
  printf(" -Autor do Programa: Marcos Vinícius Ribeiro da Silva\n\n -Função do Programa: simular o funcionamento de um posto de \ncombustível de pequeno porte, com uma bomba apenas e que \nsó trabalha com um combustível, gasolina comum, tendo apenas \n200 litros no tanque no início.\n\n\nInforme o preço do litro da gasolina comum (em reais)\n"GRN"(Atenção! Por favor, digite o valor usando ponto e não vírgula!): "WHT);
  precogasolina = Validacao (); //Inicia a subrotina de Validação para validar o valor informado, garantindo que o valor não seja negativo ou zero
  printf("\nInforme o tamanho máximo da fila de automóveis: ");
  tamanhofila = Validacao ();
  while (opcaomenu != 5){     //Laço de repetição do Menu Principal
    system("clear");         //Limpa a tela toda vez que o laço recomeça
    printf(BLU"\n-----------------MENU PRINCIPAL------------------------"WHT"\n\n Selecione uma das seguintes opções:\n1-Adicionar um carro na fila\n2-Abastecimento\n3-Exibir carros na fila de espera\n4-Relatórios\n5-Encerrar\n");
    scanf("%d",&opcaomenu);
    switch (opcaomenu){
      case 1:
        if (fila < tamanhofila){
          printf(GRN"\n *Carro adicionado"WHT);
          fila = fila + 1;
        }
        else {
          printf(RED"\nLimite máximo da fila atingido\n"WHT);
        }
        break;
      case 2:
        if (fila != 0){
          if (combustivel <= 0){
            printf(RED" Não há mais combustível no tanque\n Os carros que estavam esperando na fila foram embora"WHT);
            fila = 0;
          }
          else {
            printf (" *Quantos litros deseja abastecer? ");
            litrosabastecer = Validacao ();
            while (litrosabastecer > combustivel){
              printf(RED"\nA quantidade de litros informada é superior a quantidade de litros restando no tanque\n\n"WHT" *Quantos litros deseja abastecer? ");
              scanf("%f",&litrosabastecer); 
            }
          printf(GRN"\n *Carro abastecido"WHT);
          fila--;
          combustivel = combustivel - litrosabastecer;
          litrosvendidos = litrosvendidos + litrosabastecer;
          lucro = lucro + (litrosabastecer * precogasolina);
          carrosatendidos++;
          }
        }
        else {
          printf(RED"\nNão há nenhum carro na fila atualmente\n"WHT);
        }
        break;
      case 3:
        printf(GRN"\n *Lista de carros na fila de espera = %d carros na fila"WHT,fila);
        break;
      case 4:
        while (opcaorelatorio != 6){ //Laço de repetição do submenu Relatórios
          system("clear");
          printf(BLU"\n-----------------MENU RELATÓRIOS------------------------"WHT"\n\n Selecione um dos seguintes relatórios:\n1-Quantidade de litros vendidos\n2-Valor total arrecadado\n3-Quantidade de carros atendidos\n4-Quantidade de combustível restante no tanque\n5-Gerar arquivo para impressão\n6-Voltar ao menu anterior\n");
          scanf("%d",&opcaorelatorio);
            switch (opcaorelatorio){
              case 1:
                printf("\n *Litros vendidos = %.2f litros",litrosvendidos);
                break;
              case 2:
                printf("\n *Valor total arrecadado = R$ %.2f",lucro);
                break;
              case 3:
                printf("\n *Carros atendidos = %d",carrosatendidos);
                break;
              case 4:
                printf("\n *Litros restantes = %.2f litros",combustivel);
                break;
              case 5:
                printf("\n *Arquivo para impressão: \n *Litros vendidos = %.2f litros\n *Valor total arrecadado = R$ %.2f\n *Carros atendidos = %d\n *Litros restantes = %.2f litros",litrosvendidos,lucro,carrosatendidos,combustivel);
                break;
              case 6:
                printf(CYN"\t\n *Por favor, aperte Enter três vezes\n"WHT);
                break; //Servia apenas para o caso 6 não cair no default (um coringa)
              default: printf(RED"\n Comando incorreto-Escolha uma das opções informadas\n");
            }
          getchar(); 
          getchar(); 
         }
        opcaorelatorio = 0;
        break;
      case 5:
        printf(CYN"\n\t\t\t-Programa encerrado-");
        break;
      default: printf(RED"\n Comando incorreto-Escolha uma das opções informadas\n");
    }
    getchar(); //Fica esperando o usuário apertar qualquer tecla para continuar
    getchar(); //Comando repetido duas vezes por causa do bug no Replit
  }
  return 0;
}

float Validacao (){ //Função usada na validação do preço do combustível e do tamanho da fila
  float validacao1; //Variável genérica para a validação
  scanf("%f",&validacao1);
  while (validacao1 <= 0){
    printf(RED"\nValor negativo ou nulo informado - Por favor, informe um valor \npositivo\n\n"WHT"Informe um valor válido: ");
    scanf("%f",&validacao1);
  }
  return(validacao1);
}