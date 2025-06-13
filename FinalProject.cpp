#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <iomanip>
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

struct historyNode{
    string activity;
    historyNode *next;
};
historyNode *head = NULL;

void init();
bool full();
bool empty();
string toLowerCase(string str);
void show();
void push(); //fungsi menampilkan barang baru
void deleteByName();
void searchByName();
void searchById();
void searching();
void sortByName();
void sortBySmallest();
void sortByLargest();
void sorting();
void restock();
void takeByQuantity();
void addHistory(string activity);
void showHistory();

int main() {
    init();
    int choice; // untuk menampilkan menu pilihan
    do{
      system("cls");
      cout << " \n----- Program Pendataan Barang Gudang -----\n\n";
      cout << "1. Tambahkan Barang\n";
      cout << "2. Tampilkan Barang\n";
      cout << "3. Cari Barang\n";
      cout << "4. Sorting Barang\n";
      cout << "5. Restock Barang\n";
      cout << "6. Ambil Barang\n";
      cout << "7. Hapus Barang\n";
      cout << "8. Tampilkan Riwayat Aktivitas\n";
      cout << "9. Keluar\n\n";
      cout << "Masukkan Pilihan Anda : "; cin >> choice;
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                show();
                break;
            case 3:
                searching();
                break;
            case 4:
                sorting();
                break;
            case 5:
                restock();
                break;
            case 6:
                takeByQuantity();
                break;
            case 7:
                deleteByName();
                break;
            case 8:
                showHistory();
                break;
            case 9:
                cout <<"Keluar dari Program.\n\n";
                break;
            default:
            cout << "Pilihan Tidak Valid. Silahkan Coba Lagi.\n\n";
            getchar();
            cin.get();
        }
    }while(choice != 9);
    system("pause");
    return 0;
}

void init(){    
    stack.top = -1;
}

bool full (){ 
    return stack.top == max-1;
}

bool empty() {  
    return stack.top == -1;
}

string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void searching(){
    cin.ignore();
    int choose;
    do{
        system("cls");
        cout<<"Pilih Metode Pencarian: \n\n";
        cout<<"1. Cari Barang Berdasarkan Nama\n";
        cout<<"2. Cari Barang Berdasarkan ID\n";
        cout<<"3. Kembali ke Menu\n";
        cout<<"\nMasukkan Pilihan Anda: "; cin>>choose;

        switch(choose){
            case 1:
                searchByName();
                break;
            case 2:
                searchById();
                break;
            case 3:
                break;
            default:
                cout<<"\nPilihan Tidak Valid!\n\n";
                break;
                getchar();
                cin.get();
        }
    }while(choose != 3);
    return;
}

void sorting(){
    cin.ignore();
    string choose;
    do{
        system("cls");
        cout<<"Pilih Metode Pengurutan: \n\n";
        cout<<"1. Urutkan Barang Berdasarkan Nama (A-Z)\n";
        cout<<"2. Urutkan Barang Berdasarkan Jumlah Terkecil\n";
        cout<<"3. Urutkan Barang Berdasarkan Jumlah Terbesar\n";
        cout<<"4. Kembali ke Menu\n";
        cout<<"\nMasukkan Pilihan Anda: "; cin>>choose;

        if(choose == "1"){
            sortByName();
        }else if(choose == "2"){
            sortBySmallest();      
        }else if(choose == "3"){
            sortByLargest();
        }else if (choose == "4"){
            break;
        }else{
            cout<<"\nPilihan Tidak Valid!\n\n";
            getchar();
            cin.get();
        }
    }while(choose != "4");
    return;
}

void show() {
    cin.ignore();
    cout << "\n======= Menampilkan Daftar Barang =======\n";
    if (empty()) {
        cout <<"\nBelum Ada Data Barang!\n\n";
    } else {
        cout << left << setw(10) << "ID"
             << left << setw(25) << "Nama"
             << left << setw(10) << "Jumlah" << endl;
        for (int i = stack.top; i >= 0; i--) {
            cout << left << setw(10) << stack.data[i].id
                 << left << setw(25) << stack.data[i].nama
                 << left << setw(10) << stack.data[i].jumlah << endl;
        }
    }
 
    getchar();
}

void push() {
    if (!full()) {
        cin.ignore();
        barang.id = stack.top+2;
        cout << "\n----- Menambahkan Barang -----\n";
        cout << "\nID Barang\t\t: "<<barang.id<<endl;
        cout << "Masukkan Nama Barang\t: "; getline(cin, barang.nama); 
        cout << "Masukkan Jumlah Barang \t: "; cin >> barang.jumlah;
        stack.top++;
        stack.data[stack.top] = barang;
        cin.ignore();

        cout<<"\nData Berhasil Ditambahkan\n\n";
        addHistory("Menambahkan Barang: " + barang.nama);
    }else {
        cout <<"\nBarang Sudah Penuh!\n\n";
    }
    getchar();
}

void deleteByName() {
    cin.ignore();
    string name;
    bool found = false;
    if (empty()) {
        cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return;
    }else{
        cout << "\nMasukkan Nama Barang yang Ingin Dihapus: ";
        getline(cin, name);

        for (int i = 0; i <= stack.top; i++) {
            if (toLowerCase(stack.data[i].nama) == toLowerCase(name)) {

                addHistory("Menghapus Barang: " + stack.data[i].nama);
                found = true;
                
                for (int j = i; j < stack.top; j++) {
                    stack.data[j] = stack.data[j + 1];
                }
                stack.top--;

                cout << "\nBarang dengan Nama '" << name << "' Berhasil Dihapus.\n";
               break;
            }
        }
    }
    if (!found) {
        cout << "\nBarang dengan Nama '" << name << "' Tidak Ditemukan.\n";
    }
    getchar();
}

