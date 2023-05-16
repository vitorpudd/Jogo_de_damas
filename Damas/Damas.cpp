#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

class tabuleiro { //clase define peças e tabuleiro;
public:
	int i = 0, j = 0, m = 0, n = 0;
	char tabu[8][8];

	int grid(char tabu[8][8]) {

		tabu[0][0] = 'p', tabu[0][1] = 'b';
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {

				if (j > 0) {
					if (tabu[i][j - 1] == 'p')
						tabu[i][j] = 'b';
					else
						tabu[i][j] = 'p';
				}

				if (j == 0 && i > 0) 
					tabu[i][j] = tabu[i - 1][j + 7];
				

			}

		}
	

		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8 ; j++) {


				if (i <= 2 && tabu[i][j] == 'p')
					tabu[i][j] = 'x';
				if (i >= 5 && tabu[i][j] == 'p')
					tabu[i][j] = 'o';
			}
		}


		return tabu[8][8];
	}
	//define local
	int imprimetab(char tabu[8][8]) {
		system("cls");
		for (i = -1; i < 8; i++) {
			for (j = 0; j <10; j++){
				while (m < 8) {
					cout << fixed << setw(2) << m;
					m++;
					if (m == 8)
						cout << "\n";
				}

				if(i>=0 && j < 8)
					cout << fixed << setw(2) << tabu[i][j];
				if (j == 8 && i>=0)
					cout << "  ";
				if (j == 9 && i>=0) {
					cout << fixed << setw(2) << n;
					n++;
				}
			}
			cout << "\n";
		}
		cout << "\n";

		n = 0;
		m = 0;

		return 0;
	}
	//imprime o tabuleiro
};
class moveX {//Clase move peça 3
public:
	int i = 0, j = 0, n = 0, m = 0, lin = 0, col = 0;

	int defposx(char tabu[8][8]) {
		cout << "Digite a coord de uma peca x:" << endl;
		cin >> lin >> col;

		while (tabu[lin][col] != 'x' || (tabu[lin + 1][col - 1] == 'x' || tabu[lin + 1][col + 1] == 'x')) {
			cout << "Digite uma coord valida:" << endl;
			cin >> lin >> col;
		}


		return tabu[8][8];
	}
	//define a peça x a ser movimentada

	int movex(char tabu[8][8]) {

		i = lin;
		j = col;

		cout << "Digite a coord para mover a peca: " << i << ", " << j << endl;
		cin >> lin >> col;

		while (tabu[lin][col] != 'p' || lin > i + 1 || (col>j + 1 || col < j - 1)) {
			cout << "Digite a coord valida para mover a peca: " << i << ", " << j << endl;
			cin >> lin >> col;
		}
		
	
			tabu[lin][col] = 'x';
			tabu[i][j] = 'p';


		return tabu[8][8];
	}
	//movimenta a peça x selecionada

	int verto(char tabu[8][8]) {

		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (tabu[i][j] == 'o') {
					while (tabu[lin + 2][col - 2] == 'p' && tabu[lin + 1][col - 1] == 'o') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
					while (tabu[lin - 2][col + 2] == 'p' && tabu[lin - 1][col + 1] == 'o') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
					while (tabu[lin + 2][col + 2] == 'p' && tabu[lin + 1][col + 1] == 'o') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
					while (tabu[lin - 2][col - 2] == 'p' && tabu[lin - 1][col - 1] == 'o') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
				}
			}
		}


		return tabu[8][8];
	}
	//verifica possibilidade de tomada de peça o
};
class moveO { //Clase move peça 5
public:
	int i=0, j=0, n=0, m=0, lin=0, col=0;

	int defposo(char tabu[8][8]) {
	
		
		cout << "Digite a coord de uma peca o:" << endl;
		cin >> lin >> col;

		while (tabu[lin][col] != 'o' || (tabu[lin - 1][col - 1] == 'o' || tabu[lin - 1][col + 1] == 'o')) {
			cout << "Digite uma coord valida:" << endl;
			cin >> lin >> col;
		}


		return tabu[8][8];
	}
	//define a peça o a ser movimentada

