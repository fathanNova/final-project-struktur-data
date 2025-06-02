#include <iostream>
#include <conio.h>
using namespace std;
#define max 50

struct barangGudang{
    int id;
    string nama;
    int jumlah;
}barang;

struct stackBarang{
    barangGudang data[max];
    int top;
}stack;

void init();
bool full();
bool empty();
void show();

int main(){
    init();

    do{

    }while(true);
}

void init(){    //Satria
    stack.top = -1;
}

bool full (){ //Satria
    return stack.top == max-1;
}

bool empty() {  //satria
    return stack.top == -1;
}

void show() {
    if (!empty ()){
        cout<<"\n----Menampilkan Daftar Barang ----\n";
        for(int i = stack.top; i>=0; i--) {
            cout<<"Id          : "<< stack.data[i].id<<endl;
            cout<<"Nama        : "<< stack.data[i].nama<<endl;
            cout<<"Jumlah      : "<< stack.data[i].jumlah<<endl;
        }
    }else {
        cout<<"\nStack Kosong";
    } cin.get();
}
