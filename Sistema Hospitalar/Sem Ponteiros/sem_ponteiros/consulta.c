#include <stdio.h>
#include "consulta.h"

Paciente consulta[CONSULTA_MAX];
int frente_c = 0;
int tras_c   = -1;

void iniciarConsulta()
{
    frente_c = 0;
    tras_c   = -1;
}

/* Fila cheia: trás chegou ao limite do vetor */
int ConsultaCheia()
{
    return tras_c == CONSULTA_MAX - 1;
}

/* Fila vazia: nenhum elemento inserido ou todos foram removidos */
int ConsultaVazia()
{
    return frente_c > tras_c;
}

void ConsultaEnqueue(Paciente p)
{
    if (ConsultaCheia()) {
        printf("Fila de consultas cheia! Não é possível aceitar mais pacientes.\n");
    } else {
        tras_c++;
        consulta[tras_c] = p;
        printf("Paciente %s adicionado à fila de Consultas.\n", p.nome);
    }
}

void ConsultaDequeue()
{
    if (ConsultaVazia()) {
        printf("Fila de consultas vazia! Nenhum paciente no momento.\n");
    } else {
        printf("\n--- Atendendo Consulta ---\n");
        printf("Nome    : %s\n", consulta[frente_c].nome);
        printf("Idade   : %d\n", consulta[frente_c].idade);
        printf("Gravidade: %d\n", consulta[frente_c].gravidade);
        frente_c++;
    }
}

void ListarConsultas()
{
    if (ConsultaVazia()) {
        printf("Não há nenhuma consulta no momento!\n");
    } else {
        printf("\n--- Fila de Consultas (frente → trás) ---\n");
        int pos = 1;
        for (int i = frente_c; i <= tras_c; i++) {
            printf("[%d] Nome: %-20s | Idade: %3d | Gravidade: %d\n",
                   pos++, consulta[i].nome, consulta[i].idade, consulta[i].gravidade);
        }
    }
}

void RelatorioConsultas()
{
    printf("\n===== Consultas Agendadas (Fila Simples) =====\n");
    if (ConsultaVazia()) {
        printf("Não há nenhuma consulta no momento!\n");
    } else {
        printf("Pacientes na fila: %d / %d\n", tras_c - frente_c + 1, CONSULTA_MAX);
        ListarConsultas();
    }
}
