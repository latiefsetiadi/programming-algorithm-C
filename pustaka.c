#include "pustaka.h"

void input(mahasiswa mhs[],int x,int *bts)
{
    int tanya=1,sum=0,kurang;
    mhs[x].index=0;
    fflush(stdin);
    printf("======================================\n");
    printf("Mahasiswa ke - %d\n",x+1);
    printf("Nama     : "); gets(mhs[x].nama);
    printf("NIM      : "); gets(mhs[x].nim);
    printf("Jurusan  : "); gets(mhs[x].jurusan);
    printf("Semester : "); scanf("%d",&mhs[x].semester);
    printf("Jumlah sks yang diambil : "); scanf("%d",&mhs[x].jum_sks);
    printf("Proses Input mata kuliah\n");
   // fprintf(arsipfile,"\n%s\n%s\n%s %d\n%s %d\n",mhs[x].nama,mhs[x].nim,"Semeseter",mhs[x].semester,"Jumlah SKS",mhs[x].jum_sks);
   // fprintf(arsipfile,"%s\t%s\t%s\t\t%s\n","Matkul","SKS","Nilai UTS","Nilai UAS");
    printf("--------------------------------------\n");
    while(sum<mhs[x].jum_sks)
    {
        fflush(stdin);
        printf("Mata Kuliah    : "); gets(mhs[x].KHS[mhs[x].index].matkul);
        printf("Nama dosen     : "); gets(mhs[x].KHS[mhs[x].index].dosen);
        printf("Kelompok kelas : "); gets(mhs[x].KHS[mhs[x].index].kelompok);
        printf("SKS         : "); scanf("%d",&mhs[x].KHS[mhs[x].index].sks);
        printf("Nilai Tugas : "); scanf("%f",&mhs[x].KHS[mhs[x].index].nilai_tugas);
        printf("Nilai UTS   : "); scanf("%f",&mhs[x].KHS[mhs[x].index].nilai_uts);
       printf("Status uts (u : v:) ");fflush(stdin); gets(mhs[x].KHS[mhs[x].index].status_uts);

    predikatuts(mhs,x,mhs[x].index);
        printf("Nilai UAS   : "); scanf("%f",&mhs[x].KHS[mhs[x].index].nilai_uas);
        printf("Status UAS (u : v:) "); fflush(stdin); gets(mhs[x].KHS[mhs[x].index].status_uas);
        fflush(stdin);
    predikatuas(mhs,x,mhs[x].index);
mhs[x].KHS[mhs[x].index].nilai_akhir=(0.4*mhs[x].KHS[mhs[x].index].nilai_tugas)+(0.3*mhs[x].KHS[mhs[x].index].nilai_uts)+(0.3*mhs[x].KHS[mhs[x].index].nilai_uas);
       fflush(stdin);
       predikatnilaiakhir(mhs,x,mhs[x].index);

sum=sum+mhs[x].KHS[mhs[x].index].sks;
kurang=mhs[x].jum_sks-sum;
printf("SKS yang anda input kurang %d sks \n\n",kurang);
mhs[x].index=mhs[x].index + 1;

    }

*bts=*bts+1;
    ips(mhs,x,mhs[x].index);
     printf("======================================\n");

}


void output(mahasiswa mhs[],int x)
{
    int a=0;
    int b;
    while(a<x)
    {
        printf("~Mahasiswa \n");
        printf("Nama     : %s\n",mhs[a].nama);
        printf("NIM      : %s\n",mhs[a].nim);
        printf("Jurusan  : %s\n",mhs[a].jurusan);
        printf("semester : %d\n",mhs[a].semester);
        printf("\n====Daftar Nilai :=====\n");
        b=0;
        while(b<mhs[a].index)
        {
            printf("~Mata kuliah %d~\n",b+1);
            printf("Mata kuliah : %s\n",mhs[a].KHS[b].matkul);
            printf("Dosen       : %s\n",mhs[a].KHS[b].dosen);
            printf("Kelompok    : %s\n",mhs[a].KHS[b].kelompok);
            printf("SKS         : %d\n",mhs[a].KHS[b].sks);
            printf("|Nilai Tugas| |Nilai UTS| |u/v| |Nilai UAS| |u/v| |Nilai Akhir| \n");
            printf("    %.2f        %.2f:%s   %s ",mhs[a].KHS[b].nilai_tugas,mhs[a].KHS[b].nilai_uts,mhs[a].KHS[b].predikat_uts,mhs[a].KHS[b].status_uts);
            printf("    %.2f:%s   %s     %.2f:%s ",mhs[a].KHS[b].nilai_uas,mhs[a].KHS[b].predikat_uas,mhs[a].KHS[b].status_uas,mhs[a].KHS[b].nilai_akhir,mhs[a].KHS[b].predikat_nilaiakhir);
           printf("\n~~~~~~\n");
            b++;

        }
        printf("\t IPS : %.2f\n",mhs[a].ip);
        printf("\n\n");
        a++;
    }
}

