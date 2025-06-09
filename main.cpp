#include <iomanip>
#include <iostream>
#include "cgame.h"

using namespace std;

int main(){
    cout << setw(50) << "Bem-vindo ao jogo 4 Em Linha!" << endl
         << setw(55) << "Criado por Joao Domingos & Joao Ferreira" << endl
         << setw(50) << "Projeto para a cadeira de EDA" << endl << endl;
    Cgame teste;
    teste.Menu();
    return 0;
}
