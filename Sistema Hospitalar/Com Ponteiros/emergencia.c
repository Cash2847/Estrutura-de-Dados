#include <stdio.h>
#include "emergencia.h"

void iniciarEmergencia(PilhaEmergencia *pilha)
{
    pilha->topo = -1;
}

int EmergenciaCheia(const PilhaEmergencia *pilha)
{
    return pilha->topo == EMERGENCIA_MAX - 1;
}

int EmergenciaVazia(const PilhaEmergencia *pilha)
{
    return pilha->topo == -1;
}

void EmergenciaPush(PilhaEmergencia *pilha, const Paciente *p)
{
    if (EmergenciaCheia(pilha)) {
        printf("Pilha de emergência cheia! Não é possível aceitar mais pacientes.\n");
    } else {
        pilha->topo++;
        pilha->dados[pilha->topo] = *p;
        printf("Paciente %s adicionado à Emergência.\n", p->nome);
    }
}

void EmergenciaPop(PilhaEmergencia *pilha)
{
    if (EmergenciaVazia(pilha)) {
        printf("Pilha de emergência vazia! Nenhum paciente no momento.\n");
    } else {
        Paciente *atual = &pilha->dados[pilha->topo];
        printf("\n--- Atendendo Emergência ---\n");
        printf("Nome     : %s\n", atual->nome);
        printf("Idade    : %d\n", atual->idade);
        printf("Gravidade: %d\n", atual->gravidade);
        pilha->topo--;
    }
}

void ListarEmergencias(const PilhaEmergencia *pilha)
{
    if (EmergenciaVazia(pilha)) {
        printf("Não há nenhuma emergência no momento!\n");
    } else {
        printf("\n--- Pilha de Emergência (topo → base) ---\n");
        for (int i = pilha->topo; i >= 0; i--) {
            const Paciente *p = &pilha->dados[i];
            printf("[%d] Nome: %-20s | Idade: %3d | Gravidade: %d\n",
                   pilha->topo - i + 1, p->nome, p->idade, p->gravidade);
        }
    }
}

void RelatorioEmergencias(const PilhaEmergencia *pilha)
{
    printf("\n===== Emergências (Pilha) =====\n");
    if (EmergenciaVazia(pilha)) {
        printf("Não há nenhuma emergência no momento!\n");
    } else {
        printf("Pacientes na pilha: %d / %d\n", pilha->topo + 1, EMERGENCIA_MAX);
        ListarEmergencias(pilha);
    }
}
