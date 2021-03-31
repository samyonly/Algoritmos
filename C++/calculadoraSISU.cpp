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
#include <stdio.h>
using namespace std;

int main(int argc, char **argv) {
    
    //Declaração de variáveis
    int menu;
    float pesos[5], nota[5], somaPesos = 0.0;
    string provas[5] = {"Redacao", "Matematica", "Linguagens", "Humanas", "Natureza"};
    
    //Prototipação de funções e procedimentos
    float leiaVetor(float valor[5], string provas[5], string cabecalho, string nomeValor);
    float mediaPonderada(float nota[5], float peso[5], float somaPesos);
    
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
                leiaVetor(nota, provas, "Cadastrar Notas", "nota");
                break;
            case 2:
                // 2. Cadastrar pesos
                somaPesos = leiaVetor(pesos, provas, "Cadastrar Pesos", "peso");
                break;
            case 3:
                // 3. Ver média
                cout << "Sua media ponderada eh igual a " << mediaPonderada(nota, pesos, somaPesos) << endl << endl;
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
float leiaVetor(float valor[5], string provas[5], string cabecalho, string nomeValor){
    
    float soma;
    
    system("cls");
    //system("clear");
    
    cout << cabecalho << endl << endl;
    
    for(int i = 0; i < 5; i++){
            cout << "Digite o " << nomeValor << " de " << provas[i] << ": ";
            cin >> valor[i];
            setbuf(stdin, NULL);
            soma += valor[i];
        }
    return soma;
}

//Função para calcular a média ponderada
float mediaPonderada(float nota[5], float peso[5], float somaPesos){
    
    float media;
    
    for(int i = 0; i < 5; i++){
        media += nota[i] * peso[i];
    }
    
    return media/somaPesos;
}
