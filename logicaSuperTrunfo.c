#include <stdio.h>
#include <string.h>
// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct {
  char estado[3];  //< Estado, uma letra de 'A' a 'H'
  char codigo[4]; //< Código da Carta, ex: A01
  char nome[50]; //< Nome da Cidade
  int populacao; //< População
  float area; //< Área em km²
  float pib; //< PIB
  int numPontosTuristicos; //< Número de Pontos Turísticos

  // obtido atraves calculos (não atraves de input)
  float densidadePopulacional; //< Densidade Populacional
  float pibPerCapita; //< PIB per Capita
  float poder;
} Carta;

int main() {
    // Área para definição das variáveis para armazenar as propriedades das cidades
    Carta carta1, carta2;

    // reset de memoria
    memset(&carta1, 0, sizeof(Carta));
    memset(&carta2, 0, sizeof(Carta));

    // Entrada dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %2s", carta1.estado);
    printf("Código: ");
    scanf(" %3s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", carta1.nome);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.numPontosTuristicos);

    // Cálculo dos atributos derivados da Carta 1
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1e9) / carta1.populacao;
    /*
    Para cada carta, calcule o "Super Poder" somando todos os atributos numéricos 
    (população, área, PIB, número de pontos turísticos, PIB per capita e o inverso 
    da densidade populacional – quanto menor a densidade, maior o "poder"). 
    Armazene o Super Poder como float. 
    Atenção: Preste muita atenção na conversão de tipos ao somar valores de tipos diferentes!
    */
    carta1.poder = (float)carta1.populacao + carta1.area + (carta1.pib * 1e9) + (float)carta1.numPontosTuristicos + carta1.pibPerCapita + (1.0f / carta1.densidadePopulacional);

    // Entrada dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %2s", carta2.estado);
    printf("Código: ");
    scanf(" %3s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", carta2.nome);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.numPontosTuristicos);
    
    // Cálculo dos atributos derivados da Carta 2
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1e9) / carta2.populacao;
    carta2.poder = (float)carta2.populacao + carta2.area + (carta2.pib * 1e9) + (float)carta2.numPontosTuristicos + carta2.pibPerCapita + (1.0f / carta2.densidadePopulacional);
    
    // Exibição dos dados da Carta 1
    printf("\nDados da Carta 1:\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    // Exibição dos dados da Carta 2
    printf("\nDados da Carta 2:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km² \n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);

    /*
    Comparar um atributo escolhido: Você deverá escolher apenas um dos atributos numéricos 
    (População, Área, PIB, Densidade Populacional ou PIB per capita) para realizar a 
    comparação entre as duas cartas. Essa escolha deve ser feita diretamente no código, 
    não pela entrada do usuário.
    
    Para todos os atributos, exceto Densidade Populacional, a carta com o maior valor vence.
 
    Para Densidade Populacional, a carta com o menor valor vence.


    Comparação de cartas (Atributo: População):

    Carta 1 - São Paulo (SP): 12.300.000

    Carta 2 - Rio de Janeiro (RJ): 6.000.000

    Resultado: Carta 1 (São Paulo) venceu!
    */

    // escolhido o atributo PIB per capita
    printf("\n");
    printf("Carta 1 - %s (%s): %.3f\n", carta1.nome, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.3f\n", carta2.nome, carta2.estado, carta2.pibPerCapita);
    printf("\n");

    Carta cartaVencedora;
    if(carta1.pibPerCapita > carta2.pibPerCapita)
    {
        memcpy(&cartaVencedora, &carta1, sizeof(Carta));
    }
    else
    {
        memcpy(&cartaVencedora, &carta2, sizeof(Carta));
    }

    printf("Resultado: %s venceu!\n", cartaVencedora.nome);
    printf("\n");
    return 0;
}
