#include "pustaka.h"

/*
Nama : Latief Setiadi
NIM  : A11.2018.11376
program : Project uas membuat struct serta operasi file
*/

int main()
{

mahasiswa mhs[256];
    int tanya=1;
    int x=0;
    int menu=0;
    int bats=0;
    int count=0;
    int pilihan;
    int batasfile;
    char carinama[30];
    char carinim[30];

while(menu==0)
{
printf("Masuk menu\n");
printf("1.input data  \n");
printf("2.Cetak data\n");
printf("3.cari data berdasarkan nama dan nim \n");
printf("4.urutkan data \n");
printf("5.Simpan data \n");
printf("6.Baca data\n");
printf("7.Keluar \n");
printf(" : "); scanf("%d",&pilihan);
    switch(pilihan)
    {
    case 1: printf("Input data\n");
            input(mhs,x,&bats);
            x++;
            break;
    case 2: output(mhs,x);
            break;
    case 3: printf("Proses pencarian\n");
            printf("Masukan nama : \n"); fflush(stdin); gets(carinama);
            printf("Masukan NIM  : \n"); fflush(stdin); gets(carinim);
            if(count==0)
            {
            searching(mhs,x,carinama,carinim);
            }
            else{
                SearchingFile(mhs,bats,carinama,carinim);
                count=0;
            }
            break;

    case 4: printf("\nProses Sorting berdasarkan nama dan semester akan dimulai\n");
            system("pause");
            selectionSort(mhs,x);
            output(mhs,x);
            printf("~Data Sukses diurutkan~\n\n");
            break;

    case 5: savefile(mhs,x,bats);
            printf("~Data telah disimpan~\n\n");
            break;

    case 6:readfile(mhs,&bats);
            count=1;
            output(mhs,bats);
            break;

    case 7:printf("~Terima Kasih~\n");
           menu=1;
           break;
    }
}



    return 0;
}
