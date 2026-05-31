#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "emergencia.h"
#include "consulta.h"
#include "exame.h"

/* ── estruturas globais passadas por ponteiro para todas as funções ── */
static PilhaEmergencia pilhaEmergencia;
static FilaConsulta    filaConsulta;
static FilaExame       filaExame;

/* ── protótipos ── */
static void CadastrarPaciente(PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe);
static void AtenderPaciente  (PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe);
static void MostrarPacientes (const PilhaEmergencia *pe, const FilaConsulta *fc, const FilaExame *fe);
static void TransferirPaciente(PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe);
static void Relatorios        (const PilhaEmergencia *pe, const FilaConsulta *fc, const FilaExame *fe);
static void TesteEstresse     (PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe);

/* ─────────────────────────────────────────────────────────────────── */
int main()
{
    iniciarEmergencia(&pilhaEmergencia);
    iniciarConsulta(&filaConsulta);
    iniciarFilaExame(&filaExame);

    int opcao;

    do {
        printf("\n========== Menu do Hospital ==========\n");
        printf("1. Cadastrar Paciente\n");
        printf("2. Atender Paciente\n");
        printf("3. Mostrar Pacientes\n");
        printf("4. Transferir Paciente\n");
        printf("5. Relatórios\n");
        printf("6. Teste de Estresse\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: CadastrarPaciente(&pilhaEmergencia, &filaConsulta, &filaExame);  break;
            case 2: AtenderPaciente  (&pilhaEmergencia, &filaConsulta, &filaExame);  break;
            case 3: MostrarPacientes (&pilhaEmergencia, &filaConsulta, &filaExame);  break;
            case 4: TransferirPaciente(&pilhaEmergencia, &filaConsulta, &filaExame); break;
            case 5: Relatorios        (&pilhaEmergencia, &filaConsulta, &filaExame); break;
            case 6: TesteEstresse     (&pilhaEmergencia, &filaConsulta, &filaExame); break;
            case 0: printf("Saindo do programa...\n"); break;
            default: printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

/* ─────────────────────────────────────────────────────────────────── */
static void CadastrarPaciente(PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe)
{
    Paciente p;

    printf("\n--- Cadastrar Paciente ---\n");
    printf("Nome   : ");
    scanf(" %49[^\n]", p.nome);
    printf("Idade  : ");
    scanf("%d", &p.idade);

    do {
        printf("Gravidade (1-5): ");
        scanf("%d", &p.gravidade);
        if (p.gravidade < 1 || p.gravidade > 5)
            printf("Valor inválido. Digite entre 1 e 5.\n");
    } while (p.gravidade < 1 || p.gravidade > 5);

    /* Regra de negócio: gravidade 4 ou 5 → Emergência */
    if (p.gravidade >= 4) {
        p.atendimento = 1;
        printf("Gravidade alta! Paciente direcionado automaticamente para Emergência.\n");
        EmergenciaPush(pe, &p);
        return;
    }

    do {
        printf("Tipo de atendimento – 2 (Consulta) ou 3 (Exame): ");
        scanf("%d", &p.atendimento);
        if (p.atendimento != 2 && p.atendimento != 3)
            printf("Opção inválida. Digite 2 ou 3.\n");
    } while (p.atendimento != 2 && p.atendimento != 3);

    if (p.atendimento == 2)
        ConsultaEnqueue(fc, &p);
    else
        ExameEnqueue(fe, &p);
}

/* ─────────────────────────────────────────────────────────────────── */
static void AtenderPaciente(PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe)
{
    int setor;
    printf("\n--- Atender Paciente ---\n");
    printf("1. Emergência\n");
    printf("2. Consultas\n");
    printf("3. Exames\n");
    printf("Setor: ");
    scanf("%d", &setor);

    switch (setor) {
        case 1: EmergenciaPop(pe);   break;
        case 2: ConsultaDequeue(fc); break;
        case 3: ExameDequeue(fe);    break;
        default: printf("Setor inválido!\n");
    }
}

/* ─────────────────────────────────────────────────────────────────── */
static void MostrarPacientes(const PilhaEmergencia *pe, const FilaConsulta *fc, const FilaExame *fe)
{
    int setor;
    printf("\n--- Mostrar Pacientes ---\n");
    printf("1. Emergência\n");
    printf("2. Consultas\n");
    printf("3. Exames\n");
    printf("4. Todos\n");
    printf("Setor: ");
    scanf("%d", &setor);

    switch (setor) {
        case 1: ListarEmergencias(pe);   break;
        case 2: ListarConsultas(fc);     break;
        case 3: ListarExames(fe);        break;
        case 4:
            ListarEmergencias(pe);
            ListarConsultas(fc);
            ListarExames(fe);
            break;
        default: printf("Setor inválido!\n");
    }
}

/* ─────────────────────────────────────────────────────────────────── */
static void TransferirPaciente(PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe)
{
    int origem, destino;
    Paciente p;

    printf("\n--- Transferir Paciente ---\n");
    printf("Setores: 1-Emergência | 2-Consultas | 3-Exames\n");
    printf("Setor de origem : ");
    scanf("%d", &origem);
    printf("Setor de destino: ");
    scanf("%d", &destino);

    if (origem == destino) {
        printf("Origem e destino são iguais!\n");
        return;
    }

    int encontrado = 0;
    switch (origem) {
        case 1:
            if (EmergenciaVazia(pe)) { printf("Emergência vazia!\n"); return; }
            p = pe->dados[pe->topo];
            EmergenciaPop(pe);
            encontrado = 1;
            break;
        case 2:
            if (ConsultaVazia(fc)) { printf("Fila de consultas vazia!\n"); return; }
            p = fc->dados[fc->frente];
            ConsultaDequeue(fc);
            encontrado = 1;
            break;
        case 3:
            if (ExameVazio(fe)) { printf("Fila de exames vazia!\n"); return; }
            p = fe->dados[fe->frente];
            ExameDequeue(fe);
            encontrado = 1;
            break;
        default:
            printf("Setor de origem inválido!\n");
    }

    if (!encontrado) return;

    p.atendimento = destino;
    switch (destino) {
        case 1: EmergenciaPush(pe, &p);  break;
        case 2: ConsultaEnqueue(fc, &p); break;
        case 3: ExameEnqueue(fe, &p);    break;
        default: printf("Setor de destino inválido!\n");
    }

    printf("Paciente %s transferido com sucesso!\n", p.nome);
}

/* ─────────────────────────────────────────────────────────────────── */
static void Relatorios(const PilhaEmergencia *pe, const FilaConsulta *fc, const FilaExame *fe)
{
    printf("\n========== Relatórios ==========\n");
    RelatorioEmergencias(pe);
    RelatorioConsultas(fc);
    RelatorioExames(fe);
}

/* ─────────────────────────────────────────────────────────────────── */
static void TesteEstresse(PilhaEmergencia *pe, FilaConsulta *fc, FilaExame *fe)
{
    printf("\n--- Teste de Estresse ---\n");

    const char nomes[15][50] = {
        "Ana Lima","Bruno Souza","Carla Nunes","Diego Ramos","Eva Costa",
        "Fábio Dias","Gabi Lopes","Hugo Melo","Iris Pinto","João Brito",
        "Kátia Melo","Lucas Faria","Marta Gomes","Nando Cruz","Olga Teixeira"
    };
    int idades[15]     = {25,34,45,28,60,38,22,50,31,47,55,19,66,41,73};
    int gravidades[15] = { 1, 5, 3, 4, 2, 1, 5, 3, 2, 4, 1, 3, 5, 2, 4};

    for (int i = 0; i < 15; i++) {
        Paciente p;
        strcpy(p.nome, nomes[i]);
        p.idade     = idades[i];
        p.gravidade = gravidades[i];

        if (p.gravidade >= 4) {
            p.atendimento = 1;
            EmergenciaPush(pe, &p);
        } else if (p.gravidade == 3) {
            p.atendimento = 2;
            ConsultaEnqueue(fc, &p);
        } else {
            p.atendimento = 3;
            ExameEnqueue(fe, &p);
        }
    }

    printf("\nEstado após inserção de 15 pacientes:\n");
    Relatorios(pe, fc, fe);
}
