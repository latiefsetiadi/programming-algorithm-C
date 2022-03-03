#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char matkul[50];
    char dosen[50];
    char kelompok[20];
    int sks;
    float nilai_tugas;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    char status_uts[2];
    char status_uas[2];
    char predikat_uts[5];
    char predikat_uas[5];
    char predikat_nilaiakhir[5];
}khs;

typedef struct{
    char nama[50];
    char nim[30];
    char jurusan[20];
    int semester;
    int jum_sks;
    int index;
    float ip;
    khs KHS[20];
}mahasiswa;

  FILE *arsipfile;

void selectionSort(mahasiswa mhs[],int x);
void predikatuts(mahasiswa mhs[],int x,int y);
void predikatuas(mahasiswa mhs[],int x,int y);
void ip(mahasiswa mhs[],int x,int y);
#endif // PUSTAKA_H_INCLUDED
