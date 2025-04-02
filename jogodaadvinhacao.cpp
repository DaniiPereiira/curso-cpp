#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

int main (){
    cout << "*************************************"<< endl; 
    cout << "* Bem-vindos ao jogo da advinhação! *"<< endl; 
    cout << "*************************************"<< endl;
    
    int numero_de_tentativas = 0;
   
    cout <<"Escolha o nível de dificuldade:"<< endl;
    while (numero_de_tentativas <= 0)
    {
        cout<<"(F) -> Fácil | (M) -> Médio | (D) -> Difícil"<< endl;
        
        char dificuldade;
        cin>> dificuldade;
    
        if(toupper(dificuldade) == 'F'){
            numero_de_tentativas = 15;
        }else if (toupper(dificuldade) == 'M'){
            numero_de_tentativas = 10;
        }else if(toupper(dificuldade) == 'D'){
            numero_de_tentativas = 5;
        }else{
            cout<<"Escolha uma opção correta."<< endl;
        }
    }
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
        
        cout << "Tentativa " << tentativas << endl;
        int chute;
    
        cout << "Qual o valor do seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;
    
        cout << "O valor do seu chute é: " << chute << endl;
        
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
    
        if(acertou){
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        } else if (maior){
            cout << "Seu chute foi maior que o número secreto" << endl;
        }else{
            cout << "Seu chute foi menor que o número secreto" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;

    if(nao_acertou){
        cout <<"Você perdeu! Tente novamente!"<< endl;
    }else{
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
}


