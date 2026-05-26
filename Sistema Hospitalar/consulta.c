# include <stdio.h>
# include "consulta.h"

Paciente consulta[CONSULTA_MAX];
static int frente = 0;
static int tras = -1;

void iniciarConsulta() 
{
    frente = 0;
    tras = -1;
}

int ConsultaCheia() 
{
    return frente > tras;
}

int ConsultaVazia() 
{
    return tras == CONSULTA_MAX - 1;
}

void ConsultaEnqueue(Paciente p) 
{
    if (ConsultaCheia()){
        printf("Fila cheia! Incapaz de aceitar mais consultas.");
    } else {
        tras++;
        consulta[tras] = p;
        printf("Paciente %s está agora na fila de Consultas.\n", p.nome);
    }
}

void ConsultaDequeue() 
{
    if (ConsultaVazia()) {
        printf("Fila vazia! Nenhuma consulta no momento.");
    } else {
        printf("Paciente %s foi atendido.\n", consulta[frente].nome);
        frente++;
    }
}

void ListarConsultas()
{
    if (ConsultaVazia()){
        printf("Não há nenhuma consulta no momento!\n");
    
    }
    else{
        for(int i = frente; i <= tras; i++){
            printf("Nome: %s | Gravidade: %d\n", consulta[i].nome, consulta[i].gravidade);
        }
    }
}

void RelatorioConsultas()
{
    printf("\n===== Consultas (Fila Simples) =====\n");
    if (ConsultaVazia()){
        printf("Não há nenhuma consulta no momento!\n");
    }
    else{
        printf("Pacientes na fila de Consultas: %d\n", tras - frente + 1);
    }
}