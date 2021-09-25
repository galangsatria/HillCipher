/*
 Nama     : 
- Muhammad Galang Satria (140810190003)
- Roisyal Bariz (140810190023)
- Mohamad Alghaz Hernanda (140810190069)
 Kelas    : A
 Program mencari ciphertext dan plaintext menggunakan metode Hill Cipher
*/

#include<iostream>
#include<math.h>
 
using namespace std;
 
float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
 
void encryption();    //deklarasi fungsi enkripsi pesan yang diinput
void decryption();    //deklarasi fungsi deksripsi pesan yang diinput
void getKeyMessage();    
void inverse();        
 
int main() {
    getKeyMessage();
    encryption();
    decryption();
}
 
void encryption() {
    int i, j, k;
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
    
    cout<<"\nHasil Enkripsi (Ciphertext) adalah: ";
    for(i = 0; i < 3; i++)
        cout<<(char)(fmod(encrypt[i][0], 26) + 97);
}
 
void decryption() {
    int i, j, k;
    
    inverse();
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
    
    cout<<"\nHasil Dekripsi (Plaintext) adalah: ";
    for(i = 0; i < 3; i++)
        cout<<(char)(fmod(decrypt[i][0], 26) + 97);
    
    cout<<"\n";
}
 
void getKeyMessage() {
    int i, j;
    char msg[3];

    cout<<"---------------------------------------------------------------\n";
    cout<<"-PROGRAM MENCARI ENKRIPSI DAN DEKRIPSI MENGGUNAKAN HILL CIPHER-\n";
    cout<<"---------------------------------------------------------------\n";
 
    cout<<"Silahkan Masukkan matriks kunci 3x3 (Yang bisa diinverse kan):\n";
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            cin>>a[i][j];
            c[i][j] = a[i][j];
        }
    
    cout<<"\nSilahkan masukkan 3 huruf: ";
    cin>>msg;
    
    for(i = 0; i < 3; i++)
        mes[i][0] = msg[i] - 97;
}
 
void inverse() {
    int i, j, k;
    float p, q;
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }
        
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];
                
            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];
}