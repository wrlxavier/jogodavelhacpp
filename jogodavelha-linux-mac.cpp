#include <iostream>
#include <string>

using namespace std;

void limpar_tela_SO(){
    system("clear");
}


void creditos(int ordem){
    if(ordem==1)
    {
        cout<<"\tJOGO DA VELHA 1.0\nESCRITO POR WARLEY XAVIER (CRIADO EM OUT/2019; OTIMIZADO EM SET/2020)\nUM JOGO SIMPLES PARA APRENDER A CRIAR E ORGANIZAR ALGORITMOS EM C++\n\n";
        cout<<"TUTORIAL:\n\nPARA SELECIONAR UM CAMPO, DIGITE A COORDENADA DE SUA ESCOLHA.\nEXEMPLO: O CAMPO DO CENTRO, LINHA 2, COLUNA 2, COORDENADA = 22.\n\n";
    } else
    {
        cout<<"\n\tFIM DE JOGO.\n\nOBRIGADO POR UTILIZAR O MEU PROGRAMA :)\n\n";
    }
}

void receber_nome(string &nome_jogador1, string &nome_jogador2){
    cout<<"\tNOMES DOS JOGADORES"<<endl<<endl;
    cout<<"JOGADOR(A) 1: "; getline(cin, nome_jogador1);
    cout<<"JOGADOR(A) 2: "; getline(cin, nome_jogador2);
}

void limpar_jogo(char jogo[]){
    for(int i=0;i<9;i++){ jogo[i]=' '; }
}

void atualizar_tela(char jogo[], int estado){
    limpar_tela_SO();
    cout<<endl;
    cout<<"\t  JOGO DA VELHA"<<endl<<endl;
    cout<<"\t     RODADA "<<estado<<endl;
    cout<<endl<<endl;
    cout<<"\t    1   2   3"<<endl;
    cout<<"\t  -------------"<<endl;
    cout<<"\t1 | "<<jogo[0]<<" | "<<jogo[1]<<" | "<<jogo[2]<<" |"<<endl;
    cout<<"\t  |---+---+---|"<<endl;
    cout<<"\t2 | "<<jogo[3]<<" | "<<jogo[4]<<" | "<<jogo[5]<<" |"<<endl;
    cout<<"\t  |---+---+---|"<<endl;
    cout<<"\t3 | "<<jogo[6]<<" | "<<jogo[7]<<" | "<<jogo[8]<<" |"<<endl;
    cout<<"\t  -------------"<<endl<<endl<<endl;
}

void alterar_jogo(int escolha, char jogo[], char carimbo){
    if      (escolha==11){ jogo[0]=carimbo; }
    else if (escolha==12){ jogo[1]=carimbo; }
    else if (escolha==13){ jogo[2]=carimbo; }
    else if (escolha==21){ jogo[3]=carimbo; }
    else if (escolha==22){ jogo[4]=carimbo; }
    else if (escolha==23){ jogo[5]=carimbo; }
    else if (escolha==31){ jogo[6]=carimbo; }
    else if (escolha==32){ jogo[7]=carimbo; }
    else if (escolha==33){ jogo[8]=carimbo; }
}

int analisar_resultado(char jogo[], int estado){
    if(jogo[0]!=' '&&jogo[0]==jogo[3]&&jogo[3]==jogo[6]){ return 1; }
    if(jogo[1]!=' '&&jogo[1]==jogo[4]&&jogo[4]==jogo[7]){ return 1; }
    if(jogo[2]!=' '&&jogo[2]==jogo[5]&&jogo[5]==jogo[8]){ return 1; }
    if(jogo[0]!=' '&&jogo[0]==jogo[1]&&jogo[1]==jogo[2]){ return 1; }
    if(jogo[3]!=' '&&jogo[3]==jogo[4]&&jogo[4]==jogo[5]){ return 1; }
    if(jogo[6]!=' '&&jogo[6]==jogo[7]&&jogo[7]==jogo[8]){ return 1; }
    if(jogo[0]!=' '&&jogo[0]==jogo[4]&&jogo[4]==jogo[8]){ return 1; }
    if(jogo[2]!=' '&&jogo[2]==jogo[4]&&jogo[4]==jogo[6]){ return 1; }
    if(estado>=10) { return 0; }
    else { return -1; }
}

int receber_escolha(int &escolha, string jogador){
    cout<<jogador<<": "; cin>>escolha;
}

void validar_escolha(char jogo[], int coordenadas[], int escolha, char carimbo, string jogador){
    bool existencia = false;
    bool disponibilidade = false;
    while(existencia==false || disponibilidade==false){
        existencia = false; disponibilidade = false;
        for(int i=0;i<9;i++){
            if(coordenadas[i]==escolha)
            {
                existencia = true;
                if(jogo[i]==' ')
                {
                    disponibilidade = true;
                }
                break;
            }
        }
        if(existencia==false){
            cout<<"COORDENADA INEXISTENTE!"<<endl;
            receber_escolha(escolha, jogador);
        } else if ( disponibilidade==false){
            cout<<"COORDENADA INDISPONIVEL!"<<endl;
            receber_escolha(escolha, jogador);
        } else {
            alterar_jogo(escolha, jogo, carimbo);
        }
    }
}

int main(){

    creditos(1);
    string nome_jogador1, nome_jogador2; receber_nome(nome_jogador1, nome_jogador2);
    int coordenadas[9] = {11, 12, 13, 21, 22, 23, 31, 32, 33};
    char jogo[9];
    string jogador;
    char carimbo;
    int escolha, estado;
    int rodada = 0;

    while(true)
    {
    limpar_jogo(jogo);
    estado = 0;
    rodada+=1;
        while(true)
        {
            estado+=1;
            if((estado%2)!=0)
            {
                atualizar_tela(jogo, rodada);
                if(analisar_resultado(jogo, estado)==(-1))
                {
                    jogador = nome_jogador1;
                    carimbo = 'X';
                    receber_escolha(escolha, jogador);
                    validar_escolha(jogo, coordenadas, escolha, carimbo, jogador);
                } else {
                    break;
                }
            } else
            {
                atualizar_tela(jogo, rodada);
                if(analisar_resultado(jogo, estado)==(-1))
                {
                    jogador = nome_jogador2;
                    carimbo = 'O';
                    receber_escolha(escolha, jogador);
                    validar_escolha(jogo, coordenadas, escolha, carimbo, jogador);
                } else {
                    break;
                }
            }
        }
        atualizar_tela(jogo, rodada);
        if(analisar_resultado(jogo, estado)==1 || analisar_resultado(jogo, estado)==2)
        {
            cout<<jogador<<" VENCEU!"<<endl;
        } else {
            cout<<"DEU VELHA!"<<endl;
        }
        cout<<"REPETIR JOGO? (S/N): "; cin>>jogador;
        if(jogador=="n" || jogador=="N")
        {
            break;
        }
    }
    limpar_tela_SO();
    creditos(2);
}
