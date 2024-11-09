#include <stdio.h>
#include<locale.h>

int is_in_fibonacci(int n) {
    int a = 0, b = 1, next = 0;

    while (next <= n) {
        if (next == n) {
            return 1;  // Pertence à sequência
        }
        a = b;
        b = next;
        next = a + b;
    }
    return 0;  // Não pertence à sequência
}

int main() {
	setlocale(LC_ALL,"portuguese");
    int numero;
    printf("Informe um número: ");
    scanf("%d", &numero);

    if (is_in_fibonacci(numero)) {
        printf("%d pertence a sequência de Fibonacci.\n", numero);
    } else {
        printf("%d não pertence a sequência de Fibonacci.\n", numero);
    }
    
    return 0;
}
