

#include <iostream>
using namespace std;
enum enQuizzLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOPType = 5 };
struct stQuizzResulte
{
    short NumOfQuestion=0;
    string Level="";
    string OPType="";
    short Right=0;
    short Wrong=0;
};
short AskHowManyQuestion()
{
    short How = 0;
    cout << "How Many Question You Want ? ";
    cin >> How;
    return How;
}
enQuizzLevel AskQuestionLevel()
{
    short Level;
    cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix : ";
    cin >> Level;
    return (enQuizzLevel)Level;
}
enOperationType AskOperationType()
{
    short OperationType;
    cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ";
    cin >> OperationType;
    return (enOperationType)OperationType;
}
int RandomNumber(int From, int To)
{
    int randNum = 0;
    randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void GenerateNumOPAdd(enQuizzLevel Level, short& N1, short& N2)
{

    if (Level == enQuizzLevel::Easy)
    {
        N1 = RandomNumber(1, 10);
        N2 = RandomNumber(1, 10);
        cout << N1 << endl;
        cout << N2 << "  +" << endl;
        cout << "_______\n";
    }
    else if (Level == enQuizzLevel::Med)
    {
        N1 = RandomNumber(1, 25);
        N2 = RandomNumber(1, 25);
        cout << N1 << endl;
        cout << N2 << "  +" << endl;
        cout << "_______\n";

    }
    else if (Level == enQuizzLevel::Hard)
    {
        N1 = RandomNumber(1, 50);
        N2 = RandomNumber(1, 50);
        cout << N1 << endl;
        cout << N2 << "  +" << endl;
        cout << "_______\n";

    }
    else
    {
        Level = (enQuizzLevel)RandomNumber(1, 3);
        GenerateNumOPAdd(Level, N1, N2);
    }
}
void GenerateNumOPSub(enQuizzLevel Level, short& N1, short& N2)
{
    if (Level == enQuizzLevel::Easy)
    {
        N1 = RandomNumber(1, 10);
        N2 = RandomNumber(1, 10);
        cout << N1 << endl;
        cout << N2 << "  -" << endl;
        cout << "_______\n";
    }
    else if (Level == enQuizzLevel::Med)
    {
        N1 = RandomNumber(1, 25);
        N2 = RandomNumber(1, 25);
        cout << N1 << endl;
        cout << N2 << "  -" << endl;
        cout << "_______\n";

    }
    else if (Level == enQuizzLevel::Hard)
    {
        N1 = RandomNumber(1, 50);
        N2 = RandomNumber(1, 50);
        cout << N1 << endl;
        cout << N2 << "  -" << endl;
        cout << "_______\n";
    }
    else
    {
        Level = (enQuizzLevel)RandomNumber(1, 3);
        GenerateNumOPSub(Level, N1, N2);
    }
}
void GenerateNumOPMul(enQuizzLevel Level, short& N1, short& N2)
{
    if (Level == enQuizzLevel::Easy)
    {
        N1 = RandomNumber(1, 10);
        N2 = RandomNumber(1, 10);
        cout << N1 << endl;
        cout << N2 << "  *" << endl;
        cout << "_______\n";
    }
    else if (Level == enQuizzLevel::Med)
    {
        N1 = RandomNumber(1, 25);
        N2 = RandomNumber(1, 25);
        cout << N1 << endl;
        cout << N2 << "  *" << endl;
        cout << "_______\n";

    }
    else if (Level == enQuizzLevel::Hard)
    {
        N1 = RandomNumber(1, 50);
        N2 = RandomNumber(1, 50);
        cout << N1 << endl;
        cout << N2 << "  *" << endl;
        cout << "_______\n";
    }
    else
    {
        Level = (enQuizzLevel)RandomNumber(1, 3);
        GenerateNumOPMul(Level, N1, N2);
    }
}
void GenerateNumOPDiv(enQuizzLevel Level, short& N1, short& N2)
{
    if (Level == enQuizzLevel::Easy)
    {
        N1 = RandomNumber(1, 10);
        N2 = RandomNumber(1, 10);
        cout << N1 << endl;
        cout << N2 << "  /" << endl;
        cout << "_______\n";
    }
    else if (Level == enQuizzLevel::Med)
    {
        N1 = RandomNumber(1, 25);
        N2 = RandomNumber(1, 25);
        cout << N1 << endl;
        cout << N2 << "  /" << endl;
        cout << "_______\n";

    }
    else if (Level == enQuizzLevel::Hard)
    {
        N1 = RandomNumber(1, 50);
        N2 = RandomNumber(1, 50);
        cout << N1 << endl;
        cout << N2 << "  /" << endl;
        cout << "_______\n";
    }
    else
    {
        Level = (enQuizzLevel)RandomNumber(1, 3);
        GenerateNumOPDiv(Level, N1, N2);
    }
}
enOperationType GenerateNumMixOP(enQuizzLevel Level, short& N1, short& N2)
{
    enOperationType RandomOPtype = (enOperationType)RandomNumber(1, 4);

    switch (RandomOPtype)
    {
    case enOperationType::Add:
        GenerateNumOPAdd(Level, N1, N2);
        return RandomOPtype;
        break;
    case enOperationType::Sub:
        GenerateNumOPSub(Level, N1, N2);
        return RandomOPtype;

            break;
    case enOperationType::Mul:
        GenerateNumOPMul(Level, N1, N2);
        return RandomOPtype;
        break;
    case enOperationType::Div:
        GenerateNumOPDiv(Level, N1, N2);
        return RandomOPtype;
        break;
    }
}
short CheckAnswer(enOperationType OPType, short N1, short N2)
{
    switch (OPType)
    {
    case enOperationType::Add:
        return N1 + N2;
        break;
    case enOperationType::Sub:
        return N1 - N2;
        break;
    case enOperationType::Mul:
        return N1 * N2;
        break;
    case enOperationType::Div:
        return N1 / N2;
        break;
    case enOperationType::MixOPType:
        if (OPType == enOperationType::Add)
            return N1 + N2;
        else if (OPType == enOperationType::Sub)
            return N1 - N2;
        else if (OPType == enOperationType::Mul)
            return N1 * N2;
        else if (OPType == enOperationType::Div)
            return N1 / N2;
    }

}
string LevelName(enQuizzLevel Level)
{
    string arrLevelName[4] = { "Easy","Med","Hard","Mix" };
    return arrLevelName[Level - 1];
}
string OPtypeName(enOperationType OPtype)
{
    string arrOPTypeName[5] = { "Add","Sub","Mul","Div","Mix" };
    return arrOPTypeName[OPtype - 1];
}
stQuizzResulte PlayGame(short HowManyQuestion, enQuizzLevel Level, enOperationType OPType)
{
    stQuizzResulte ResulteGame;
    short N1 = 0; short N2 = 0; short Answer = 0;

    for (int i = 1; i <= HowManyQuestion; i++)
    {
        cout << "\nQuestion [" << i << "/" << HowManyQuestion << "] : \n";
        if (OPType == enOperationType::Add)
        {
            GenerateNumOPAdd(Level, N1, N2);
            cin >> Answer;
            if (Answer == CheckAnswer(OPType, N1, N2))
            {
                system("color 2F");
                cout << "Right Answer :)\n";
                ResulteGame.Right++;
            }
            else
            {
                system("color 4F");
                cout << "\a";
                cout << "Wrong Answer :(\n";
                cout << "The Right Answer : " << CheckAnswer(OPType, N1, N2) << endl;
                ResulteGame.Wrong++;
            }
        }
        else if (OPType == enOperationType::Sub)
        {
            GenerateNumOPSub(Level, N1, N2);
            cin >> Answer;
            if (Answer == CheckAnswer(OPType, N1, N2))
            {
                system("color 2F");
                cout << "Right Answer :)\n";
                ResulteGame.Right++;
            }
            else
            {
                system("color 4F");
                cout << "\a";
                cout << "Wrong Answer :(\n";
                cout << "The Right Answer : " << CheckAnswer(OPType, N1, N2) << endl;
                ResulteGame.Wrong++;
            }
        }
        else if (OPType == enOperationType::Mul)
        {
            GenerateNumOPMul(Level, N1, N2);
            cin >> Answer;
            if (Answer == CheckAnswer(OPType, N1, N2))
            {
                system("color 2F");
                cout << "Right Answer :)\n";
                ResulteGame.Right++;
            }
            else
            {
                system("color 4F");
                cout << "\a";
                cout << "Wrong Answer :(\n";
                cout << "The Right Answer : " << CheckAnswer(OPType, N1, N2) << endl;
                ResulteGame.Wrong++;
            }
        }
        else if (OPType == enOperationType::Div)
        {
            GenerateNumOPDiv(Level, N1, N2);
            cin >> Answer;
            if (Answer == CheckAnswer(OPType, N1, N2))
            {
                system("color 2F");
                cout << "Right Answer :)\n";
                ResulteGame.Right++;
            }
            else
            {
                system("color 4F");
                cout << "\a";
                cout << "Wrong Answer :(\n";
                cout << "The Right Answer : " << CheckAnswer(OPType, N1, N2) << endl;
                ResulteGame.Wrong++;
            }
        }
        else if (OPType == enOperationType::MixOPType)
        {
            enOperationType MixType = GenerateNumMixOP(Level, N1, N2);
            cin >> Answer;
            if (Answer == CheckAnswer(MixType, N1, N2))
            {
                system("color 2F");
                cout << "Right Answer :)\n";
                ResulteGame.Right++;
            }
            else
            {
                system("color 4F"); 
                cout << "\a";
                cout << "Wrong Answer :(\n";
                cout << "The Right Answer : " << CheckAnswer(MixType, N1, N2) << endl;
                ResulteGame.Wrong++;
            }
        }

    }

    ResulteGame.Level = LevelName(Level);
    ResulteGame.NumOfQuestion = HowManyQuestion;
    ResulteGame.OPType = OPtypeName(OPType);
    return ResulteGame;
}
bool CheckFinalResult(short Pass, short Fail)
{
    if (Pass > Fail)
    {
        return true;
    }
    else
        return 0;
}
void PrintGameResulte(stQuizzResulte GameResulte)
{
    if (CheckFinalResult(GameResulte.Right, GameResulte.Wrong))
    {
        cout << "\n-----------------------------------\n";
        cout << "Final Resulte is PASS :)";
        cout << "\n-----------------------------------\n";

    }
    else
    {
        cout << "\n-----------------------------------\n";
        cout << "Final Resulte is Fail :(";
        cout << "\n-----------------------------------\n";
    }
        cout << "Number of Questions : " << GameResulte.NumOfQuestion << endl;
        cout << "Questions Level : " << GameResulte.Level << endl;
        cout << "OP Type : " << GameResulte.OPType << endl;
        cout << "Number of Right Questions : " << GameResulte.Right << endl;
        cout << "Number of Worng Questions : " << GameResulte.Wrong << endl;
        cout << "-----------------------------------\n";

}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
    short HowManyQuestions = AskHowManyQuestion();
    enQuizzLevel Level = AskQuestionLevel();
    enOperationType OPtype = AskOperationType();
    stQuizzResulte GameResulte=PlayGame(HowManyQuestions, Level, OPtype);
    PrintGameResulte(GameResulte);
    cout << "Do You Want Play Again ? Y/N ";
    cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}