	int moveo(char tabu[8][8]) {

		i = lin;
		j = col;

		cout << "Digite a coord para mover a peca: " << i << ", " << j << endl;
		cin >> lin >> col;
			
		while (tabu[lin][col] != 'p' || lin < i - 1 || col>j+1 || col<j-1){
			cout << "Digite a coord valida para mover a peca: " << i << ", " << j << endl;
			cin >> lin >> col;
		}


		tabu[lin][col] = 'o';
		tabu[i][j] = 'p';

		return tabu[8][8];
	}
	//movimenta a peça o selecionada

	int vertx(char tabu[8][8]) {

		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (tabu[i][j] == 'o') {
					while (tabu[lin + 2][col - 2] == 'p' && tabu[lin + 1][col - 1] == 'x') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
					while (tabu[lin - 2][col + 2] == 'p' && tabu[lin - 1][col + 1] == 'x') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
					while (tabu[lin + 2][col + 2] == 'p' && tabu[lin + 1][col + 1] == 'x') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
					while (tabu[lin - 2][col - 2] == 'p' && tabu[lin - 1][col - 1] == 'x') {
						cout << "Voce e obrigado a tomar uma peca inimiga! " << endl;
						cin >> lin >> col;
					}
				}
			}
		}


		return tabu[8][8];
	}//verifica possibilidade de tomada de peça x

};
class dama {
public:
	
	int damad(char tabu[8][8]) {

		return tabu[8][8];
	}

	int damas(char tabu[8][8]) {

		return tabu[8][8];
	}

};


int jogo() { //função para inicio de jogo
	system("cls");

	tabuleiro grid;
	moveO moveo;
	moveX movex;
	//define objetos

	char tabu[8][8] = {};
	grid.grid(tabu);
	int i = 0, j = 0, lin = 0, col = 0, rods=1;
	//variaveis

	grid.imprimetab(tabu);

	label:
	moveo.vertx(tabu);
	moveo.defposo(tabu);
	moveo.moveo(tabu);
	grid.imprimetab(tabu);
	
	grid.imprimetab(tabu);

	movex.verto(tabu);
	movex.defposx(tabu);
	movex.movex(tabu);
	grid.imprimetab(tabu);

	goto label;

	return 0;
}

void regras() {
	system("cls");

	string verifica;
	
	cout << "\n";
	cout << "As regras gerais sao:" << endl;
	cout << "   -As pecas movimentam somente para as diagonais e uma casa por vez;" << endl;
	cout << "   -As pecas sao obrigadas a capturar uma peca inimiga quando possível;" << endl;
	cout << "   -Quando uma peca chega a linha do extremo oposto do seu campo inicial, a mesma se tornara dama;" << endl;
	cout << "   -A dama pode se mover quantas casas quiser na diagonas, nao podendo passar por cima de uma dama do mesmo time;" << endl;
	cout << "   -O time de peça 5 sempre iniciará primeiro." << endl;
	cout << "\n";
	
	cout << "Para iniciar digite 'Iniciar' ou digite 'Sair' para fechar o jogo." << endl;
	cin >> verifica;
	cout << "\n";
	
	if (verifica == "Iniciar")
		jogo();
	if (verifica == "Sair")
		exit;
}

int main() {

	string op;
	//variaveis
	
	cout << "Bem-vindo!" << endl;
	cout << "\n";
	cout << "Para iniciar digite 'Iniciar' " << endl;
	cout << "Para saber as regras digite 'Regras'" << endl;
	cout << "Para sair digite 'Sair'" << endl;
	cin >> op;

	if (op == "Iniciar")//inicia o jogo
		jogo();
	if (op == "Regras")//chama a funcao regra
		regras();
	if (op == "Sair")//fecha o programa
		exit;
	return 0;
}