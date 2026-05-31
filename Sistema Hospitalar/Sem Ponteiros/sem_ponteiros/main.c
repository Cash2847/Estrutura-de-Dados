#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "emergencia.h"
#include "consulta.h"
#include "exame.h"

/* variável global da fila de exames (passada por valor/retorno) */
Exame filaExame;

/* ── protótipos das funções do menu ── */
static void CadastrarPaciente();
static void AtenderPaciente();
static void MostrarPacientes();
static void TransferirPaciente();
static void Relatorios();
static void TesteEstresse();

/* ─────────────────────────────────────────────────────────────── */
int main()
{
    iniciarEmergencia();
    iniciarConsulta();
    filaExame = iniciarFila();

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
            case 1: CadastrarPaciente();  break;
            case 2: AtenderPaciente();    break;
            case 3: MostrarPacientes();   break;
            case 4: TransferirPaciente(); break;
            case 5: Relatorios();         break;
            case 6: TesteEstresse();      break;
            case 0: printf("Saindo do programa...\n"); break;
            default: printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

/* ─────────────────────────────────────────────────────────────── */
static void CadastrarPaciente()
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
        EmergenciaPush(p);
        return;
    }

    do {
        printf("Tipo de atendimento – 2 (Consulta) ou 3 (Exame): ");
        scanf("%d", &p.atendimento);
        if (p.atendimento != 2 && p.atendimento != 3)
            printf("Opção inválida. Digite 2 ou 3.\n");
    } while (p.atendimento != 2 && p.atendimento != 3);

    if (p.atendimento == 2)
        ConsultaEnqueue(p);
    else
        filaExame = ExameEnqueue(filaExame, p);
}

/* ─────────────────────────────────────────────────────────────── */
static void AtenderPaciente()
{
    int setor;
    printf("\n--- Atender Paciente ---\n");
    printf("1. Emergência\n");
    printf("2. Consultas\n");
    printf("3. Exames\n");
    printf("Setor: ");
    scanf("%d", &setor);

    switch (setor) {
        case 1: EmergenciaPop();               break;
        case 2: ConsultaDequeue();             break;
        case 3: filaExame = ExameDequeue(filaExame); break;
        default: printf("Setor inválido!\n");
    }
}

/* ─────────────────────────────────────────────────────────────── */
static void MostrarPacientes()
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
        case 1: ListarEmergencias();          break;
        case 2: ListarConsultas();            break;
        case 3: ListarExames(filaExame);      break;
        case 4:
            ListarEmergencias();
            ListarConsultas();
            ListarExames(filaExame);
            break;
        default: printf("Setor inválido!\n");
    }
}

/* ─────────────────────────────────────────────────────────────── */
static void TransferirPaciente()
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

    /* Busca o paciente na origem */
    int encontrado = 0;
    switch (origem) {
        case 1:
            if (EmergenciaVazia()) { printf("Emergência vazia!\n"); return; }
            p = emergencia[topo];
            EmergenciaPop();
            encontrado = 1;
            break;
        case 2:
            if (ConsultaVazia()) { printf("Fila de consultas vazia!\n"); return; }
            p = consulta[frente_c];
            ConsultaDequeue();
            encontrado = 1;
            break;
        case 3:
            if (ExameVazio(filaExame)) { printf("Fila de exames vazia!\n"); return; }
            p = filaExame.exame[filaExame.frente];
            filaExame = ExameDequeue(filaExame);
            encontrado = 1;
            break;
        default:
            printf("Setor de origem inválido!\n");
    }

    if (!encontrado) return;

    /* Insere no destino */
    p.atendimento = destino;
    switch (destino) {
        case 1: EmergenciaPush(p);                    break;
        case 2: ConsultaEnqueue(p);                   break;
        case 3: filaExame = ExameEnqueue(filaExame, p); break;
        default: printf("Setor de destino inválido!\n");
    }

    printf("Paciente %s transferido com sucesso!\n", p.nome);
}

/* ─────────────────────────────────────────────────────────────── */
static void Relatorios()
{
    printf("\n========== Relatórios ==========\n");
    RelatorioEmergencias();
    RelatorioConsultas();
    RelatorioExames(filaExame);
}

/* ─────────────────────────────────────────────────────────────── */
static void TesteEstresse()
{
    printf("\n--- Teste de Estresse ---\n");

    char nomes[15][50] = {
        "Ana Lima","Bruno Souza","Carla Nunes","Diego Ramos","Eva Costa",
        "Fábio Dias","Gabi Lopes","Hugo Melo","Iris Pinto","João Brito",
        "Kátia Melo","Lucas Faria","Marta Gomes","Nando Cruz","Olga Teixeira"
    };
    int idades[15]     = {25,34,45,28,60,38,22,50,31,47,55,19,66,41,73};
    int gravidades[15] = { 1, 5, 3, 4, 2, 1, 5, 3, 2, 4, 1, 3, 5, 2, 4};

    for (int i = 0; i < 15; i++) {
        Paciente p;
        strcpy(p.nome, nomes[i]);
        p.idade      = idades[i];
        p.gravidade  = gravidades[i];

        if (p.gravidade >= 4) {
            p.atendimento = 1;
            EmergenciaPush(p);
        } else if (p.gravidade == 3) {
            p.atendimento = 2;
            ConsultaEnqueue(p);
        } else {
            p.atendimento = 3;
            filaExame = ExameEnqueue(filaExame, p);
        }
    }

    printf("\nEstado após inserção de 15 pacientes:\n");
    Relatorios();
}
