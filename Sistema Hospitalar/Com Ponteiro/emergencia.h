#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include "paciente.h"

#define EMERGENCIA_MAX 10

/* Pilha de Emergência gerenciada via ponteiros */
typedef struct {
    Paciente dados[EMERGENCIA_MAX];
    int topo; /* índice do elemento no topo (-1 = vazia) */
} PilhaEmergencia;

void iniciarEmergencia(PilhaEmergencia *pilha);
int  EmergenciaCheia(const PilhaEmergencia *pilha);
int  EmergenciaVazia(const PilhaEmergencia *pilha);
void EmergenciaPush(PilhaEmergencia *pilha, const Paciente *p);
void EmergenciaPop(PilhaEmergencia *pilha);
void ListarEmergencias(const PilhaEmergencia *pilha);
void RelatorioEmergencias(const PilhaEmergencia *pilha);

#endif
