#include <iostream>
#include <unistd.h>
#include <limits>

using namespace std;
// Define a capacidade máxima de p_1 a serem cadastrados
#define qtdMaxDeProdutos 50
// Define a chave de acesso para entrar no modo administrador
#define chave_acesso 1212

#define tudo numeric_limits<streamsize>::max(), '\n'
#define delay 1

// Cria as caracteristicas dos p_1
struct item {
  string nome;
  float preco;
  int quantidade;
  int codigo;
};

void base_dados(struct item p_1[]) {
    p_1[0] = {"Coca-Cola", 4.0, 15};
    p_1[1] = {"Ruffles", 3.5, 12};
    p_1[2] = {"Snickers", 2.5, 20};
    p_1[3] = {"Barrinha de Cereal", 1.75, 25};
    p_1[4] = {"Água Mineral", 2.0, 20};
    p_1[5] = {"Oreo", 3.0, 18};
    p_1[6] = {"KitKat", 2.0, 15};
    p_1[7] = {"Red Bull", 8.0, 10};
    p_1[8] = {"Trident", 1.5, 30};
    p_1[9] = {"Hershey's", 3.0, 15};
    p_1[10] = {"Doritos", 3.5, 20};
    p_1[11] = {"Sprite", 3.0, 18};
    p_1[12] = {"Lacta", 2.5, 25};
    p_1[13] = {"Nature Valley", 2.0, 15};
    p_1[14] = {"Água de Coco", 2.5, 20};
    p_1[15] = {"Club Social", 2.0, 18};
    p_1[16] = {"Twix", 2.5, 15};
    p_1[17] = {"Monster", 7.0, 10};
    p_1[18] = {"Bubbaloo", 1.75, 30};
    p_1[19] = {"Nestlé", 3.5, 15};
    p_1[20] = {"Cheetos", 3.0, 20};

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
  
  while(true){
    cout << "Insira o preco de " << p_1[*p_2].nome << ": R$";
    if(!(cin >> p_1[*p_2].preco)){
      cout << endl;
      cout << "Insira um valor válido!" << endl;
      cout << endl;
      sleep(delay);
      
      cin.clear();
      cin.ignore(tudo);
    } else {
      break;
    }
  }

    while(true){
    cout << "Insira a quantidade de " << p_1[*p_2].nome << ":";
    if(!(cin >> p_1[*p_2].quantidade)){
      cout << endl;
      cout << "Insira um valor válido!" << endl;
      cout << endl;
      sleep(delay);
      
      cin.clear();
      cin.ignore(tudo);
    } else {
      break;
    }
  }

  cout << "\n"
       << p_1[*p_2].quantidade << "un de " << p_1[*p_2].nome << " à R$"
       << p_1[*p_2].preco << " foram cadastradas com sucesso!\n"
       << endl;
  
  sleep(delay);

  p_1[*p_2].codigo = *p_2 + 1;
  (*p_2)++;
}

void excluir(struct item p_1[], int *p_2, int p_3) {
  for (int i = p_3 - 1; i < *p_2; i++) {
    p_1[i].nome = p_1[i + 1].nome;
    p_1[i].preco = p_1[i + 1].preco;
    p_1[i].quantidade = p_1[i + 1].quantidade;
    p_1[i].quantidade = p_1[i + 1].codigo;
  }
  (*p_2)--;
}

void alterar(struct item p_1[], int *p_2) {
  int selecionado;

  while(true) {
    cout << "-----MENU ALTERAÇÃO----" << endl;
    cout << endl;
    cout << "Selecione uma opção: \n1 - Alterar nome\n2 - Alterar preço\n3 - "
            "Alterar quantidade\n4 - Excluir "
            "produto\n\nOutra tecla - Voltar\n\nOpção: ";
    cin >> selecionado;
    switch (selecionado) {
    case 1:
      while(true){
        cout << "Insira o código do produto: ";
        if(!(cin >> selecionado)){
          cout << endl;
          cout << "Insira um código válido!" << endl;
          cout << endl;
          sleep(delay);
          cin.clear();
          cin.ignore(tudo);
    } else {
        break;
    }
  }

      cout << p_1[selecionado - 1].nome << " será alterado para: ";
      cin >> p_1[selecionado - 1].nome;
      cout << endl;
      cout << "Alteração realizada com sucesso!" << endl;
      sleep(delay);
      break;
    case 2:
      cout << "Insira o código do produto: ";
      cin >> selecionado;

      cout << p_1[selecionado - 1].nome << " R$" << p_1[selecionado - 1].preco
           << " será alterado para: ";
      cin >> p_1[selecionado - 1].preco;
      cout << endl;
      cout << "Alteração realizada com sucesso!" << endl;
      sleep(delay);
      break;
    case 3:
      cout << "Insira o código do produto: ";
      cin >> selecionado;

      cout << p_1[selecionado - 1].nome << " "
           << p_1[selecionado - 1].quantidade << "un"
           << " será alterado para: ";
      cin >> p_1[selecionado - 1].quantidade;
      cout << endl;
      cout << "Alteração realizada com sucesso!" << endl;
      sleep(delay);
      break;
    case 4:
      int selecionado_2;

      while(true){
        cout << "Insira o código do produto: ";
        if(!(cin >> selecionado) || p_1[selecionado - 1].quantidade < 0){
          cout << endl;
          cout << "Insira um código válido!" << endl;
          cout << endl;
          cin.clear();
          cin.ignore(tudo);
        } else {
          break;
        }
      }
      
      cout << "Confirmar exclusão de: " << p_1[selecionado - 1].nome
           << "? \n1 - Sim\nOutra tecla - Não\n\nOpção: ";
      cin >> selecionado_2;
      
      if (selecionado_2 == 1) {
        excluir(p_1, p_2, selecionado);
        cout << endl;
        cout << "Produto excluido com sucesso!" << endl;
        sleep(delay);
      } 

      cin.clear();
      cin.ignore(tudo);
      break;
    default:
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      return;
    }
  } 
}

