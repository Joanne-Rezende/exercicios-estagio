#include <stdio.h>
#include <string.h>
#include<locale.h>

void inverter_string(char *s) {
    int inicio = 0;
    int fim = strlen(s) - 1;
    while (inicio < fim) {
        char temp = s[inicio];
        s[inicio] = s[fim];
        s[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
	setlocale(LC_ALL,"portuguese");
    char string[100];
    printf("Informe uma string: ");
    scanf("%s", string);

    inverter_string(string);
    printf("String invertida: %s\n", string);

    return 0;
}
