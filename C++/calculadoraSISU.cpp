/*  Projeto: Calculadora SISU
 *  Atividade: Cálculo de média aritmética ponderada
 *  Desenvolvedor(a): Samahra Stefanny
 * 
 * Como funciona:
 *      O calculo da média ponderada é feito multiplicando as notas
 *      por seus respectivos pesos, somando-as e dividindo pela soma
 *      de todos os dos pesos.
 *      Ex.: priemeira nota tem peso 2 e segunda nota tem peso 3
 *          primeira nota = 10
 *          segunda nota = 6
 *          (10 * 2) + (6 * 3) = 38
 *          2 + 3 = 5
 *          38 / 5 = 7.6
 *      Então a média aritmética ponderada será 7.6
 * 
 * Observações:
 *      Caso esteja utilizando um sistema Linux, por favor
 *      retire as barras de comentário do comando 'system("clear")'
 *      e coloque-as no comando 'system("cls")'.
 */

#include <iostream>
#include <string>
using namespace std;

//Estrutura com os atributos de uma prova
struct Prova{
    string nome;
    float nota;
    float peso;
};

int main(int argc, char **argv) {
          
    //Prototipação de funções e procedimentos
    float leiaVetor(Prova nome[5], string cabecalho, string valor);
    float mediaPonderada(Prova nome[5], float somaPesos);
    
    //Declaração de variáveis
    int menu;
    float somaPesos = 0.0;
    Prova enem[5];
    
    //Atribuição dos nomes das provas
    enem[0].nome = "Redacao";
    enem[1].nome = "Matematica";
    enem[2].nome = "Linguagens";
    enem[3].nome = "Humanas";
    enem[4].nome = "Natureza";
    
    do{
        system("cls");
        //system("clear");
        
        // Menu
        cout << "Calculadora SISU" << endl << endl;
    
        cout << "Menu de opcoes:" << endl;
        cout << "1. Cadastrar notas" << endl;
        cout << "2. Cadastrar pesos" << endl;
        cout << "3. Ver media" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite a opcao desejada: ";
        
        cin >> menu;
        setbuf(stdin, NULL);
        
        cout << endl;
        
        switch(menu){
            case 1:
                // 1. Cadastrar notas
                leiaVetor(enem, "Cadastrar Notas", "nota");
                break;
            case 2:
                // 2. Cadastrar pesos
                somaPesos = leiaVetor(enem, "Cadastrar Pesos", "peso");
                break;
            case 3:
                // 3. Ver média
                cout << "Sua media ponderada equivale a " << mediaPonderada(enem, somaPesos) << endl << endl;
                getchar();
                break;
            case 0:
                // 4. Sair
                cout << "Pressione qualquer tecla para sair...";
                break;
            default:
                // Opção inválida
                cout << "Opcao invalida. Tente novamente." << endl;
                getchar();
                break;
        }
        
    }while(menu != 0);
    
    getchar();
    return 0;
}

//Função para preencher um vetor de 5 espaços e retorna seus valores somados
float leiaVetor(Prova nome[5], string cabecalho, string valor){
    
    float soma;
    
    system("cls");
    //system("clear");
    
    cout << cabecalho << endl << endl;
    
    for(int i = 0; i < 5; i++){
            cout << "Digite o " << valor << " de " << nome[i].nome << ": ";
            if(valor == "nota"){
                cin >> nome[i].nota;
                setbuf(stdin, NULL);
                soma = 0;
            }
            else if(valor == "peso"){
                cin >> nome[i].peso;
                setbuf(stdin, NULL);
                soma += nome[i].peso;
            }
        }
    return soma;
}

//Função para calcular a média ponderada
float mediaPonderada(Prova nome[5], float somaPesos){
    
    float media;
    
    for(int i = 0; i < 5; i++){
        media += nome[i].nota * nome[i].peso;
    }
    
    return media/somaPesos;
}
