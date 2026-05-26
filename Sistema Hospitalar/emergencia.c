#include <stdio.h>
#include "emergencia.h"

Paciente emergencia[EMERGENCIA_MAX]; // Pilha de Emergência
static int topo = -1;

void iniciarEmergencia() 
{
    topo = -1;
}

int EmergenciaCheia() 
{
    return topo == EMERGENCIA_MAX - 1;
}

int EmergenciaVazia() 
{
    return topo == -1;
}

void EmergenciaPush(Paciente p) 
{
    if (EmergenciaCheia()){
        printf("A Pilha de emergências está cheia! Incapaz de aceitar mais emergências.");
    } else {
        topo++;
        emergencia[topo] = p;
        printf("Paciente %s está agora na pilha de Emergências.\n", p.nome);
    }
}

void EmergenciaPop() 
{
    if (EmergenciaVazia()) {
        printf("Pilha vazia! Nenhuma emergência no momento.");
    } else {
        printf("Paciente %s foi atendido.\n", emergencia[topo].nome);
        topo--;
    }
}

void ListarEmergencias()
{
    if (EmergenciaVazia()){
        printf("Não há nenhuma emergência no momento!\n");
    
    }
    else{
        for(int i = topo; i >= 0; i--){
            printf("Nome: %s | Gravidade: %d\n", emergencia[i].nome, emergencia[i].gravidade);
        }
    }
}

void RelatorioEmergencias()
{
    printf("\n===== Emergências (Pilha) =====\n");
    if (EmergenciaVazia()){
        printf("Não há nenhuma emergência no momento!\n");
    
    }
    else{
        for(int i = topo; i >= 0; i--){
            printf("Nome: %s | Gravidade: %d\n", emergencia[i].nome, emergencia[i].gravidade);
        }
    }
}