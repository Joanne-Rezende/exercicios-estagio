#include <stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL,"portuguese");
    int INDICE = 13, SOMA = 0, K = 0;

    while (K < INDICE) {
        K += 1;
        SOMA += K;
    }

    printf("Valor final de SOMA: %d\n", SOMA);
    return 0;
}
