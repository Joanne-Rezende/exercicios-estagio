#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"  
#include "cJSON.c"  

// Função para ler o conteúdo do arquivo JSON
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* content = (char*)malloc(length + 1);
    fread(content, 1, length, file);
    fclose(file);
    content[length] = '\0';
    return content;
}

int main() {
    char* json_data = read_file("dados.json"); // Arquivo JSON com o faturamento diário

    if (json_data == NULL) {
        return 1;
    }

    cJSON* json = cJSON_Parse(json_data);
    if (json == NULL) {
        printf("Erro ao analisar o JSON\n");
        free(json_data);
        return 1;
    }

    int dias_acima_media = 0, dias_com_faturamento = 0;
    double soma_faturamento = 0.0, menor = -1, maior = -1;

    cJSON* dia_data;
    cJSON_ArrayForEach(dia_data, json) {
        cJSON* valor = cJSON_GetObjectItem(dia_data, "valor");
        if (cJSON_IsNumber(valor) && valor->valuedouble > 0) {
            double faturamento_diario = valor->valuedouble;
            
            // Atualizar menor e maior valor
            if (menor == -1 || faturamento_diario < menor) menor = faturamento_diario;
            if (maior == -1 || faturamento_diario > maior) maior = faturamento_diario;
            
            // Somar o faturamento para calcular a média
            soma_faturamento += faturamento_diario;
            dias_com_faturamento++;
        }
    }

    // Calcular a média mensal (ignorando dias sem faturamento)
    double media_mensal = soma_faturamento / dias_com_faturamento;

    // Contar dias com faturamento acima da média
    cJSON_ArrayForEach(dia_data, json) {
        cJSON* valor = cJSON_GetObjectItem(dia_data, "valor");
        if (cJSON_IsNumber(valor) && valor->valuedouble > media_mensal) {
            dias_acima_media++;
        }
    }

    // Exibir resultados
    printf("Menor valor de faturamento: %.2f\n", menor);
    printf("Maior valor de faturamento: %.2f\n", maior);
    printf("Dias com faturamento acima da media mensal: %d\n", dias_acima_media);

    // Limpeza
    cJSON_Delete(json);
    free(json_data);

    return 0;
}
