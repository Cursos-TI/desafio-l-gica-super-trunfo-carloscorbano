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
    Carta sp, rj;

    // reset de memoria
    memset(&sp, 0, sizeof(Carta));
    memset(&rj, 0, sizeof(Carta));

    // carta 1 = SP
    strcpy(sp.estado, "SP");
    strcpy(sp.codigo, "A01");
    strcpy(sp.nome, "Sao Paulo");
    sp.populacao = 11451245;
    sp.area = 1521.11f;
    sp.pib = 828.9f;
    sp.numPontosTuristicos = 30;

    // Cálculo dos atributos derivados da Carta 1
    sp.densidadePopulacional = sp.populacao / sp.area;
    sp.pibPerCapita = (sp.pib * 1e9) / sp.populacao;
    /*
    Para cada carta, calcule o "Super Poder" somando todos os atributos numéricos 
    (população, área, PIB, número de pontos turísticos, PIB per capita e o inverso 
    da densidade populacional – quanto menor a densidade, maior o "poder"). 
    Armazene o Super Poder como float. 
    Atenção: Preste muita atenção na conversão de tipos ao somar valores de tipos diferentes!
    */
    sp.poder = (float)sp.populacao + sp.area + (sp.pib * 1e9) + (float)sp.numPontosTuristicos + sp.pibPerCapita + (1.0f / sp.densidadePopulacional);

    // carta 1 = rj
    strcpy(rj.estado, "RJ");
    strcpy(rj.codigo, "B02");
    strcpy(rj.nome, "Rio de Janeiro");
    rj.populacao = 6211423;
    rj.area = 1200.33f;
    rj.pib = 364.5f;
    rj.numPontosTuristicos = 25;

    // Cálculo dos atributos derivados da Carta 1
    rj.densidadePopulacional = rj.populacao / rj.area;
    rj.pibPerCapita = (rj.pib * 1e9) / rj.populacao;
    rj.poder = (float)rj.populacao + rj.area + (rj.pib * 1e9) + (float)rj.numPontosTuristicos + rj.pibPerCapita + (1.0f / rj.densidadePopulacional);
    
    // Exibição dos dados da Carta 1
    printf("\nDados da Carta 1:\n");
    printf("Estado: %s\n", sp.estado);
    printf("Código: %s\n", sp.codigo);
    printf("Nome da Cidade: %s\n", sp.nome);
    printf("População: %d\n", sp.populacao);
    printf("Área: %.2f km²\n", sp.area);
    printf("PIB: %.2f bilhões de reais\n", sp.pib);
    printf("Número de Pontos Turísticos: %d\n", sp.numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", sp.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", sp.pibPerCapita);

    // Exibição dos dados da Carta 2
    printf("\nDados da Carta 2:\n");
    printf("Estado: %s\n", rj.estado);
    printf("Código: %s\n", rj.codigo);
    printf("Nome da Cidade: %s\n", rj.nome);
    printf("População: %d\n", rj.populacao);
    printf("Área: %.2f km²\n", rj.area);
    printf("PIB: %.2f bilhões de reais\n", rj.pib);
    printf("Número de Pontos Turísticos: %d\n", rj.numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km² \n", rj.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", rj.pibPerCapita);

    //escolha do atributo pelo usuario
    printf("Escolha o atributo para comparação\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demográfica\n");

    int escolha = 0;
    scanf(" %i", &escolha);

    printf("Batalha entre %s vs %s\n", sp.nome, rj.nome);

    switch (escolha)
    {
    case 1: // população
        printf("Escolhido atributo de população!\n");
        printf("Sao Paulo: %i\n", sp.populacao);
        printf("Rio de Janeiro: %i\n", rj.populacao);
        if(sp.populacao > rj.populacao)
        {
            printf("Sao Paulo venceu!\n");
        }
        else if(sp.populacao < rj.populacao)
        {
            printf("Rio de Janeiro venceu!\n");
        }
        else
        {
            printf("Empatou!\n");
        }
        break;
    case 2: // area
        printf("Escolhido atributo de Area!\n");
        printf("Sao Paulo: %.2f\n", sp.area);
        printf("Rio de Janeiro: %.2f\n", rj.area);
        if(sp.area > rj.area)
        {
            printf("Sao Paulo venceu!\n");
        }
        else if(sp.area < rj.area)
        {
            printf("Rio de Janeiro venceu!\n");
        }
        else
        {
            printf("Empatou!\n");
        }
        break;
    case 3: // PIB
        printf("Escolhido atributo de PIB!\n");
        printf("Sao Paulo: %.2f\n", sp.pib);
        printf("Rio de Janeiro: %.2f\n", rj.pib);
        if(sp.pib > rj.pib)
        {
            printf("Sao Paulo venceu!\n");
        }
        else if(sp.pib < rj.pib)
        {
            printf("Rio de Janeiro venceu!\n");
        }
        else
        {
            printf("Empatou!\n");
        }
        break;
    case 4: // pontos turisticos
        printf("Escolhido atributo de Pontos Turisticos!\n");
        printf("Sao Paulo: %i\n", sp.numPontosTuristicos);
        printf("Rio de Janeiro: %i\n", rj.numPontosTuristicos);
        if(sp.numPontosTuristicos > rj.numPontosTuristicos)
        {
            printf("Sao Paulo venceu!\n");
        }
        else if(sp.numPontosTuristicos < rj.numPontosTuristicos)
        {
            printf("Rio de Janeiro venceu!\n");
        }
        else
        {
            printf("Empatou!\n");
        }
        break;
    case 5: // densidade demografica
        printf("Escolhido atributo de Densidade Demografica!\n");
        printf("Sao Paulo: %.2f\n", sp.densidadePopulacional);
        printf("Rio de Janeiro: %.2f\n", rj.densidadePopulacional);
        if(sp.densidadePopulacional < rj.densidadePopulacional)
        {
            printf("Sao Paulo venceu!\n");
        }
        else if(sp.densidadePopulacional > rj.densidadePopulacional)
        {
            printf("Rio de Janeiro venceu!\n");
        }
        else
        {
            printf("Empatou!\n");
        }
        break;
    case 0:
    default:
        printf("Valor inserido não é válido...");
        break;
    }
    return 0;
}
