#include <stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL,"portuguese");
    double faturamento_sp = 67836.43;
    double faturamento_rj = 36678.66;
    double faturamento_mg = 29229.88;
    double faturamento_es = 27165.48;
    double faturamento_outros = 19849.53;

    double total_faturamento = faturamento_sp + faturamento_rj + faturamento_mg + faturamento_es + faturamento_outros;

    printf("SP: %.2f%%\n", (faturamento_sp / total_faturamento) * 100);
    printf("RJ: %.2f%%\n", (faturamento_rj / total_faturamento) * 100);
    printf("MG: %.2f%%\n", (faturamento_mg / total_faturamento) * 100);
    printf("ES: %.2f%%\n", (faturamento_es / total_faturamento) * 100);
    printf("Outros: %.2f%%\n", (faturamento_outros / total_faturamento) * 100);

    return 0;
}
