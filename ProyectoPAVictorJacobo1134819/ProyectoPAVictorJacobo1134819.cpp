// ProyectoPAVictorJacobo1134819.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

void IngresarCanciones() {
    string nombre, artista;
    int p = 1;
    fstream fout;
    fout.open("Playlist.csv", ios::out | ios::app);
    while (p != 0)
    {
        cout << "Ingrese nombre de la cancion\n";
        cin >> nombre;
        fout << nombre << "-";
        cout << "Ingrese nombre del artista\n";
        cin >> artista;
        fout << artista;
        fout << "\n";
        cout << "Para terminar de ingresar presione 0, para continuar presione cualquier tecla.";
        cin >> p;
    }
    //Menu();
    cin ;
}
int  MostrarPlaylist() {
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    stack<string> pis;
    string line, word, temp;
    fstream fin;
    fin.open("Playlist.csv", ios::in);
    cout << "Esta es la playlist actual: \n";

    while (fin >> temp) {

        pis.pop();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, '-')) {
            pis.push(word);
        }

    }
    while (!pis.empty()) {
        cout << pis.top() << " ";
        cout << "\n";
    }

    
    cin;
    return 0;
}
void BuscarPlaylist() {
    fstream fin;
    fin.open("Playlist.csv", ios::in);

    string nombre;
    cout << "Ingrese el nombre de la cancion para buscar";
    cin >> nombre;
    vector<string> fila;
    string linea, p, temp;
    
    while (fin >> temp) {
        fila.clear();
        getline(fin, linea);
        stringstream s(linea);
        while (getline(s, p, '-'))
        {
            fila.push_back(p);
        }
        if (p == nombre) {
            cout << "Se encontro:  \n";
            cout << "Nombre: " << fila[0] ;
            cout << "Artista: " << fila[1];
            break;
        }
        else {
            cout << "No se encontro";
        }
    }
    //seria mas simple si no lo buscara en el csv, si no solo buscar en un stack o algo asi
    cin;
}
void EmpezarPlaylist() {
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    cout << "~~~~~~~~~~~~~~~~~~~~~Reproduciendo Playlist~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Presione espacio para ir a la siguiente cancion";
    cout << "\n";
    cout << "\n";
    queue<string> pis2;
    fstream fin;
    string line, word, temp;
    fin.open("Playlist.csv", ios::in);
    while (fin >> temp) {

        pis2.pop();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, '-')) {
            pis2.push(word);
        }

    }
    while (!pis2.empty()) {
        cout << pis2.front() << " ";
        pis2.pop();
        cout << "\n";
        cin;
    }
    cin;
}
void Menu() {
    int n;
    std::cout << "Seleccione una de las siguientes opciones: 1. Ingresar canciones 2. Mostrar playlist actual\n";
    std::cout << "3. Buscar una cancion en la playlist 4. Empezar la lista de reproduccion\n";
    cout << "\n";
    cout << "\n";
    //2 stacks para cancion, artista, ordenar como una lista enlazada or smthn -> para la lista de reproduccion pasarlo a una queue 
    cin >> n;

    switch (n)
    {
    case 1:
        IngresarCanciones();
        break;
    case 2:
        MostrarPlaylist();
        break;
    case 3:
        BuscarPlaylist();
        break;
    case 4:
        EmpezarPlaylist();
        break;
    default:
        cout << "Ingrese un valor valido";
        Menu();
        break;
    }
}

int main()
{
    
    /*cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣶⣶⣶⣶⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀\n";
    cout << "⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀\n";
    cout << "⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀\n";
    cout << "⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⡇⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀\n";
    cout << "⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠈⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⡄ \n";
    cout << "⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⣉⣿⣿⣿⣿⣿⣿⣿⣿ \n";
    cout << "⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⠃ \n";
    cout << "⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀ \n";
    cout << "⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀ \n";
    cout << "⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀ \n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀\n";*/
    //no funciono el ascii art oops
    std::cout << "=========================================================================\n";
    std::cout << "                 Bienvenido al Music Festival Player                     \n";
    std::cout << "=========================================================================\n";
    std::cout << "                                                                         \n";
    std::cout << "                                                                         \n";
    cout << "\n";
    
    Menu();
    //std::cout << "Seleccione una de las siguientes opciones: 1. Ingresar canciones 2. Mostrar playlist actual\n";
    //std::cout << "3. Ordenar la playlist 4. Empezar la lista de reproduccion\n" ;
    //cout << "\n";
    ////2 stacks para cancion, artista, ordenar como una lista enlazada or smthn -> para la lista de reproduccion pasarlo a una queue 
    //cin >> n;
    //
    //switch (n)
    //{
    //case 1:
    //    IngresarCanciones();
    //    break;
    //case 2:
    //    MostrarPlaylist();
    //    break;
    //case 3:
    //    OrdenarPlaylist();
    //    break;
    //case 4:
    //    EmpezarPlaylist();
    //    break;
    //default:
    //    cout << "bitch ese no";
    //    break;
    //}
}


