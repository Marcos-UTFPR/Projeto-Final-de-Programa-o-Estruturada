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

float Validacao (); //Subrotina usada para validação de valores informados
void RelatorioTanque (float combustivel); //Subrotina usada para cor dinâmica no relatório de litros restantes no tanque de gasolina
void flush_in(); //Limpa o buffer do teclado

struct TCarro{
char modelo[20];
char cor[20];
int placa;
float valorGasto;
};

int main(void) {
  float precogasolina = 0; //Registra o preço da gasolina definido pelo usuário
  float combustivel = 200; //Padrão 200 litros no reservatório
  int tamanhofila = 0; //Controla o tamanho máximo da fila
  int opcaomenu = 0; //Seleção do Menu Principal
  int opcaorelatorio = 0; //Seleção do Submenu Relatórios
  int fila = 0; //Controla a quantidade de carros na fila atualmente
  float litrosabastecer = 0; //Controla quantos litros serão abastecidos
  int carrosatendidos = 0; //Registra quantos carros foram atendidos
  float lucro = 0; //Registra quanto dinheiro foi ganho até o momento
  float litrosvendidos = 0; //Registra quantos litros foram vendidos
  struct TCarro *filaAtual; //Registra os carros atualmente na fila
  struct TCarro *carrosAtendidos1; //Registra os carros já atendidos
  carrosAtendidos1 = (struct TCarro*)calloc(0,sizeof(struct TCarro)); //Alocação dinâmica
  int contRelatorio = 0; //Registra quantos relatórios completos foram emitidos
  char nomeArquivo[20]; //Nome de arquivo do relatório
  
  printf(" -Autor do Programa: Marcos Vinícius Ribeiro da Silva\n\n -Função do Programa: simular o funcionamento de um posto d ve \ncombustível de pequeno porte, com uma bomba apenas e que \nsó trabalha com um combustível, gasolina comum, tendo apenas \n200 litros no tanque no início.\n\n\nInforme o preço do litro da gasolina comum (em reais)\n"GRN"(Atenção! Por favor, digite o valor usando ponto e não vírgula!): "WHT);
  precogasolina = Validacao (); //Inicia a subrotina de Validação para validar o valor informado, garantindo que o valor não seja negativo ou zero
  printf("\nInforme o tamanho máximo da fila de automóveis: ");
  tamanhofila = Validacao ();
  filaAtual = (struct TCarro*)calloc(tamanhofila,sizeof(struct TCarro)); //Alocação Dinâmica
  if (filaAtual == NULL){ //Verifica se a alocação de memória funcionou
    printf(RED"\n\t\t\tERRO DE MEMÓRIA - FALHA DE SISTEMA\n\n\t\t\t\t\tPROGRAMA ENCERRADO"WHT);
    exit(0);
  }
  printf("\n Preço do litro da gasolina = R$ %.2f\n Tamanho máximo da fila = %d"CYN"\n\n *Aperte Enter para continuar\n"WHT,precogasolina,tamanhofila); //Exibe os dois valores lido anteriormente
  getchar();
  getchar();
  while (opcaomenu != 5){     //Laço de repetição do Menu Principal
    system("clear");         //Limpa a tela toda vez que o laço recomeça
    printf(BLU"\n-----------------MENU PRINCIPAL------------------------"WHT"\n\n Selecione uma das seguintes opções:\n1-Adicionar um carro na fila\n2-Abastecimento\n3-Exibir carros na fila de espera\n4-Relatórios\n5-Encerrar\n");
    scanf("%d",&opcaomenu);
    switch (opcaomenu){
      case 1: //Adicionar um carro na fila
        if (combustivel == 0){
          printf(RED"\n *Não há mais combustível no tanque - Não é possível adicionar mais carros na fila"WHT);
        }
        else {
          if (fila < tamanhofila){
            printf("\nInforme o número da placa do carro: ");
            scanf("%d",&filaAtual[fila].placa);
            
            flush_in();
            printf("\nInforme o modelo do carro: ");
            fgets(filaAtual[fila].modelo,20,stdin);
            filaAtual[fila].modelo[strcspn(filaAtual[fila].modelo,"\n")]=0;
            
            printf("\nInforme a cor do carro: ");                                                               fgets(filaAtual[fila].cor,20,stdin);
            filaAtual[fila].cor[strcspn(filaAtual[fila].cor,"\n")]=0;
            
            printf(GRN"\n *Carro adicionado!"WHT);
            fila++;
          }
          else {
            printf(RED"\nLimite máximo da fila atingido\n"WHT);
          }
        }
        break;
      case 2: //Abastecimento
        if (fila != 0){
          printf (" *Quantos litros deseja abastecer? ");
          litrosabastecer = Validacao ();
          while (litrosabastecer > combustivel){
            printf(RED"\nA quantidade de litros informada é superior a quantidade de litros restando no tanque\n\n"WHT" *Quantos litros deseja abastecer? ");
            litrosabastecer = Validacao (); 
          }
          printf(GRN"\n *Carro abastecido!"WHT);
          carrosAtendidos1 = (struct TCarro*)realloc(carrosAtendidos1,(carrosatendidos+1)*sizeof(struct TCarro));
          carrosAtendidos1[carrosatendidos] = filaAtual[0]; //Copia os dados o primeiro carro da fila para o vetor de carros atendidos
          carrosAtendidos1[carrosatendidos].valorGasto = litrosabastecer * precogasolina;
          for(int i = 0;i < fila;i++){ //Ordenação do vetor que registra a fila atual
            filaAtual[i] = filaAtual[i+1];
          }
          fila--;
          combustivel = combustivel - litrosabastecer;
          litrosvendidos = litrosvendidos + litrosabastecer;
          lucro = lucro + (litrosabastecer * precogasolina);
          carrosatendidos++;
          if (combustivel == 0){
            printf(RED"\n\n\t Não há mais combustível no tanque\n\t Os carros que estavam esperando na fila foram embora"WHT);
            fila = 0; //Zera a fila quando acaba o combustível
            free (filaAtual); //Apaga o vetor que registra os carros atualmente na fila
            filaAtual = NULL;
          }    
        }
        else {
          printf(RED"\nNão há nenhum carro na fila atualmente\n"WHT);
        }
        break;
      case 3: //Exibir carros na fila
        printf(GRN"\n *Lista de carros na fila de espera = %d carros na fila"WHT,fila);
        int i = 0;
        for (int i  = 0;i < fila;i++){
                  printf(BLU"\n -"WHT"Carro %d\t\tPlaca do Carro: %d\t\tModelo: %s\t\tCor: %s",i+1,filaAtual[i].placa,filaAtual[i].modelo,filaAtual[i].cor);
                  }
        break;
      case 4: //Relatórios
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
                printf("\n *Carros atendidos: %d",carrosatendidos);
                for (int i  = 0;i < carrosatendidos;i++){ 
                  printf(BLU"\n -"WHT"Carro %d\t\tPlaca do Carro: %d\t\tModelo: %s\t\tCor: %s\n  Valor Gasto: R$%.2f\n",i+1,carrosAtendidos1[i].placa,carrosAtendidos1[i].modelo,carrosAtendidos1[i].cor,carrosAtendidos1[i].valorGasto);
                }
                break;
              case 4:
                printf("\n");
                RelatorioTanque(combustivel);
                break;
              case 5:
                printf(GRN"\n  *Gerando relatório..."WHT);
                contRelatorio++;
                FILE *arquivo;
                sprintf(nomeArquivo,"relatorio_%d.txt",contRelatorio); 
                arquivo = fopen(nomeArquivo, "w");
                if (arquivo == NULL){
                  printf("\n\n\n"RED"   Erro de arquivo"WHT);
                  exit(0);
                } 
                else {
                  printf("\n");
                }
                fprintf(arquivo, "-----------------RELATÓRIO %d------------------------\n *Arquivo para impressão: \n\n *Litros vendidos = %.2f litros\n\n *Valor total arrecadado = R$ %.2f\n\n *Gasolina restante no tanque = %.2f/200 litros\n\n *Carros atendidos: %d\n",contRelatorio,litrosvendidos,lucro,combustivel,carrosatendidos);
                for (int i  = 0;i < carrosatendidos;i++){
                  fprintf(arquivo, "\n -Carro %d\t\tPlaca do Carro: %d\t\tModelo: %s\t\tCor: %s\n  Valor Gasto: R$%.2f\n",i+1,carrosAtendidos1[i].placa,carrosAtendidos1[i].modelo,carrosAtendidos1[i].cor,carrosAtendidos1[i].valorGasto);
                }
                fclose(arquivo); //Imprime e fecha o arquivo gerado
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
      case 5: //Encerrar
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
  float validacao1 = 0; //Variável genérica para a validação
  scanf("%f",&validacao1);
  while (validacao1 <= 0){
    printf(RED"\nValor negativo ou nulo informado - Por favor, informe um valor \npositivo\n\n"WHT"Informe um valor válido: ");
    scanf("%f",&validacao1);
  }
  return(validacao1);
}

void RelatorioTanque (float combustivel) {
  if (combustivel >= 150){
                  printf(" *Gasolina restante no tanque = "GRN"%.2f"WHT"/200 litros",combustivel);
                } 
                else { 
                  if (combustivel >= 100){
                    printf(" *Gasolina restante no tanque = "CYN"%.2f"WHT"/200 litros",combustivel);
                  }
                  else{
                    if (combustivel >= 50){
                      printf(" *Gasolina restante no tanque = "MAG"%.2f"WHT"/200 litros",combustivel);
                    }
                    else {
                      if (combustivel >= 10){
                        printf(" *Gasolina restante no tanque = "YEL"%.2f"WHT"/200 litros",combustivel);
                      }
                      else {
                        printf(" *Gasolina restante no tanque = "RED"%.2f"WHT"/200 litros",combustivel);
                      }
                    }
                  }
                }
}

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}