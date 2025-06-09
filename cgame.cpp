#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "cgame.h"

const int GANHA=4;
const int LINHAS=6;
const int COLUNAS=7;

using namespace std;

//O que cada função faz é comentado no file Header

void Clear(){//função retirada do stackoverflow para dar clear ao ecrã, link: https://stackoverflow.com/questions/6486289/how-can-i-clear-console
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Cgame::LimpaTabela(){
    for(int i=0; i<6; i++){ // linhas
        for(int j=0; j<7; j++){ //colunas
            matrix[i][j]= ' ';
        }
    }
}

void Cgame::Desenha(void){
    cout << endl << "| 1 || 2 || 3 || 4 || 5 || 6 || 7 |"<<endl;
    for(int i=0; i<6; i++){ // linhas
        for(int j=0; j<7; j++){ //colunas
            cout << "| " << matrix[i][j] << " |";
        }
        cout << endl;
    }
}

int Cgame::DecideJogador(){
    switch (versus) {
    case '1'://pvp
        do{
            Clear();
            cout << "Quem faz a primeira jogada? " << endl;
            cout << "1-Jogador 1" << endl;
            cout << "2-Jogador 2" << endl;
            cout << "3-Aleatorio" << endl;
            cout << "->";
            cin >> primeiro;
            //primeiro -= '0';
        }while(primeiro!=1 && primeiro!=2 && primeiro!=3);
        if(primeiro==1){
            player='X';
            cout << "O " << nome_player << " joga primeiro" << endl;
            return primeiro;
        }
        else if(primeiro==2){
            player='O';
            cout << "O " << nome_player_versus << " joga primeiro" << endl;
            return primeiro;
        }
        else{
            int i=rand()%10+1;
            if(i%2==0){
                primeiro=1;
                player='X';
                cout << "O " << nome_player << " joga primeiro" << endl;
                return primeiro;
            }
            else {
                primeiro=2;
                player='O';
                cout << "O " << nome_player_versus << " joga primeiro" << endl;
                return primeiro;
            }
        }
        break;
    case '2'://pve
        do{
            Clear();
            cout << "Quem faz a primeira jogada? " << endl;
            cout << "1-Jogador" << endl;
            cout << "2-Computador" << endl;
            cout << "3-Aleatorio" << endl;
            cout << "->";
            cin >> primeiro;
            //primeiro -= '0';
        }while(primeiro!=1 && primeiro!=2 && primeiro!=3);
        if(primeiro==1){
            player='X';
            cout << "O " << nome_player << " joga primeiro" << endl;
            return primeiro;
        }
        else if(primeiro==2){
            player='O';
            cout << "O computador joga primeiro" << endl;
            return primeiro;
        }
        else{
            int i=rand()%10+1;
            if(i%2==0){
                primeiro=1;
                player='X';
                cout << "O " << nome_player << " joga primeiro" << endl;
                return primeiro;
            }
            else {
                primeiro=2;
                player='O';
                cout << "O Computador joga primeiro" << endl;
                return primeiro;
            }
        }
        break;
    case '3': //eve
        do{
            Clear();
            cout << "Quem faz a primeira jogada? " << endl;
            cout << "1-Computador 1" << endl;
            cout << "2-Computador 2" << endl;
            cout << "3-Aleatorio" << endl;
            cout << "->";
            cin >> primeiro;
            //primeiro -= '0';
        }while(primeiro!=1 && primeiro!=2 && primeiro!=3);
        if(primeiro==1){
            player='X';
            cout << "O Computador 1 joga primeiro" << endl;
            return primeiro;
        }
        else if(primeiro==2){
            player='O';
            cout << "O Computador 2 joga primeiro" << endl;
            return primeiro;
        }
        else{
            int i=rand()%10+1;
            if(i%2==0){
                primeiro=1;
                player='X';
                cout << "O Computador 1 joga primeiro" << endl;
                return primeiro;
            }
            else {
                primeiro=2;
                player='O';
                cout << "O Computador 2 joga primeiro" << endl;
                return primeiro;
            }
        }
        break;
    default:
        cout << "ERRO!(DecideJogador)" << endl;
        break;
    }
}

int Cgame::DefVersus(){
    do{
        Clear();
        cout << "Selecione o modo de jogo:" << endl;
        cout << "(1) - Jogador VS Jogador" << endl;
        cout << "(2) - Jogador VS Computador" << endl;
        cout << "(3) - Computador VS Computador" << endl;
        cout << "->";
        cin >> versus;
        //cout funciona
        versus-='0'; //não está a funcionar n sei o porque
    }while( versus!='1' && versus!='2' && versus!='3' );
    return versus;
}

int Cgame::DefNivel(){
    switch (versus) {
    case '1':
        Clear();
        cout << "Player 1: Digite o seu nome(maximo 10 caracteres): ";
        cin.width(50);
        cin >> nome_player;
        cin.ignore(100,'\n');
        cout << "Player 2: Digite o seu nome(maximo 10 caracteres): ";
        cin.width(50);
        cin >> nome_player_versus;
        cin.ignore(100,'\n');
        nivel=1;
        return nivel;
        break;
    case '2':
        cout << "Digite o seu nome(maximo 10 caracteres): ";
        cin.width(50);
        cin >> nome_player;
        cin.ignore(100,'\n');
        do{
            Clear();
            cout << "Selecione o nivel do Computador:" << endl;
            cout << "1-Elementar" << endl;
            cout << "2-Basico" << endl;
            cout << "3-Medio" << endl;
            cout << "4-Avancado(inc)" << endl;
            cout << "->";
            cin >> nivelPC;
        }while(nivelPC!=1 && nivelPC!=2 && nivelPC!=3 && nivelPC!=4);
        return nivelPC;
        break;
    case '3':
        do{
            Clear();
            cout << "Selecione o nivel do Computador:" << endl;
            cout << "1-Elementar" << endl;
            cout << "2-Basico" << endl;
            cout << "3-Medio" << endl;
            cout << "4-Avancado(inc)" << endl;
            cout << "->";
            cin >> nivelPC;
        }while(nivelPC!=1 && nivelPC!=2 && nivelPC!=3 && nivelPC!=4);
        return nivelPC;
        break;
    default:
        Clear();
        cout << "ERRO!! (DEFnIVEL)" << endl;
        break;
    }

}

int Cgame::ReturnNivelPC(int a){
    switch (a) {
    case 1:
        return (Elementar());
    case 2:
        return (Basico());
    case 3:
        return (Medio());
    /*case 4:
        return (Avancado());*/
    default:
        return -1;
    }
}

void Cgame::coutNivel(int aux){
    if(versus=='1'){ //pvp
        switch (aux) {
        case 1:
            cout << endl << "Modo de Jogo: PvP" << endl;
            break;
        default:
            cout << "ERRO!  coutNivel" << endl;
        }
    }
    else if(versus=='2'){ // pve
        switch (aux) {
        case 1:
            cout << endl << "Modo de Jogo: Elementar" << endl;
            break;
        case 2:
            cout << endl << "Modo de Jogo: Basico" << endl;
            break;
        case 3:
            cout << endl << "Modo de Jogo: Medio" << endl;
            break;
        /*case 4:
            cout << endl << "Modo de Jogo: Avancado" << endl;*/
        default:
            cout << endl << "ERRO!   coutNivel" << endl;
            break;
        }
    }
    else if(versus=='3'){ //eve
        switch (aux) {
        case 1:
            cout << endl << "Modo de Jogo: Elementar" << endl;
            break;
        case 2:
            cout << endl << "Modo de Jogo: Basico" << endl;
            break;
        case 3:
            cout << endl << "Modo de Jogo: Medio" << endl;
            break;
        /*case 4:
            cout << endl << "Modo de Jogo: Avancado" << endl;*/
        default:
            cout << endl << "ERRO!  coutNivel" << endl;
            break;
        }
    }
    else cout << "ERRO!   coutNivel" << endl;
}

void Cgame::ResetJogo(){
    char aux;
    if(checkWin() || nJogadas==42){
        do{
            cout << endl << "Quer jogar de novo? (S/N)" << endl;
            cin >> aux;
        }while(aux!='S' && aux!= 's' && aux!='N' && aux!= 'n');
        if(aux=='S' || aux=='s' ){
            nJogadas=0;
            player='X';
            LimpaTabela();
            if( versus=='2' || versus=='3' ){
                nivelPC=DefNivel();
                coutNivel(nivelPC);
            }
            else if( versus == '1' ){
                nivel=DefNivel();
                coutNivel(nivel);
            }
            primeiro=DecideJogador();
            Jogar();
            ResetJogo();//12-05-21
           //12-05-21
        }
        else{
            Clear();
            LimpaTabela();
            return; //fecha o ciclo e vai para o return 0 do main
        }
    }
}

void Cgame::Menu(void){
    Cgame player;
    char i; // tentar se possivel transformar em char
    do{
        cout << "(1)-Jogar" << endl;
        cout << "(2)-HighScore" << endl;
        cout << "(3)-Sair" << endl;
        cout << "->";
        cin >> i;
    }while( i < '1' || i > '3' );
    switch (i) {
    case '1': {
        Clear();
        bool continua=continuaJogo();
        if(continua==false){
            /*cout << "Digite o seu nome(maximo 10 caracteres): ";
            cin.width(50);
            cin >> player.nome_player;
            cin.ignore(100,'\n');*/
            //TENTAR USAR O getline
            DefVersus();
            if( versus == '2' || versus == '3' ){
                nivelPC=DefNivel();
                coutNivel(nivelPC);
            }
            if( versus == '1' ) {
                nivel=DefNivel();
                coutNivel(nivel);
            }
            player.DecideJogador();
            player.Jogar();
            if( versus=='1' || versus=='2' ) guardaJogador(nome_win);
            player.ResetJogo();
            Menu();//12-05-21
            break;
        }
        else if(continua==true){
            Jogar();
            if( versus=='1' || versus=='2' ) guardaJogador(nome_win);
            ResetJogo();
            Menu();//12-05-21
            break;
        }
        else
            break;
    }
    case '2': {
        //mostrar o highscore
        Clear();
        mostraTop10(); cout << endl;
        Menu();//12-05-21
        break;
    }
    case '3': {
       Clear();//12-05-21
        break;
    }
    default: {
       //12-05-21
        cout << "ERRO!" << endl;
        break;
    }
    }
}

bool Cgame::VerificaJogada(int coluna){//Verfica se escolheu o intervalo das colunas ou se a coluna não está preenchida
    if( coluna < 1 || coluna > 7 ){
        cout << "ERRO! Escolha um numero entre 1 a 7 " << endl;
        return false;
    }
    if(matrix[0][coluna-1]!= ' ' ){
        cout << "Coluna preenchida!!" << endl;
        return false;
    }
    else return true;
}

int Cgame::Joga_check(int coluna){ //Joga na coluna e verifica se o jogador ganhou ou não
    for(int i=6; i>=0; i--){
        if(matrix[i][coluna-1]==' '){
            matrix[i][coluna-1] = player;
            if( checkWin() ){
                return 0;
            }
            return 1;
        }
    }
}

int Cgame::checkJogada(int coluna){ //Simula jogada na coluna e verifica se o jogador ganhou ou não
    for(int i=6; i>=0; i--){
        if(matrix[i][coluna-1]==' '){
            matrix[i][coluna-1] = player;
            if( checkWin() ){
               matrix[i][coluna-1] = ' ';//DDD
                return 0;
            }
            matrix[i][coluna-1] = ' ';//DDD
            return 1;
        }
    }
}

int Cgame::ConfirmarJogada(int coluna){
    char aux;
    do{
        cout << "Deseja mudar a sua jogada? (S/N)" << endl;
        cin >> aux;
    }while(aux!='S' && aux!= 's' && aux!='N' && aux!= 'n');
    if(aux=='S' || aux=='s' ){
        return 10; //valor fora do ciclo q implica repetir a jogada
    }
    else
        return coluna; //fecha o ciclo e continua o jogo
}

int Cgame::JogadaVersus1(){
    char auxColuna;
    switch (player) {
    case 'X':
        do{
            cout << "Jogada do " << nome_player << endl;
            cout << "Selecione um digito entre 1 e 7: " << endl;
            cin >> auxColuna;
            auxColuna-='0';
            if(VerificaJogada(auxColuna)==true)
                auxColuna=ConfirmarJogada(auxColuna);
        }while ( auxColuna < 1 || auxColuna > 7 || matrix[0][auxColuna-1]!= ' ' );
        Joga_check(auxColuna);
        break;
    case 'O':
        do{
            cout << "Jogada do " << nome_player_versus << endl;
            cout << "Selecione um digito entre 1 e 7: " << endl;
            cin >> auxColuna;
            auxColuna-='0';
            if(VerificaJogada(auxColuna)==true)
                auxColuna=ConfirmarJogada(auxColuna);
        }while ( auxColuna < 1 || auxColuna > 7 || matrix[0][auxColuna-1]!= ' ' );
        Joga_check(auxColuna);
        break;
    default:
        cout << "Erro! (JogadaVersus2)" << endl;
        break;
    }
}

int Cgame::JogadaVersus2(){
    char auxColuna;
    int auxColunaPC;
    switch (player) {
    case 'X':
        do{
            cout << "Jogada do " << nome_player << endl;
            cout << "Selecione um digito entre 1 e 7: " << endl;
            cin >> auxColuna;
            auxColuna-='0';
            if(VerificaJogada(auxColuna)==true)
                auxColuna=ConfirmarJogada(auxColuna);
        }while ( auxColuna < 1 || auxColuna > 7 || matrix[0][auxColuna-1]!= ' ' );
        Joga_check(auxColuna);
        break;
    case 'O':
        do{
            cout << "Jogada do Computador" << endl;
            auxColunaPC = ReturnNivelPC(nivelPC);
        }while ( auxColunaPC < 1 || auxColunaPC > 7 || matrix[0][auxColunaPC-1]!= ' ' );
        Joga_check(auxColunaPC);
        break;
    default:
        cout << "Erro! (JogadaVersus2)" << endl;
        break;
    }
}

int Cgame::JogadaVersus3(){
    int auxColunaPC;
    switch (player) {
    case 'X':
        do{
            cout << "Jogada do Computador 1" << endl;
            auxColunaPC = ReturnNivelPC(nivelPC);
        }while ( auxColunaPC < 1 || auxColunaPC > 7 || matrix[0][auxColunaPC-1]!= ' ' );
        Joga_check(auxColunaPC);
        break;
    case 'O':
        do{
            cout << "Jogada do Computador 2" << endl;
            auxColunaPC = ReturnNivelPC(nivelPC);
        }while ( auxColunaPC < 1 || auxColunaPC > 7 || matrix[0][auxColunaPC-1]!= ' ' );
        Joga_check(auxColunaPC);
        break;
    default:
        cout << "Erro! (JogadaVersus3)" << endl;
        break;
    }
}

int Cgame::Jogada(){ //faz a jogada ,ou seja, seleciona a coluna onde vai jogar
    int aux;
    if( versus == '1' ) aux=JogadaVersus1();
    if( versus == '2' ) aux=JogadaVersus2();
    if ( versus == '3') aux=JogadaVersus3();
    if ( versus != '1' && versus != '2' && versus != '3') cout << "ERRO! (Jogada)" << endl;

    return aux;
}

void Cgame::MudaJogador(){
    if(player=='X')
        player='O';
    else
        player='X';
}

bool Cgame::JogarVersus1(int continua){
    if(continua==1){
        nJogadas++;//increment
        if(nJogadas==42){
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "Empate!" << endl;
            return false;
        }
    }
    else if(continua==0 && nJogadas<=42){
        if(player=='X'){
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "O/A " << nome_player << " ganhou!" << endl;
            //nome_win=nome_player;
            equalArray(nome_player,nome_win, 10);
            return false;
        }
        else{
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "O/A " << nome_player_versus << " ganhou!" << endl;
            equalArray(nome_player_versus, nome_win, 10);
            return false;
        }
    }
    else
        cout << "ERRO!! Jogar Versus1" << endl;

    coutNivel(nivel);
    cout << "Jogada numero: " << nJogadas << endl << endl;
}

bool Cgame::JogarVersus2(int continua){
    if(continua==1){
        nJogadas++;//increment
        if(nJogadas==42){
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "Empate!" << endl;
            return false;
        }
    }
    else if(continua==0 && nJogadas<=42){
        if(player=='X'){
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "O/A " << nome_player << " ganhou!" << endl;
            //nome_win=nome_player;
            equalArray(nome_player,nome_win, 10);
            return false;
        }
        else{
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "O computador ganhou!" << endl;
            return false;
        }
    }
    else
        cout << "ERRO!! Jogar Versus2" << endl;

    coutNivel(nivelPC);
    cout << "Jogada numero: " << nJogadas << endl << endl;
}

bool Cgame::JogarVersus3(int continua){
    if(continua==1){
        nJogadas++;//increment
        if(nJogadas==42){
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "Empate!" << endl;
            return false;
        }
    }
    else if(continua==0 && nJogadas<=42){
        if(player=='X'){
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "O Computador 1 ganhou!" << endl;
            return false;
        }
        else{
            //cout << "Jogada numero: "<< nJogadas << endl << endl;
            cout << "O Computador 2 ganhou!" << endl;
            return false;
        }
    }
    else
        cout << "ERRO!! Jogar Versus3" << endl;

    coutNivel(nivelPC);
    cout << "Jogada numero: " << nJogadas << endl << endl;
}

bool Cgame::Jogar(void){ // fazer os metodos de verificação na jogada
    Desenha();
    int continua=1;// este continua é o da função jogada se for 0 então alguém ganhou se é 1 o jogo continua
    while(nJogadas<42 && continua==1){
        continua=Jogada();
        Desenha();

        if( versus=='1' ) JogarVersus1(continua);
        if( versus=='2' ) JogarVersus2(continua);
        if( versus=='3' ) JogarVersus3(continua);
        if ( versus != '1' && versus != '2' && versus != '3') cout << "ERRO! (Jogar)" << endl;

        //cout << "Jogada numero: "<< nJogadas << endl << endl;
        guardaJogo();
        MudaJogador();
    }
}

bool Cgame::checkWin(){
    // Loop em todas as posições
      for (int c = 0; c < COLUNAS; c++){
          for (int l = 0; l < LINHAS; l++){
              if (matrix[l][c] == player){
                 // Verifica linha
                 int count = 0;
                 for (int i = 0; i < GANHA; i++)
                    if ((l+i < 6) && (matrix[l+i][c] == player))
                        count++;
                 if (count == GANHA)
                     return true;

                 // Verifica coluna
                 count = 0;
                 for (int i = 0; i < GANHA; i++)
                    if ((c+i < COLUNAS) && (matrix[l][c+i] == player))
                        count++;
                 if (count == GANHA)
                     return true;

                 // Verifica primeira diagonal
                 count = 0;
                 for (int i = 0; i < GANHA; i++)
                    if ((l+i < LINHAS) && (c+i < COLUNAS) && (matrix[l+i][c+i] == player))
                        count++;
                 if (count == GANHA)
                     return true;
                 // Verfica segunda diagonal
                 count = 0;
                 for (int i = 0; i < GANHA; i++)
                    if ((l-i >= 0) && (c+i < COLUNAS) && (matrix[l-i][c+i] == player))
                        count++;
                 if (count == GANHA)
                     return true;
              }
          }
      }
      return false;
}

int Cgame::Elementar(){
    return rand()%7+1;
}

int Cgame::Basico(void) { //return a jogada do nivel basico para o computador
    int aux;
    for(int i = 1; i <= 7; i++) {
        if(VerificaJogada(i)) {
            do{
                aux=i;
            }while ( aux < 1 || aux > 7 || matrix[0][aux-1]!= ' ' );
            if(checkJogada(aux)==0) {
                return aux;
            }
        }
    }
    return Elementar();
}

int Cgame::Medio(void){ //return a jogada do nivel médio para o computador
    int aux;
    for(int i = 1; i <= 7; i++) {
        if(VerificaJogada(i)) {
            player='X';
            do{
                aux=i;
            }while ( aux < 1 || aux > 7 || matrix[0][aux-1]!= ' ' );
            if(checkJogada(aux)==0) {
                player= 'O';
                return aux;
            }
            player='O';
        }
    }
    return Basico();
}

void Cgame::mostraTop10(){
    ifstream inputFile("highscore.txt");
    int numMinTop10=0;
    struct dados jogadorTop10;
    char contarLinhas;

    if(!inputFile.is_open()){
        cout<<"Erro a abrir o ficheiro";
    }

    while(inputFile && numMinTop10<11){
        inputFile.get(contarLinhas);
        if(contarLinhas=='\n') numMinTop10++;
    }
    numMinTop10--;
    if(numMinTop10==-1){
        cout<<"Nao existem jogadores no ficheiro"<<endl;
        return;
    }
    inputFile.close();
    //Escrever no ecrã o top 10 ou os nomes que estiverem guardados(<=10)
    ifstream inputFile1("highscore.txt");
    //cout <<"numMinTop10 -"<<numMinTop10<<endl;
    cout<<setw(40)<<setfill('=')<<"="<<endl;
    cout<<"#  Nome      Vitorias"<<endl;
    for(int i=0; i<numMinTop10 /*&& inputFile*/ ;i++){
        inputFile1>> jogadorTop10.nome >> jogadorTop10.vitorias;
        cout<<i+1<<"- "<<setfill(' ')<<left<<setw(10)<<jogadorTop10.nome <<jogadorTop10.vitorias <<endl;
    }
    inputFile.close();
}

void Cgame::guardaJogador(char * playername){
    ifstream file1("highscore.txt",ios::in);
    int numJogadores=0;
    int aux=0;
    bool existirjogador=false;
    char contarLinhas;

    if(!file1.is_open()){
        cout<<"Erro a abrir o ficheiro";
    }
    //Contar o numero de linhas no ficheiro
    if(file1.is_open()){
        while(file1){
            file1.get(contarLinhas);
            if(contarLinhas=='\n')
                numJogadores++;
        }
    }
    file1.close();
    if(numJogadores>0){
        ifstream inputFile("highscore.txt",ios::in);
        struct dados jogadores[numJogadores];
        numJogadores--;
        while(inputFile && aux<numJogadores){
            inputFile >> jogadores[aux].nome >> jogadores[aux].vitorias;
            if(strcmp(jogadores[aux].nome,playername)==0){
                jogadores[aux].vitorias++;
                existirjogador = true;
            }
            aux++;
        }
        qsort(jogadores,numJogadores,sizeof (struct dados),compara);
        inputFile.close();
        ofstream outputFile("highscore.txt");
        if(!outputFile.is_open()){
            cout<<"Erro a abrir o ficheiro"<<endl;
        }
        for(int i= 0;i<numJogadores ;i++){
            outputFile <<left<< setw(10) << jogadores[i].nome <<" "<<jogadores[i].vitorias<<endl;
        }
        //cout << existirjogador;
        if(existirjogador == false) outputFile<<left<< setw(10) << playername <<" 1"<<endl;
        file1.close();
    }
    else{
        ofstream file1("highscore.txt");
        file1 << setw(10) << playername << " 1"<<endl;
        file1.close();
    }
    return;
}

int Cgame::compara(const void *a, const void *b) {
    const struct dados *aCompara = (const struct dados *) a;
    const struct dados *bCompara = (const struct dados *) b;
    return (bCompara->vitorias-aCompara->vitorias);
}

void Cgame::equalArray(char tab[], char arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]=tab[i];
    }
}

