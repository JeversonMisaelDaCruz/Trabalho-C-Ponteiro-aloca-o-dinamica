#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 20

struct Endereco {
    char rua[80];
    int numeroCasa;
    char bairro[40];
    char cidade[40];
    char estado[3];
};

struct Materias {
    float ciencias;
    float matematica;
    float ingles;
    float historia;
    float geografia;
};

struct FichaAluno {
    char nome[40];
    int RA;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    struct Endereco endereco1;
    struct Endereco endereco2;
    struct Materias notas;
};

// Função para cadastrar um aluno
void cadastrarAluno(struct FichaAluno alunos[], int *total_alunos) {
    if (*total_alunos < MAX_ALUNOS) {
        struct FichaAluno novo_aluno;

        printf("Digite o nome do aluno: ");
        scanf("%s", novo_aluno.nome);

        printf("Digite o RA: ");
        scanf("%d", &novo_aluno.RA);

        printf("Digite a data de nascimento (Dia): ");
        scanf("%d", &novo_aluno.diaNascimento);

        printf("Digite a data de nascimento (Mês): ");
        scanf("%d", &novo_aluno.mesNascimento);

        printf("Digite a data de nascimento (Ano): ");
        scanf("%d", &novo_aluno.anoNascimento);

        printf("Digite o primeiro endereco (Rua): ");
        scanf("%s", novo_aluno.endereco1.rua);

        printf("Digite o primeiro endereco (NumeroCasa): ");
        scanf("%d", &novo_aluno.endereco1.numeroCasa);

        printf("Digite o primeiro endereco (Bairro): ");
        scanf("%s", novo_aluno.endereco1.bairro);

        printf("Digite o primeiro endereco (Cidade): ");
        scanf("%s", novo_aluno.endereco1.cidade);

        printf("Digite o primeiro endereco (Estado): ");
        scanf("%s", novo_aluno.endereco1.estado);

        printf("Digite o segundo endereco (Rua): ");
        scanf("%s", novo_aluno.endereco2.rua);

        printf("Digite o segundo endereco (NumeroCasa): ");
        scanf("%d", &novo_aluno.endereco2.numeroCasa);

        printf("Digite o segundo endereco (Bairro): ");
        scanf("%s", novo_aluno.endereco2.bairro);

        printf("Digite o segundo endereco (Cidade): ");
        scanf("%s", novo_aluno.endereco2.cidade);

        printf("Digite o segundo endereco (Estado): ");
        scanf("%s", novo_aluno.endereco2.estado);

        printf("Digite a média do aluno em Ciencias: ");
        scanf("%f", &novo_aluno.notas.ciencias);

        printf("Digite a média do aluno em Matematica: ");
        scanf("%f", &novo_aluno.notas.matematica);

        printf("Digite a média do aluno em Ingles: ");
        scanf("%f", &novo_aluno.notas.ingles);

        printf("Digite a média do aluno em Historia: ");
        scanf("%f", &novo_aluno.notas.historia);

        printf("Digite a média do aluno em Geografia: ");
        scanf("%f", &novo_aluno.notas.geografia);

        alunos[*total_alunos] = novo_aluno;
        (*total_alunos)++;

        printf("Aluno cadastrado com sucesso!\n");
    } else {
        printf("Não é possível adicionar mais alunos. Limite atingido.\n");
    }
}

// Função para listar todos os alunos
void listarAlunos(struct FichaAluno alunos[], int total_alunos) {
    printf("\nLista de Alunos:\n");
    for (int i = 0; i < total_alunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("RA: %d\n", alunos[i].RA);
        printf("Data de Nascimento: %d/%d/%d\n", alunos[i].diaNascimento, alunos[i].mesNascimento, alunos[i].anoNascimento);
        printf("Endereco 1: %s, %d, %s, %s, %s\n", alunos[i].endereco1.rua, alunos[i].endereco1.numeroCasa, alunos[i].endereco1.bairro, alunos[i].endereco1.cidade, alunos[i].endereco1.estado);
        printf("Endereco 2: %s, %d, %s, %s, %s\n", alunos[i].endereco2.rua, alunos[i].endereco2.numeroCasa, alunos[i].endereco2.bairro, alunos[i].endereco2.cidade, alunos[i].endereco2.estado);
        printf("Média em Ciencias: %.2f\n", alunos[i].notas.ciencias);
        printf("Média em Matematica: %.2f\n", alunos[i].notas.matematica);
        printf("Média em Ingles: %.2f\n", alunos[i].notas.ingles);
        printf("Média em Historia: %.2f\n", alunos[i].notas.historia);
        printf("Média em Geografia: %.2f\n", alunos[i].notas.geografia);
        printf("\n");
    }
}

