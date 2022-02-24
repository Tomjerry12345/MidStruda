#include <iostream>
#include<conio.h>
#include<windows.h>
#include <stdio.h>
using namespace std;

int pil , data , terbesar;
float rata , jumlah;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void tampil();

struct simpul{
 int data;
 struct simpul *next;
}mhs, *baru, *awal=NULL, *akhir=NULL, *bantu;

void clrscr(){
 system("cls");
}

int main(){
 do{
  clrscr();
  cout << "MENU SINGLE  LINKEDLIST" << endl;
  cout << "1.Tambah Data" << endl;
  cout << "2. Tampil" << endl;
  cout << "3. Selesai" << endl;
  cout << "Pilihan anda: ";
  cin>>pil;
  pilih();
 }while (pil!=3);
 return 0;
}

void pilih(){
 if(pil==1){
  buat_baru();
 }
 else if(pil==2){
  tampil();
 }
}


void tambah_belakang(){
 if(awal==NULL){
  awal=baru;
 }
 else{ 
  akhir->next=baru;
 }
 akhir=baru;
 akhir->next=NULL;
 cout << endl << endl;
 tampil();
}

void tambah_depan(){
 if(awal==NULL){
  awal=baru;
  akhir=baru;
  akhir->next=NULL;
 }
 else{
  baru->next=awal;
  awal=baru;
 }
 cout << endl << endl;
 tampil();
}

void buat_baru(){
 baru=(simpul*)malloc(sizeof(struct simpul));
 cout << "Input Data : ";
 cin >> data;
 
 if (data > terbesar)
 {
 	terbesar = data;
 	baru->data = terbesar;
 	baru->next=NULL;
 	rata = rata + baru->data;
 	jumlah++;
 	tambah_belakang();
 } else {
 	terbesar = data;
 	baru->data = data;
 	baru->next=NULL;
 	rata = rata + baru->data;
 	jumlah++;
 	tambah_depan();
 }
 
 
}


void tampil(){
 if(awal==NULL){
  cout << "Kosong";
 }
 else{
  bantu=awal;
  while(bantu!=NULL){
   cout << bantu->data<< " ";
   bantu=bantu->next;
    
  }
  cout << endl;
  cout << "Total data : " << rata << endl;
  cout << "Jumlah data : " << jumlah << endl;
  cout << "rata - rata = " << rata / jumlah << endl;
  
 }

 getch();
}