void modo_administrador(struct item p_1[], int *p_2, float p_3) {
  int inserido;

  while(true) {
    cout << endl;
    cout << "-----MODO ADMNISTRADOR-----" << endl;
    cout << endl;
    cout << "Selecione uma opção:\n \n1 - Cadastrar novo produto\n2 - "
            "Alterar produto\n3 - Inventario\n4 - "
            "Caixa\n\nOutra tecla - Sair\n\nOpção: ";
    cin >> inserido;

    cout << endl;
    switch (inserido) {
    case 1:
      if(*p_2 < qtdMaxDeProdutos){
        sleep(delay);
        cadastrar(p_1, p_2);
      } else {
        cout << endl;
        cout << "A capacidade máxima de produtos cadastrados\nfoi atingida. Para cadastrar novos produtos\nremova algum já existem para liberar espaço!" << endl;
        cout << endl;
      }
      
      cin.clear();
      cin.ignore(tudo);
      break;
    case 2:
      sleep(delay);
      alterar(p_1, p_2);
      break;
    case 3:
      sleep(delay);
      exibir(p_1, *p_2);
      sleep(delay*2);
      break;
    case 4:
      sleep(delay);
      caixa(p_1, *p_2, p_3);
      sleep(delay*2);
      break;
    default:
      cout << "Saindo do modo administrador..." << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      return;
    }
  } 
}

void comprar(struct item p_1[], int p_2, float *p_3) {
  float pagamento;

  cout << endl;
  cout << "Produto: " << p_1[p_2 - 1].nome << endl;
  cout << "Preço: R$" << p_1[p_2 - 1].preco << endl;
  cout << endl;

  while(true){
    cout << "Insira o dinheiro: R$";
    if(!(cin >> pagamento)){
          cout << endl;
          cout << "Insira um valor válido!" << endl;
          cout << endl;
          sleep(delay);
          cin.clear();
          cin.ignore(tudo);
    } else {
        if (pagamento >= p_1[p_2 - 1].preco) {
          cout << "Obrigado pela compra!"
                << "\n\nTroco: R$" << (pagamento - p_1[p_2 - 1].preco) << endl;
          *p_3 += pagamento - p_1[p_2 - 1].preco;
          p_1[p_2 - 1].quantidade--;
          cin.clear();
          cin.ignore(tudo);
          sleep(delay);
          break;
        } else {
          cout << "Dinheiro insuficiente!\nFaltam R$"
                << p_1[p_2 - 1].preco - pagamento << endl;
          cin.clear();
          cin.ignore(tudo);
          sleep(delay);
          break;
        }
    }
  }
}

int main() {
  struct item produtos[qtdMaxDeProdutos];
  int qtdProdutos = inicializar(produtos);
  float cofre = 0.0;

  while(true) {
    int inserido;
    float pagamento;

    cout << "-----MÁQUINA DE VENDAS------" << endl;
    cout << endl;
    exibir(produtos, qtdProdutos);
    cout << endl;
    cout << "Insira o código do produto: ";
    cin >> inserido;

    if (inserido == chave_acesso) {
      cout << endl;
      cout << "Entrando no modo administrador..." << endl;
    sleep(delay);
      modo_administrador(produtos, &qtdProdutos, cofre);
    } else if (inserido > 0 && inserido <= qtdProdutos){
      int opcao;
      cout << "-----COMPRAR-----" << endl;
      cout << endl;
      cout << "Selecionado: " << produtos[inserido - 1].nome << " R$"
           << produtos[inserido - 1].preco << endl;
      cout << endl;
      cout << "Confirma a comprar?\n1 - Sim\nOutra tecla - Não\n\nOpção: ";
      cin >> opcao;

      switch (opcao) {
      case 1:
        comprar(produtos, inserido, &cofre);
        cin.clear();
        cin.ignore(tudo);
        break;
      default:
        cin.clear();
        cin.ignore(tudo);
        break;
      }
    } else {
      cout << "Por favor, insira uma opção válida" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      continue;
    } 
  } 
  return 0;
}
