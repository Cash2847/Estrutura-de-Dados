#ifndef CONSULTA_H
#define CONSULTA_H

#include "paciente.h"

#define CONSULTA_MAX 10

/* Fila simples de Consultas – controle por frente e trás */
extern Paciente consulta[CONSULTA_MAX];
extern int frente_c;
extern int tras_c;

void  iniciarConsulta();
int   ConsultaCheia();
int   ConsultaVazia();
void  ConsultaEnqueue(Paciente p);
void  ConsultaDequeue();
void  ListarConsultas();
void  RelatorioConsultas();

#endif
