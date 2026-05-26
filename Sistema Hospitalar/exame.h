# ifndef EXAME_H
# define EXAME_H
# include "paciente.h"
# define EXAME_MAX 10

typedef struct {
    int frente;
    int tras;
    int qnt;
    Paciente exame[EXAME_MAX];
    
} Exame;

Exame iniciarFila();

int ExameCheio(Exame e);

int ExameVazio(Exame e);

Exame ExameEnqueue(Exame e, Paciente p);

Exame ExameDequeue(Exame e);

void ListarExames(Exame e);

void RelatorioExames(Exame e);

# endif