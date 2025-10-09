#include <stdio.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;    // calculada: populacao / area
    float pibPerCapita; // calculada: pib / populacao
} Carta;

int main() {
    Carta carta1, carta2;

    // ----------------------------
    // Passo 1: Ler dados da carta 1
    // ----------------------------
    printf("Digite os dados da carta 1:\n");
    printf("Estado: "); 
    scanf("%s", carta1.estado);
    printf("Codigo da carta: "); 
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: "); 
    scanf("%s", carta1.nome);
    printf("Populacao: "); 
    scanf("%d", &carta1.populacao);
    printf("Area: "); 
    scanf("%f", &carta1.area);
    printf("PIB: "); 
    scanf("%f", &carta1.pib);
    printf("Pontos turisticos: "); 
    scanf("%d", &carta1.pontosTuristicos);

    // Calcular densidade populacional e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // ----------------------------
    // Passo 2: Ler dados da carta 2
    // ----------------------------
    printf("\nDigite os dados da carta 2:\n");
    printf("Estado: "); 
    scanf("%s", carta2.estado);
    printf("Codigo da carta: "); 
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: "); 
    scanf("%s", carta2.nome);
    printf("Populacao: "); 
    scanf("%d", &carta2.populacao);
    printf("Area: "); 
    scanf("%f", &carta2.area);
    printf("PIB: "); 
    scanf("%f", &carta2.pib);
    printf("Pontos turisticos: "); 
    scanf("%d", &carta2.pontosTuristicos);

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

  
   
    int atributoEscolhido = 1; // 1 = populacao, 2 = area, 3 = PIB, 4 = densidade, 5 = pibPerCapita

   
    if (atributoEscolhido == 1) { // População
        printf("\nComparacao de cartas (Atributo: Populacao):\n");
        printf("Carta 1 - %s: %d\n", carta1.nome, carta1.populacao);
        printf("Carta 2 - %s: %d\n", carta2.nome, carta2.populacao);

        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

   

    return 0;
}
