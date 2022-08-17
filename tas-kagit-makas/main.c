#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int karsilastir(int a,int b){//fonksiyonu tanimliyoruz. islemleri yapacak.
if (a==b){ //(tas=1,kagit=2,makas=3)(a=insan,b=bilgisayar)
    return 0;
}
else if (a==1&&b==2){
    return 2;
}
else if (a==1&&b==3){
    return 1;
}                       //0=berabere 1=insan kazandi 2=pc kazandi gonderiyor.
else if (a==2&&b==1){
    return 1;
}
else if (a==2&&b==3){
    return 2;
}
else if (a==3&&b==1){
    return 2;
}
else if (a==3&&b==2){
    return 1;
}
}
int random_yap(int r){ //rastgele bir sayi verme fonksiyonu
    srand(time(NULL));
    return rand()%r+1; //rastgele sayi alinip 3 ile modu aliniyor. Bulunan degere 1 eklenip gonderiliyor.
}
int main()
{
int pc_skor=0,insan_skor=0,a,b;
char arrinsan[50],arrpc[50]; //yapilan tercihler bir diziye kaydediliyor.
char karsilik[]={'t','k','m'}; // tercihin sonucunu yazdirmak için bir dizi olusturdum
char pc_tercih,insan_tercih;
printf("----Tas Kagit Makas Oyununa Hos Geldiniz----\n");
printf("+++++ 5 Puan  Olan Kazanir +++++\n\n");
printf("<<<<<<<<Hazirsaniz Baslayalim>>>>>>>>\n");
for (int i=0;i<50;i++){ //dongu olusturuluyor
    printf("Tas=1,Kagit=2,Makas=3'tur\n\n");
    printf("Hamlenizi seciniz: (1,2,3)???\n");
    scanf("%d",&a);
    if ((a<1) || (a>3)){
        printf("Lutfen 1 ile 3 arasinda bir deger giriniz...\n"); //Baska bir deger girilirse uyari veriyor.
        scanf("%d",&a);
        insan_tercih=karsilik[a-1];//yapilan tercih harfe donusturuluyor.
        arrinsan[i]=insan_tercih;//diziye kaydediliyor
        printf("Bunu Sectiniz=%c\n\n",insan_tercih);
    }
    else {
        insan_tercih=karsilik[a-1];
        arrinsan[i]=insan_tercih;
        printf("Bunu Sectiniz=%c\n\n",insan_tercih);
    }
    printf("Simdi Bilgisayar Seciyor...\n\n");
    b=random_yap(3); // Fonkisyona 3 degeri gonderiliyor.
    pc_tercih=karsilik[b-1];
    arrpc[i]=pc_tercih;
    printf("PC Bunu Secti=%c\n\n",pc_tercih);

    if(karsilastir(a,b)==0){ //fonksiyon cagiriliyor.
        printf("Berabere\n\n");
    }
    else if (karsilastir(a,b)==1){ //donen sonuca gore puan veriliyor.
        printf("Kazandin\n\n");
        insan_skor++;
    }
    else if (karsilastir(a,b)==2){
        printf("PC kazandi\n\n");
        pc_skor++;
    }
if((insan_skor==5) || (pc_skor==5)){ //biri 5 olursa oyun bitiyor.
        break;
    }
}
printf("<<<<OYUN BITTI>>>>\n");
printf("----KAZANAN ACIKLANIYOR----\n");
if (insan_skor>pc_skor){
    printf("Kazandin\n\n");
    printf("Insan Puan=%d,PC Puan=%d\n\n",insan_skor,pc_skor);
}
else if (insan_skor<pc_skor){
    printf("PC Kazandi\n\n");
    printf("Insan Puan=%d,  PC Puan=%d\n\n",insan_skor,pc_skor);
    }
printf("Senin Tercihlerin={%s}\n\n",arrinsan); //tum yapilan tercihler ekrana bastiriliyor.
printf("PC'nin tercihler={%s}\n\n",arrpc);
    return 0;
}
