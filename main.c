#include <iostream>
using namespace std;
struct ihtiyaclar
{
        int cinko;
        int demir;
        int et;
        int su;
        int kum;
};
class AnaBina
{
    public:
        int anaBinaSeviye=1;
        int anaBinaGerekenPara=10;

};
class AskeriBina
{
    public:
        int askeriBinaSeviye=1;
        int askerEnerjisi=8;
        ihtiyaclar seviyeAtlamaAskeri;
        void askeriBinaSeviyeAtlamaIhtiyac()
        {
            seviyeAtlamaAskeri.cinko=askeriBinaSeviye*2+1;
            seviyeAtlamaAskeri.demir=askeriBinaSeviye*2-1;
            seviyeAtlamaAskeri.kum=askeriBinaSeviye*2+2;
            seviyeAtlamaAskeri.su=askeriBinaSeviye*2-2;
            seviyeAtlamaAskeri.et=askeriBinaSeviye*2-1;
        }
};
class ArastirmaBinasi
{
    public:
        int arastirmaBinasiSeviye=1;
        ihtiyaclar seviyeAtlamaArastirma;
        void arastirmaBinasiSeviyeAtlamaIhtiyac()
        {
            seviyeAtlamaArastirma.cinko=arastirmaBinasiSeviye*2+1;
            seviyeAtlamaArastirma.demir=arastirmaBinasiSeviye*2-1;
            seviyeAtlamaArastirma.kum=arastirmaBinasiSeviye*3-2;
            seviyeAtlamaArastirma.et=arastirmaBinasiSeviye+2;
            seviyeAtlamaArastirma.su=arastirmaBinasiSeviye+1;
        }

};
class Depo
{
    public:
        int Su=8;
        int Kum=10;
        int Demir=6;
        int Cinko=12;
        int Et=14;
};
class Karakter:public AnaBina, public AskeriBina, public ArastirmaBinasi, public Depo
{
public:
    int mevcutPara=10;
    void seviyeAtlaAnaBina()
    {
        if(mevcutPara>=anaBinaGerekenPara)
        {
            cout<< "Ana Bina Seviyesi Basariyla Yukseltildi."<<endl;
            anaBinaSeviye=anaBinaSeviye+1;
            mevcutPara=mevcutPara-anaBinaGerekenPara;
            anaBinaGerekenPara=anaBinaGerekenPara+3;
        }
        else
        {
            cout<< "Yeteri kadar paraniz bulunmamaktadir.!"<<endl;
        }
    }
    void statuGoruntule()
    {
        cout<<"Su: "<<Su<<endl;
        cout<<"Kum: "<<Kum<<endl;
        cout<<"Demir: "<<Demir<<endl;
        cout<<"Cinko: "<<Cinko<<endl;
        cout<<"Et: "<<Et<<endl;
        cout<< "Mevcut Para: "<<mevcutPara<<endl;
        cout<< "Asker Enerjisi: "<<askerEnerjisi<<endl;
        cout<< "Ana Bina Seviye: "<<anaBinaSeviye<<endl;
        cout<< "Askeri Bina Seviye: "<<askeriBinaSeviye<<endl;
        cout<< "Arastirma Bina Seviye: "<<arastirmaBinasiSeviye<<endl;
    }
    void seviyeAtlaArastirmaBinasi()
    {
        arastirmaBinasiSeviyeAtlamaIhtiyac();
        if(Su>=seviyeAtlamaArastirma.su && Kum>=seviyeAtlamaArastirma.kum && Demir>seviyeAtlamaArastirma.demir && Cinko>=seviyeAtlamaArastirma.cinko && Et>=seviyeAtlamaArastirma.et)
        {
            cout<< "Arastirma Binasi Seviyesi Basariyla Artirildi"<<endl;
            Su=Su-seviyeAtlamaArastirma.su;
            Kum=Kum-seviyeAtlamaArastirma.kum;
            Demir=Demir-seviyeAtlamaArastirma.demir;
            Cinko=Cinko-seviyeAtlamaArastirma.cinko;
            Et=Et-seviyeAtlamaArastirma.et;
            arastirmaBinasiSeviye=arastirmaBinasiSeviye+1;
        }
        else
        {
            cout<< "Malzeme eksikliginden dolayi seviye yukseltilemedi."<<endl;
        }
    }
    void seviyeAtlaAskeriBina()
    {
        askeriBinaSeviyeAtlamaIhtiyac();
        if(Su>=seviyeAtlamaAskeri.su && Kum>=seviyeAtlamaAskeri.kum && Demir>seviyeAtlamaAskeri.demir && Cinko>=seviyeAtlamaAskeri.cinko && Et>=seviyeAtlamaAskeri.et)
        {
            cout<< "Askeri Bina Seviyesi Basariyla Artirildi."<<endl;
            Su=Su-seviyeAtlamaAskeri.su;
            Kum=Kum-seviyeAtlamaAskeri.kum;
            Demir=Demir-seviyeAtlamaAskeri.demir;
            Cinko=Cinko-seviyeAtlamaAskeri.cinko;
            Et=Et-seviyeAtlamaAskeri.et;
            askeriBinaSeviye=askeriBinaSeviye+1;
        }
        else
        {
            cout<< "Malzeme eksikliginden dolayi seviye yukseltilemedi."<<endl;
        }
    }

