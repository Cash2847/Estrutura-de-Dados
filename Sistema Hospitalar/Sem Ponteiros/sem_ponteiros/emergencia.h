#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include "paciente.h"

#define EMERGENCIA_MAX 10

/* Pilha de Emergência – controle por vetor e variável de topo */
extern Paciente emergencia[EMERGENCIA_MAX];
extern int topo;

void  iniciarEmergencia();
int   EmergenciaCheia();
int   EmergenciaVazia();
void  EmergenciaPush(Paciente p);
void  EmergenciaPop();
void  ListarEmergencias();
void  RelatorioEmergencias();

#endif
