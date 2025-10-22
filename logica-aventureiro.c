#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

int main() {
    // --- Cadastro das duas cartas ---
    struct Carta carta1, carta2;

    // Carta 1
    strcpy(carta1.pais, "Brasil");
    carta1.populacao = 203000000;
    carta1.area = 8516000.0;
    carta1.pib = 2100000000000.0;
    carta1.pontosTuristicos = 50;
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    // Carta 2
    strcpy(carta2.pais, "Argentina");
    carta2.populacao = 45300000;
    carta2.area = 2780000.0;
    carta2.pib = 632000000000.0;
    carta2.pontosTuristicos = 40;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    // --- Menu interativo ---
    int opcao;

    printf("=========================================\n");
    printf("     SUPER TRUNFO - COMPARAÇÃO DE CARTAS\n");
    printf("=========================================\n\n");

    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("\nDigite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=========================================\n");

    // --- Variáveis auxiliares ---
    float valor1 = 0, valor2 = 0;
    char atributo[50];
    int menorVence = 0; // usado para densidade demográfica

    // --- Escolha do atributo usando switch ---
    switch (opcao) {
        case 1:
            strcpy(atributo, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2:
            strcpy(atributo, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3:
            strcpy(atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4:
            strcpy(atributo, "Número de Pontos Turísticos");
            valor1 = carta1.pontosTuristicos;
            valor2 = carta2.pontosTuristicos;
            break;
        case 5:
            strcpy(atributo, "Densidade Demográfica");
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;
            menorVence = 1; // regra invertida
            break;
        default:
            printf("Opção inválida! Encerrando programa.\n");
            return 0;
    }

    // --- Exibição dos dados comparados ---
    printf("Comparação de Cartas (Atributo: %s)\n", atributo);
    printf("-----------------------------------------\n");
    printf("Carta 1 - %s: %.2f\n", carta1.pais, valor1);
    printf("Carta 2 - %s: %.2f\n", carta2.pais, valor2);
    printf("-----------------------------------------\n");

    // --- Lógica de comparação ---
    if (menorVence) {
        // Atributo onde o menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.pais);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.pais);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Regra normal: maior vence
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.pais);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.pais);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    printf("=========================================\n");
    return 0;
}
