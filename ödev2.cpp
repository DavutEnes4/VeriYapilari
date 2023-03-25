#include <iostream>
#include <string>  

using namespace std;
class Dugum
{
	public:
		string veri;
		Dugum *sonraki = nullptr;
		Dugum *onceki = nullptr;
		Dugum(string veri)
		{
			this->veri=veri;
		}
		Dugum(){}
};

class Liste
{
	Dugum *root;

	public:
		Liste ListeElemanEkle(Liste liste, string data)
		{
			if(liste.root == nullptr)
			{
				liste.root = new Dugum(data);
				liste.root->sonraki = liste.root;
				liste.root->onceki = liste.root;
			}
			else if(root->sonraki == root)
			{
				liste.root->sonraki = new Dugum(data);
				liste.root->onceki = liste.root->sonraki;
				liste.root->sonraki->sonraki = liste.root;
			}
			else
			{
				Dugum *tekrar = liste.root;
				while (tekrar->sonraki != liste.root)
					tekrar = tekrar->sonraki;
				tekrar->sonraki = new Dugum(data);
				tekrar->sonraki->sonraki = liste.root;
				liste.root->onceki = tekrar->sonraki;
			}
			return(liste);

		}

		void liste_yazdir(Liste liste)
		{
			Dugum *tekrar = liste.root;
				while (tekrar->sonraki != liste.root)
				{
					cout << tekrar->veri;
					tekrar = tekrar->sonraki;
				}
				cout << tekrar->veri;
		}
};

int main()
{
	Liste liste;
	int i = 0;
	while(++i<101)
		liste = liste.ListeElemanEkle(liste,to_string(i*i)+" ");
	liste.liste_yazdir(liste);
}