#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nomecidade[50];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// calculando a densidade e PIB per capita
void calcularindicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomecidade, carta.estado);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhoes\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosturisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("\n");
}

int main() {
    // Cadastro das cartas
    Carta carta1 = {"RR", "carta1", "Roraima", 716793, 224.301, 2100.00, 20};
    Carta carta2 = {"SC", "carta2", "florianopolis", 537211, 674.44, 23.00, 30};

    // Cálculo dos indicadores para saber os resultados 
    calcularindicadores(&carta1);
    calcularindicadores(&carta2);

    // Exibir cartas para fazzer a comparacao
    printf("Carta 1 \n");
    exibirCarta(carta1);
    printf(" Carta 2 \n");
    exibirCarta(carta2);

    //  COMPARAÇÃO 
    // escolhendo os tributos para a comparacao das duas cartas
    //  populacao, area, pib, densidadePopulacional, pibPerCapita

    printf("Comparacao de cartas (Atributo: Populacao):\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nomecidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomecidade, carta2.estado, carta2.populacao);

    
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomecidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomecidade);
    } else {
        printf("Resultado: Empate!\n");
    }
    // o if e o else sao estrutura de repeticao se a carta1 venceu longo a carta2 perde. 

    return 0;
}

