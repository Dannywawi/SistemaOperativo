#include <iostream>
#include <vector>
using namespace std;


//Marca un error en push back del pair, lo estoy viendo


class tareas{
    public:
        int actividad;
        int horas; //Horas totales a la semana(se dividira cantidad de dias/tareas)
        bool interrumpible; //true: se puede interrumpir, false: caso contrario
        vector<int> horas_inicio; 
        vector<int> dias;
        tareas(int act, int h, bool i, vector<int> hi, vector<int> d){
            this->actividad = act;
            this->horas = h;
            this->interrumpible = i;
            this->horas_inicio = hi;
            this->dias = d;
        }

        void printhorasinicio(){
            for(int i=0;i<this->horas_inicio.size();i++){
                cout << this->horas_inicio.at(i) << " ";
            }
            cout << endl;
        }

        void printdiasinicio(){
            for(int i=0;i<this->dias.size();i++){
                cout << this->dias.at(i) << " ";
            }
            cout << endl;
        }

        int cantidad(){
            int cant = this->horas / this->dias.size();
            return cant;
        }

        vector<int> ordenHoras2(){
            vector<int> orden;
            for(int i=0;i<this->dias.size();i++){
 
                if (this->dias.at(i) == 0){
                    cout << "Actividad dia lunes: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                    orden.push_back(this->horas_inicio.at(i));
 
                }
            }
            
            return orden;
        }

        void calendarizacionLunes(){
            //int cant = this->horas / this->dias.size();
            //vector<int> orden;
            for(int i=0;i<this->dias.size();i++){

                if (this->dias.at(i) == 0){
                    cout << "Actividad dia lunes: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                    //orden.push_back(this->horas_inicio.at(i));
                }
            }   

            //sort(orden.begin(), orden.end());
            //for(int i=0;i<orden.size();i++){
                //cout << orden.at(i) << " ";
            //}
            //cout << endl << cant << endl;
        }

        void calendarizacionMartes(){
            for(int i=0;i<this->dias.size();i++){
                if (this->dias.at(i) == 1){
                    cout << "Actividad dia martes: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                }
            }        
        }

        void calendarizacionMiercoles(){
            for(int i=0;i<this->dias.size();i++){
                if (this->dias.at(i) == 2){
                    cout << "Actividad dia miercoles: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                }
            }        
        }

        void calendarizacionJueves(){
            for(int i=0;i<this->dias.size();i++){
                if (this->dias.at(i) == 3){
                    cout << "Actividad dia jueves: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                }
            }        
        }

        void calendarizacionViernes(){
            for(int i=0;i<this->dias.size();i++){
                if (this->dias.at(i) == 4){
                    cout << "Actividad dia viernes: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                }
            }        
        }

        void calendarizacionSabado(){
            for(int i=0;i<this->dias.size();i++){
                if (this->dias.at(i) == 5){
                    cout << "Actividad dia sabado: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                }
            }        
        }

        void calendarizacionDomingo(){
            for(int i=0;i<this->dias.size();i++){
                if (this->dias.at(i) == 6){
                    cout << "Actividad dia domingo: " << this->actividad << endl;
                    cout << "Hora de la actividad: " << this->horas_inicio.at(i) << endl;
                }
            }        
        }

        void printinfo(){
            cout << this->actividad << endl;
            cout << this->horas << endl;
            printhorasinicio();
            printdiasinicio();
            cout << this->interrumpible << endl;
        }
};

int main(){
    vector<tareas*> mis_tareas;
    for (int i=0;i<2;i++){
        int a;
        a = i+1;


        //INPUT
        //Horas
        cout << "Ingrese horas de la actividad " << a << endl;
        int h;
        cin >> h;

        //Horas de inicio y Dias
        vector<int> hi;
        string hi_in;

        vector<int> d;
        string d_in;
        
        cout << "Ingrese hora de inicio de la actividad " << a << endl;

        getline(cin, hi_in); //Linea vacia
        getline(cin, hi_in);


        int number = 0;

        for(int j=0;j<hi_in.length();j++){
            if(hi_in[j] != ' '){
                number = number * 10 + (int)hi_in[j] - '0';
            } else{
                hi.push_back(number);
                number = 0;
            }
        }

        if(number !=0) hi.push_back(number);

        cout << "Ingrese dias de la actividad " << a << endl;
        getline(cin, d_in);

        for(int j=0; j<d_in.length();j++){
            if (d_in[j] != ' ') d.push_back((int)d_in[j] - '0');
        }

        //Interrumpible

        cout << "Ingrese si se puede interrumpir la actividad " << a << endl;
        bool b;
        cin >> b;

       tareas* t = new tareas(a,h,b,hi,d);
       mis_tareas.push_back(t);

    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->printinfo();
    }

    vector<pair<int, int> > v_ordenado;
    int cpu_burst;

    for(int i=0;i<mis_tareas.size();i++){
        
        vector<int> new_v;
        new_v = mis_tareas.at(i)->ordenHoras2();
        cpu_burst = mis_tareas.at(i)->cantidad();
        
        for(int i=0;i<new_v.size();i++){
            v_ordenado.push_back(pair(new_v.at(i),cpu_burst));
        }

        sort(v_ordenado.begin(), v_ordenado.end());

        for(int i=0;i<v_ordenado.size();i++){
            cout << v_ordenado.at(i).first << "," << v_ordenado.at(i).second << " ";
        }

    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->calendarizacionMartes();
    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->calendarizacionMiercoles();
    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->calendarizacionJueves();
    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->calendarizacionViernes();
    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->calendarizacionSabado();
    }

    for(int i=0;i<mis_tareas.size();i++){
        mis_tareas.at(i)->calendarizacionDomingo();
    }

}