void selectionSort(mahasiswa mhs[],int x)
{
    int a=0;
    int idx;
    int b;
    while(a<x)
    {
        idx=a;
        b=a;
        while(b<x)
        {
            if(strcmp(mhs[idx].nama,mhs[b].nama)>0)
            {
                idx=b;
            }
            else if(strcmp(mhs[idx].nama,mhs[b].nama)==0)
            {
                if(mhs[idx].semester>mhs[b].semester)
                {
                    idx=b;
                }
            }
            b++;
        }
        swap(&mhs[idx],&mhs[a]);
        a++;
    }
}

void swap(mahasiswa *data1,mahasiswa *data2)
{
    mahasiswa tmp;
    tmp=*data1;
    *data1=*data2;
    *data2=tmp;
}


void predikatuts(mahasiswa mhs[],int x,int y)
{
        if((mhs[x].KHS[y].nilai_uts>=85) && (mhs[x].KHS[y].nilai_uts<=100))
        {
            strcpy(mhs[x].KHS[y].predikat_uts," A ");
        }
        else if((mhs[x].KHS[y].nilai_uts>=80) && (mhs[x].KHS[y].nilai_uts<85))
        {
            strcpy(mhs[x].KHS[y].predikat_uts," AB ");
        }
        else if((mhs[x].KHS[y].nilai_uts>=70) && (mhs[x].KHS[y].nilai_uts<80))
        {
            strcpy(mhs[x].KHS[y].predikat_uts," B ");
        }
        else if((mhs[x].KHS[y].nilai_uts>=65) && (mhs[x].KHS[y].nilai_uts<70))
        {
            strcpy(mhs[x].KHS[y].predikat_uts," BC ");
        }
        else if((mhs[x].KHS[y].nilai_uts>=60) && (mhs[x].KHS[y].nilai_uts<65))
        {
            strcpy(mhs[x].KHS[y].predikat_uts," C ");
        }
        else if(mhs[x].KHS[y].nilai_uts<60)
        {
            strcpy(mhs[x].KHS[y].predikat_uts," D ");
        }


}
void searching(mahasiswa mhs[],int x,char name[],char nem[])
{
    int a=0;
    int b,jum=0;
    while(a<x)
    {
        if(strcmp(mhs[a].nama,name)==0)
        {
            if(strcmp(mhs[a].nim,nem)==0)
            {
        printf("Nama     : %s\n",mhs[a].nama);
        printf("NIM      : %s\n",mhs[a].nim);
        printf("Jurusan  : %s\n",mhs[a].jurusan);
        printf("semester : %d\n",mhs[a].semester);
        printf("\n====Daftar Nilai :=====\n");
        b=0;
        while(b<mhs[a].index)
        {
            printf("~Mata kuliah %d~\n",b+1);
            printf("Mata kuliah : %s\n",mhs[a].KHS[b].matkul);
            printf("Dosen       : %s\n",mhs[a].KHS[b].dosen);
            printf("Kelompok    : %s\n",mhs[a].KHS[b].kelompok);
            printf("SKS         : %d\n",mhs[a].KHS[b].sks);
            printf("|Nilai Tugas| | Nilai UTS | |u/v| |Nilai UAS| |u/v| |Nilai Akhir| \n");
            printf("    %.2f        %.2f:%s   %s ",mhs[a].KHS[b].nilai_tugas,mhs[a].KHS[b].nilai_uts,mhs[a].KHS[b].predikat_uts,mhs[a].KHS[b].status_uts);
            printf("    %.2f:%s   %s     %.2f:%s ",mhs[a].KHS[b].nilai_uas,mhs[a].KHS[b].predikat_uas,mhs[a].KHS[b].status_uas,mhs[a].KHS[b].nilai_akhir,mhs[a].KHS[b].predikat_nilaiakhir);
           printf("\n");
            b++;

        }
        printf("\t\t IPS : %.2f\n",mhs[a].ip);
        jum++;

            }
        }
        a++;
    }
    printf("Data yang ditemukan sebanyak %d data\n",jum);

}
void predikatuas(mahasiswa mhs[],int x,int y)
{

    if((mhs[x].KHS[y].nilai_uas>=85)&&(mhs[x].KHS[y].nilai_uas<=100))
        {
            strcpy(mhs[x].KHS[y].predikat_uas," A ");
        }
        else if((mhs[x].KHS[y].nilai_uas>=80)&&(mhs[x].KHS[y].nilai_uas<85))
        {
            strcpy(mhs[x].KHS[y].predikat_uas," AB ");
        }
        else if((mhs[x].KHS[y].nilai_uas>=70)&&(mhs[x].KHS[y].nilai_uas<80))
        {
            strcpy(mhs[x].KHS[y].predikat_uas," B ");
        }
        else if((mhs[x].KHS[y].nilai_uas>=65)&&(mhs[x].KHS[y].nilai_uas<70))
        {
            strcpy(mhs[x].KHS[y].predikat_uas," BC ");
        }
        else if((mhs[x].KHS[y].nilai_uas>=60)&&(mhs[x].KHS[y].nilai_uas<65))
        {
            strcpy(mhs[x].KHS[y].predikat_uas," C ");
        }
        else if(mhs[x].KHS[y].nilai_uas<60)
        {
            strcpy(mhs[x].KHS[y].predikat_uas," D ");
        }
}


