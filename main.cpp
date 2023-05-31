#include <iostream>
using namespace std;
// Define a capacidade máxima de p_1 a serem cadastrados
#define qtdMaxDeProdutos 50
// Define a chave de acesso para entrar no modo administrador
#define chave_acesso 1212

// Cria as caracteristicas dos p_1
struct item {
  string nome;
  float preco;
  int quantidade;
  int codigo;
};

void caixa(struct item p_1[], int p_2, float p_3) {
  float somaPreco = 0.0;
  cout << "-----CAIXA-----" << endl;
  cout << endl;
  cout << "Cofre da máquina: R$" << p_3 << endl;
  for (int i = 0; i < p_2; i++) {
    somaPreco += p_1[i].preco * p_1[i].quantidade;
  }
  cout << "Valor bruto: R$" << somaPreco << endl;
}
void base_dados(struct item p_1[]) {
  p_1[0] = {"Doritos", 13.5, 15};
  p_1[1] = {"Pepsi", 3.5, 15};
  p_1[2] = {"Coca-cola", 4.0, 15};
  p_1[3] = {"Ruffles", 4.0, 7};
  p_1[4] = {"Doritos", 7, 9};

  // Para inserir um novo produto na base de dados siga o modelo:
  // p_1[codigo do produto - 1] = {"nome do produto", preco, quantidade}
}

int inicializar(struct item p_1[]) {
  int cadastrados = 0;

  // Define todos as posicoes do array como negativas/sem produtos
  for (int i = 0; i < qtdMaxDeProdutos; i++) {
    p_1[i].quantidade = -1;
  }

  // Carrega base de dados e substitui os produtos nao existentes
  base_dados(p_1);

  // Coloca o codigo dos produtos e retorna a quantidade de produtos ja
  // cadastrados
  for (int i = 0; i < qtdMaxDeProdutos; i++) {
    if (p_1[i].quantidade >= 0) {
      p_1[i].codigo = (i + 1);
      cadastrados++;
    }
  }

  return cadastrados;
}
void exibir(struct item p_1[], int p_2) {
  cout << "Cód | Prod | Preço | Qtd" << endl;
  for (int i = 0; i < p_2; i++) {
    if (p_1[i].quantidade > 0) {
      cout << p_1[i].codigo << " | " << p_1[i].nome << "  | R$" << p_1[i].preco
           << " | " << p_1[i].quantidade << "un" << endl;
    }
  }
}
void cadastrar(struct item p_1[], int *p_2) {
  cout << "----CADASTRO DE PRODUTOS----" << endl;
  cout << "Insira o nome: ";
  cin >> p_1[*p_2].nome;
  cout << "Insira o valor de " << p_1[*p_2].nome << " R$";
  cin >> p_1[*p_2].preco;
  cout << "Insira a quantidade de " << p_1[*p_2].nome << ": ";
  cin >> p_1[*p_2].quantidade;

  cout << "\n"
       << p_1[*p_2].quantidade << "un de " << p_1[*p_2].nome << " à R$"
       << p_1[*p_2].preco << " foram cadastradas com sucesso!\n"
       << endl;

  p_1[*p_2].codigo = *p_2 + 1;
  (*p_2)++;
}
void modo_administrador(struct item p_1[], int *p_2, float p_3) {
  int inserido_2;

  do {
    cout << "\n-----MODO ADMNISTRADOR-----" << endl;
    cout << endl;
    cout << "Selecione uma opção: \n1 - Cadastrar novo produto\n2 - "
            "Alterar produto\n3 - Inventario\n4 - "
            "Caixa\n\n0 - Sair\n\nOpção: ";
    cin >> inserido_2;
    cout << endl;
    switch (inserido_2) {
    case 1:
      cadastrar(p_1, p_2);
      break;
    case 3:
      exibir(p_1, *p_2);
      break;
    case 4:
      caixa(p_1, *p_2, p_3);
      break;
    }
  } while (inserido_2 != 0);
}

int main() {
  struct item produtos[qtdMaxDeProdutos];
  int qtdProdutos = inicializar(produtos);
  int inserido;
  float cofre = 0.0;

  while (true) {
    cout << "-----MÁQUINA DE VENDAS------" << endl;
    cout << endl;
    exibir(produtos, qtdProdutos);
    cout << "Insira o código do produto: ";
    cin >> inserido;

    if (inserido == chave_acesso) {
      modo_administrador(produtos, &qtdProdutos, cofre);
    } else {
    }
  }

  return 0;
}
