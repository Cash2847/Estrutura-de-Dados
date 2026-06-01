#include <stdio.h>
#include "exame.h"

void iniciarFilaExame(FilaExame *fila)
{
    fila->frente = 0;
    fila->tras   = -1;
    fila->qnt    = 0;
}

int ExameCheio(const FilaExame *fila)
{
    return fila->qnt == EXAME_MAX;
}

int ExameVazio(const FilaExame *fila)
{
    return fila->qnt == 0;
}

/* Ao atingir capacidade máxima, descarta automaticamente o mais antigo */
void ExameEnqueue(FilaExame *fila, const Paciente *p)
{
    if (ExameCheio(fila)) {
        printf("Fila de exames cheia! Removendo paciente mais antigo: %s\n",
               fila->dados[fila->frente].nome);
        fila->frente = (fila->frente + 1) % EXAME_MAX;
        fila->qnt--;
    }
    fila->tras = (fila->tras + 1) % EXAME_MAX;
    fila->dados[fila->tras] = *p;
    fila->qnt++;
    printf("Paciente %s adicionado à fila de Exames.\n", p->nome);
}

void ExameDequeue(FilaExame *fila)
{
    if (ExameVazio(fila)) {
        printf("Fila de exames vazia! Nenhum paciente no momento.\n");
    } else {
        const Paciente *atual = &fila->dados[fila->frente];
        printf("\n--- Atendendo Exame ---\n");
        printf("Nome     : %s\n", atual->nome);
        printf("Idade    : %d\n", atual->idade);
        printf("Gravidade: %d\n", atual->gravidade);
        fila->frente = (fila->frente + 1) % EXAME_MAX;
        fila->qnt--;
    }
}

void ListarExames(const FilaExame *fila)
{
    if (ExameVazio(fila)) {
        printf("Não há nenhum exame no momento!\n");
    } else {
        printf("\n--- Fila de Exames ---\n");
        int idx = fila->frente;
        for (int i = 0; i < fila->qnt; i++) {
            const Paciente *p = &fila->dados[idx];
            printf("[%d] Nome: %-20s | Idade: %3d | Gravidade: %d\n",
                   i + 1, p->nome, p->idade, p->gravidade);
            idx = (idx + 1) % EXAME_MAX;
        }
    }
}

void RelatorioExames(const FilaExame *fila)
{
    printf("\n===== Exames/Laboratório (Fila Circular – máx %d) =====\n", EXAME_MAX);
    if (ExameVazio(fila)) {
        printf("Fila de exames está vazia.\n");
    } else {
        printf("Pacientes na fila: %d / %d\n", fila->qnt, EXAME_MAX);
        ListarExames(fila);
    }
    printf("Vagas disponíveis: %d\n", EXAME_MAX - fila->qnt);
}