void predikatnilaiakhir(mahasiswa mhs[],int x,int y)
{
        if((mhs[x].KHS[y].nilai_akhir>=85) && (mhs[x].KHS[y].nilai_akhir<=100))
        {
            strcpy(mhs[x].KHS[y].predikat_nilaiakhir," A ");
        }
        else if((mhs[x].KHS[y].nilai_akhir>=80) && (mhs[x].KHS[y].nilai_akhir<85))
        {
            strcpy(mhs[x].KHS[y].predikat_nilaiakhir," AB ");
        }
        else if((mhs[x].KHS[y].nilai_akhir>=70) && (mhs[x].KHS[y].nilai_akhir<80))
        {
            strcpy(mhs[x].KHS[y].predikat_nilaiakhir," B ");
        }
        else if((mhs[x].KHS[y].nilai_akhir>=65) && (mhs[x].KHS[y].nilai_akhir<70))
        {
            strcpy(mhs[x].KHS[y].predikat_nilaiakhir," BC ");
        }
        else if((mhs[x].KHS[y].nilai_akhir>=60) && (mhs[x].KHS[y].nilai_akhir<65))
        {
            strcpy(mhs[x].KHS[y].predikat_nilaiakhir," C ");
        }
        else if(mhs[x].KHS[y].nilai_akhir<60)
        {
            strcpy(mhs[x].KHS[y].predikat_nilaiakhir," D ");
        }


}

void ips(mahasiswa mhs[],int x,int y)
{
    int a=0;
    float nilaisementara=0;
    float nilaitotal=0;
    while(a<y)
    {

    if(strcmp(mhs[x].KHS[a].predikat_nilaiakhir," A ")==0)
    {
        nilaisementara=mhs[x].KHS[a].sks*4;
    }
   else if(strcmp(mhs[x].KHS[a].predikat_nilaiakhir," AB ")==0)
    {
        nilaisementara=mhs[x].KHS[a].sks*3.5;
    }
   else if(strcmp(mhs[x].KHS[a].predikat_nilaiakhir," B ")==0)
    {
        nilaisementara=mhs[x].KHS[a].sks*3;
    }
   else if(strcmp(mhs[x].KHS[a].predikat_nilaiakhir," BC ")==0)
    {
        nilaisementara=mhs[x].KHS[a].sks*2.5;
    }
   else if(strcmp(mhs[x].KHS[a].predikat_nilaiakhir," C ")==0)
    {
        nilaisementara=mhs[x].KHS[a].sks*2;
    }
   else if(strcmp(mhs[x].KHS[a].predikat_nilaiakhir," D ")==0)
    {
        nilaisementara=mhs[x].KHS[a].sks*1.5;
    }

    nilaitotal=nilaitotal+nilaisementara;
    a++;

    }
    mhs[x].ip=nilaitotal/mhs[x].jum_sks;
}


void savefile(mahasiswa mhs[],int x,int bts)
{
    int a=0;
    arsipfile=fopen("ArsipFile.txt","w");
    int b;
    fprintf(arsipfile,"%d\n",bts);
    while(a<x)
    {
        fprintf(arsipfile,"%s\n",mhs[a].nama);
        fprintf(arsipfile,"%s\n",mhs[a].nim);
        fprintf(arsipfile,"%s\n",mhs[a].jurusan);
        fprintf(arsipfile,"%d\n",mhs[a].semester);
        fprintf(arsipfile,"%d\n",mhs[a].index);
        b=0;
        while(b<mhs[a].index)
        {
            fprintf(arsipfile,"%s\n",mhs[a].KHS[b].matkul);
            fprintf(arsipfile,"%s\n",mhs[a].KHS[b].dosen);
            fprintf(arsipfile,"%s\n",mhs[a].KHS[b].kelompok);
            fprintf(arsipfile,"%d\n",mhs[a].KHS[b].sks);
            fprintf(arsipfile,"\t%.2f\t%.2f\t%s\t%s",mhs[a].KHS[b].nilai_tugas,mhs[a].KHS[b].nilai_uts,mhs[a].KHS[b].predikat_uts,mhs[a].KHS[b].status_uts);
            fprintf(arsipfile,"\t%.2f\t%s\t%s\t%.2f\t%s\n",mhs[a].KHS[b].nilai_uas,mhs[a].KHS[b].predikat_uas,mhs[a].KHS[b].status_uas,mhs[a].KHS[b].nilai_akhir,mhs[a].KHS[b].predikat_nilaiakhir);

            b++;

        }
        fprintf(arsipfile,"%.2f\n",mhs[a].ip);
        a++;
    }
fclose(arsipfile);
}

