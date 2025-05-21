#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

#define DEV_MODE false

#define TAM 4
#define DIG1 senha[0]
#define DIG2 senha[1]
#define DIG3 senha[2]
#define DIG4 senha[3]

int main() {
	srand(time(NULL));

	int option, senha[TAM], senha_usr[TAM], tent = 10, pos_err = 0, pos_cer = 0,
	                                        cod_tent = 0;
	bool continuar = true;

	do {
		// solicita ao usuario a variavel option que definira em qual case do switch
		// entraremos.
		cout << "+==============================+" << endl;
		cout << "|         MENU PRINCIPAL       |" << endl;
		cout << "+==============================+" << endl;
		cout << "|           (1) Jogar          |" << endl;
		cout << "|           (2) Sobre          |" << endl;
		cout << "|           (3) Sair           |" << endl;
		cout << "+==============================+" << endl;
		cout << "        Escolha uma opção: ";
		cin >> option;

		cout << "\033c";

		switch (option) {  // Menu do jogo

		case 1: /*Jogar*/

			//   Reseta variáveis
			tent = 10;
			pos_err= 0;
			pos_cer= 0;

			/*Algoritimo para gerar os digitos aleatorios da senha e verificar se
			 * todos os digitos da senha sao diferentes*/
			do {
				for (int i = 0; i < 4; i++) {
					senha[i] = (rand() % 6) + 1;
				}
			} while (DIG1 == DIG2 || DIG1 == DIG3 || DIG1 == DIG4 || DIG2 == DIG3 ||
			         DIG2 == DIG4 || DIG3 == DIG4);

			do {  // LOOP DA TENTATIVA

				/*define a quantidade de números certos na posição certa e números
				certos na posição errada para 0. essas variáveis serão usadas como
				contadores dentro desse loop a cada tentativa*/

				if(DEV_MODE) {
					cout << endl
					     << "|          SENHA: " << DIG1 << DIG2 << DIG3 << DIG4
					     << "         |" << endl;
				}

				cout << "+==============================+" << endl;
				cout << "|   TENTATIVAS RESTANTES: ";
				if (tent < 10) cout << " ";
				cout << tent << "   |" << endl;
				cout << "+==============================+" << endl;
				cout << "|          SENHA: ****         |" << endl;
				cout << "|Corretos na posição errada: " << pos_err << " |" << endl;
				cout << "|Corretos na posição certa:  " << pos_cer << " |" << endl;
				cout << "+==============================+" << endl;
				cout << "Digite um código (4 dígitos): ";
				cin >> cod_tent;
				
				/* Separa o número de 4 dígitos digitado pelo jogador em dígitos
				individuais e joga dentro do vetor senha_dig. A operação é feita do
				último para o primeiro dígito usando módulo e divisão:*/

				senha_usr[3] =
				    cod_tent % 10;  // - `cod_tent % 10` obtém o último dígito
				cod_tent /=
				    10;  // - `cod_tent /= 10` remove o último dígito já extraído
				senha_usr[2] = cod_tent % 10;
				cod_tent /= 10;
				senha_usr[1] = cod_tent % 10;
				cod_tent /= 10;
				senha_usr[0] = cod_tent % 10;
				cod_tent /= 10;

				if (senha_usr[0] == senha_usr[1] || senha_usr[0] == senha_usr[2] ||
				        senha_usr[0] == senha_usr[3] || senha_usr[1] == senha_usr[2] ||
				        senha_usr[1] == senha_usr[3] || senha_usr[2] == senha_usr[3]) {
					cout << "\033c";
					cout << endl << "Você digitou uma senha inválida! ";
					cout << endl << "- Os números precisam ser diferentes entre si." << endl;

				} else if (senha_usr[0] < 1 || senha_usr[0] > 6 || senha_usr[1] < 1 ||
				           senha_usr[1] > 6 || senha_usr[2] < 1 || senha_usr[2] > 6 ||
				           senha_usr[3] < 1 || senha_usr[3] > 6) {
					cout << "\033c";
					cout << endl
					     << "Você digitou uma senha inválida! Verifique as seguintes regras: ";
					cout << endl << "- Os números precisam estar entre 1 e 6." << endl;

				} else

					// Caso onde o jogador acertou todas os digitos
					if (senha_usr[0] == DIG1 && senha_usr[1] == DIG2 &&
					        senha_usr[2] == DIG3 && senha_usr[3] == DIG4) {

						cout << "\033c";
						cout << endl << "Parabéns! Você acertou todos os números!" << endl;
						cout << endl << "Você venceu!" << endl;
						cout << endl << "1 - Retornar ao Menu Principal" << endl;
						cin >> option;
						cout << "\033c";
						option = 4;
					} else {
						// Outros casos
						pos_err = 0;
						pos_cer = 0;

						// Itera sob cada elemento da senha
						for (int i = 0; i < TAM; i++) {
							// Checa se o caracter está correto (Mesma posição)
							if (senha_usr[i] == senha[i]) {
								pos_cer++;
							}

							// Checa se o caracter está correto (Posição errada)
							for (int f = 0; f < TAM; f++) {
								if (senha_usr[i] == senha[f] && i != f) {
									pos_err++;
								}
							}
						}

						if (tent == 1) {
							cout << "\033c";
							cout << endl
							     << "Que pena, suas tentativas acabaram! Você perdeu! "
							     << endl
							     << endl;
							cout << "1 - Retornar ao Menu Principal" << endl;
							cin >> option;
						}

						tent--;
						cout << "\033c";
					}
			} while (option != 4 && tent > 0);
			break;

		case 2: /*Sobre*/

			cout << "\033c";
			cout << endl;
			cout << "+==============================+" << endl;
			cout << "|            SOBRE             |" << endl;
			cout << "+==============================+" << endl;
			cout << "|       Desenvolvedores:       |" << endl;
			cout << "| - Matheus Alexandre Santos   |" << endl;
			cout << "| - Luiz Miguel Silvino        |" << endl;
			cout << "| - Luiz Borba                 |" << endl;
			cout << "| - Carlos Henrique Deucher    |" << endl;
			cout << "|                              |" << endl;
			cout << "|   (4) Retornar ao Menu       |" << endl;
			cout << "+==============================+" << endl;
			cout << "    Escolha uma opção: ";
			cin >> option;

			cout << "\033c";

			break;
		case 3: /*Sair*/
			continuar = false;
			break;
		case 4:
			tent = 10;
			break;
		}

	} while (continuar);
}
