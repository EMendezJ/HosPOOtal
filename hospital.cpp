#include<iostream>
#include<string>
using namespace std;  


class Humano {
    protected:
        string nombre;
        int edad;
        string nacionalidad;
    public:
        Humano();
        Humano(string, int, string);
    };
    


class Paciente: public Humano{

    protected:
    string enfermedad;

    public:
    
    Paciente();
    Paciente(string, int, string, string);

    void show_paciente();
    void solicitar_comida();
    void llamada_emergencia();

};

class Terminal: public Paciente{
    private:
    int cantidad_dias;
    int visitas_programadas;
    
    public:

    Terminal();
    Terminal(string, int, string, string, int, int);

    void cambiarr_dias(int);
};

class NoTerminal: public Paciente{
    private:
    string tratamiento;
    string operacion;
    
    public:

    NoTerminal();
    NoTerminal(string, int, string, string, string, string);

    void cambiarr_dias(int);
};
 
class Personal:public Humano{
protected:
    float sueldo;
    string antiguedad;
    
    
public:
    Personal();
    Personal(string, int, string, float, string);

    void muestraPersonal();
};

class Doctor: public Personal{
    private:
    string especialidad;
    string cedula_profesional;

    public: 
    Doctor
};

class Enfermero: public Personal{
    private:
    string area_de_apoyo;
    string uniforme;
    
    public:

    Enfermero();
    Enfermero(string, int, string, float, string, string, string);

    void cambiarr_dias(int);
};

Humano::Humano(){
    nombre = "Sin nombre";
    edad = 18;
    nacionalidad = "Mex";
}

Humano::Humano(string _nombre, int _edad, string _nacionalidad){
    nombre = _nombre;
    edad = _edad;
    nacionalidad = _nacionalidad;
}

