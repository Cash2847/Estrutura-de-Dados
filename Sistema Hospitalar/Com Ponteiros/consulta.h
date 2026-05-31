#ifndef CONSULTA_H
#define CONSULTA_H

#include "paciente.h"

#define CONSULTA_MAX 10

/* Fila simples de Consultas gerenciada via ponteiros */
typedef struct {
    Paciente dados[CONSULTA_MAX];
    int frente;
    int tras;
} FilaConsulta;

void iniciarConsulta(FilaConsulta *fila);
int  ConsultaCheia(const FilaConsulta *fila);
int  ConsultaVazia(const FilaConsulta *fila);
void ConsultaEnqueue(FilaConsulta *fila, const Paciente *p);
void ConsultaDequeue(FilaConsulta *fila);
void ListarConsultas(const FilaConsulta *fila);
void RelatorioConsultas(const FilaConsulta *fila);

#endif