// Função para apagar um aluno pelo RA
void apagarAluno(struct FichaAluno alunos[], int *total_alunos, int raParaApagar) {
    for (int i = 0; i < *total_alunos; i++) {
        if (alunos[i].RA == raParaApagar) {
            for (int j = i; j < (*total_alunos) - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            (*total_alunos)--;
            printf("Aluno com RA %d foi apagado com sucesso.\n", raParaApagar);
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", raParaApagar);
}

// Função para consultar um aluno pelo RA
void consultarAlunoPorRA(struct FichaAluno alunos[], int total_alunos, int raParaConsultar) {
    for (int i = 0; i < total_alunos; i++) {
        if (alunos[i].RA == raParaConsultar) {
            printf("Aluno encontrado:\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("RA: %d\n", alunos[i].RA);
            printf("Data de Nascimento: %d/%d/%d\n", alunos[i].diaNascimento, alunos[i].mesNascimento, alunos[i].anoNascimento);
            printf("Endereco 1: %s, %d, %s, %s, %s\n", alunos[i].endereco1.rua, alunos[i].endereco1.numeroCasa, alunos[i].endereco1.bairro, alunos[i].endereco1.cidade, alunos[i].endereco1.estado);
            printf("Endereco 2: %s, %d, %s, %s, %s\n", alunos[i].endereco2.rua, alunos[i].endereco2.numeroCasa, alunos[i].endereco2.bairro, alunos[i].endereco2.cidade, alunos[i].endereco2.estado);
            printf("Média em Ciencias: %.2f\n", alunos[i].notas.ciencias);
            printf("Média em Matematica: %.2f\n", alunos[i].notas.matematica);
            printf("Média em Ingles: %.2f\n", alunos[i].notas.ingles);
            printf("Média em Historia: %.2f\n", alunos[i].notas.historia);
            printf("Média em Geografia: %.2f\n", alunos[i].notas.geografia);
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", raParaConsultar);
}

// Função para verificar se o RA já existe
int verificarRAExistente(struct FichaAluno alunos[], int total_alunos, int raParaVerificar) {
    for (int i = 0; i < total_alunos; i++) {
        if (alunos[i].RA == raParaVerificar) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int escolha;
    struct FichaAluno alunos[MAX_ALUNOS];
    int total_alunos = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Cadastro de Alunos\n");
        printf("2. Consultar Alunos Cadastrados\n");
        printf("3. Apagar cadastro Aluno\n");
        printf("4. Consultar aluno pelo RA\n");
        printf("5. Verificar se o RA ja existe\n");
        printf("6. Sair\n");
        printf("Selecione uma opcao: ");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarAluno(alunos, &total_alunos);
                break;
            case 2:
                listarAlunos(alunos, total_alunos);
                break;
            case 3:
                if (total_alunos > 0) {
                    int raParaApagar;
                    printf("Digite o RA do aluno que deseja apagar: ");
                    scanf("%d", &raParaApagar);
                    apagarAluno(alunos, &total_alunos, raParaApagar);
                } else {
                    printf("Nao ha alunos cadastrados para apagar.\n");
                }
                break;
            case 4:
                if (total_alunos > 0) {
                    int raParaConsultar;
                    printf("Digite o RA do aluno que deseja consultar: ");
                    scanf("%d", &raParaConsultar);
                    consultarAlunoPorRA(alunos, total_alunos, raParaConsultar);
                } else {
                    printf("Nao ha alunos cadastrados para consultar.\n");
                }
                break;
            case 5:
                if (total_alunos > 0) {
                    int raParaVerificar;
                    printf("Digite o RA que deseja verificar: ");
                    scanf("%d", &raParaVerificar);
                    if (verificarRAExistente(alunos, total_alunos, raParaVerificar)) {
                        printf("O RA %d ja existe na lista de alunos cadastrados.\n", raParaVerificar);
                    } else {
                        printf("O RA %d nao foi encontrado na lista de alunos cadastrados.\n", raParaVerificar);
                    }
                } else {
                    printf("Nao ha alunos cadastrados para verificar o RA.\n");
                }
                break;
            case 6:
                printf("Voce ira sair do sistema.\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
