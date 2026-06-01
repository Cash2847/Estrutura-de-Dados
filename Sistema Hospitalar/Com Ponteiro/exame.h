#ifndef EXAME_H
#define EXAME_H

#include "paciente.h"

#define EXAME_MAX 8  /* capacidade da fila circular */

/* Fila Circular de Exames gerenciada via ponteiros */
typedef struct {
    Paciente dados[EXAME_MAX];
    int frente;
    int tras;
    int qnt;
} FilaExame;

void iniciarFilaExame(FilaExame *fila);
int  ExameCheio(const FilaExame *fila);
int  ExameVazio(const FilaExame *fila);
void ExameEnqueue(FilaExame *fila, const Paciente *p);
void ExameDequeue(FilaExame *fila);
void ListarExames(const FilaExame *fila);
void RelatorioExames(const FilaExame *fila);

#endif
