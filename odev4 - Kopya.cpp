-#include <iostream>

using namespace std;
class yigin
{
	private:
		int kapasite;
		char *veri;
		int konum;
	public:
		yigin(int kapasite)
		{
			this->kapasite=kapasite;
			veri = (char *)malloc(sizeof(char)*kapasite);
            konum = -1;
		}
		void ekle(char data)
		{
			if (konum != kapasite -1)
				veri[++konum]= data;
		}
		void yaz()
		{
			int i = konum;
			if(konum != -1)
			{
				while( i >= 0)
				{
					cout << veri[i] << endl;
					i--;
				}
			}
		}
		void temizle()
		{
			int i = -1;
			while(++i < kapasite)
				veri[i] = 0;
			free(veri);
		}
};

class kuyruk
{
    private:
        int kapasite;
        char *veri;
        int konum;
        int sira;
	public:
		kuyruk(int kapasite)
		{
			this->kapasite=kapasite;
			veri = (char *)malloc(sizeof(char)*kapasite);
			sira = 0;
			konum = 0;
		}
		void ekle(char data)
		{
		    if(konum == kapasite)
		    {
		        konum = 0;
		    }
			if( sira <= konum && veri[konum] == 0)
			{
				veri[konum] = data;
			    konum++;
			}
			else if(sira > konum && veri[konum] == 0)
			{
				veri[konum] = data;
			    konum++;
			}
			else
			{
				cout << "sira dolu";
			}
		}
		void cikar()
		{
			veri[sira%kapasite] = 0;
			sira++;
			if(sira == kapasite)
			{
			    sira = 0;
			}
		}
		void yaz()
		{
		    int i = sira;
		    while(veri[i])
		    {
		        cout << veri[i] << endl;
		        i++;
		    }
		    i=0;
		    while(veri[i] && i < sira)
		    {
		        cout << veri[i] << endl;
		        i++;
		    }
		}
		void temizle()
		{
			int i = -1;
			while(++i < kapasite)
				veri[i] = 0;
			free(veri);
		}
};

int main()
{
	bool polindrom;
	char devam;
	int kapasite;
	string kelime;
	do
	{
		cout << endl << "Kelimey Girin...:";
		cin  >> kelime;
		kapasite = 0;
		while(kelime[kapasite])
			kapasite++;
		yigin ygn(kapasite);
		kuyruk kyrk(kapasite);
		
		int i = 0;
		while(i < kapasite)
		{
			ygn.ekle(kelime[i]);
			kyrk.ekle(kelime[i]);
			i++;
		}
		cout << "---STACK YAPISI---" << endl;
		ygn.yaz();
		cout << "---QUEUE YAPISI---" << endl;
		kyrk.yaz();
		i = 0; 
		while (i < kapasite)
		{
			if(kelime[i] == kelime[kapasite-1] && i < kapasite)
			{
				polindrom = true;
				i++;
				kapasite--;
			}
			else
			{
				polindrom = false;
				break;
			}
		}
		if(polindrom)
			cout << "*****Polindrom Bir Kelime Girdiniz..." << endl;
		else
			cout << "*****Girilen Kelime Polindrom Değil..." << endl;
		
		cout << "******Devam Etmek Istiyormusunuz? <e/h>...:";
		cin  >> devam;
	} while (devam == 'e' || devam == 'E');
	return 0;
}