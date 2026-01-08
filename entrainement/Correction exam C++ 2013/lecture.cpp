#include <iostream>
#include <string>
#include <fstream>
  
using namespace std;
  
int main()
{
        ifstream fichier("test.txt", ios::in);  // on ouvre en lecture
  
        if(fichier)
					{
        string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                cout << ligne << endl;  // on l'affiche
        }
					}
        else
                cout << "Impossible d'ouvrir le fichier !" << endl;
  
        return 0;
}