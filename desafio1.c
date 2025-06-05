#include <stdio.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

int main() {
    Carta carta1 = {"Dragao", 90, 70, 60};
    Carta carta2 = {"Fenix", 85, 75, 65};

    int escolha;

    while (1) {
        printf("\n=== Comparador de Cartas ===\n");
        printf("%s - Força: %d, Velocidade: %d, Inteligência: %d\n", carta1.nome, carta1.forca, carta1.velocidade, carta1.inteligencia);
        printf("%s - Força: %d, Velocidade: %d, Inteligência: %d\n\n", carta2.nome, carta2.forca, carta2.velocidade, carta2.inteligencia);

        printf("Escolha uma opção:\n");
        printf("1 - Comparar um único atributo\n");
        printf("2 - Comparar força e velocidade somados\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Saindo...\n");
            break;
        }

        if (escolha == 1) {
            int atributo;
            printf("Escolha o atributo:\n1 - Força\n2 - Velocidade\n3 - Inteligência\n");
            scanf("%d", &atributo);

            int val1 = 0, val2 = 0;
            char *nomeAtributo;

            switch (atributo) {
                case 1: val1 = carta1.forca; val2 = carta2.forca; nomeAtributo = "Força"; break;
                case 2: val1 = carta1.velocidade; val2 = carta2.velocidade; nomeAtributo = "Velocidade"; break;
                case 3: val1 = carta1.inteligencia; val2 = carta2.inteligencia; nomeAtributo = "Inteligência"; break;
                default:
                    printf("Atributo inválido.\n");
                    continue;
            }

            printf("%s - %d\n%s - %d\n", carta1.nome, val1, carta2.nome, val2);

            if (val1 > val2)
                printf("%s ganhou na %s!\n", carta1.nome, nomeAtributo);
            else if (val2 > val1)
                printf("%s ganhou na %s!\n", carta2.nome, nomeAtributo);
            else
                printf("Empate na %s.\n", nomeAtributo);

        } else if (escolha == 2) {
            int soma1 = carta1.forca + carta1.velocidade;
            int soma2 = carta2.forca + carta2.velocidade;

            printf("%s - Soma Força+Velocidade: %d\n", carta1.nome, soma1);
            printf("%s - Soma Força+Velocidade: %d\n", carta2.nome, soma2);

            if (soma1 > soma2)
                printf("%s ganhou na soma de força e velocidade!\n", carta1.nome);
            else if (soma2 > soma1)
                printf("%s ganhou na soma de força e velocidade!\n", carta2.nome);
            else
                printf("Empate na soma de força e velocidade.\n");
        } else {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}