    void askerEnerjisiDoldur()
    {
        if(Et>=askeriBinaSeviye+4)
        {
            askerEnerjisi=askerEnerjisi+4+arastirmaBinasiSeviye;
            Et=Et-askeriBinaSeviye-4;
            cout<< "Asker enerjileri dolduruldu.!"<<endl;
        }
        else
        {
            cout<< "Yeteri kadar Et bulunmamaktadir.!"<<endl;
        }
    }
    void gollomKes()
    {
        if(askerEnerjisi>3)
        {
            cout<< "Gollom kesildi ve 3 adet cinko, ve 3 adet et kazanildi."<<endl;
            Et=Et+3+arastirmaBinasiSeviye;
            Cinko=Cinko+3+arastirmaBinasiSeviye;
            askerEnerjisi=askerEnerjisi-3;
        }
        else
        {
            cout<< "Asker Enerjisi Yetersiz."<<endl;
        }
    }
    void agacKes()
    {
        if(askerEnerjisi>=2)
        {
            cout<< "Agac kesildi ve 2 adet su, 4 adet demir kazanildi."<<endl;
            Su=Su+2+arastirmaBinasiSeviye;
            Demir=Demir+4+arastirmaBinasiSeviye;
            askerEnerjisi=askerEnerjisi-2;
        }
        else
        {
            cout<< "Yeteri kadar enerji olmadigi icin agac kesilemedi."<<endl;
        }
    }
    void kusKes()
    {
        if(askerEnerjisi>=5)
        {
            Kum=Kum+3+arastirmaBinasiSeviye;
            Et=Et+2+arastirmaBinasiSeviye;
            askerEnerjisi=askerEnerjisi-5;
        }
        else
        {
            cout<< "Yeteri kadar enerji olmadigi icin kus kesilemedi.!"<<endl;
        }
    }
    void yagmala()
    {
        if(askerEnerjisi>=2)
        {
            mevcutPara=mevcutPara+5+anaBinaSeviye;
            askerEnerjisi=askerEnerjisi-2;
        }
    }
    void suSatinAl()
    {
        if(mevcutPara>=4)
        {
            Su=Su+4;
            mevcutPara=mevcutPara-4;
            cout<< "Su Satin Alindi."<<endl;
        }
        else
        {
            cout<< "Yeteri kadar paraniz bulunmamaktadir.!"<<endl;
        }
    }
    void cinkoSatinAl()
    {
        if(mevcutPara>=4)
        {
            Cinko=Cinko+4;
            mevcutPara=mevcutPara-4;
            cout<< "Cinko Satin Alindi."<<endl;
        }
        else
        {
            cout<< "Yeteri kadar paraniz bulunmamaktadir.!"<<endl;
        }
    }
    void demirSatinAl()
    {
        if(mevcutPara>=4)
        {
            Demir=Demir+4;
            mevcutPara=mevcutPara-4;
            cout<< "Demir Satin Alindi."<<endl;
        }
        else
        {
            cout<< "Yeteri kadar paraniz bulunmamaktadir.!"<<endl;
        }
    }
    void kumSatinAl()
    {
        if(mevcutPara>=4)
        {
            Kum=Kum+4;
            mevcutPara=mevcutPara-4;
            cout<< "Kum Satin Alindi."<<endl;
        }
        else
        {
            cout<< "Yeteri kadar paraniz bulunmamaktadir.!"<<endl;
        }
    }
};
int main()
{
    Karakter k1;
    printf("Age-Of-Root Oyununa Hosgeldiniz.\n");
    bool oyun_devam_ediyor=true;
    int secenek;
    while(oyun_devam_ediyor)
    {
        printf("1) Ana Bina Seviyesi Artir.\n2) Arastirma Binasi Seviyesi Artir.\n3) Seviye Atla Askeri Bina.\n");
        printf("4) Asker Enerjisini Doldur.\n5) Gollom Kes.\n6) Agac Kes.\n7) Kus Kes.\n8) Hazine Yagmala.\n");
        printf("9) Su Satin Al.\n10) Cinko Satin Al.\n11) Demir Satin Al.\n12) Kum Satin Al.\n13) Statuleri Gor.\n14) Oyunu Sonlandir.\n");
        cin>>secenek;
        switch(secenek)
        {
            case 1:
                k1.seviyeAtlaAnaBina();
                break;
            case 2:
                k1.seviyeAtlaArastirmaBinasi();
                break;
            case 3:
                k1.seviyeAtlaAskeriBina();
                break;
            case 4:
                k1.askerEnerjisiDoldur();
                break;
            case 5:
                k1.gollomKes();
                break;
            case 6:
                k1.agacKes();
                break;
            case 7:
                k1.kusKes();
                break;
            case 8:
                k1.yagmala();
                break;
            case 9:
                k1.suSatinAl();
                break;
            case 10:
                k1.cinkoSatinAl();
                break;
            case 11:
                k1.demirSatinAl();
                break;
            case 12:
                k1.kumSatinAl();
                break;
            case 13:
                k1.statuGoruntule();
                break;
            case 14:
                cout<< "Cikis Yapiliyor."<<endl;
                oyun_devam_ediyor=false;
                break;
            default:
                cout<< "Gecerli bir deger girmediniz."<<endl;
        }


    }






    return 0;
}

