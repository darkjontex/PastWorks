#include <vector>
#include <iostream>

using namespace std;
/*funcao de comparar peças*/
bool funcLinha(const vector<string>& tabuleiro, int x, int y, char a1, char a2)
{    
    if (   (x - 1 >= 0 && (tabuleiro[y][x - 1] == a1 || tabuleiro[y][x - 1] == a2))
        || (x + 1 < 8 && (tabuleiro[y][x + 1] == a1 || tabuleiro[y][x + 1] == a2))
        || (y - 1 >= 0 && (tabuleiro[y - 1][x] == a1 || tabuleiro[y - 1][x] == a2))
        || (y + 1 < 8 && (tabuleiro[y + 1][x] == a1 || tabuleiro[y + 1][x] == a2)))
        
        return true;
     
    for (int xc = -1; xc + x - 1 >= 0 && tabuleiro[y][xc + x] == '.'; --xc)
        if (tabuleiro[y][xc + x - 1] == a1 || tabuleiro[y][xc + x - 1] == a2)
            return true;
    
    for (int xc = 1; xc + x + 1 < 8 && tabuleiro[y][xc + x] == '.'; ++xc)
        if (tabuleiro[y][xc + x + 1] == a1 || tabuleiro[y][xc + x + 1] == a2)
            return true;
    
    for (int yc = -1; yc + y - 1 >= 0 && tabuleiro[y + yc][x] == '.'; --yc)
        if (tabuleiro[y + yc - 1][x] == a1 || tabuleiro[y + yc - 1][x] == a2)
            return true;
    
    for (int yc = 1; yc + y + 1 < 8 && tabuleiro[y + yc][x] == '.'; ++yc)
        if (tabuleiro[y + yc + 1][x] == a1 || tabuleiro[y + yc + 1][x] == a2)
            return true;
        
    
    return false;
}

bool funcDiagonal(const vector<string>& tabuleiro, int x, int y, char a1, char a2)
{
    bool upLeft(true), upRight(true), downLeft(true), downRight(true);
    
    for (int c(1); upLeft || upRight || downLeft || downRight; ++c)
    {
        if (upLeft)
        {
            if (x - c >= 0 && y - c >= 0)
            {                
                if (tabuleiro[y - c][x - c] == a1 || tabuleiro[y - c][x - c] == a2)
                    return true;
                
                else if (tabuleiro[y - c][x - c] != '.')
                    upLeft = false;
            }
            else
                upLeft = false;
        }
        
        if (upRight)
        {
            if (x + c < 8 && y - c >= 0)
            {
                if (tabuleiro[y - c][x + c] == a1 || tabuleiro[y - c][x + c] == a2)
                    return true;
                
                else if (tabuleiro[y - c][x + c] != '.')
                    upRight = false;
            }
            else
                upRight = false;
        }
        
        if (downLeft)
        {
            if (x - c >= 0 && y + c < 8)
            {
                if (tabuleiro[y + c][x - c] == a1 || tabuleiro[y + c][x - c] == a2)
                    return true;
                
                else if (tabuleiro[y + c][x - c] != '.')
                    downLeft = false;
            }
            else
                downLeft = false;
        }
        
        if (downRight)
        {
            if (x + c < 8 && y + c < 8)
            {
                if (tabuleiro[y + c][x + c] == a1 || tabuleiro[y + c][x + c] == a1)
                    return true;
                
                else if (tabuleiro[y + c][x + c] != '.')
                    downRight = false;
            }
            else
                downRight = false;
        }
    }
    
    return false;
}


bool funcKnight(const vector<string>& tabuleiro, int x, int y, char a)
{
    if (x - 2 >= 0)
    {
        if (y - 1 >= 0 && tabuleiro[y - 1][x - 2] == a)
            return true;
        
        if (y + 1 < 8 && tabuleiro[y + 1][x - 2] == a)
            return true;
    }
    
    if (x + 2 < 8)
    {
        if (y - 1 >= 0 && tabuleiro[y - 1][x + 2] == a)
            return true;
            
        if (y + 1 < 8 && tabuleiro[y + 1][x + 2] == a)
            return true;
    }
    
    if (y - 2 >= 0)
    {
        if (x - 1 >= 0 && tabuleiro[y - 2][x - 1] == a)
            return true;
        
        if (x + 1 < 8 && tabuleiro[y - 2][x + 1] == a)
            return true;
    }
    
    if (y + 2 < 8)
    {
        if (x - 1 >= 0 && tabuleiro[y + 2][x - 1] == a)
            return true;
            
        if (x + 1 < 8 && tabuleiro[y + 2][x + 1] == a)
            return true;
    }
    
    return false;
}

bool funcPiao(const vector<string>& tabuleiro, int x, int y, char a, int yChange)
{
    if (y + yChange < 8 && y + yChange >= 0)
    {
        if (x - 1 >= 0 && tabuleiro[y + yChange][x - 1] == a)
            return true;
        
        if (x + 1 < 8 && tabuleiro[y + yChange][x + 1] == a)
            return true;
    }
    return false;
}
//FUNÇÃO MAIN PARA CHAMAR AS FUNÇÕES DE COMPARAÇÃO DO TABULEIRO
int main()
{
    bool forever(true);
    
    int whitePosx, blackPosx, whitePosy, blackPosy, temp;
    
    vector<string> tabuleiro(8);
    
    for (int t = 1; forever; ++t)
    {
        whitePosx = blackPosx = -1;
    
        
        for (int i = 0; i < 8; ++i)
        {
            cin >> tabuleiro[i];
            temp = tabuleiro[i].find('k');
            if (temp != string::npos)
            {
                blackPosy = i;
                blackPosx = temp;
            }
            
            temp = tabuleiro[i].find('K');
            if (temp != string::npos)
            {
                whitePosy = i;
                whitePosx = temp;
            }
        }
        
        if (whitePosx == -1)
            break;
        
        cout << "Jogo #" << t << ": ";
        
        if (funcPiao(tabuleiro, whitePosx, whitePosy, 'p', -1))
            cout << "white king esta em check.\n";
        
        else if (funcPiao(tabuleiro, blackPosx, blackPosy, 'P', 1))
            cout << "black king esta em check.\n";
        
        else if (funcKnight(tabuleiro, whitePosx, whitePosy, 'n'))
            cout << "white king esta em check.\n";
            
        else if (funcKnight(tabuleiro, blackPosx, blackPosy, 'N'))
            cout << "black king esta em check.\n";
            
        else if (funcLinha(tabuleiro, whitePosx, whitePosy, 'r', 'q'))
            cout << "white king esta em check.\n";
        
        else if (funcLinha(tabuleiro, blackPosx, blackPosy, 'R', 'Q'))
            cout << "black king esta em check.\n";
        
        else if (funcDiagonal(tabuleiro, whitePosx, whitePosy, 'b', 'q'))
            cout << "white king esta em check.\n";
        
        else if (funcDiagonal(tabuleiro, blackPosx, blackPosy, 'B', 'Q'))
            cout << "black king esta em check.\n";
        
        else
            cout << "Nenhum rei esta em check.\n";
    }
}