#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define TAM 4
#define DIG1 senha[0]
#define DIG2 senha[1]
#define DIG3 senha[2]
#define DIG4 senha[3]

int main() {
    
    srand(time(NULL));

    int option, senha[TAM], senha_usr[TAM], tent = 10, pos_err = 0, pos_cer = 0, cod_tent = 0;
    bool continuar = true;
    

    do
    {
        //solicita ao usuario a variavel option que definira em qual case do switch entraremos.
        cout<<"\033c";
        cout<< "+==============================+" <<endl;
        cout<< "|         MENU PRINCIPAL       |" <<endl;
        cout<< "+==============================+" <<endl;
        cout<< "|           (1) Jogar          |" <<endl;
        cout<< "|           (2) Sobre          |" <<endl;
        cout<< "|           (3) Sair           |" <<endl;
        cout<< "+==============================+" <<endl;
        cout<< "        Escolha uma opção: ";
        cin>>option;
        
        
        switch (option){ //Menu do jogo
             
            case 1: /*Jogar*/

                    /*Algoritimo para gerar os digitos aleatorios da senha e verificar se todos os digitos da senha sao diferentes*/
                do{
                    for (int i = 0; i<4 ; i++){
                        senha[i] = (rand() % 6) + 1;
                    }
                } while (DIG1 == DIG2 || DIG1 == DIG3 || DIG1 == DIG4 || DIG2 == DIG3 || DIG2 == DIG4 || DIG3 == DIG4);

                
                do{ //LOOP DA TENTATIVA

                    /*define a quantidade de numeros certos na posicao certa e numeros certos na posicao errada para 0. essas
                    variaveis serao usadas como contadores dentro desse loop a cada tentativa*/

                    cout<<"\033c";
                    
                    cout << "|          SENHA: " << DIG1 << DIG2 << DIG3 << DIG4 << "         |" << endl;
                    
                    cout << "+==============================+" << endl;
                    cout << "|   TENTATIVAS RESTANTES: ";
                    if (tent < 10) cout << " ";
                    cout << tent << "    |" << endl;
                    cout<< "+==============================+" <<endl;
                    cout<< "|          SENHA: ****         |" <<endl;
                    cout<< "|Corretos na posição errada: "<<pos_err<<" |" <<endl;
                    cout<< "|Corretos na posição certa:  " <<pos_cer<<" |" <<endl;
                    cout<< "+==============================+" <<endl;
                    cout<< "Digite um código (4 dígitos): ";
                    cin>>cod_tent;
                        
                    /* Separa o número de 4 dígitos digitado pelo jogador em dígitos individuais e joga dentro do vetor senha_dig.
                    A operação é feita do último para o primeiro dígito usando módulo e divisão:*/
        
                    senha_usr[3] = cod_tent % 10; // - `cod_tent % 10` obtém o último dígito
                    cod_tent /= 10; // - `cod_tent /= 10` remove o último dígito já extraído
                        senha_usr[2] = cod_tent % 10;
                        cod_tent /= 10;
                            senha_usr[1] = cod_tent % 10;
                            cod_tent /= 10;
                                senha_usr[0] = cod_tent % 10;
                                cod_tent /= 10;
                        
                        // Caso onde o jogador acertou todas os digitos
                    if (senha_usr[0] == DIG1 && senha_usr[1] == DIG2 && senha_usr[2] == DIG3 && senha_usr[3] == DIG4){ 
                        option = 4;
                    }else{

                        //Outros casos
                        pos_err = 0;
                        pos_cer = 0;
                        for (int i = 0; i<TAM; i++){
                            if (senha_usr[i] == senha[i]) {
                                pos_cer++;}
                            for (int f = 0; f<TAM; f++){
                                if(senha_usr[i] == senha[f] && i != f){
                                    pos_err++;
                                    }
                            }
                        }
                        tent--;
                    }
                      

            } while (option != 4 && tent > 0);

                break;

            case 2: /*Sobre*/
            
                cout<<"\033c";
                cout<< endl;
                cout<< "+==============================+" <<endl;
                cout<< "|            SOBRE             |" <<endl;
                cout<< "+==============================+" <<endl;
                cout<< "|       Desenvolvedores:       |" <<endl;
                cout<< "| - Matheus Alexandre Santos   |" <<endl;
                cout<< "| - Luiz Miguel Silvino        |" <<endl;
                cout<< "| - Luiz Borba                 |" <<endl;
                cout<< "| - Carlos Deuscher            |" <<endl;
                cout<< "|                              |" <<endl;
                cout<< "|   (4) Retornar ao Menu       |" <<endl;
                cout<< "+==============================+" <<endl;
                cout<< "    Escolha uma opção: ";
                cin>> option;
        
                break;
            
            case 3: /*Sair*/
                continuar = false;
                
            case 4:
                tent = 10;
                break;
        }
    
    } while (continuar);
}