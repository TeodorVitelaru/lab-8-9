//#include "ui.h"
#include "teste.h"
using namespace std;


void start_app()
{
    string filename = "../oferte.txt";
    try {
        RepoFile repo{filename};
        Validator val;
        cosOferte cos;
        Service srv{ repo, val, cos};
        Consola ui{srv};
        ui.run();
    }
    catch (RepoException& re)
    {
        cout<<re.getErrorMessage();
    }
}

int main()
{
    test_all();
    start_app();
}