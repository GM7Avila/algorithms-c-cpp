#include <iostream>
 
using namespace std;

int day, month, year; //day, month, year
int currentDay = 0, currentMonth = 0, currentYear = 0; 
int daysCount=0;

int verifyDate(const int d, const int m, const int y){
    
    if (d < 1 || d > 31 || m < 1 || m > 12){
        return 0;
    } 
    else if (m==2 && d > 29){
        return 0;
    } else return 1;


}

int getDays(const int d, const int m, const int y){

    daysCount = (currentDay - day) + (currentMonth - month)*30 + (currentYear - year)*365;

    int yearsOld = daysCount/365;

    if(daysCount == 0) { 
        cout << "Você nasceu hoje!";

    } else { 
        cout << "Você tem " << yearsOld << " anos, e "<< daysCount << " dias de vida!";
    } 


}

int main()
{

    cout << "Dia atual: ";
    cin >> currentDay;
    cout << "\nMês atual: ";
    cin >> currentMonth;
    cout << "\nAno atual: ";
    cin >> currentYear;

    if (verifyDate(currentDay, currentMonth, currentYear)==0){
         cout << "\n\nData inválida";
    } else {
        cout << "\n\nDigite seu dia de nascimento: "; cin >> day;
        cout << "\nDigite seu mês de nascimento: "; cin >> month;
        cout << "\nDigite seu ano de nascimento: "; cin >> year;
        
        if (verifyDate(day, month, year) == 0){
            cout << "\n\nData inválida";
        } else if (verifyDate(day, month, year) == 1){
            getDays(day, month, year);
        }
    }
}