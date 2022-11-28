#include <iostream>
using namespace std;

int bissexto(int year){

    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        return 1;
    } else return 0;

}

int validarData (int d, int m, int y){

    //datas inválidas
    if (d < 1 || d > 31 || m < 1 || m > 12){
        return 0;
    } 
    else if (d == 31 && (m==4 || m==6 || m==9 || m==1)){
        return 0;
    }
    else if (m==2 && d > 29){
        return 0;
    } 
    else if (m==2 && d == 29 && bissexto(y) == 0){
        return 0;
    } else return 1; //data válida

}

int daysMonth (int m, int y){

    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        return 31;
    } else if (m==4 || m==6 || m==9 || m==11){
        return 30;
    } else if (bissexto(y)==1){
        return 29; //para bissexto
    } else return 28; //para não bissexto

}

void calcularIdade(int db, int mb, int yb){
    //Definindo data atual
    int da = 8;
    int ma = 12;
    int ya = 2022;

    int dcount = 0, mcount = 0, ycount = 0;

    while(mb < ma -1 || yb < ya){
        mb++;
        mcount++;

        if (mcount == 12){
            mcount = 0;
            ycount++;
        } else if (mb == 12){
            yb++;
            mb = 0; //inicia uma nova contagem de mês
        }
    }
    //aguste para o último mês   
    if (db == da){
        mcount++;
        dcount = 0;
    }
    else if (db < da) {
        mcount++;
        dcount = da - db;
    } 
    else {
        dcount = daysMonth(ma - 1, ya) + da - db;
    }

    cout << ycount << " anos, " << mcount << " meses e " << dcount << " dias.\n";
}

int main(){
    int d, m, y;
    cout << "Digite a data de nascimento no formato: dd mm yyyy: \n";
    
    cin >> d; 
    cin >> m; 
    cin >> y;

    if (validarData(d,m,y) == 1){
        calcularIdade(d,m,y);
    } else cout << "Data inválida\n";

    return 0;
}