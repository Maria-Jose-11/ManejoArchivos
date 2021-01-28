#include <iostream>
#include<fstream>
using namespace std;

int main() {
  string nombre;
  string apellido;
  long numero;
  char r;
  ofstream archivoprueba;
  string nombrearchivo;
  cout<<"Ingrese el nombre del archivo: ";
  getline(cin, nombrearchivo);
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do{
    cout<<"Ingrese el nombre del contacto: ";
    getline(cin,nombre);
    cout<<"Ingrese el apellido del contacto: ";
    getline(cin,apellido);
    cout<<"Ingrese el número del contacto: ";
    cin>>numero;
    archivoprueba<<nombre<<"\t"<<apellido<<"\t"<<numero<<endl;
    cout<<"Desea ingresar otro contacto s/n: ";
    cin>>r;
    cin.ignore();
  }
  while(r=='s'|| r=='S');
  archivoprueba.close();

  ifstream archivolectura(nombrearchivo.c_str());
  string texto;
  cout<<"\nNombre \t Apellido \t    Número \n";
  while (!archivolectura.eof()){
    archivolectura>>nombre>>apellido>>numero;
    //getline(archivolectura,texto);
    if(!archivolectura.eof()){
      cout<<nombre<<" \t\t"<<apellido<<" \t\t"<<numero<<" \t\t\n";
    }
  }
  archivolectura.close();
}