#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[50];
    int idade;
    int gravidade;   /* 1 a 5, sendo 5 o mais grave */
    int atendimento; /* 1-Emergência, 2-Consulta, 3-Exame */
} Paciente;

#endif
