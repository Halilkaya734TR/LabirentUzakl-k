#include <stdlib.h>
#include <stdio.h>

int main()
{
    int bolgesayisi;
    int sinirx, siniry; //Sınırlar
    int konumx, konumy; //Konumumuz
    struct konum // Diğer bölgelerin konumu ve mesafesi
    {
        int x;
        int y;
        int mesafe;
    };
   
    printf("x ve y sinirlarini giriniz!\n");
    scanf("%d%d",&sinirx,&siniry);
    
    if(sinirx < 0 || siniry < 0) // Eğer konum negatif girilirse hata verir.
    {
        printf("Hata Kodu 0:Negatif sınır girilemez!");
        return 0;
    }
    
    printf("Kaç Bölge girilecek?\n");
    scanf("%d",&bolgesayisi);
    
    if(bolgesayisi <=0) //Eğer bölge sayısı 0 ya da negatifse hata verir.
    {
        printf("Hata Kodu 1:Bölge sayisi negatif veya 0 olamaz!");
        return 0;
    }
    
    struct konum *konumlar = malloc(bolgesayisi * 3 * sizeof(int)); //malloc ile bellek tahsis edilir. Bölge sayısı ve 3 tane parametre 
//                                                                    olduğundan (x,y,mesafe) bolgesayısı * 3 * sizeof(int) kullandım.

    if(konumlar == NULL) //Bellek tahsis edilemezse verilecek hata
    {
        printf("Hata Kodu -1:Bellek tahsis edilemedi!");
        return 0;
    }
    
    printf("Konumunuzun kordinatını giriniz!\n");
    scanf("%d%d",&konumx,&konumy);
    
    if(konumx < 0 || konumy < 0 || konumx > sinirx || konumy > siniry) //Konumumuz negatif ya da sınırdan büyük olursa hata verir.
    {
        printf("Hata Kodu 2: Konum negatif ya da sınırlardan büyük olamaz!");
        return 0;
    }
    for(int i=0; i<bolgesayisi;i++)
    {
        printf("%d. Bölgenin konumlarını giriniz!\n",i+1);
        scanf("%d%d",&konumlar[i].x,&konumlar[i].y);
        
        if(konumlar[i].x < 0 || konumlar[i].x > sinirx || konumlar[i].y < 0 || konumlar[i].y > siniry) //Konumlar negatif ya da 
        //                                                                                               sınırdan büyük olamaz.
        {
            printf("Hata Kodu 3:Bölgeniz negatif ya da sınırlardan büyük olamaz!");
            return 0;
        }

    }

    for(int i=0; i<bolgesayisi;i++) //Manhattan yöntemine göre mesafe bulur. Öklid de karekök alma mantığını çözemedim.
    {
        if(konumx > konumlar[i].x && konumy> konumlar[i].y)
        {
            konumlar[i].mesafe = konumx - konumlar[i].x + konumy - konumlar[i].y;
        }
        
        else if(konumx > konumlar[i].x && konumy < konumlar[i].y)
        {
            konumlar[i].mesafe = konumx - konumlar[i].x + konumlar[i].y - konumy;
        }

        else if(konumx < konumlar[i].x && konumy < konumlar[i].y)
        {
            konumlar[i].mesafe = konumlar[i].x - konumx + konumlar[i].y - konumy;
        }
        
        else
        {
            konumlar[i].mesafe = konumlar[i].x - konumx + konumy - konumlar[i].y;
        }

    }

    for(int i=0; i<bolgesayisi;i++) //Bölgeleri yazdırır.
    {
        printf("%d.Bölgeye uzaklık(%d,%d):%d \n",i+1,konumlar[i].x,konumlar[i].y,konumlar[i].mesafe);
    }

    int enyakin[4]; //En yakın bölgenin verilerini yedeklemek için.
    int enuzak[4]; //En uzak bölgenin verilerini yedeklemek için.

    enyakin[0] = 1;                     //Bölge numarası yedekler.
    enyakin[1] = konumlar[0].x;         //Bölgenin x kordinatını yedekler.
    enyakin[2] = konumlar[0].y;         // Bölgenin y kordinatını yedekler.
    enyakin[3] = konumlar[0].mesafe;    //Bölgenin mesafe değerini yedekler.
    
    for(int i=0; i<bolgesayisi-1;i++)
    {
        if(konumlar[i].mesafe > konumlar[i+1].mesafe) //Karşılaştırır ve en küçüğü yedekler.
        {
            enyakin[0] = i+2;
            enyakin[1] = konumlar[i+1].x;
            enyakin[2] = konumlar[i+1].y;
            enyakin[3] = konumlar[i+1].mesafe;
        }
    }
    
    // Üstteki yedeklemeyle aynı mantık.
    enuzak[0] = 1;
    enuzak[1] = konumlar[0].x;
    enuzak[2] = konumlar[0].y;
    enuzak[3] = konumlar[0].mesafe;
    
    for(int i=0; i<bolgesayisi-1;i++)
    {
        if(konumlar[i].mesafe < konumlar[i+1].mesafe) // Karşılaştırır ve en büyüğü yedekler.
        {
            enuzak[0] = i+2;
            enuzak[1] = konumlar[i+1].x;
            enuzak[2] = konumlar[i+1].y;
            enuzak[3] = konumlar[i+1].mesafe;
        }
    }

    printf("En Yakın Yer: %d.Bölge(%d,%d):%d\n",enyakin[0],enyakin[1],enyakin[2],enyakin[3]);
    printf("En Uzak Yer: %d.Bölge(%d,%d):%d\n",enuzak[0],enuzak[1],enuzak[2],enuzak[3]);
    printf("Hesaplamalar Manhattan yöntemine göre yapılmıştır!!!");

    free(konumlar);
}