void searchByName() {
    cin.ignore();
    string name;
    bool found = false;
    if(empty()){
        cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return; 
    }else{
        cout << "\nMasukkan Nama Barang yang Dicari: "; getline(cin, name);
        for (int i = 0; i <= stack.top; i++) {
            if (toLowerCase(stack.data[i].nama) == toLowerCase(name)) {
                cout << "\nBarang ditemukan:\n";
                cout << "ID       : " << stack.data[i].id<< endl;
                cout << "Nama     : " << stack.data[i].nama<< endl;
                cout << "Jumlah   : " << stack.data[i].jumlah << endl<<endl;
                found = true;
                addHistory("Mencari Barang dengan Nama: " + stack.data[i].nama);
                break;
            }
        }
    }
    if (!found) {
        cout << "\nBarang dengan Nama '"<< name << "' Tidak Ditemukan.\n";
    }
    getchar();
}

void searchById() {
    cin.ignore();
    int id;
    bool found = false;
    if(empty()){
        cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return; 
    }else{
        cout << "\nMasukkan ID Barang yang Dicari: ";cin >> id;
        cin.ignore();

        for (int i = 0; i <= stack.top; i++) {
            if (stack.data[i].id == id) {
                cout << "\nBarang Ditemukan:\n";
                cout << "ID     : " << stack.data[i].id <<endl;
                cout << "Nama   : " << stack.data[i].nama <<endl;
                cout << "Jumlah : " << stack.data[i].jumlah <<endl<<endl;
                addHistory("Mencari Barang dengan ID: " + stack.data[i].id);
                found = true;
                break;
            }
        }
    }
    if (!found) { 
        cout << "\nBarang dengan ID '" << id << "' Tidak Ditemukan.\n\n";
    }
    getchar();
}

void restock(){
    cin.ignore();
    string name;
    int restock;
    bool found = false;

    if(empty()){
         cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return;
    }else{
        cout<<"\nMasukkan Nama Barang yang Ingin di Restock: "; getline(cin, name);
        for(int i = 0; i <= stack.top; i++){
            if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
                cout<<"Masukkan Jumlah "<<name<<" yang Akan di Restock: "; cin>>restock;
                stack.data[i].jumlah += restock;
                found = true;
                cin.ignore();

                cout<<"\nData Berhasil Disimpan\n\n";
                addHistory("Restock Barang: " + stack.data[i].nama + " Sejumlah " + to_string(restock));
                break;
            }
        } 
    }
    if(!found){
        cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
    }
    getchar();
}

void takeByQuantity(){
    cin.ignore();
    string name;
    int take;
    bool found = false;

    if(empty()){
         cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return;
    }else{
        cout<<"\nMasukkan Nama Barang yang Akan Diambil: "; getline(cin, name);
        for(int i = 0; i <= stack.top; i++){
            if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
                cout<<"Masukkan Jumlah "<<name<<" yang Akan Diambil: "; cin>>take;
                stack.data[i].jumlah -= take;
                found = true;
                cin.ignore();

                cout<<"\nData Berhasil Disimpan\n\n";
                addHistory("Mengambil Barang: " + stack.data[i].nama + " Sejumlah " + to_string(take));
                break;
            }
        }
    }
    if(!found){
        cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
    }
    getchar();
}

void addHistory(string activity){
    historyNode *add = new historyNode;
    add -> activity = activity;
    add -> next = head;
    head = add;
}

void showHistory(){
    cin.ignore();
    cout<<"\n\n====== Riwayat Aktivitas =======\n\n";
    if(head == NULL){
        cout<<"\nTidak Ada Aktivitas\n\n";
        getchar();
        return;
    }
    historyNode *now = head;
    while(now != NULL){
        cout<<"- "<<now -> activity<<endl;
        now = now -> next;
    }
    getchar();
}

void sortByName(){
    cin.ignore();
    if (empty()) {
        cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return;
    }else{
        for (int i = 0; i < stack.top; i++) {
            for (int j = 0; j < stack.top - i; j++) {
                if (toLowerCase(stack.data[j].nama) < toLowerCase(stack.data[j + 1].nama)) {
                    barangGudang temp = stack.data[j];
                    stack.data[j] = stack.data[j + 1];
                    stack.data[j + 1] = temp;
                }
            }
        }
    }
    addHistory("Mengurutkan Barang Berdasarkan Nama");
    cout << "\nBarang Selesai Diurutkan\n";
    show();
}

void sortBySmallest(){
    cin.ignore();
    if (empty()) {
        cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return;
    }else{
        for (int i = 0; i < stack.top; i++) {
            for (int j = 0; j < stack.top - i; j++) {
                if (stack.data[j].jumlah < stack.data[j + 1].jumlah) {
                    barangGudang temp = stack.data[j];
                    stack.data[j] = stack.data[j + 1];
                    stack.data[j + 1] = temp;
                }
            }
        }
    }
    addHistory("Mengurutkan Barang Berdasarkan Jumlah yang Terkecil");
    cout << "\nBarang Selesai Diurutkan\n";
    show();
}

void sortByLargest(){
     cin.ignore();
    if (empty()) {
        cout << "\nBelum Ada Data Barang!\n\n";
        getchar();
        return;
    }else{
        for (int i = 0; i < stack.top; i++) {
            for (int j = 0; j < stack.top - i; j++) {
                if (stack.data[j].jumlah > stack.data[j + 1].jumlah) {
                    barangGudang temp = stack.data[j];
                    stack.data[j] = stack.data[j + 1];
                    stack.data[j + 1] = temp;
                }
            }
        }
    }
    addHistory("Mengurutkan Barang Berdasarkan Jumlah yang Tebesar");
    cout << "\nBarang Selesai Diurutkan\n";
    show();
}