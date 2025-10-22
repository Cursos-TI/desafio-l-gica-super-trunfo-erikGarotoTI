#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para exibir o menu de atributos (dinâmico)
void exibirMenu(int atributoEscolhido) {
    printf("\nEscolha um atributo:\n");
    if (atributoEscolhido != 1) printf("1 - População\n");
    if (atributoEscolhido != 2) printf("2 - Área\n");
    if (atributoEscolhido != 3) printf("3 - PIB\n");
    if (atributoEscolhido != 4) printf("4 - Número de Pontos Turísticos\n");
    if (atributoEscolhido != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

int main() {
    struct Carta carta1, carta2;

    // --- Cadastro das cartas ---
    strcpy(carta1.pais, "Brasil");
    carta1.populacao = 203000000;
    carta1.area = 8516000.0;
    carta1.pib = 2100000000000.0;
    carta1.pontosTuristicos = 50;
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    strcpy(carta2.pais, "Argentina");
    carta2.populacao = 45300000;
    carta2.area = 2780000.0;
    carta2.pib = 632000000000.0;
    carta2.pontosTuristicos = 40;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int opcao1 = 0, opcao2 = 0;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    char atributo1[50], atributo2[50];
    int menorVence1 = 0, menorVence2 = 0;

    printf("=========================================\n");
    printf("      SUPER TRUNFO - DESAFIO FINAL\n");
    printf("=========================================\n");

    // --- Escolha do primeiro atributo ---
    exibirMenu(0);
    scanf("%d", &opcao1);

    // Switch do primeiro atributo
    switch (opcao1) {
        case 1:
            strcpy(atributo1, "População");
            valor1_c1 = carta1.populacao;
            valor1_c2 = carta2.populacao;
            break;
        case 2:
            strcpy(atributo1, "Área");
            valor1_c1 = carta1.area;
            valor1_c2 = carta2.area;
            break;
        case 3:
            strcpy(atributo1, "PIB");
            valor1_c1 = carta1.pib;
            valor1_c2 = carta2.pib;
            break;
        case 4:
            strcpy(atributo1, "Número de Pontos Turísticos");
            valor1_c1 = carta1.pontosTuristicos;
            valor1_c2 = carta2.pontosTuristicos;
            break;
        case 5:
            strcpy(atributo1, "Densidade Demográfica");
            valor1_c1 = carta1.densidadeDemografica;
            valor1_c2 = carta2.densidadeDemografica;
            menorVence1 = 1;
            break;
        default:
            printf("Opção inválida! Encerrando o jogo.\n");
            return 0;
    }

    // --- Escolha do segundo atributo (dinâmico, sem repetir) ---
    exibirMenu(opcao1);
    scanf("%d", &opcao2);

    // Evita repetição do mesmo atributo
    if (opcao2 == opcao1) {
        printf("\nVocê escolheu o mesmo atributo duas vezes! Encerrando o jogo.\n");
        return 0;
    }

    // Switch do segundo atributo
    switch (opcao2) {
        case 1:
            strcpy(atributo2, "População");
            valor2_c1 = carta1.populacao;
            valor2_c2 = carta2.populacao;
            break;
        case 2:
            strcpy(atributo2, "Área");
            valor2_c1 = carta1.area;
            valor2_c2 = carta2.area;
            break;
        case 3:
            strcpy(atributo2, "PIB");
            valor2_c1 = carta1.pib;
            valor2_c2 = carta2.pib;
            break;
        case 4:
            strcpy(atributo2, "Número de Pontos Turísticos");
            valor2_c1 = carta1.pontosTuristicos;
            valor2_c2 = carta2.pontosTuristicos;
            break;
        case 5:
            strcpy(atributo2, "Densidade Demográfica");
            valor2_c1 = carta1.densidadeDemografica;
            valor2_c2 = carta2.densidadeDemografica;
            menorVence2 = 1;
            break;
        default:
            printf("Opção inválida! Encerrando o jogo.\n");
            return 0;
    }

    printf("\n=========================================\n");
    printf("Comparação entre %s e %s\n", carta1.pais, carta2.pais);
    printf("Atributos escolhidos: %s e %s\n", atributo1, atributo2);
    printf("-----------------------------------------\n");

    // --- Comparação dos dois atributos individualmente ---
    // Usando operador ternário para elegância
    float resultado1_c1 = menorVence1 ? (1 / valor1_c1) : valor1_c1;
    float resultado1_c2 = menorVence1 ? (1 / valor1_c2) : valor1_c2;
    float resultado2_c1 = menorVence2 ? (1 / valor2_c1) : valor2_c1;
    float resultado2_c2 = menorVence2 ? (1 / valor2_c2) : valor2_c2;

    // --- Soma ponderada dos dois atributos ---
    float soma1 = resultado1_c1 + resultado2_c1;
    float soma2 = resultado1_c2 + resultado2_c2;

    // --- Exibição detalhada ---
    printf("%s - %s: %.2f | %s: %.2f | Soma total: %.2f\n",
           carta1.pais, atributo1, valor1_c1, atributo2, valor2_c1, soma1);
    printf("%s - %s: %.2f | %s: %.2f | Soma total: %.2f\n",
           carta2.pais, atributo1, valor1_c2, atributo2, valor2_c2, soma2);
    printf("-----------------------------------------\n");

    // --- Determinar o vencedor ---
    if (soma1 > soma2)
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.pais);
    else if (soma2 > soma1)
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.pais);
    else
        printf("Resultado: Empate!\n");

    printf("=========================================\n");
    return 0;
}
