# include <iostream>
using namespace std;

int main(){

    int temperatura;
    int negativas = 0;

    do{
        cin >> temperatura;

        if(temperatura < 0){
            negativas += 1;

        }

    }while(temperatura != 0);
        cout << negativas;

return 0;
}
