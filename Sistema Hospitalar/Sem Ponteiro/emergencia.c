#include <stdio.h>
#include "emergencia.h"

Paciente emergencia[EMERGENCIA_MAX];
int topo = -1;

void iniciarEmergencia()
{
    topo = -1;
}

int EmergenciaCheia()
{
    return topo == EMERGENCIA_MAX - 1;
}

int EmergenciaVazia()
{
    return topo == -1;
}

void EmergenciaPush(Paciente p)
{
    if (EmergenciaCheia()) {
        printf("Pilha de emergência cheia! Não é possível aceitar mais pacientes.\n");
    } else {
        topo++;
        emergencia[topo] = p;
        printf("Paciente %s adicionado à Emergência.\n", p.nome);
    }
}

void EmergenciaPop()
{
    if (EmergenciaVazia()) {
        printf("Pilha de emergência vazia! Nenhum paciente no momento.\n");
    } else {
        printf("\n--- Atendendo Emergência ---\n");
        printf("Nome    : %s\n", emergencia[topo].nome);
        printf("Idade   : %d\n", emergencia[topo].idade);
        printf("Gravidade: %d\n", emergencia[topo].gravidade);
        topo--;
    }
}

void ListarEmergencias()
{
    if (EmergenciaVazia()) {
        printf("Não há nenhuma emergência no momento!\n");
    } else {
        printf("\n--- Fila de Emergência (topo → base) ---\n");
        for (int i = topo; i >= 0; i--) {
            printf("[%d] Nome: %-20s | Idade: %3d | Gravidade: %d\n",
                   i + 1, emergencia[i].nome, emergencia[i].idade, emergencia[i].gravidade);
        }
    }
}

void RelatorioEmergencias()
{
    printf("\n===== Emergências (Pilha) =====\n");
    if (EmergenciaVazia()) {
        printf("Não há nenhuma emergência no momento!\n");
    } else {
        printf("Pacientes na pilha: %d / %d\n", topo + 1, EMERGENCIA_MAX);
        ListarEmergencias();
    }
}
