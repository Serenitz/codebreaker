/*
3 digits random number color guessing game
*/
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

char colorList[7]={'R','G','B','Y','P','W','K'};
typedef struct guess
{
    int num[3];
    char color[3];
};

void randCheck(int pos, guess* randCode)
{
    int flag=false;
    int j=pos;

    do
    {
        flag=false;
        for(int i=0;i<j;i++)
        {
            if(randCode->num[j]==randCode->num[i])
            {
                randCode->num[j]=rand()%(9-1+1)+1;
                flag=true;
                break;
            }
        }
    }
    while(flag==true);

    do
    {
        flag=false;
        for(int i=0;i<j;i++)
        {
            if(randCode->color[j]==randCode->color[i])
            {
                randCode->color[j]=colorList[rand()%7];
                flag=true;
                break;
            }
        }
    }
    while(flag==true);
}

int codeCheck(guess guessCode, guess randCode)
{
    int check=0,whiteNum=0,redNum=0,whiteColor=0,redColor=0;

    for(int i=0;i<3;i++)
    {
        if(guessCode.num[0]==randCode.num[i])
        {
            whiteNum++;
        }
        if(guessCode.num[1]==randCode.num[i] || guessCode.num[2]==randCode.num[i])
        {
            redNum++;
        }

        swap(guessCode.num[0],guessCode.num[1]);
        swap(guessCode.num[1],guessCode.num[2]);
    }

    cout<<"You have "<<whiteNum<<" white(s) and "<<redNum<<" red(s) for Numbers"<<endl;

    for(int i=0;i<3;i++)
    {
        if(guessCode.color[0]==randCode.color[i])
        {
            whiteColor++;
        }
        if(guessCode.color[1]==randCode.color[i] || guessCode.color[2]==randCode.color[i])
        {
            redColor++;
        }

        swap(guessCode.color[0],guessCode.color[1]);
        swap(guessCode.color[1],guessCode.color[2]);
    }

    cout<<"You have "<<whiteColor<<" white(s) and "<<redColor<<" red(s) for Colors"<<endl<<endl;

    if(whiteColor==3 && whiteNum==3)
    {
        check=1;
    }

    return check;
}

int main()
{
    guess guessCode;
    guess randCode;
    int check;
    srand(time(0));

    for(int i=0; i<3; i++) // loops 3 times to randomize number and color
    {
        randCode.num[i]=rand()%(9-1+1)+1;
        randCode.color[i]=colorList[rand()%7];
        
        if (i>0)
        {
            randCheck(i,&randCode);  // random check for duplicates
        }
        
        cout<<randCode.num[i]<<randCode.color[i]<<" "<<endl;
    }

    //intro to game
    {
    
    cout<<"Hello, Welcome to CodeBreaker!"<<endl;
    cout<<"In this game, you will crack the randomized code provided by the AI."<<endl;
    cout<<"You will try to guess 3 random Number and Color."<<endl;
    cout<<"There won't be duplicates on the Numbers and Colors."<<endl;
    cout<<"Try your best to guess in 10 tries. Goodluck!"<<endl;

    cout<<endl<<"(White means you got the number/color and placement right and red means you got ONLY the number/color right)"<<endl<<endl;

    cout<<"Use space to seperate the Number and Color and Color is (CASE SENSITIVE) when guessing."<<endl<<endl;
    
    }
    //end of intro

    for(int i=0; i<10; i++) //10 tries to guess
    {
        cout<<"Guess the 3 Numbers and Colors (1-9 and R,G,B,Y,P,W,K)"<<endl<<"R=Red, G=Green, B=Blue, Y=Yellow, P=Purple, W=White, K=Black"<<endl;
        
        int j=0;

        do
        {
            cout<<"Digit "<<j+1<<" : ";
            cin>>guessCode.num[j]>>guessCode.color[j];;
            j++;
        }while(j<3);

        //check guessed code
        check=codeCheck(guessCode,randCode);

        if(check==1)
        {
            cout<<"You Cracked The Code ! ("<<randCode.num[0]<<randCode.color[0]<<" "<<randCode.num[1]<<randCode.color[1]<<" "<<randCode.num[2]<<randCode.color[2]<<")"<<endl;
            break;
        }
    }
    
    if(check!=1)
    {
        cout<<"Sorry, You Didn't Cracked The Code"<<endl<<"The Code is "<<randCode.num[0]<<randCode.color[0]<<" "<<randCode.num[1]<<randCode.color[1]<<" "<<randCode.num[2]<<randCode.color[2]<<endl;
    }

    return 0;
}
