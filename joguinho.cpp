#include<iostream>

using namespace std;

int main()
{

    //variaveis locais
        int contador_jogador_1_linha = 0, contador_jogador_2_linha = 0;
        int  contador_jogador_1_coluna = 0, contador_jogador_2_coluna = 0;
        int contador_jogador_1_diagonal_principal = 0,contador_jogador_2_diagonal_principal = 0;
        int contador_jogador_1_diagonal_secundaria = 0,contador_jogador_2_diagonal_secundaria = 0;
        char matriz[3][3];
        int vez_jogador_1 = 1, vez_jogador_2 = 0;
        int linha = 0, coluna = 0;
        int contador = 0;
        int error = 0;
        bool verificador = false;
    //fim

    //preenchendo inicialmente a matriz:
        for(int i = 0; i < 3 ; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                matriz[i][j] = '+';
            }
        }
    //fim


    //informativo ao usuário
        for(int i = 0; i < 3 ; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout<<"["<<matriz[i][j]<<"]";
                }
                cout<<endl;
            }
    //fim

    do{
        contador = 0;
        contador_jogador_1_linha = 0;
        contador_jogador_2_linha = 0;
        contador_jogador_1_coluna = 0;
        contador_jogador_2_coluna = 0;
        contador_jogador_1_diagonal_principal = 0;
        contador_jogador_2_diagonal_principal = 0;
        contador_jogador_1_diagonal_secundaria = 0;
        contador_jogador_2_diagonal_secundaria = 0;
        

        if(vez_jogador_2 == 1)
        {

        //para garantir que o usuário não digite uma linha ou coluna inexistente
            do{

                verificador = false;

                if(linha > 3)
                {
                    cout<<"Você digitou uma linha inexistente"<<endl;
                }
                if(coluna > 3)
                {
                    cout<<"Você digitou uma coluna inexistente"<<endl;
                }

            cout<<"Qual casa deseja preencher jogador 2?,Digite a linha e a coluna, respectivamente";
            
                do{
                    error = 0;
                    cin>>linha;
                    if(cin.fail())
                    {
                        cout<<"Digite um número, por gentileza, você não digitou um número!"<<endl;
                        cin.clear();
                        cin.ignore();
                        error = 1;
                    }
                }while(error == 1);
            
                do{
                    error = 0;
                    cin>>coluna;
                    if(cin.fail())
                    {
                        cout<<"Digite um número, por gentileza, você não digitou um número!"<<endl;
                        cin.clear();
                        cin.ignore();
                        error = 1;
                    }
                }while(error == 1);

            linha = linha - 1;
            coluna = coluna - 1;

            if(matriz[linha][coluna] == 'X' || matriz[linha][coluna] == 'O')
            {
                cout<<"Você tentou preencher onde seu adversário preencheu ou onde você ja havia preenchido, preencha novamente onde estiver com o sinal +"<<endl;
                verificador = true;
            }

            linha = linha + 1;
            coluna = coluna + 1;

            }while(linha > 3 || coluna > 3 || verificador == true);

        //fim

        //para que se adeque a contagem do sistema
            linha = linha - 1;
            coluna = coluna - 1;
        //fim

            matriz[linha][coluna] = 'O';

        //para que a jogada seja passada ao outro jogador:
            vez_jogador_1 = 1;
            vez_jogador_2 = 0;
        //fim

        }else if(vez_jogador_1 == 1)
        {

        //para garantir que o usuário não digite uma linha ou coluna inexistente
            do{

                verificador = false;

                if(linha > 3)
                {
                    cout<<"Você digitou uma linha inexistente"<<endl;
                }
                if(coluna > 3)
                {
                    cout<<"Você digitou uma coluna inexistente"<<endl;
                }

                cout<<"Qual casa deseja preencher jogador 1?,Digite a linha e a coluna, respectivamente";
                
                do{
                    error = 0;
                    cin>>linha;
                    if(cin.fail())
                    {
                        cout<<"Digite um número, por gentileza, você não digitou um número!"<<endl;
                        cin.clear();
                        cin.ignore();
                        error = 1;
                    }
                }while(error == 1);
            
                do{
                    error = 0;
                    cin>>coluna;
                    if(cin.fail())
                    {
                        cout<<"Digite um número, por gentileza, você não digitou um número!"<<endl;
                        cin.clear();
                        cin.ignore();
                        error = 1;
                    }
                }while(error == 1);

                linha = linha - 1;
                coluna = coluna - 1;

                if(matriz[linha][coluna] == 'O' || matriz[linha][coluna] == 'X')
                {
                    cout<<"Você tentou preencher onde seu adversário preencheu ou onde você ja havia preenchido, preencha novamente onde estiver com o sinal +"<<endl;
                    verificador = true;
                }

                linha = linha + 1;
                coluna = coluna + 1;
            
            }while(linha > 3 || coluna > 3 || verificador == true);

        //fim

        //para que se adeque a contagem do sistema
            linha = linha - 1;
            coluna = coluna - 1;
        //fim

            matriz[linha][coluna] = 'X';

        //para que a jogada seja passada ao outro jogador:
            vez_jogador_1 = 0;
            vez_jogador_2 = 1;
        //fim
        }

    //inicio do procedimento de averiguação de vitoria 

    for(int i = 0; i < 3 ; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int h = j + 1;

                //para vitória nas linhas

                    if(matriz[i][j] == matriz[i][h] && h < 3 && matriz[i][j] == 'X')
                    {
                        if(contador_jogador_1_linha < 3)
                        contador_jogador_1_linha = contador_jogador_1_linha + 1;

                        if(matriz[i][j]==matriz[i][h+1] && h < 3 && matriz[i][j] == 'X')
                        {
                            if(contador_jogador_1_linha < 3)
                            contador_jogador_1_linha = contador_jogador_1_linha + 2;
                        }
                    }
                    if(matriz[i][j]==matriz[i][h] && h < 3 && matriz[i][j] == 'O')
                    {
                        if(contador_jogador_2_linha <3)
                        contador_jogador_2_linha = contador_jogador_2_linha + 1;
                        
                        if(matriz[i][j]==matriz[i][h+1] && h < 3 && matriz[i][j] == 'O')
                        {
                            if(contador_jogador_2_linha <3)
                            contador_jogador_2_linha = contador_jogador_2_linha + 2;
                        }
                    }

                //fim

                //para vitória nas colunas:
                int p = i + 1 ;

                    if(matriz[i][j] == matriz[p][j] && p < 3 && matriz[i][j] == 'X')
                    {
                        if(contador_jogador_1_coluna < 3)
                        contador_jogador_1_coluna = contador_jogador_1_coluna + 1;
                        

                        if(matriz[i][j] == matriz[p+1][j] && p < 3 && matriz[i][j] == 'X')
                        {
                            if(contador_jogador_1_coluna < 3)
                            contador_jogador_1_coluna = contador_jogador_1_coluna + 2;
                        }
                    }

                    p = i + 1;

                    if(matriz[i][j] == matriz[p][j] && p < 3 && matriz[i][j] == 'O')
                    {
                        if(contador_jogador_2_coluna < 3)
                        contador_jogador_2_coluna = contador_jogador_2_coluna +1;

                        if(matriz[i][j] == matriz[p+1][j] && p < 3 && matriz[i][j] == 'O')
                        {
                            if(contador_jogador_2_coluna < 3)
                            contador_jogador_2_coluna = contador_jogador_2_coluna + 2;
                        }
                    }
                    
                
                //fim
            
                //para vitória nas diagonais

                    if(matriz[i][j] == matriz[i+1][j+1] && matriz[i][j] == 'X')
                    {
                        contador_jogador_1_diagonal_principal = contador_jogador_1_diagonal_principal + 1;

                        if(matriz[i][j] == matriz[i+2][j+2] && matriz[i][j] == 'X')
                        {
                            contador_jogador_1_diagonal_principal = contador_jogador_1_diagonal_principal + 2;
                        }
                    }
                    if(matriz[i][j] == matriz[i+1][j+1] && matriz[i][j] == 'O')
                    {
                        contador_jogador_2_diagonal_principal = contador_jogador_2_diagonal_principal + 1;
                        
                        if(matriz[i][j] == matriz[i+2][j+2] && matriz[i][j] == 'O')
                        {
                            contador_jogador_2_diagonal_principal = contador_jogador_2_diagonal_principal + 2;
                        }
                    }

                    if(matriz[i][j] == matriz[i-1][j+1] && matriz[i][j] == 'X')
                    {
                        contador_jogador_1_diagonal_secundaria = contador_jogador_1_diagonal_secundaria + 1;

                        if(matriz[i][j] == matriz[i-2][j+2] && matriz[i][j] == 'X')
                        {
                            contador_jogador_1_diagonal_secundaria = contador_jogador_1_diagonal_secundaria + 2;
                        }
                    }
                    if(matriz[i][j] == matriz[i-1][j+1] && matriz[i][j] == 'O')
                    {
                        contador_jogador_2_diagonal_secundaria = contador_jogador_2_diagonal_secundaria + 1;
                        
                        if(matriz[i][j] == matriz[i-2][j+2] && matriz[i][j] == 'O')
                        {
                            contador_jogador_2_diagonal_secundaria = contador_jogador_2_diagonal_secundaria + 2;
                        }
                    }

                //fim
            }
        }

    //fim
        
    system("clear");

    //informativo aos usuários:

        for(int i = 0; i < 3 ; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout<<"["<<matriz[i][j]<<"]";
            }
            cout<<endl;
        }
    //fim


    //para averiguar se todos os espaços foram preenchidos
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(matriz[i][j] == '+')
                {
                    contador++;
                }
            }

        }
    //fim

    //informartivo ao ganhador
        if(contador_jogador_1_linha == 3 || contador_jogador_1_coluna == 3 || contador_jogador_1_diagonal_principal >= 3 || contador_jogador_1_diagonal_secundaria >= 3)
        {
            cout<<"O jogador 1 ganhou!!"<<endl;

        }else if(contador_jogador_2_coluna == 3 || contador_jogador_2_linha == 3 || contador_jogador_2_diagonal_principal >= 3 || contador_jogador_1_diagonal_secundaria >= 3)
        {
            cout<<"O jogador 2 ganhou!!"<<endl;
        }else if(contador == 0)
        {
            cout<<"Ninguem ganhou!"<<endl;
            
        }
    //fim

    }while(contador_jogador_1_linha < 3 && contador_jogador_2_linha < 3 && contador != 0 && contador_jogador_1_coluna < 3 && contador_jogador_2_coluna < 3 && contador_jogador_1_diagonal_principal < 3 && contador_jogador_2_diagonal_principal < 3 && contador_jogador_1_diagonal_secundaria < 3 && contador_jogador_2_diagonal_secundaria < 3);

    return 0;
}

//fim do código