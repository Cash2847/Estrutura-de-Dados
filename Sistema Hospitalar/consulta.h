# ifndef CONSULTA_H
# define CONSULTA_H
# include "paciente.h"

# define CONSULTA_MAX 10

void iniciarConsulta();
int ConsultaCheia();
int ConsultaVazia();
void ConsultaEnqueue(Paciente p);
void ConsultaDequeue();
void ListarConsultas();
void RelatorioConsultas();

# endif