# include <stdio.h>
# include "exame.h"

Exame iniciarFila() 
{
    Exame e;
    e.frente = -1;
    e.tras = -1;
    e.qnt = 0;
    return e;
}

int ExameCheio(Exame e) 
{
    return e.qnt = EXAME_MAX;
}

int ExameVazio(Exame e) 
{
    return e.qnt = 0;
}

Exame ExameEnqueue(Exame e, Paciente p) 
{
    if (ExameCheio(e)){
        printf("Fila cheia! Incapaz de aceitar mais exames.");
    } else {
        e.tras = (e.tras + 1) % EXAME_MAX;
        e.exame[e.tras] = p;
        e.qnt++;
        printf("Paciente %s está agora na fila de Exames.\n", p.nome);
    }
    return e;
}

Exame ExameDequeue(Exame e) 
{
    if (ExameVazio(e)) {
        printf("Fila vazia! Nenhum exame no momento.");
    } else {
        e.frente = (e.frente + 1) % EXAME_MAX;
        printf("Paciente %s foi atendido.\n", e.exame[e.frente].nome);
    }
    
    return e;
}
    
void ListarExames(Exame e)
{
    if (ExameVazio(e)){
        printf("Não há nenhum exame no momento!\n");
    
    }
    else{
        int q = e.frente;
        int total = e.qnt;
        for(int cont = 0; cont < total; cont++){
            printf("Nome: %s | Gravidade: %d\n", e.exame[q].nome, e.exame[q].gravidade);
            q = (q + 1) % EXAME_MAX;
        }
        
    }
}

void RelatorioExames(Exame e)
{
    printf("\n===== Exames/Laboratório (Fila Circular) =====\n");    if (ExameVazio(e)){
        printf("Área de exames está vazia.\n");
    }
    else{
        
        printf("Pacientes na de Exames: %d\n", e.qnt);
    }
    int vagas = EXAME_MAX - e.qnt;
    if (vagas == 0){
        printf("Fila de exames cheia.\n");
    }
    else{
        printf("Vagas disponiveis: %d\n", vagas);
    }
}