#include <iostream>

using namespace std;

int main() {
    int impares=0, pares=0;    
    int i, A[6]={}, B[6]={};
    int iA =0, iD = 0;
    
    //salva + contabiliza os pares e impares em A
    for (i=0; i<6; i++) {
        cout << "A [" << i << "] => ";
        cin >> A[i];
        
        if (A[i] % 2 == 0) {
            pares++; 
        } else{
            impares++; 
        }
    }
    
    //salva + contabiliza os pares e impares em B
    for (i=0; i<6; i++) {
        cout << "B [" << i << "] => ";
        cin >> B[i];

        if (B[i] % 2 == 0) {
            pares++; 
        }else{
            impares++; 
        }
        
    }
    //cria os vetores C e D com o tamanho dos contadores: pares e impares
    int C[pares], D[impares];
    
    cout << "\nC.size = " << pares << "\n";
    cout << "D.size = " << impares << "\n";
    
    //transcreve os valores de A para os novos vetores
    for (i=0; i<6; i++){
                
            if (A[i] % 2 == 0){
                C[iA] = A[i];
                iA ++;
            }else{
                D[iD] = A[i];
                iD ++;
            }
    }
    
    //transcreve os valores de B para os novos vetores
    for (i=0; i<6; i++){
            
            if (B[i] % 2 == 0){
                C[iA] = B[i];
                iA++;
            }else{
                D[iD] = B[i];
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
