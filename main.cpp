// Código criado por:
// Normando Nascimento Oliveira Meira
// RA: 2840482311028
// Fatec-RP

#include <iomanip>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;
// Define as constantes para o funcionamento do código;
const int qtdMaxDeProdutos = 20;
// Adiciona 1 unidade de espaço vazio para alterções no código do produto
const int tamanhoDoArray = qtdMaxDeProdutos + 3;
const int delay = 2;
int chaveDeAcesso = 121212;
#define tudo 100, '\n'

// Cria as caracteristicas dos p_1
struct item {
  string nome;
  float preco;
  int quantidade;
  int codigo;
};

// Pausa o programa até o usuario inserir um valor
// NOTA: Tentar substituir por system("pause")
void pausa() {
  string pausa;
  cout << endl;
  cout << "Digite algo para continuar...";
  cin >> pausa;
  cin.clear();
  cin.ignore(tudo);
}
// Base de dados dos produtos nativos do sistema
void inicializar_baseDeDados(struct item p_1[]) {
  p_1[0] = {"Coca-Cola", 4.0, 1};
  p_1[1] = {"Ruffles", 7, 1};
  p_1[2] = {"Snickers", 2.5, 1};
  p_1[3] = {"Barrinha de Cereal", 1.75, 1};
  p_1[4] = {"Agua Mineral", 2.0, 1};
  p_1[5] = {"Oreo", 3.0, 1};
  p_1[6] = {"KitKat", 4, 15};
  p_1[7] = {"Red Bull", 8.0, 10};
  p_1[8] = {"Trident", 3, 30};
  p_1[9] = {"Hershey's", 3.0, 15};
  p_1[10] = {"Doritos", 12, 20};
  p_1[11] = {"Sprite", 4, 18};
  p_1[12] = {"Lacta", 6.5, 25};
  p_1[13] = {"Nature Valley", 2.0, 15};
  p_1[14] = {"Agua de Coco", 4.5, 20};
  p_1[15] = {"Twix", 2.5, 15};
  p_1[16] = {"Monster", 7.0, 10};
  p_1[17] = {"Bubbaloo", 1, 30};
  p_1[18] = {"Nestle", 3.5, 15};
  p_1[19] = {"Cheetos", 8, 20};

  // Para inserir um novo produto na base de dados siga o modelo:
  // p_1[codigo do produto - 1] = {"nome do produto", preco, quantidade}
  // OBS: Por favor, cadastre o nome dos produtos sem acento ou caracteres
  // especiais
}
// Carrega a base de dados
int inicializar(struct item p_1[]) {
  int cadastrados = 0;

  // Define todos as posicoes do array como negativas/sem produtos
  for (int i = 0; i < qtdMaxDeProdutos; i++) {
    p_1[i].quantidade = -1;
  }

  // Carrega base de dados e substitui os produtos nao existentes
  inicializar_baseDeDados(p_1);

  // Verifica se as quantidades dos produtos não são negativas para adicionar os
  // códigos e conta a quantidade de produtos que existem na base de dados
  for (int i = 0; i < qtdMaxDeProdutos; i++) {
    if (p_1[i].quantidade >= 0) {
      p_1[i].codigo = (i + 1);
      cadastrados++;
    }
  }

  // Retorna quantos produtos existem na base de dados
  return cadastrados;
}
int exibir_maiorNome(struct item p_1[], int p_2) {
  int maior;
  // Calcula qual o maior nome do produto passado como parametro em p_1
  for (int i = 0; i < p_2; i++) {
    if (i == 0) {
      maior = p_1[i].nome.length();
    } else {
      if (p_1[i].nome.length() > maior) {
        maior = p_1[i].nome.length();
      }
    }
  }
  // Retorna a quantidade de caracteres do maior nome encontrado
  return maior;
}
void exibir(struct item p_1[], int p_2, int p_3) {
  // Cria varios menus de exibição com ou sem algumas das seguintes
  // propriedades: codigo, nome, preco ou quantidade Além disso, usa a função
  // exibir_maiorNome para formatar o tamanho do menu de exibição
  switch (p_3) {
  case 1:
    cout << left << setw(3) << "Cód"
         << " | " << left << setw(exibir_maiorNome(p_1, p_2) + 2) << "Produto"
         << " | " << left << setw(7) << "Preço" << endl;

    for (int i = 0; i < p_2; i++) {
      if (p_1[i].quantidade > 0) {
        cout << left << setw(3) << p_1[i].codigo << " | " << left
             << setw(exibir_maiorNome(p_1, p_2) + 2) << p_1[i].nome << " | "
             << left << setw(3) << "R$" << fixed << setprecision(2)
             << p_1[i].preco << endl;
      }
    }
    break;
  case 2:
    cout << left << setw(3) << "Cód"
         << " | " << left << setw(exibir_maiorNome(p_1, p_2) + 2) << "Produto"
         << " | " << left << setw(7) << "Preço"
         << " | " << right << setw(2) << "Qtd" << endl;

    for (int i = 0; i < p_2; i++) {
      cout << left << setw(3) << p_1[i].codigo << " | " << left
           << setw(exibir_maiorNome(p_1, p_2) + 2) << p_1[i].nome << " | "
           << left << setw(3) << "R$" << fixed << setprecision(2)
           << p_1[i].preco;
      if (!(p_1[i].quantidade > 0)) {
        cout << " | " << left << setw(2) << "ESGOTADO" << endl;
      } else {
        cout << " | " << left << setw(2) << p_1[i].quantidade << "un" << endl;
      }
    }
    break;
  default:
    cout << "opção de exibição inválida!" << endl;
    break;
  }
}
void modoADM_alterar_nome(struct item p_1[], int p_2) {
  int selecionado;

  while (true) {
    system("clear");
    cout << "----ALTERAR NOME-----" << endl;
    exibir(p_1, p_2, 2);
    cout << endl;
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > p_2) {
      system("clear");
      cout << "Insira um código válido!" << endl;
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
        system("clear");
        cout << "Alteração realizada com sucesso!" << endl;
        pausa();
        return;
      }
    }
  }
}
void modoADM_alterar_preco(struct item p_1[], int p_2) {
  int selecionado;

  while (true) {
    system("clear");
    cout << "----ALTERAR PREÇO-----" << endl;
    exibir(p_1, p_2, 2);
    cout << endl;
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > p_2) {
      system("clear");
      cout << "Insira um código válido!" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        return;
      } else {
        while (true) {
          system("clear");
          cout << p_1[selecionado - 1].nome << " R$"
               << p_1[selecionado - 1].preco << " será alterado para: ";
          if (!(cin >> p_1[selecionado - 1].preco) ||
              p_1[selecionado - 1].preco <= 0) {
            system("clear");
            cout << "Insira um preço válido!" << endl;
            sleep(delay);
            cin.clear();
            cin.ignore(tudo);
          } else {
            system("clear");
            cout << "Alteração realizada com sucesso!" << endl;
            pausa();
            return;
          }
        }
      }
    }
  }
}
void modoADM_alterar_quantidade(struct item p_1[], int p_2) {
  while (true) {
    int selecionado;
    system("clear");
    cout << "----ALTERAR QUANTIDADE-----" << endl;
    exibir(p_1, p_2, 2);
    cout << endl;
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > p_2) {
      system("clear");
      cout << "Insira um código válido!" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else {
      if (selecionado == 0) {
        system("clear");
        return;
      } else {
        while (true) {
          system("clear");
          cout << p_1[selecionado - 1].quantidade << "un de "
               << p_1[selecionado - 1].nome << " será alterado para: ";
          if (!(cin >> p_1[selecionado - 1].quantidade) ||
              p_1[selecionado - 1].quantidade < 0) {
            system("clear");
            cout << "Insira uma quantidade válida!" << endl;
            sleep(delay);
            cin.clear();
            cin.ignore(tudo);
          } else {
            system("clear");
            cout << "Alteração realizada com sucesso!" << endl;
            pausa();
            return;
          }
        }
      }
    }
  }
}
void modoADM_alterar_codigo(struct item p_1[], int *p_2) {
  while (true) {
    int selecionado;
    system("clear");
    cout << "----ALTERAR CÓDIGO-----" << endl;
    exibir(p_1, *p_2, 2);
    cout << endl;
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > *p_2) {
      system("clear");
      cout << "Código inválido!" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else if (selecionado == 0) {
      return;
    } else {
      while (true) {
        int selecionado_2;

        system("clear");
        cout << "Código " << p_1[selecionado - 1].codigo << " ("
             << p_1[selecionado - 1].nome
             << ") será alterado para \n(ou 0 para cancelar): ";

        if (!(cin >> selecionado_2) || selecionado_2 < 0 ||
            selecionado_2 > *p_2) {
          system("clear");
          cout << "Código inválido!" << endl;
          sleep(delay);
          cin.clear();
          cin.ignore(tudo);
        } else {
          if (selecionado_2 == 0) {
            return;
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
            p_1[selecionado_2 - 1].quantidade = p_1[selecionado - 1].quantidade;
            p_1[selecionado_2 - 1].codigo = selecionado_2;

            // Substitui as propriedades do produto #2 para o produto #1
            p_1[selecionado - 1].nome = p_1[*p_2].nome;
            p_1[selecionado - 1].preco = p_1[*p_2].preco;
            p_1[selecionado - 1].quantidade = p_1[*p_2].quantidade;
            p_1[selecionado - 1].codigo = selecionado;

            // Apaga o espaço extra criado
            (*p_2)--;

            system("clear");
            cout << "Alteração realizada com sucesso!" << endl;
            pausa();
            return;
          }
        }
      }
    }
  }
}
void modoADM_excluir(struct item p_1[], int *p_2) {
  while (true) {
    int selecionado;
    system("clear");
    cout << "----EXCLUIR PRODUTO-----" << endl;
    exibir(p_1, *p_2, 2);
    cout << endl;
    cout << "Insira o código do produto (ou 0 para cancelar): ";
    if (!(cin >> selecionado) || selecionado < 0 || selecionado > *p_2) {
      system("clear");
      cout << "Insira um código válido!" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
    } else if (selecionado == 0) {
      return;
    } else {
      int selecionado_2;
      system("clear");
      cout << "Confirmar exclusão de: " << p_1[selecionado - 1].nome
           << "? \n1 - Sim\nOutra tecla - Não\n\nOpção: ";
      cin >> selecionado_2;

      switch (selecionado_2) {
      case 1:
        for (int i = selecionado - 1; i < *p_2; i++) {
          p_1[i].nome = p_1[i + 1].nome;
          p_1[i].preco = p_1[i + 1].preco;
          p_1[i].quantidade = p_1[i + 1].quantidade;
          p_1[i].quantidade = p_1[i + 1].codigo;
        }
        (*p_2)--;

        system("clear");
        cout << "Produto excluido com sucesso!" << endl;
        pausa();
        return;
      default:
        return;
      }
    }
  }
}
void modoADM_cadastrar(struct item p_1[], int *p_2) {
  cout << "----CADASTRO DE PRODUTOS----" << endl;

  cout << "OBS: Por favor, não use acentos \nou caracteres especiais" << endl;
  cout << endl;
  cout << "Insira o nome: ";
  cin >> p_1[*p_2].nome;

  while (true) {
    cout << "Insira o preco de " << p_1[*p_2].nome << ": R$";
    if (!(cin >> p_1[*p_2].preco) || p_1[*p_2].preco <= 0) {
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
    if (!(cin >> p_1[*p_2].quantidade) || p_1[*p_2].quantidade <= 0) {
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
  system("clear");
  p_1[*p_2].codigo = *p_2 + 1;

  cout << p_1[*p_2].quantidade << "un de " << p_1[*p_2].nome << " à R$"
       << p_1[*p_2].preco
       << " foram cadastradas\ncom sucesso sob o código: " << p_1[*p_2].codigo
       << endl;
  (*p_2)++;
}
void modoADM_alterar(struct item p_1[], int *p_2) {
  while (true) {
    int selecionado;

    cout << "-----MENU ALTERAÇÃO----" << endl;
    cout << endl;
    cout << "Selecione uma opção: \n1 - Alterar nome\n2 - Alterar preço\n3 - "
            "Alterar quantidade\n4 - Alterar código\n\nOutra tecla - "
            "Voltar\n\nOpção: ";
    if (!(cin >> selecionado)) {
      cin.clear();
      cin.ignore(tudo);
      return;
    } else {
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
        return;
      default:
        return;
      }
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
  cout << "Total em produtos: R$" << somaPreco << endl;
  cout << endl;
  cout << "TOTAL: R$" << p_3 + somaPreco << endl;
  pausa();
}
void modoADM_trocarSenha(int *p_1) {
  while (true) {
    int selecionado;
    int chaveAntiga = *p_1;

    cout << "----TROCAR SENHA-----" << endl;
    cout << "Chave de acesso atual: " << *p_1 << endl;
    cout << endl;
    cout << "Insira a nova chave (ou 0 para cancelar): ";
    // Verifica se o caracter inserido é um inteiro e se ele tem 6 digitos (para
    // ter uma senha forte, além de impedir que a senha seja igual a um código
    // de produto e gerar erro)
    if (!(cin >> selecionado) || (selecionado < 100000 && selecionado != 0)) {
      system("clear");
      cout << "Insira uma chave válida!\n\nOBS: A chave precisa ser um número "
              "inteiro de 6 dígitos"
           << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
    } else {
      if (selecionado == 0) {
        return;
      }
      // Verifica se a nova senha é diferente da anterior
      else if (selecionado == chaveAntiga) {
        system("clear");
        cout << "A nova chave de acesso não pode ser igual à anterior!" << endl;
        sleep(delay);
        cin.clear();
        cin.ignore(tudo);
        system("clear");
      }
      // Substitui o valor da variavel ChaveDeAcesso com a nova senha informada
      else {
        system("clear");
        cout << selecionado << " cadastrada com sucesso como nova chave!"
             << endl;
        (*p_1) = selecionado;
        pausa();
        return;
      }
    }
  }
}
void modoADM(struct item p_1[], int *p_2, float p_3, int *p_4) {
  int inserido;

  // Cria um loop para sempre mostrar o menu de administrador
  while (true) {
    cout << "-----MODO ADMNISTRADOR-----" << endl;
    cout << endl;
    cout << "Selecione uma opção:\n \n1 - Cadastrar novo produto\n2 - "
            "Alterar produto\n3 - Excluir um produto\n4 - Inventario\n5 - "
            "Caixa\n6 - Trocar senha\n\nOutra tecla - Sair\n\nOpção: ";
    // Verifica se o caracter  inserido é do mesmo tipo da variavel, caso não
    // seja, encerra a função
    if (!(cin >> inserido)) {
      system("clear");
      cout << "Saindo do modo administrador..." << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
      return;
    }
    // Caso tenha sido inserido um numero, verifica em qual das opções se
    // encaixa
    else {
      switch (inserido) {
      case 1:
        // Verifica se há espaço dentro do array de produtos para inserir um
        // novo produto
        system("clear");
        if (*p_2 < qtdMaxDeProdutos) {
          modoADM_cadastrar(p_1, p_2);
        } else {
          cout << "A capacidade máxima de produtos cadastrados\nfoi atingida! "
                  "Para cadastrar novos produtos,\nexclua algum "
                  "existem para "
                  "liberar espaço"
               << endl;
          cin.clear();
          cin.ignore(tudo);
        }
        pausa();
        system("clear");
        break;
      case 2:
        system("clear");
        modoADM_alterar(p_1, p_2);
        system("clear");
        break;
      case 3:
        system("clear");
        modoADM_excluir(p_1, p_2);
        system("clear");
        break;
      case 4:
        system("clear");
        cout << "--------INVENTARIO---------" << endl;
        exibir(p_1, *p_2, 2);
        pausa();
        system("clear");
        break;
      case 5:
        system("clear");
        modoADM_caixa(p_1, *p_2, p_3);
        system("clear");
        break;
      case 6:
        system("clear");
        modoADM_trocarSenha(p_4);
        system("clear");
        break;
      default:
        system("clear");
        cout << "Saindo do modo administrador..." << endl;
        sleep(delay);
        cin.clear();
        cin.ignore(tudo);
        system("clear");
        return;
      }
    }
  }
}
void comprar(struct item p_1[], int p_2, float *p_3) {

  // Cria um loop para sempre exibir o menu de compra
  while (true) {
    float pagamento;
    cout << "----COMPRAR-----" << endl;
    cout << "Produto: " << p_1[p_2 - 1].nome << endl;
    cout << "Preço: R$" << p_1[p_2 - 1].preco << endl;
    cout << endl;
    cout << "Insira o dinheiro (ou 0 para cancelar): R$";

    // Verifica se o valor inserido como pagamento é do tipo float
    if (!(cin >> pagamento)) {
      system("clear");
      cout << "Insira um valor válido!" << endl;
      cout << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
    }
    // Caso o valor inserido seja 0, encerra a função
    else if (pagamento == 0) {
      return;
    }
    // Verifica se o valor é suficiente para pagar o produto
    else if (pagamento >= p_1[p_2 - 1].preco) {
      system("clear");
      cout << "Obrigado pela compra!"
           << "\n\nTroco: R$" << (pagamento - p_1[p_2 - 1].preco) << endl;
      *p_3 += p_1[p_2 - 1].preco;
      p_1[p_2 - 1].quantidade--;

      pausa();
      return;
    }
    // Informa que o valor é insuficiente (menor que o preço do produto) e
    // encerra a função
    else {
      system("clear");
      cout << "Dinheiro insuficiente!\nFaltam R$"
           << p_1[p_2 - 1].preco - pagamento << endl;
      cin.clear();
      cin.ignore(tudo);
      sleep(delay);
      return;
    }
  }
}

int main() {
  // Carrega a estrutura dos produtos
  struct item produtos[tamanhoDoArray];
  // Inicializa a base de dados e retorna quantos produtos há na base para o
  // sinalizador
  int qtdProdutos = inicializar(produtos);
  float cofre = 0.00;

  system("clear");

  // Cria um loop para sempre exibir o menu de vendas
  while (true) {
    int inserido;
    float pagamento;

    cout << "-----MÁQUINA DE VENDAS------" << endl;
    cout << endl;
    exibir(produtos, qtdProdutos, 1);
    cout << endl;
    cout << "Insira o código do produto: ";
    // Verifica se o código inserido é do tipo int e se está dentro do intervalo
    // de produtos
    if (!(cin >> inserido) || inserido <= 0 ||
        (inserido > qtdProdutos && inserido != chaveDeAcesso)) {
      system("clear");
      cout << "Código inválido!" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
    }
    // Verifica se o codigo inserido é a chavde de acesso
    else if (inserido == chaveDeAcesso) {
      system("clear");
      cout << "Entrando no modo administrador..." << endl;
      sleep(delay);
      system("clear");
      modoADM(produtos, &qtdProdutos, cofre, &chaveDeAcesso);
    }
    // Verifica se há produtos disponiveis em estoque (quantidade > 0)
    else if (!(produtos[inserido - 1].quantidade > 0)) {
      system("clear");
      cout << "Infelizmente " << produtos[inserido - 1].nome
           << " está em falta..." << endl;
      cout << "Por favor, selecione outro produto" << endl;
      sleep(delay);
      cin.clear();
      cin.ignore(tudo);
      system("clear");
    }
    // Entra no modo de compra
    else {
      int opcao;

      system("clear");
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
        system("clear");
        break;
      default:
        system("clear");
        cin.clear();
        cin.ignore(tudo);
        break;
      }
    }
  }

  return 0;
}
