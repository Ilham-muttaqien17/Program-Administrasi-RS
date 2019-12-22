#ifndef PASIEN
#define PASIEN
#include <iostream>
#include <cstdio>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>

#define file_database "database_rumah_sakit.txt"


using namespace std;

struct _pasien {
	char antrean[8];
	char nama[32];
	char id[17];
	char kode[8];
	int umur;
	char alamat[64];
	char ttl[64];
};

int tambah_pasien(){
	

	FILE *handle;
	int latest_code;
	char buffer[1024],pilih;
	struct _pasien pasien,tmp;

	Tambah:

	system("cls");
	cout<<setw(59)<<"+++++++++++++++++++++++++++++++++++++\n";
	cout<<setw(59)<<"+++         TAMBAH PASIEN         +++\n";
	cout<<setw(59)<<"+++++++++++++++++++++++++++++++++++++\n";
	cout<<"\n"<<setw(38)<<"Input Data Pasien";
	cout<<"\n\n"<<setw(37)<<"+ Nama Pasien\t: ";
	fgets(pasien.nama , 31 , stdin);
	cout<<setw(32)<<"+ No ID\t\t: ";
	fgets(pasien.id , 63 , stdin);
	cout<<setw(37)<<"+ Umur Pasien\t: ";
	fgets(buffer, 1023 , stdin);
	pasien.umur = atoi(buffer);
	cout<<setw(39)<<"+ Alamat Pasien\t: ";
	fgets(pasien.alamat , 63 , stdin);
	cout<<setw(36)<<"+ TTL Pasien\t: ";
	fgets(pasien.ttl, 63, stdin);
	cout<<"\n"<<setw(56)<<"+++++++++++++++++++++++++++++++++\n\n";


	// if((*pasien.nama == 0xa && *(pasien.nama + 1 )== '\0') && (pasien.umur == '\0') && (*pasien.alamat == 0xa && *(pasien.alamat + 1 ) == '\0') && (*pasien.ttl == 0xa && *(pasien.ttl + 1 ) == '\0')){
	// 	cout<<"Inputan tidak boleh kosong";
	// 	getch();
	// 	goto Tambah;
	// }

	if(*pasien.nama == 0xa && *(pasien.nama + 1 )== '\0'){
		cout<<"\n"<<setw(47)<<"Inputan tidak boleh kosong";
		getch();
		goto Tambah;
	}
	if(*pasien.id == 0xa && *(pasien.id + 1 ) == '\0'){
		cout<<"\n"<<setw(47)<<"Inputan tidak boleh kosong";
		getch();
		goto Tambah;
	}

	// #define _nik (sizeof(pasien.nik))

	// if(*pasien.nik > _nik){
	// 	cout<<"NIK harus 16 Digit!";
	// 	getch();
	// 	goto Tambah;
	// }
	if(pasien.umur == '\0'){
		cout<<"\n"<<setw(47)<<"Inputan tidak boleh kosong";
		getch();
		goto Tambah;
	}
	if(*pasien.alamat == 0xa && *(pasien.alamat + 1 ) == '\0'){
		cout<<"\n"<<setw(47)<<"Inputan tidak boleh kosong";
		getch();
		goto Tambah;
	}
	if(*pasien.ttl == 0xa && *(pasien.ttl + 1 ) == '\0'){
		cout<<"\n"<<setw(47)<<"Inputan tidak boleh kosong";
		getch();
		goto Tambah;
	}


	pasien.nama[strlen(pasien.nama) - 1] = '\0';
	pasien.id[strlen(pasien.id) - 1] = '\0';
	pasien.alamat[strlen(pasien.alamat) - 1] = '\0';
	pasien.ttl[strlen(pasien.ttl) - 1] = '\0';

	
	
	cout<<setw(46)<<"BIODATA PASIEN\n\n";
	
	cout<<setw(37)<<"+ Nama Pasien\t: "<<pasien.nama<<"\n";
	cout<<setw(38)<<"+ No ID Pasien\t: "<<pasien.id<<"\n";
	cout<<setw(37)<<"+ Umur Pasien\t: "<<pasien.umur<<"\n";
	cout<<setw(39)<<"+ Alamat Pasien\t: "<<pasien.alamat<<"\n";
	cout<<setw(36)<<"+ TTL Pasien\t: "<<pasien.ttl<<"\n";
	cout<<"\n"<<setw(42)<<"Simpan data? [y/n] : ";
	cin>>pilih;

	if(pilih == 'Y' || pilih == 'y'){
		handle = fopen(file_database, "r");
		if(handle == NULL){
			strcpy(pasien.kode , "000001A");
		}else{
			while(!feof(handle)){
				fread (&tmp , sizeof(struct _pasien), 1 , handle);
			}
			latest_code = atoi(tmp.kode) + 1;
			sprintf(pasien.kode, "%06dA", latest_code);
		}
		fclose(handle);

		handle = fopen(file_database, "a");
		fwrite(&pasien, sizeof(pasien), 1, handle);
		fclose(handle);

		cout<<"\n"<<setw(55)<<"=================================\n";
		cout<<setw(41)<<"===== Kode Pasien : "<<pasien.kode<<" =====\n";
		cout<<setw(55)<<"=================================\n";
		cout<<"\n"<<setw(48)<<"Data Berhasil disimpan";
		getch();
	}else{
		cout<<"\n"<<setw(48)<<"Silahkan Ulangi Pengisian Data";
		cin.ignore();
		getch();

		goto Tambah;
	}

	return 0;
}
#endif //