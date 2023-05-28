#include <iostream>
using namespace std;
// Define a capacidade máxima de produtos a serem cadastrados
#define qtdMaxDeProdutos 45
// Define a chave de acesso para entrar no modo administrador
#define chaveDeAcesso "admads2023"

// Cria as caracteristicas dos produtos
struct produto {
  string nome;
  int quantidade;
  int codigo;
  float preco;
};

// Carrega as funções
void inicializarProdutos(int qtdProdutos, struct produto produtos[qtdProdutos]);
void exibirMenu(int qtdProdutos, struct produto produtos[qtdProdutos]);
void continuar();
void modoAdm(int *qtdProdutos, struct produto produtos[*qtdProdutos],
             float caixaDaMaquina);
void modoUsuario(int qtdProdutos, struct produto produtos[qtdProdutos],
                 float caixaDaMaquina);

// Código principal
int main() {
  static struct produto produtos[qtdMaxDeProdutos];
  static int qtdProdutos = 2;
  float caixaDaMaquina;

  // Carrega uma pequena base de dados com produtos já cadastrados no sistema
  inicializarProdutos(qtdProdutos, produtos);

  // Cria um loop para entrar no modo ADM ou usuario
  while (true) {
    string opcaoDeModo;

    cout << "Bem-vindo(a) à máquina de vendas da Fatec - RP!" << endl;
    cout << "\nCapacidade da máquina: " << qtdMaxDeProdutos
         << " produtos\nCriadores: @Normado e @Kelvin" << endl;
    cout << "Digite algo para continuar... ";
    cin >> opcaoDeModo;

    // Caso tenha sido inserido a chave de acesso, entra no modo ADM. Do
    // contrário, vai  para o modo usuário
    if (opcaoDeModo == chaveDeAcesso) {
      // MODO ADM
      modoAdm(&qtdProdutos, produtos, caixaDaMaquina);
    } else {
      // MODO USUÁRIO
      modoUsuario(qtdProdutos, produtos, caixaDaMaquina);
    }
  }
}

// Funções

// Carrega uma pequena base de dados de produtos já cadastrados
void inicializarProdutos(int qtdProdutos,
                         struct produto produtos[qtdProdutos]) {
  // Inicializa os produtos
  produtos[0].nome = "Banana";
  produtos[0].quantidade = 5;
  produtos[0].preco = 10.0;
  produtos[1].nome = "Chocolate";
  produtos[1].quantidade = 2;
  produtos[1].preco = 20.0;

  for (int i = 0; i < qtdProdutos; i++) {
    produtos[i].codigo = (i + 1);
  }
}

// Exibe os itens da máquina
void exibirMenu(int qtdProdutos, struct produto produtos[qtdProdutos]) {

  // Exibe os produtos da máquina
  cout << "Cód | Prod | Preço | Qtd" << endl;
  for (int i = 0; i < qtdProdutos; i++) {
    cout << produtos[i].codigo << " | " << produtos[i].nome << "  | R$"
         << produtos[i].preco << " | " << produtos[i].quantidade << "un"
         << endl;
  }
}

// Exibe um botão de pause para continuar
void continuar() {
  string nada;
  cout << "Digite algo para continuar... ";
  cin >> nada;
}

