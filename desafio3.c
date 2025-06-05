#include <stdio.h>

// Estrutura Carta com atributos
typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

// Função para pegar o valor do atributo escolhido da carta
int valorDoAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.forca;
        case 2: return c.velocidade;
        case 3: return c.inteligencia;
        default: return -1; // Valor inválido
    }
}

int main() {
    Carta carta1 = {"Gigante", 85, 60, 70};
    Carta carta2 = {"Elfo", 60, 90, 85};

    int att1, att2;

    printf("Escolha o primeiro atributo (1-Força, 2-Velocidade, 3-Inteligência): ");
    scanf("%d", &att1);
    printf("Escolha o segundo atributo (1-Força, 2-Velocidade, 3-Inteligência): ");
    scanf("%d", &att2);

    // Validar entradas
    if ((att1 < 1 || att1 > 3) || (att2 < 1 || att2 > 3)) {
        printf("Atributo inválido escolhido. Por favor, escolha números entre 1 e 3.\n");
        return 1; // Encerra o programa com erro
    }

    int valor1 = valorDoAtributo(carta1, att1) + valorDoAtributo(carta1, att2);
    int valor2 = valorDoAtributo(carta2, att1) + valorDoAtributo(carta2, att2);

    printf("\nPontuação total de %s: %d\n", carta1.nome, valor1);
    printf("Pontuação total de %s: %d\n", carta2.nome, valor2);

    // Decidir vencedor usando operador ternário
    (valor1 > valor2) ? printf("%s venceu!\n", carta1.nome) :
    (valor2 > valor1) ? printf("%s venceu!\n", carta2.nome) :
    printf("Empate!\n");

        return 0;
}