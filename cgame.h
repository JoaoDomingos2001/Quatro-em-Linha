#ifndef CGAME_H
#define CGAME_H

struct dados{
    char nome[50]; //nome do jogador
    int  vitorias;
};

class Cgame{
private:
    dados jogador, top10[10];
    int nTop;
    char matrix[6][7];
    char player; //char de identificação do jogador
    char nome_player[10]; //char para guardar no ficheiro o nome
    int nivelPC; //nivel do PC
    int nJogadas; //numero de jogadas
    char primeiro; //primeiro a jogar


public:
    Cgame(){nJogadas=0; player='X'; LimpaTabela();}

    void LimpaTabela(void);//Limpa a tabela
    void Desenha(void); //desenha tabela
    int GetNivelComp(void){return nivelPC;} //return do nivel do computador aka funcionalidade
    int ReturnNivelPC(int);//dá return ao nivel do computador
    int DefNivel(void);//define o nivel do computador
    void coutNivel(int);//print do nivel do computador aka funcionalidade
    void Menu(void); //menu inicial
    bool VerificaJogada(int);//verifica se é possivel fazer certa jogada
    int checkJogada(int);//verifica se ao fazer a jogada
    int Jogada(); //pergunta onde queremos jogar
    void MudaJogador(void); // muda de jogador
    int DecideJogador(void);// decide quem joga primeiro
    char GetPlayer(void){return player;} // return do X ou O
    int GetnJogadas(void){return nJogadas;} // return numero de jogadas
    bool Jogar(void); // jogar
    bool checkWin(void);//dá return se um dos utilizadores ganhou ao longo do jogo
    int Elementar(void);//return do valor a ser inserido para a coluna no modo Elementar
    int Basico(void);//return do valor a ser inserido para a coluna no modo Básico
    int Medio(void);
    int Joga_check(int);//Joga na coluna e verifica se o jogador ganhou ou não
    void ResetJogo();// dá reset ao jogo depois de acabar um
    int ConfirmarJogada(int); //confirma se quer fazer a jogada ou se quer voltar atras e fazer outra
    void mostraTop10();//mostrar os melhores jogadores
    void guardaJogador(char *); //guardar os jogadores no ficheiro
    static int compara(const void*,const void*); //compara os jogadores para ver quem tem melhor score
    void guardaJogo(); //guarda o jogo ao longo das rondas(ex. todos os movimentos feitos e o nome do player)
    bool continuaJogo(); //ve se o ficheiro tem algum jogo guardado e se tiver pergunta se quer jogar

    void LimpaJogo();
};

#endif // CGAME_H