// Entra nas configurações de administrador
void modoAdm(int *qtdProdutos, struct produto produtos[*qtdProdutos],
             float caixaDaMaquina) {
  while (true) {
    int opcao;

    cout << "\n-----MODO ADMNISTRADOR-----" << endl;
    cout << "\nSelecione uma opção: \n1 - Cadastrar novo produto\n2 - "
            "Alterar preço\n3 - Alterar quantidade\n4 - Inventario\n5 - "
            "Caixa da máquina\n\n0 - Sair\n\nOpção: ";
    cin >> opcao;
    cout << endl;

    if (opcao == 1) {
      while (true) {
        if (*qtdProdutos <= qtdMaxDeProdutos) {
          cout << "----CADASTRO DE PRODUTOS----" << endl;
          cout << "Insira o nome: ";
          cin >> produtos[*qtdProdutos].nome;
          cout << "Insira o valor de " << produtos[*qtdProdutos].nome << " R$";
          cin >> produtos[*qtdProdutos].preco;
          cout << "Insira a quantidade de " << produtos[*qtdProdutos].nome
               << ": ";
          cin >> produtos[*qtdProdutos].quantidade;

          cout << "\n"
               << produtos[*qtdProdutos].quantidade << "un de "
               << produtos[*qtdProdutos].nome << " à R$"
               << produtos[*qtdProdutos].preco
               << " foram cadastradas com sucesso!\n"
               << endl;

          produtos[*qtdProdutos].codigo = *qtdProdutos + 1;
          (*qtdProdutos)++;

          continuar();
          break;
        } else {
          cout << "\nAVISO: Quantidade máxima de produtos cadastrados "
                  "atingiada!\nNão é possível cadastrar mais produtos"
               << endl;
          break;
        }
      }
    } else if (opcao == 2) {
      while (true) {
        float novoPreco;

        exibirMenu(*qtdProdutos, produtos);

        cout << "Insira o código do produto que deseja alterar o preço:";
        cin >> opcao;

        cout << produtos[opcao - 1].nome << " R$" << produtos[opcao - 1].preco
             << endl;
        cout << "Insira o novo preço (ou 0 para voltar): ";
        cin >> novoPreco;

        if (novoPreco > 0) {
          produtos[opcao - 1].preco = novoPreco;
          cout << "O valor de " << produtos[opcao - 1].nome
               << " foi atualizado para R$" << produtos[opcao - 1].preco
               << endl;

          continuar();
        } else {
          break;
        }
      }
    } else if (opcao == 3) {
      while (true) {
        int novaQtd;
        exibirMenu(*qtdProdutos, produtos);

        cout << "Insira o código do produto que deseja alterar a "
                "quantidade:";
        cin >> opcao;

        cout << produtos[opcao - 1].nome << " "
             << produtos[opcao - 1].quantidade << " un" << endl;
        cout << "Insira a nova quantidade (ou 0 para voltar): ";
        cin >> novaQtd;

        if (novaQtd > 0) {
          produtos[opcao - 1].quantidade = novaQtd;
          cout << "A quantidade de " << produtos[opcao - 1].nome
               << " foi atualizado para " << produtos[opcao - 1].quantidade
               << " un" << endl;

          continuar();
        } else if (novaQtd == 0) {
          break;
        } else {
          cout << "Quantidade inválida" << endl;
          break;
        }
      }
    } else if (opcao == 4) {
      // Exibe os produtos da máquina
      cout << "------INVENTÁRIO------" << endl;
      cout << "Código | Produto | Quantidade" << endl;
      for (int i = 0; i < *qtdProdutos; i++) {
        if (produtos[i].quantidade > 0) {
          cout << produtos[i].codigo << " - " << produtos[i].nome << " ("
               << produtos[i].quantidade << ")" << endl;
        }
      }
      cout << endl;
      continuar();
    } else if (opcao == 5) {
      float lucroProjetado;
      cout << "\n----CAIXA DA MÁQUINA----\n" << endl;
      cout << "Dinheiro no caixa: R$" << caixaDaMaquina << endl;
      for (int i = 0; i < *qtdProdutos; i++) {
        lucroProjetado += produtos[i].quantidade * produtos[i].preco;
      }
      cout << "Lucro projetado: R$" << lucroProjetado << endl;
      cout << endl;
      continuar();
    } else {
      break;
    }
  }
}

// Entra nas configuraçõess de usuário
void modoUsuario(int qtdProdutos, struct produto produtos[qtdProdutos],
                 float caixaDaMaquina) {
  while (true) {
  display_maquina:
    // Exibe os produtos da máquina
    cout << "------MÁQUINA DE VENDAS------" << endl;
    exibirMenu(qtdProdutos, produtos);
    // Recebe o código do produto escolhido pelo usuário
    cout << "\nInsira o código do produto desejado: ";
    int codigoSelecionado;
    cin >> codigoSelecionado;
    // Caso o código seja 0, sai do modo usuario para poder entrar no modo
    // ADM com a chave de acesso
    if (codigoSelecionado == 0) {
      break;
    }

    // Verifica qual código o usuario selecionou e exibe o produto
    for (int i = 0; i < qtdProdutos; i++) {
      if (codigoSelecionado == produtos[i].codigo) {
        if (produtos[i].quantidade > 0) {
          cout << "\nVocê selecionou:\n"
               << produtos[i].nome << " | R$" << produtos[i].preco << endl;
          // Confirma se o usuario deseja continuar
          string opcaoSelecionada;
          while (true) {

          confirmar_compra:
            cout << "\nConfirmar a compra? \n1 - Sim\n2 - Não" << endl;
            cin >> opcaoSelecionada;
            cout << endl;

            // Recebe o valor e verifica se o usuario tem dinheiro
            // suficiente
            float valorInserido;
            if (opcaoSelecionada == "1") {
              cout << "Insira o valor de depósito: R$";
              cin >> valorInserido;
              if (valorInserido < produtos[codigoSelecionado - 1].preco) {
                cout << "Dinheiro insuficiente!" << endl;
              } else if (valorInserido ==
                         produtos[codigoSelecionado - 1].preco) {
                cout << "Obrigado pela compra!" << endl;
                cout << "(Sem troco)" << endl;
                produtos[codigoSelecionado - 1].quantidade--;
                caixaDaMaquina += valorInserido;
                break;
              } else if (valorInserido >
                         produtos[codigoSelecionado - 1].preco) {
                cout << "Obrigado pela compra!" << endl;
                cout << "Troco R$"
                     << valorInserido - produtos[codigoSelecionado - 1].preco
                     << endl;
                produtos[codigoSelecionado - 1].quantidade--;
                caixaDaMaquina +=
                    valorInserido - produtos[codigoSelecionado - 1].preco;
                break;
              }
            } else if (opcaoSelecionada == "2") {
              goto display_maquina;
              break;
            } else {
              cout << "Opção inválida" << endl;
              goto confirmar_compra;
            }
          }
        } else {
          cout << "Infelizmente " << produtos[i].nome
               << " está em falta.\nPor favor, escolha outro produto." << endl;
        }
      }
    }
  }
}
