usuarios = {}

def cadastrar_usuario():
    nome_usuario = input("Digite o nome de usuário: ")
    if nome_usuario in usuarios:
        print("Usuário já existe!")
        return
    senha = input("Digite a senha: ")
    usuarios[nome_usuario] = senha
    print("Usuário cadastrado com sucesso!")

def alterar_senha():
    nome_usuario = input("Digite o nome de usuário: ")
    if nome_usuario not in usuarios:
        print("Usuário não encontrado!")
        return
    nova_senha = input("Digite a nova senha: ")
    usuarios[nome_usuario] = nova_senha
    print("Senha alterada com sucesso!")

def realizar_login():
    nome_usuario = input("Digite o nome de usuário: ")
    senha = input("Digite a senha: ")
    if nome_usuario in usuarios and usuarios[nome_usuario] == senha:
        print("Login realizado com sucesso!")
    else:
        print("Usuário ou senha incorretos!")

def excluir_usuario():
    nome_usuario = input("Digite o nome de usuário a ser excluído: ")
    if nome_usuario in usuarios:
        del usuarios[nome_usuario]
        print("Usuário excluído com sucesso!")
    else:
        print("Usuário não encontrado!")

def exibir_menu():
    print("\n--- Menu ---")
    print("1. Cadastrar novo usuário")
    print("2. Alterar senha do usuário")
    print("3. Realizar login")
    print("4. Excluir usuário")
    print("5. Sair")
    return input("Escolha uma opção: ")

def main():
    while True:
        opcao = exibir_menu()
        if opcao == '1':
            cadastrar_usuario()
        elif opcao == '2':
            alterar_senha()
        elif opcao == '3':
            realizar_login()
        elif opcao == '4':
            excluir_usuario()
        elif opcao == '5':
            print("Saindo...")
            break
        else:
            print("Opção inválida!")

if __name__ == "__main__":
    main()
