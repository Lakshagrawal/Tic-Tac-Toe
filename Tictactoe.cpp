#include<bits/stdc++.h>


using namespace std;
int vis[10]={0};
char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';


void draw()
{
    system("cls"); // Window goes clean after every entry;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
}
// 00 01 02
// 10 11 12
// 20 21 22
char program_tic()
{
    // horizontal check;
    if(matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2])
    {return matrix[0][0];}
    else if(matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2])
    {return matrix[1][0];}
    else if(matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2])
    {return matrix[2][0];}

    //vertical check;
    else if(matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0])
    {return matrix[0][0];}
    else if(matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1])
    {return matrix[0][1];}
    else if(matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2])
    {return matrix[0][2];}

    //diagnal
    else if(matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
    {return matrix[0][0];}
    else if(matrix[2][0] == matrix[1][1] && matrix[2][0] == matrix[0][2])
    {return matrix[2][0];}
    
    return '/';
    
}
void tople()
{
    if(player == 'X')
    player = 'O';
    else 
    player = 'X';
}
void Input()
{
    
    int pos;
    cin>>pos;
    if(vis[pos] == 1)
    {
    	cout << "Repeated Input\n";
    }
    else{
    vis[pos]=1;
    if(pos == 1)
    {matrix[0][0] = player;}
    else if(pos == 2)
    {matrix[0][1] = player;}
    else if(pos == 3)
    {matrix[0][2] = player;}
    else if(pos == 4)
    {matrix[1][0] = player;}
    else if(pos == 5)
    {matrix[1][1] = player;}
    else if(pos == 6)
    {matrix[1][2] = player;}
    else if(pos == 7)
    {matrix[2][0] = player;}
    else if(pos == 8)
    {matrix[2][1] = player;}
    else if(pos == 9)
    {matrix[2][2] = player;}

    tople();}

}
int main()
{
    system("cls");
    play_again:

    cout<<"Wellcome to the Tic-Tac_Toe game"<<endl;
    cout<<"Press key according to play"<<endl;
    cout<<"1) Press 1 for Double player"<<endl;
    cout<<"2) Press 2 for Exit the game"<<endl;
    int a ;
    cin>>a;
    if(a == 1)
   { 
        draw();

        while (1)
        {
            Input();
            draw();
            if(program_tic() == 'X')
            {cout<<"Player X Win!!!";
            break;}
            else if(program_tic() == 'O')
            {cout<<"Player O Win!!!";
            break;}
            else
            {
                bool ok = true;
                for(int i=1;i<=9;i++)
                if(!vis[i])
                ok = false;

                if(ok)
                {cout << "Tie Nobody Win";
                break;
                cout<<endl;
                cout<<"If you wand to try again press 1";
                int a;
                cin>>a;
                if(a == 1)
                {goto play_again;}}
            }
        }
    }
    else
    {system("exit");}
    

}
