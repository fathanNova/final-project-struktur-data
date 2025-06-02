#include <iostream>
using namespace std;

int main(){
    cout<<"Hello World!";
}

void inS(){    //Satria
    stack.top = -1;
}

bool full (){ //Satria
    return stack.top == maxS-1;
}

bool empty() {  //satria
    return stack.top == -1;
}

void show () {  //satria
    if (!empty ()){
        cout<<"\n---- Menampilkan Daftar Barang ----\n";
        for (int i = stack.top; i >=0; i--){
            cout<<"ID         : "<<stack.data[i].kode<<endl;
            cout<<"Nama       : "<<stack.data[i].nama<<endl;
            cout<<"Harga      : "<<stack.data[i].harga<<endl;
            cout<<"Stok       : "<<stack.data[i].stok<<endl;
        }
    }else{
        cout<<"\nStack Kosong!";
    } cin.get();
}
