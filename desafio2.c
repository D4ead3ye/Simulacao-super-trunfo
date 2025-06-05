#include <stdio.h>

// Definição da estrutura Carta com três atributos
typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

int main() {
    // Inicialização das cartas com seus atributos
    Carta carta1 = {"Minotauro", 75, 60, 50};
    Carta carta2 = {"Unicórnio", 65, 85, 90};

    int escolha;

    // Menu principal para escolher o modo de comparação
    printf("=== Comparador de Cartas ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Força\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligência\n");
    printf("4 - Comparar múltiplos atributos (vencedor em pelo menos dois)\n");
    printf("0 - Sair\n");
    printf("Digite a sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 0:
            printf("Programa encerrado.\n");
            break;

        case 1:
            if (carta1.forca > carta2.forca)
                printf("%s venceu na Força.\n", carta1.nome);
            else if (carta1.forca < carta2.forca)
                printf("%s venceu na Força.\n", carta2.nome);
            else
                printf("Empate na Força.\n");
            break;

        case 2:
            if (carta1.velocidade > carta2.velocidade)
                printf("%s venceu na Velocidade.\n", carta1.nome);
            else if (carta1.velocidade < carta2.velocidade)
                printf("%s venceu na Velocidade.\n", carta2.nome);
            else
                printf("Empate na Velocidade.\n");
            break;

        case 3:
            if (carta1.inteligencia > carta2.inteligencia)
                printf("%s venceu na Inteligência.\n", carta1.nome);
            else if (carta1.inteligencia < carta2.inteligencia)
                printf("%s venceu na Inteligência.\n", carta2.nome);
            else
                printf("Empate na Inteligência.\n");
            break;

        case 4: {
            // Contador de atributos vencidos por cada carta
            int vitoriaCarta1 = 0, vitoriaCarta2 = 0;

            // Comparar Força
            if (carta1.forca > carta2.forca) vitoriaCarta1++;
            else if (carta1.forca < carta2.forca) vitoriaCarta2++;

            // Comparar Velocidade
            if (carta1.velocidade > carta2.velocidade) vitoriaCarta1++;
            else if (carta1.velocidade < carta2.velocidade) vitoriaCarta2++;

            // Comparar Inteligência
            if (carta1.inteligencia > carta2.inteligencia) vitoriaCarta1++;
            else if (carta1.inteligencia < carta2.inteligencia) vitoriaCarta2++;

            // Verifica quem venceu em pelo menos dois atributos
            if (vitoriaCarta1 >= 2)
                printf("%s venceu em pelo menos dois atributos.\n", carta1.nome);
            else if (vitoriaCarta2 >= 2)
                printf("%s venceu em pelo menos dois atributos.\n", carta2.nome);
            else
                printf("Disputa equilibrada entre as cartas.\n");

            break;
        }

        default:
            printf("Opção inválida. Por favor, escolha um número válido.\n");
    }

    return 0;
}
