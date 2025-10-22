#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Declaração das duas cartas
    struct Carta carta1, carta2;

    // --- Cadastro da Carta 1 ---
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.nomeCidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699280000000.0; // PIB em reais
    carta1.pontosTuristicos = 30;

    // --- Cadastro da Carta 2 ---
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "A02");
    strcpy(carta2.nomeCidade, "Rio de Janeiro");
    carta2.populacao = 6748000;
    carta2.area = 1182.30;
    carta2.pib = 364000000000.0;
    carta2.pontosTuristicos = 25;

    // --- Cálculo dos atributos derivados ---
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // --- Exibição das cartas ---
    printf("=== CARTA 1 ===\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta1.pibPerCapita);

    printf("=== CARTA 2 ===\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta2.pibPerCapita);

    // --- Comparação ---
    // Escolha do atributo (pode mudar para populacao, area, pib, densidadePopulacional etc.)
    printf("=== COMPARAÇÃO DE CARTAS (Atributo: PIB per capita) ===\n");
    printf("%s (%.2f) x %s (%.2f)\n",
           carta1.nomeCidade, carta1.pibPerCapita,
           carta2.nomeCidade, carta2.pibPerCapita);

    // Para PIB per capita, vence quem tiver MAIOR valor
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
