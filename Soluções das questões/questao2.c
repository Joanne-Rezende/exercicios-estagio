#include <stdio.h>
#include<locale.h>

int is_in_fibonacci(int n) {
    int a = 0, b = 1, next = 0;

    while (next <= n) {
        if (next == n) {
            return 1;  // Pertence � sequ�ncia
        }
        a = b;
        b = next;
        next = a + b;
    }
    return 0;  // N�o pertence � sequ�ncia
}

int main() {
	setlocale(LC_ALL,"portuguese");
    int numero;
    printf("Informe um n�mero: ");
    scanf("%d", &numero);

    if (is_in_fibonacci(numero)) {
        printf("%d pertence a sequ�ncia de Fibonacci.\n", numero);
    } else {
        printf("%d n�o pertence a sequ�ncia de Fibonacci.\n", numero);
    }
    
    return 0;
}
