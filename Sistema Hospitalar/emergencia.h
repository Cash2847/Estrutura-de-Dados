# ifndef EMERGENCIA_H
# define EMERGENCIA_H
# include "paciente.h"

# define EMERGENCIA_MAX 10

void iniciarEmergencia();
int EmergenciaCheia();
int EmergenciaVazia();
void EmergenciaPush(Paciente p);
void EmergenciaPop();
void ListarEmergencias();
void RelatorioEmergencias();

# endif