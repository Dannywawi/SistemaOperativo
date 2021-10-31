#include <iostream>
#include <vector>
using namespace std;

//Input realizado por el ayduante, lo puse para tener una ideaa jsajs

class tareas{
    public:
        int horas; //Horas totales a la semana(se dividira cantidad de dias/tareas)
        bool interrumpible; //true: se puede interrumpir, false: caso contrario
        vector<int> horas_inicio; 
        vector<int> dias;
        tareas(int h, bool i, vector<int> hi, vector<int> d){
            this->horas = h;
            this->interrumpible = I;
            this->horas_inicio = hi;
            this->dias = d;
        }
};

int main(){
    vector<tareas*> mis_tareas;
    for (int i=0;i<7;i++){
        
        //INPUT
        //Horas
        int h;
        cin >> h;

        //Horas de inicio y Dias
        vector<int> hi;
        string hi_in;

        vector<int> d;
        string d_in;

        getline(cin, hi_in); //Linea vacia
        getline(cin, hi_in);
        getline(cin, d_in);

        //Interrumpible

        bool b;
        cin >> b;

        cout << h << "\n" << hi_in << "\n" << d_in << "\n" << b << endl;

    }
}