#include <stdio.h>
#include "consulta.h"

void iniciarConsulta(FilaConsulta *fila)
{
    fila->frente = 0;
    fila->tras   = -1;
}

int ConsultaCheia(const FilaConsulta *fila)
{
    return fila->tras == CONSULTA_MAX - 1;
}

int ConsultaVazia(const FilaConsulta *fila)
{
    return fila->frente > fila->tras;
}

void ConsultaEnqueue(FilaConsulta *fila, const Paciente *p)
{
    if (ConsultaCheia(fila)) {
        printf("Fila de consultas cheia! Não é possível aceitar mais pacientes.\n");
    } else {
        fila->tras++;
        fila->dados[fila->tras] = *p;
        printf("Paciente %s adicionado à fila de Consultas.\n", p->nome);
    }
}

void ConsultaDequeue(FilaConsulta *fila)
{
    if (ConsultaVazia(fila)) {
        printf("Fila de consultas vazia! Nenhum paciente no momento.\n");
    } else {
        Paciente *atual = &fila->dados[fila->frente];
        printf("\n--- Atendendo Consulta ---\n");
        printf("Nome     : %s\n", atual->nome);
        printf("Idade    : %d\n", atual->idade);
        printf("Gravidade: %d\n", atual->gravidade);
        fila->frente++;
    }
}

void ListarConsultas(const FilaConsulta *fila)
{
    if (ConsultaVazia(fila)) {
        printf("Não há nenhuma consulta no momento!\n");
    } else {
        printf("\n--- Fila de Consultas (frente → trás) ---\n");
        int pos = 1;
        for (int i = fila->frente; i <= fila->tras; i++) {
            const Paciente *p = &fila->dados[i];
            printf("[%d] Nome: %-20s | Idade: %3d | Gravidade: %d\n",
                   pos++, p->nome, p->idade, p->gravidade);
        }
    }
}

void RelatorioConsultas(const FilaConsulta *fila)
{
    printf("\n===== Consultas Agendadas (Fila Simples) =====\n");
    if (ConsultaVazia(fila)) {
        printf("Não há nenhuma consulta no momento!\n");
    } else {
        printf("Pacientes na fila: %d / %d\n",
               fila->tras - fila->frente + 1, CONSULTA_MAX);
        ListarConsultas(fila);
    }
}