void Cgame::guardaJogo(){
    ofstream file("jogo.txt");
    if (!file.is_open()) {
        cout << "Error opening file"
        << endl;
        return ;
    }
    file << versus << endl;
    file << nome_player << endl;
    if(versus=='1'){
        file << nome_player_versus << endl;
    }
    if( versus=='2' || versus=='3' ) file << nivelPC << endl;
    file << nJogadas << endl;
    for(int i=0; i<LINHAS; i++){ // linhas
        for(int j=0; j<COLUNAS; j++){ //colunas
            if(matrix[i][j]=='X'){
                file << "1" << i << j << endl;
            }
            if(matrix[i][j]=='O'){
                file << "2" << i << j << endl;
            }
        }
    }
    file.close();
}

bool Cgame::continuaJogo(){
    int jogador, linha, coluna, aux, numX=0, numO=0;
    bool existeJogo=false;
    ifstream file("jogo.txt");
    if (!file.is_open()) {
        return false;
    }
    file >> versus;
    file >> nome_player;
    if(versus =='1') file >> nome_player_versus;
    if( versus=='2' || versus=='3' ) file >> nivelPC;
    file >> nJogadas;
    while(!file.eof()){
        file>> aux;
        jogador=(int)aux/100;
        linha= (aux%100 - aux%10)/10;
        coluna= aux%10;
        if(jogador==1){
            player = 'X';
            numX++;
        }
        else {
            player = 'O';
            numO++;
        }
        file.get();
        matrix[linha][coluna]=player;
    }
    existeJogo=true;
    file.close();

    //Proxima JOGADOR
    if(numX>numO) player = 'O';
    else player = 'X';

    if( existeJogo==true ) {
        char c;
        do{
            cout << "Existe um jogo por acabar, deseja continuar ? (S/N)" << endl;
            cin >> c;
            if(c == 's' || c == 'S'){
                return true;
            }
            else {
                LimpaTabela();
                return false;;
            }
        }while(c != 's' && c != 'S' && c != 'n' && c != 'N');
    }
}
