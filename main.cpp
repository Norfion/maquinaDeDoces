#include <iostream>
using namespace std;
#define qtdProdutos 2

struct produto {
  string nome;
  int quantidade;
  int codigo;
  float preco;
};

int main() {
  struct produto produtos[qtdProdutos];

  // Atribui informações aos produtos
  produtos[0].nome = "Banana";
  produtos[0].quantidade = 5;
  produtos[0].preco = 10.0;
  produtos[1].nome = "Chocolate";
  produtos[1].quantidade = 2;
  produtos[1].preco = 20.0;
  for (int i = 0; i < qtdProdutos; i++) {
    produtos[i].codigo = (i + 1);
  }

  while (true) {
    string opcaoDeModo;

    cout << "Digite algo para continuar: ";
    cin >> opcaoDeModo;

    if (opcaoDeModo == "admads2023") {

    } else {
      while (true) {
        bool liberacaoDoProduto = false;
        // Exibe os produtos da máquina
        cout << "------MÁQUINA------" << endl;
        cout << "Código | Produto | Quantidade" << endl;
        for (int i = 0; i < qtdProdutos; i++) {
          cout << produtos[i].codigo << " - " << produtos[i].nome << " ("
               << produtos[i].quantidade << ")" << endl;
        }
        cout << "\nInsira o código do produto desejado: ";
        int codigoSelecionado;
        cin >> codigoSelecionado;
        if (codigoSelecionado == 0) {
          break;
        }

        // Verifica qual código o usuario selecionou e exibe o produto
        for (int i = 0; i < qtdProdutos; i++) {
          if (codigoSelecionado == produtos[i].codigo) {
            cout << produtos[i].nome << " R$" << produtos[i].preco << endl;
          }
        }
        // Confirma se o usuario deseja continuar
        string opcaoSelecionada;
        cout << "Confirmar a compra? ";
        cin >> opcaoSelecionada;

        // Recebe o valor e verifica se o usuario tem dinheiro suficiente
        float valorInserido;
        if (opcaoSelecionada == "S" || opcaoSelecionada == "s") {
          cout << "Insira o valor de depósito: R$";
          cin >> valorInserido;
          if (valorInserido < produtos[codigoSelecionado - 1].preco) {
            cout << "Dinheiro insuficiente!";
          } else if (valorInserido == produtos[codigoSelecionado - 1].preco) {
            cout << "Obrigado pela compra!" << endl;
            cout << "(Sem troco)" << endl;
            liberacaoDoProduto = true;
            produtos[codigoSelecionado - 1].quantidade--;
          } else if (valorInserido > produtos[codigoSelecionado - 1].preco) {
            cout << "Obrigado pela compra!" << endl;
            cout << "Troco R$"
                 << valorInserido - produtos[codigoSelecionado - 1].preco;
            produtos[codigoSelecionado - 1].quantidade--;
            liberacaoDoProduto = true;
          }
        }
      }
    }
  }
}
