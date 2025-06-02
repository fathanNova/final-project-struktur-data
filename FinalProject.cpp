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

void show_barang() { //satria
    system("cls");
    cout << "Show Barang (Stack)\n";
    if (front > rear) {
        cout << "Stack kosong!\n";
    } else {
        cout << setw(5) << "ID"
             << setw(20) << "Nama"
             << setw(10) << "Harga"
             << setw(10) << "Stock" << endl;
        for (int i = front; i <= rear; i++) {
            cout << setw(5) << db[i].id
                 << setw(20) << db[i].nama
                 << setw(10) << db[i].harga
                 << setw(10) << db[i].stock << endl;
        }
    }
    system("pause");
}