void readfile(mahasiswa mhs[],int *indexfile)
{
    int a=0;
    int b;
    arsipfile=fopen("ArsipFile.txt","r");
    if(!arsipfile)
    {
        printf("file tidak ada\n");
    }
    else{
    fscanf(arsipfile,"%d\n",&*indexfile);
    while(a<*indexfile)
    {
        //fflush(stdin);
        fscanf(arsipfile,"%[^\n]\n",&mhs[a].nama);
        fscanf(arsipfile,"%[^\n]\n",&mhs[a].nim);
        fscanf(arsipfile,"%[^\n]\n",&mhs[a].jurusan);
        fscanf(arsipfile,"%d\n",&mhs[a].semester);
        fscanf(arsipfile,"%d\n",&mhs[a].index);
      b=0;
      while(b<mhs[a].index)
        {
            //fflush(stdin);
            fscanf(arsipfile,"%[^\n]\n",&mhs[a].KHS[b].matkul);
            fscanf(arsipfile,"%[^\n]\n",&mhs[a].KHS[b].dosen);
            fscanf(arsipfile,"%[^\n]\n",&mhs[a].KHS[b].kelompok);
            fscanf(arsipfile,"%d\n",&mhs[a].KHS[b].sks);
            fscanf(arsipfile,"\t%f\t%f\t%[^\t]\t%[^\t]",&mhs[a].KHS[b].nilai_tugas,&mhs[a].KHS[b].nilai_uts,&mhs[a].KHS[b].predikat_uts,&mhs[a].KHS[b].status_uts);
            fscanf(arsipfile,"\t%f\t%[^\t]\t%[^\t]\t%f\t%[^\n]\n",&mhs[a].KHS[b].nilai_uas,&mhs[a].KHS[b].predikat_uas,&mhs[a].KHS[b].status_uas,&mhs[a].KHS[b].nilai_akhir,&mhs[a].KHS[b].predikat_nilaiakhir);

            b++;

        }
        fscanf(arsipfile,"%f\n",&mhs[a].ip);
        a++;
    }
    fclose(arsipfile);
    }
}

void SearchingFile(mahasiswa mhs[],int x,char name[],char nem[])
{
    int a=0;
    int b,jum=0;
    while(a<x)
    {
        if(strcmp(mhs[a].nama,name)==0)
        {
            if(strcmp(mhs[a].nim,nem)==0)
            {
        printf("Nama     : %s\n",mhs[a].nama);
        printf("NIM      : %s\n",mhs[a].nim);
        printf("Jurusan  : %s\n",mhs[a].jurusan);
        printf("semester : %d\n",mhs[a].semester);
        printf("\n====Daftar Nilai :=====\n");
        b=0;
        while(b<mhs[a].index)
        {
            printf("~Mata kuliah %d~\n",b+1);
            printf("Mata kuliah : %s\n",mhs[a].KHS[b].matkul);
            printf("Dosen       : %s\n",mhs[a].KHS[b].dosen);
            printf("Kelompok    : %s\n",mhs[a].KHS[b].kelompok);
            printf("SKS         : %d\n",mhs[a].KHS[b].sks);
            printf("|Nilai Tugas| | Nilai UTS | |u/v| |Nilai UAS| |u/v| |Nilai Akhir| \n");
            printf("    %.2f        %.2f:%s   %s ",mhs[a].KHS[b].nilai_tugas,mhs[a].KHS[b].nilai_uts,mhs[a].KHS[b].predikat_uts,mhs[a].KHS[b].status_uts);
            printf("    %.2f:%s   %s     %.2f:%s ",mhs[a].KHS[b].nilai_uas,mhs[a].KHS[b].predikat_uas,mhs[a].KHS[b].status_uas,mhs[a].KHS[b].nilai_akhir,mhs[a].KHS[b].predikat_nilaiakhir);
           printf("\n");
            b++;

        }
        printf("\t\t IPS : %.2f\n",mhs[a].ip);
        jum++;

            }
        }
        a++;
    }
    printf("Data yang ditemukan sebanyak %d data\n",jum);

}
