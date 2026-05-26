# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include "paciente.h"
# include "emergencia.h"
# include "consulta.h"
# include "exame.h"

// funções do menu
static void CadastrarPaciente();
static void AtenderPaciente();
static void MostrarPacientes();
static void TransferirPaciente();
static void Relatorios();
static void TesteEstresse();

int main() {
    void iniciarEmergencia();
    void iniciarConsulta();
    Exame e = iniciarFila();

    int opcao;

    do {
        printf("\n===== Menu do Hospital =====\n");
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
            case 1:
                CadastrarPaciente();
                break;
            case 2:
                AtenderPaciente();
                break;
            case 3:
                MostrarPacientes();
                break;
            case 4:
                TransferirPaciente();
                break;
            case 5:
                Relatorios();
                break;
            case 6:
                TesteEstresse();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    static void CadastrarPaciente() {
        Paciente p;
        printf("Digite o nome do paciente: ");
        scanf("%s", p.nome);
        printf("Digite a idade do paciente: ");
        scanf("%d", &p.idade);
        printf("Digite a gravidade do paciente (1-5): ");
        scanf("%d", &p.gravidade);
        p.atendimento = 0;

        if (p.gravidade >= 4) {
            printf("Paciente %s foi classificado como emergência devido à gravidade.\n", p.nome);
            EmergenciaPush(p);
        } else {
            printf("Digite seu tipo de atendimento, 2 (Consulta) ou 3 (Exame): ");
            scanf("%d", &p.atendimento);
        }
    }