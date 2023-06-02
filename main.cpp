#include <iostream>
#include <limits>
#include <unistd.h>

using namespace std;
// Define a capacidade máxima de p_1 a serem cadastrados
const int qtdMaxDeProdutos = 51;
const int tamanhoDoArray = qtdMaxDeProdutos + 1;
const int delay = 2;
int chaveDeAcesso = 1212;
// Define a chave de acesso para entrar no modo administrador

#define tudo numeric_limits<streamsize>::max(), '\n'

// Cria as caracteristicas dos p_1
struct item {
  string nome;
  float preco;
  int quantidade;
  int codigo;
};

void pausa() {
  string pausa;
  cout << "Digite algo para continuar...";
  cin >> pausa;
}
void exibir(struct item p_1[], int p_2, int p_3) {
  switch (p_3) {
  case 1:
    cout << "Cód | Prod | Preço | Qtd" << endl;
    for (int i = 0; i < p_2; i++) {
      if (p_1[i].quantidade > 0) {
        cout << p_1[i].codigo << " | " << p_1[i].nome << "  | R$"
             << p_1[i].preco << " | " << p_1[i].quantidade << "un" << endl;
      }
    }
    break;
  case 2:
    cout << "Cód | Prod | Preço" << endl;
    for (int i = 0; i < p_2; i++) {
      if (p_1[i].quantidade > 0) {
        cout << p_1[i].codigo << " | " << p_1[i].nome << "  | R$"
             << p_1[i].preco << endl;
      }
    }
    break;
  case 3:
    cout << "Cód | Prod" << endl;
    for (int i = 0; i < p_2; i++) {
      if (p_1[i].quantidade > 0) {
        cout << p_1[i].codigo << " | " << p_1[i].nome << endl;
      }
    }
    break;
  default:
    cout << "opção de exibição inválida!" << endl;
    break;
  }
}
void inicializar_baseDeDados(struct item p_1[]) {
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
  inicializar_baseDeDados(p_1);

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
void modoADM_alterar_nome(struct item p_1[], int p_2) {
  int selecionado;

  while (true) {
    cout << "----ALTERAR NOME-----" << endl;
    exibir(p_1, p_2, 3);
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > p_2) {
      cout << endl;
      cout << "Insira um código válido!" << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        return;
      } else {
        system("clear");
        cout << p_1[selecionado - 1].nome << " será alterado para: ";
        cin >> p_1[selecionado - 1].nome;
        cout << endl;
        cout << "Alteração realizada com sucesso!" << endl;
        sleep(delay);
        break;
      }
    }
  }
}
void modoADM_alterar_preco(struct item p_1[], int p_2) {
  int selecionado;

  while (true) {
    cout << "----ALTERAR PREÇO-----" << endl;
    exibir(p_1, p_2, 3);
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > p_2) {
      cout << endl;
      cout << "Insira um código válido!" << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        return;
      } else {
        while (true) {
          cout << p_1[selecionado - 1].nome << " R$"
               << p_1[selecionado - 1].preco << " será alterado para: ";
          if (!(cin >> p_1[selecionado - 1].preco) ||
              p_1[selecionado - 1].preco <= 0) {
            cout << endl;
            cout << "Insira um preço válido!" << endl;
            cout << endl;
            sleep(delay);
            cin.clear();
            cin.ignore(tudo);
          } else {
            cout << "Alteração realizada com sucesso!" << endl;
            break;
          }
        }
        break;
      }
    }
  }
}
void modoADM_alterar_quantidade(struct item p_1[], int p_2) {
  while (true) {
    int selecionado;
    cout << "----ALTERAR QUANTIDADE-----" << endl;
    exibir(p_1, p_2, 1);
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > p_2) {
      cout << endl;
      cout << "Insira um código válido!" << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        return;
      } else {
        while (true) {
          cout << p_1[selecionado - 1].quantidade << "un de "
               << p_1[selecionado - 1].nome << " será alterado para: ";
          if (!(cin >> p_1[selecionado - 1].quantidade) ||
              p_1[selecionado - 1].quantidade < 0) {
            cout << endl;
            cout << "Insira uma quantidade válida!" << endl;
            cout << endl;
            sleep(delay);
            cin.clear();
            cin.ignore(tudo);
          } else {
            cout << "Alteração realizada com sucesso!" << endl;
            break;
          }
        }
        break;
      }
    }
  }
}
void modoADM_alterar_codigo(struct item p_1[], int *p_2) {
  while (true) {
    int selecionado;

    cout << "----ALTERAR CÓDIGO-----" << endl;
    exibir(p_1, *p_2, 3);
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > *p_2) {
      cout << endl;
      cout << "Insira um código válido!" << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        return;
      } else {
        while (true) {
          int selecionado_2;

          cout << "Código " << p_1[selecionado - 1].codigo << " ("
               << p_1[selecionado - 1].nome
               << ") será alterado para (ou 0 para cancelar): ";

          if (!(cin >> selecionado_2) || selecionado_2 < 0 ||
              selecionado_2 > *p_2) {
            cout << endl;
            cout << "Insira uma código válido!" << endl;
            cout << endl;
            sleep(delay);
            cin.clear();
            cin.ignore(tudo);
          } else {
            if (selecionado_2 == 0) {
              break;
            } else {
              // Cria um novo espaço dentro do array de produtos
              (*p_2)++;

              // copia as propriedades do produto que sera substituido para o
              // novo espaço do array
              p_1[*p_2].nome = p_1[selecionado_2 - 1].nome;
              p_1[*p_2].preco = p_1[selecionado_2 - 1].preco;
              p_1[*p_2].quantidade = p_1[selecionado_2 - 1].quantidade;

              // Substitui as propriedades do produto #1 para o produto #2
              p_1[selecionado_2 - 1].nome = p_1[selecionado - 1].nome;
              p_1[selecionado_2 - 1].preco = p_1[selecionado - 1].preco;
              p_1[selecionado_2 - 1].quantidade =
                  p_1[selecionado - 1].quantidade;
              p_1[selecionado_2 - 1].codigo = selecionado_2;

              // Substitui as propriedades do produto #2 para o produto #1
              p_1[selecionado - 1].nome = p_1[*p_2].nome;
              p_1[selecionado - 1].preco = p_1[*p_2].preco;
              p_1[selecionado - 1].quantidade = p_1[*p_2].quantidade;
              p_1[selecionado - 1].codigo = selecionado;

              // Apaga o espaço extra criado
              (*p_2)--;
              cout << "Alteração realizada com sucesso!" << endl;
              break;
            }
          }
        }
        break;
      }
    }
  }
}
void modoADM_alterar_excluir(struct item p_1[], int *p_2) {
  while (true) {
    int selecionado;

    cout << "----EXCLUIR PRODUTO-----" << endl;
    exibir(p_1, *p_2, 1);
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > *p_2) {
      cout << endl;
      cout << "Insira um código válido!" << endl;
      cout << endl;
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        return;
      } else {
        int selecionado_2;

        cout << "Confirmar exclusão de: " << p_1[selecionado - 1].nome
             << "? \n1 - Sim\nOutra tecla - Não\n\nOpção: ";
        cin >> selecionado_2;

        if (selecionado_2 == 1) {

          for (int i = selecionado - 1; i < *p_2; i++) {
            p_1[i].nome = p_1[i + 1].nome;
            p_1[i].preco = p_1[i + 1].preco;
            p_1[i].quantidade = p_1[i + 1].quantidade;
            p_1[i].quantidade = p_1[i + 1].codigo;
          }
          (*p_2)--;

          cout << endl;
          cout << "Produto excluido com sucesso!" << endl;
          break;
        } else {
          break;
        }
      }
    }
  }
}
void modoADM_cadastrar(struct item p_1[], int *p_2) {
  cout << "----CADASTRO DE PRODUTOS----" << endl;

  cout << "Insira o nome: ";
  cin >> p_1[*p_2].nome;

  while (true) {
    cout << "Insira o preco de " << p_1[*p_2].nome << ": R$";
    if (!(cin >> p_1[*p_2].preco)) {
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

  while (true) {
    cout << "Insira a quantidade de " << p_1[*p_2].nome << ":";
    if (!(cin >> p_1[*p_2].quantidade)) {
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

  p_1[*p_2].codigo = *p_2 + 1;

  cout << "\n"
       << p_1[*p_2].quantidade << "un de " << p_1[*p_2].nome << " à R$"
       << p_1[*p_2].preco
       << "foram cadastradas com \nsucesso sob o código: " << p_1[*p_2].codigo
       << endl;
  (*p_2)++;
}
void modoADM_alterar(struct item p_1[], int *p_2) {
  while (true) {
    int selecionado;

    cout << "-----MENU ALTERAÇÃO----" << endl;
    cout << endl;
    cout << "Selecione uma opção: \n1 - Alterar nome\n2 - Alterar preço\n3 - "
            "Alterar quantidade\n4 - Alterar código\n5 - Excluir "
            "produto\n\nOutra tecla - Voltar\n\nOpção: ";
    cin >> selecionado;
    switch (selecionado) {
    case 1:
      system("clear");
      modoADM_alterar_nome(p_1, *p_2);
      system("clear");
      break;
    case 2:
      system("clear");
      modoADM_alterar_preco(p_1, *p_2);
      system("clear");
      break;
    case 3:
      system("clear");
      modoADM_alterar_quantidade(p_1, *p_2);
      system("clear");
      break;
    case 4:
      system("clear");
      modoADM_alterar_codigo(p_1, p_2);
      system("clear");
      break;
    case 5:
      system("clear");
      modoADM_alterar_excluir(p_1, p_2);
      system("clear");
      break;
    default:
      return;
    }
  }
}
void modoADM_caixa(struct item p_1[], int p_2, float p_3) {
  float somaPreco = 0.0;
  cout << "-----CAIXA-----" << endl;
  cout << endl;
  cout << "Cofre da máquina: R$" << p_3 << endl;
  for (int i = 0; i < p_2; i++) {
    somaPreco += p_1[i].preco * p_1[i].quantidade;
  }
  cout << "Valor bruto: R$" << somaPreco << endl;
}
void modoADM_trocarSenha(int *p_1) {
  cout << "----TROCAR SENHA-----" << endl;
  cout << "Chave de acesso atual: " << *p_1 << endl;
  cout << endl;
  while (true) {
    int selecionado;
    cout << "Insira a nova chave (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0) {
      system("clear");
      cout << "Insira uma chave válida!\n\nOBS: A chave precisa ser um número "
              "inteiro maior que 0"
           << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
    } else {
      if (selecionado == 0) {
        break;
      } else {
        cout << selecionado << " cadastrada com sucesso como nova chave!"
             << endl;
        *p_1 = selecionado;
        break;
      }
    }
  }
}
void modoADM(struct item p_1[], int *p_2, float p_3) {
  int inserido;

  while (true) {
    cout << "-----MODO ADMNISTRADOR-----" << endl;
    cout << endl;
    cout << "Selecione uma opção:\n \n1 - Cadastrar novo produto\n2 - "
            "Alterar produto\n3 - Inventario\n4 - "
            "Caixa\n5 - Trocar senha\n\nOutra tecla - Sair\n\nOpção: ";
    cin >> inserido;

    switch (inserido) {
    case 1:
      if (*p_2 < qtdMaxDeProdutos) {
        system("clear");
        modoADM_cadastrar(p_1, p_2);
        pausa();
        system("clear");
      } else {
        cout << endl;
        cout << "A capacidade máxima de produtos cadastrados\nfoi atingida. "
                "Para modoADM_cadastrar novos produtos\nremova algum já "
                "existem para "
                "liberar espaço!"
             << endl;
        cout << endl;
        cin.clear();
        cin.ignore(tudo);
      }
      break;
    case 2:
      system("clear");
      modoADM_alterar(p_1, p_2);
      system("clear");
      break;
    case 3:
      system("clear");
      cout << "-----INVENTARIO-----" << endl;
      exibir(p_1, *p_2, 1);
      pausa();
      system("clear");
      break;
    case 4:
      sleep(delay);
      system("clear");
      modoADM_caixa(p_1, *p_2, p_3);
      pausa();
      system("clear");
      break;
    case 5:
      sleep(delay);
      system("clear");
      modoADM_trocarSenha(&chaveDeAcesso);
      pausa();
      system("clear");
      break;
    default:
      system("clear");
      cout << "Saindo do modo administrador..." << endl;
      sleep(delay);
      system("clear");
      return;
    }
  }
}
void comprar(struct item p_1[], int p_2, float *p_3) {
  float pagamento;

  cout << "----COMPRAR-----" << endl;
  cout << "Produto: " << p_1[p_2 - 1].nome << endl;
  cout << "Preço: R$" << p_1[p_2 - 1].preco << endl;
  cout << endl;

  while (true) {
    cout << "Insira o dinheiro: R$";
    if (!(cin >> pagamento)) {
      cout << endl;
      cout << "Insira um valor válido!" << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (pagamento >= p_1[p_2 - 1].preco) {
        cout << endl;
        cout << "Obrigado pela compra!"
             << "\n\nTroco: R$" << (pagamento - p_1[p_2 - 1].preco) << endl;
        *p_3 += pagamento - p_1[p_2 - 1].preco;
        p_1[p_2 - 1].quantidade--;

        pausa();
        system("clear");
        break;
      } else {
        system("clear");
        cout << "Dinheiro insuficiente!\nFaltam R$"
             << p_1[p_2 - 1].preco - pagamento << endl;
        cin.clear();
        cin.ignore(tudo);
        sleep(delay);
        system("clear");
        break;
      }
    }
  }
}

int main() {
  struct item produtos[tamanhoDoArray];
  int qtdProdutos = inicializar(produtos);
  float cofre = 0.0;

  system("clear");
  while (true) {
    int inserido;
    float pagamento;

    cout << "-----MÁQUINA DE VENDAS------" << endl;
    cout << endl;
    exibir(produtos, qtdProdutos, 2);
    cout << endl;
    cout << "Insira o código do produto: ";
    cin >> inserido;

    system("clear");
    if (inserido == chaveDeAcesso) {
      system("clear");
      cout << endl;
      cout << "Entrando no modo administrador..." << endl;
      sleep(delay);
      system("clear");
      modoADM(produtos, &qtdProdutos, cofre);
    } else if (inserido > 0 && inserido <= qtdProdutos) {
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
        system("clear");
        comprar(produtos, inserido, &cofre);
        break;
      default:
        system("clear");
        cin.clear();
        cin.ignore(tudo);
        break;
      }
    } else {
      system("clear");
      cout << endl;
      cout << "Por favor, insira uma opção válida" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
    }
  }

  return 0;
}
