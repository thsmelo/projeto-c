#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USUARIOS 10
#define TAM_MAX 20

typedef struct {
    char nome_usuario[TAM_MAX];
    char senha[TAM_MAX];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int contadorUsuarios = 0;

// Funções
void cadastrarUsuario() {
    if (contadorUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuários atingido!\n");
        return;
    }

    char nome_usuario[TAM_MAX], senha[TAM_MAX];
    printf("Digite o nome de usuário: ");
    scanf("%s", nome_usuario);
    printf("Digite a senha: ");
    scanf("%s", senha);

    strcpy(usuarios[contadorUsuarios].nome_usuario, nome_usuario);
    strcpy(usuarios[contadorUsuarios].senha, senha);
    contadorUsuarios++;

    printf("Usuário cadastrado com sucesso!\n");
}

void alterarSenha() {
    char nome_usuario[TAM_MAX], nova_senha[TAM_MAX];
    printf("Digite o nome de usuário: ");
    scanf("%s", nome_usuario);

    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(usuarios[i].nome_usuario, nome_usuario) == 0) {
            printf("Digite a nova senha: ");
            scanf("%s", nova_senha);
            strcpy(usuarios[i].senha, nova_senha);
            printf("Senha alterada com sucesso!\n");
            return;
        }
    }
    printf("Usuário não encontrado!\n");
}

void realizarLogin() {
    char nome_usuario[TAM_MAX], senha[TAM_MAX];
    printf("Digite o nome de usuário: ");
    scanf("%s", nome_usuario);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(usuarios[i].nome_usuario, nome_usuario) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return;
        }
    }
    printf("Usuário ou senha incorretos!\n");
}

void excluirUsuario() {
    char nome_usuario[TAM_MAX];
    printf("Digite o nome de usuário a ser excluído: ");
    scanf("%s", nome_usuario);

    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(usuarios[i].nome_usuario, nome_usuario) == 0) {
            for (int j = i; j < contadorUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            contadorUsuarios--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }
    printf("Usuário não encontrado!\n");
}

void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar novo usuário\n");
    printf("2. Alterar senha do usuário\n");
    printf("3. Realizar login\n");
    printf("4. Excluir usuário\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                alterarSenha();
                break;
            case 3:
                realizarLogin();
                break;
            case 4:
                excluirUsuario();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
