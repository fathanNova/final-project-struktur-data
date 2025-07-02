#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <iomanip>
#define max 50
using namespace std;

/// struct untuk menyimpan data barang
struct barangGudang{
    int id;
    string nama;
    int jumlah;
}barang;

struct stackBarang{
    barangGudang data[max];
    int top;
}stack;

/// Struct untuk Linked List
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
void sortByID();
void sorting();
void restock();
void takeByQuantity();
void addHistory(string activity);
void showHistory();

int main() {
    init();
    string choice; // untuk menampilkan menu pilihan
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
        if (choice == "1" ) {
                push();
        }else if (choice == "2"){
                show();
        }else if (choice == "3"){
                searching();
        }else if (choice == "4"){
                sorting();
        }else if (choice == "5"){
                restock();
        }else if (choice == "6"){
                takeByQuantity();
        }else if (choice == "7"){
                deleteByName();
        }else if (choice == "8"){
                showHistory();
        }else if(choice == "9"){
                cout <<"\nKeluar dari Program.\n\n";
                break;
        } else {
            cout << "\nPilihan Tidak Valid. Silahkan Coba Lagi.\n\n";
            getchar();
            cin.get();
        }
    }while(choice != "9");
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

/// Fungsi untuk mengubah semua karakter menjadi huruf kecil agar tidak terjadi error.
// transform dari library <algorithm> dan tolower dari library <cctype>
// transform akan mengubah karakter yang dimulai dari str.begin() hingga str.end() 
// (bisa dibilang satu kata utuh) lalu menyimpanya ke str.begin() ketiga dan diubah menggunakan tolower.
// tolower mengubah karakter sebagai input dan mengembalikannya dalam bentuk huruf kecil (lowercase)
string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void searching(){
    string choose;
    do{
        system("cls");
        cout<<"Pilih Metode Pencarian: \n\n";
        cout<<"1. Cari Barang Berdasarkan Nama\n";
        cout<<"2. Cari Barang Berdasarkan ID\n";
        cout<<"3. Kembali ke Menu\n";
        cout<<"\nMasukkan Pilihan Anda: "; cin>>choose;

        if(choose == "1"){
            searchByName();
        }else if(choose == "2"){
            searchById();
        
        }else if(choose == "3"){
            break;
        }else{
            cout<<"\nPilihan Tidak Valid!\n\n";
            getchar();
            cin.get();
        }
    }while(choose != "3");
}

void sorting(){
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
            sortByID();
            break;
        }else{
            cout<<"\nPilihan Tidak Valid!\n\n";
            getchar();
            cin.get();
        }
    }while(choose != "4");  
}

void show() {
    cin.ignore();
    cout << "\n======= Menampilkan Daftar Barang =======\n\n";
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
        cout << "\nMasukkan ID Barang yang Dicari: ";

        // Merupakan percabangan untuk mengecek input apakah bernilai integer atau bukan.
        // Bila input bukan berupa integer maka akan menjalankan perintah didalamnya.
        // cin.clear digunakan untuk membersihkan atau mereset staus error saat 'cin' gagal
        // membaca input sehingga 'cin' bisa digunakan lagi untuk operasi input selanjutnya.
        // cin.ignore(100, \n) digunakan untuk membuang karakter dari input buffer
        // 100 berarti mengabaikan 100 karakter, dan '\n' digunakan untuk berhenti mengabaikan
        // karakter jika menemukan karakter newline (pengguna menekan tombol Enter) 
        if(!(cin>>id)){
            cout<<"\nInput ID Harus dengan Angka\n\n";
            cin.clear();
            cin.ignore(100, '\n');
            getchar();
            return;
        }

        for (int i = 0; i <= stack.top; i++) {
            if (stack.data[i].id == id) { 
                cout << "\nBarang Ditemukan:\n";    
                cout << "ID     : " << stack.data[i].id <<endl;
                cout << "Nama   : " << stack.data[i].nama <<endl;
                cout << "Jumlah : " << stack.data[i].jumlah <<endl<<endl;
                found = true;
                break;
            }
        }
    }
    if (!found) { 
        cout << "\nBarang dengan ID '" << id << "' Tidak Ditemukan.\n\n";
    }
    cin.ignore();
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
                if(stack.data[i].jumlah < 0){
                    stack.data[i].jumlah += take;
                    cout<<"\nJumlah Maksimal yang Bisa Diambil adalah "<<stack.data[i].jumlah<<endl;
                    break;
                }
                

                cout<<"\nData Berhasil Disimpan\n\n";
                addHistory("Mengambil Barang: " + stack.data[i].nama + " Sejumlah " + to_string(take)); 
                // to_string digunakan untuk mengubah nilai dari tipe data int (take) menjadi string 
                break;
            }
        }
    }
    if(!found){
        cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
    }
    getchar();
}

// fungsi Linked List untuk menambahkan histori
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
    cout << "\nBarang Selesai Diurutkan\n";
    show();
}

void sortByID(){
    for (int i = 0; i < stack.top; i++) {
        for (int j = 0; j < stack.top - i; j++) {
            if (stack.data[j].id > stack.data[j + 1].id) {
                barangGudang temp = stack.data[j];
                stack.data[j] = stack.data[j + 1];
                stack.data[j + 1] = temp;
            }
        }
    }
}   