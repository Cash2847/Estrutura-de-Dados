#include <stdio.h>
#include "exame.h"

Exame iniciarFila()
{
    Exame e;
    e.frente = 0;
    e.tras   = -1;
    e.qnt    = 0;
    return e;
}

int ExameCheio(Exame e)
{
    return e.qnt == EXAME_MAX;
}

int ExameVazio(Exame e)
{
    return e.qnt == 0;
}

/* Ao atingir capacidade máxima, remove o mais antigo automaticamente */
Exame ExameEnqueue(Exame e, Paciente p)
{
    if (ExameCheio(e)) {
        printf("Fila de exames cheia! Removendo paciente mais antigo: %s\n",
               e.exame[(e.frente) % EXAME_MAX].nome);
        /* descarta o mais antigo */
        e.frente = (e.frente + 1) % EXAME_MAX;
        e.qnt--;
    }
    e.tras = (e.tras + 1) % EXAME_MAX;
    e.exame[e.tras] = p;
    e.qnt++;
    printf("Paciente %s adicionado à fila de Exames.\n", p.nome);
    return e;
}

Exame ExameDequeue(Exame e)
{
    if (ExameVazio(e)) {
        printf("Fila de exames vazia! Nenhum paciente no momento.\n");
    } else {
        printf("\n--- Atendendo Exame ---\n");
        printf("Nome    : %s\n", e.exame[e.frente].nome);
        printf("Idade   : %d\n", e.exame[e.frente].idade);
        printf("Gravidade: %d\n", e.exame[e.frente].gravidade);
        e.frente = (e.frente + 1) % EXAME_MAX;
        e.qnt--;
    }
    return e;
}

void ListarExames(Exame e)
{
    if (ExameVazio(e)) {
        printf("Não há nenhum exame no momento!\n");
    } else {
        printf("\n--- Fila de Exames (frente → trás) ---\n");
        int idx = e.frente;
        for (int i = 0; i < e.qnt; i++) {
            printf("[%d] Nome: %-20s | Idade: %3d | Gravidade: %d\n",
                   i + 1, e.exame[idx].nome, e.exame[idx].idade, e.exame[idx].gravidade);
            idx = (idx + 1) % EXAME_MAX;
        }
    }
}

void RelatorioExames(Exame e)
{
    printf("\n===== Exames/Laboratório (Fila Circular – máx %d) =====\n", EXAME_MAX);
    if (ExameVazio(e)) {
        printf("Fila de exames está vazia.\n");
    } else {
        printf("Pacientes na fila: %d / %d\n", e.qnt, EXAME_MAX);
        ListarExames(e);
    }
    printf("Vagas disponíveis: %d\n", EXAME_MAX - e.qnt);
}
