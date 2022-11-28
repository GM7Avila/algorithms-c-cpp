#include <iostream>

using namespace std;

int main() {
    int impares=0, pares=0;    
    int i, A[6]={}, B[6]={};
    int iA =0, iD = 0;

    for (i=0; i<6; i++) {
        cout << "A [" << i << "] => ";
        cin >> A[i];
        
        if (A[i] % 2 == 0) {
            pares++; 
        } else{
            impares++; 
        }
    }
    

    for (i=0; i<6; i++) {
        cout << "B [" << i << "] => ";
        cin >> B[i];

        if (B[i] % 2 == 0) {
            pares++; 
        }else{
            impares++; 
        }
        
    }

    int C[pares], D[impares];
    
    cout << "\nC.size = " << pares << "\n";
    cout << "D.size = " << impares << "\n";
    
    for (i=0; i<6; i++){
                
            if (A[i] % 2 == 0){
                C[iA] = A[i];
                iA ++;
            }else{
                D[iD] = A[i];
                iD ++;
            }
    }
    
    for (i=0; i<6; i++){
            
            if (B[i] % 2 == 0){
                C[iA] = B[i];
                iA++;
            }else{
                D[iA] = B[i];
                iD++;
            }
    }


    cout << "\n";
    //printando A [check!]
    cout << "A = [";
    for (int count = 0; count < 6; count++){
        cout << " " << A[count] << " ";
    }
    cout << "]";
    
    //printando B [check!]
    cout << "\n";
    cout << "B = [";
    for (int count = 0; count < 6; count++){
        cout << " " << B[count] << " ";
    }
    cout << "]";
    
    //printando C
    cout << "\n";
    cout << "C = [";
    for (int count = 0; count < iA; count ++){
        cout << " " << C[count] << " ";
    }
    cout << "]";
    
    //printando D
    cout << "\n";
    cout << "D = [";
    for (int count = 0; count < iD; count ++){
        cout << " " << D[count] << " ";
    }
    cout << "]";
}