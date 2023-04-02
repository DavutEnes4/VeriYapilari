	#include <iostream>

	using namespace std;
	class yigin
	{
		private:
			int kapasite;
			int *veri;
			int konum;
		public:
			yigin(int kapasite)
			{
				this->kapasite=kapasite;
				veri = (int *)malloc(sizeof(int)*kapasite);
				konum = -1;
			}
			void ekle(int data)
			{
				if (konum != kapasite -1)
				{
					veri[++konum]= data;
					cout <<konum+1 <<". siraya "<< veri[konum] <<" degeri eklendi"<< endl;
				}
				else
				{
					cout << "!!! DİKKAT DİKKAT Bu yigin dolu !!!"<< endl;
				}
			}
			void soncikar()
			{
				
				if (konum != -1)
				{
					cout <<konum <<". siradaki "<< veri[konum] <<" degeri silindi"<< endl;
					veri [konum--] = 0;
				}
				else
				{
					cout << "!!! DİKKAT DİKKAT Bu yigin bos !!!"<< endl;
				}
			}
			
			void bulcikar(int ara)
			{
				bool durum;
				if (konum != -1)
				{
					int i = 0;
					while(i <= konum)
					{
						if(veri[i] == ara )
						{
							cout <<i + 1 <<". siradaki "<< veri[i] <<" degeri silindi"<< endl;
							veri[i]= 0;
							while(i < konum && veri[i+1] != 0)
							{
								swap(i,i+1,true);
								i++;
							}
							konum--;
						}
						i++;
					}
				}
				else
				{
					cout << "!!! DİKKAT DİKKAT Bu yigin bos !!!"<< endl;
				}
			}
			void swap(int a , int b , bool zorla= false)
			{
				int temp;
				if ( a == b )
					b = konum;
				if(veri[a] != 0 || zorla)
				{
					if(veri[b] != 0 || zorla)
					{
						temp = veri[a];
						veri[a] = veri[b];
						veri[b] = temp;
					}
					else
					{
						cout << "Fonksiyona girislmis olan 2. deger yiginda mevcut degildir" << endl;
					}
				}
				else
					{
						cout << "Fonksiyona girislmis olan 1. deger yiginda mevcut degildir" << endl;
					}
			}
			void swap()
			{
				int temp;
				temp = veri[0];
				veri[0] = veri[konum];
				veri[konum] = temp; 
			}
			void yaz()
			{
				int i = 0;
				if(konum != -1)
				{
					while( i <= konum)
					{
						cout << i + 1 << ". siradaki deger " << veri[i] << endl;
						i++;
					}
				}
				else
				{
					cout << "dizi bos" << endl;
				}
			}
	};

	void ara()
	{
		cout << "**********************************************"<<endl;
	}
	int main()
	{
		int uzunluk;
		int veri;

		cout <<"Ne kadar uzunlikta bir yigin olusturmak istiyorsunuz :";
		cin  >> uzunluk;
		yigin stack(uzunluk);
		while(uzunluk != 0)
		{
			cout << "Listeye eklenecek eleman :";
			cin  >> veri;
			stack.ekle(veri);
			cout << endl;
			uzunluk--;
		}
		stack.yaz();
		ara();
		cout << "Listeden silmek istediğiniz eleman :";
		cin  >> veri;
		stack.bulcikar(veri);
		stack.yaz();
		ara();
		cout << "Listeden son siradaki elemanini sildim"<<endl;
		if (veri)
			stack.soncikar();
		stack.yaz();
		ara();
		cout << "Listedeki elemanlarin yerini degistirdim"<<endl;
		stack.swap();
		stack.yaz();
	}	