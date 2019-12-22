#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include "tambah_pasien.cpp"

#define file_database "database_rumah_sakit.txt"


using namespace std;

int daftar_pasien(){
	system("cls");
	FILE *handle;
	int i=1;
	struct _pasien pasien;

	cout<<setw(56)<<"+++++++++++++++++++++++++++++++++\n";
	cout<<setw(56)<<"++        DAFTAR PASIEN        ++\n";
	cout<<setw(57)<<"+++++++++++++++++++++++++++++++++\n\n";

	handle = fopen(file_database,"r");
	if(handle == NULL){
		cout<<"Database Kosong";
	}else{
		while(!feof(handle)){
			if(fread(&pasien , sizeof(pasien), 1, handle) == 0) break;
			cout<<setw(23)<<i<<". ";
			cout<<"Nama Pasien\t: "<<pasien.nama<<endl;
			cout<<setw(40)<<"   No ID Pasien\t: "<<pasien.id<<endl;
			cout<<setw(39)<<"   Umur Pasien\t: "<<pasien.umur<<endl;
			cout<<setw(41)<<"   Alamat Pasien\t: "<<pasien.alamat<<endl;
			cout<<setw(38)<<"   TTL Pasien\t: "<<pasien.ttl<<endl;
			cout<<"\n";
			i++;
		}
		cout<<setw(54)<<"Press Enter to Back to Main Menu !";
	}
	getch();
	return 0;
}