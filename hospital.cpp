#include<iostream>
#include<string>
using namespace std;  

// Clase base Humano
class Humano {
    protected:
        string nombre;
        int edad;
        string nacionalidad;
    public:
        Humano() {
            nombre = "Sin nombre";
            edad = 18;
            nacionalidad = "Mex";
        }
        
        Humano(string _nombre, int _edad, string _nacionalidad) {
            nombre = _nombre;
            edad = _edad;
            nacionalidad = _nacionalidad;
        }
};

// Clase Personal que hereda de Humano
class Personal : public Humano {
    protected:
        float sueldo;
        string antiguedad;
    
    public:
        Personal() : Humano() {
            sueldo = 0.0;
            antiguedad = "Sin antiguedad";
        }
        
        Personal(string _nombre, int _edad, string _nacionalidad, float _sueldo, string _antiguedad) 
            : Humano(_nombre, _edad, _nacionalidad) {
            sueldo = _sueldo;
            antiguedad = _antiguedad;
        }
        
        void muestraPersonal() {
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Nacionalidad: " << nacionalidad << endl;
            cout << "Sueldo: " << sueldo << endl;
            cout << "Antigüedad: " << antiguedad << endl;
        }
};

// Clase Doctor que hereda de Personal
class Doctor : public Personal {
    private:
        string especialidad;
        string cedula_profesional;

    public: 
        Doctor() : Personal() {
            especialidad = "Sin especialidad";
            cedula_profesional = "Sin cédula";
        }
        
        Doctor(string _nombre, int _edad, string _nacionalidad, float _sueldo, 
               string _antiguedad, string _especialidad, string _cedula_profesional) 
            : Personal(_nombre, _edad, _nacionalidad, _sueldo, _antiguedad) {
            especialidad = _especialidad;
            cedula_profesional = _cedula_profesional;
        }
        
        void muestraDatos() {
            muestraPersonal();
            cout << "Especialidad: " << especialidad << endl;
            cout << "Cédula profesional: " << cedula_profesional << endl;
        }
        
        void recetar() {
            cout << "El doctor " << nombre << " está recetando un medicamento." << endl;
        }
};

// Clase Enfermero que hereda de Personal
class Enfermero : public Personal {
    private:
        string area_de_apoyo;
        string uniforme;
    
    public:
        Enfermero() : Personal() {
            area_de_apoyo = "Sin área asignada";
            uniforme = "Sin uniforme";
        }
        
        Enfermero(string _nombre, int _edad, string _nacionalidad, float _sueldo,
                 string _antiguedad, string _area_de_apoyo, string _uniforme) 
            : Personal(_nombre, _edad, _nacionalidad, _sueldo, _antiguedad) {
            area_de_apoyo = _area_de_apoyo;
            uniforme = _uniforme;
        }
        
        void muestraDatos() {
            muestraPersonal();
            cout << "Área de apoyo: " << area_de_apoyo << endl;
            cout << "Uniforme: " << uniforme << endl;
        }
        
        void darDeComer() {
            cout << "El enfermero " << nombre << " está dando de comer a un paciente." << endl;
        }
};

// Clase Paciente que hereda de Humano
class Paciente : public Humano {
    protected:
        string enfermedad;

    public:
        Paciente() : Humano() {
            enfermedad = "Sin diagnostico";
        }
        
        Paciente(string _nombre, int _edad, string _nacionalidad, string _enfermedad) 
            : Humano(_nombre, _edad, _nacionalidad) {
            enfermedad = _enfermedad;
        }

        void show_paciente() {
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Nacionalidad: " << nacionalidad << endl;
            cout << "Enfermedad: " << enfermedad << endl;
        }
        
        void solicitar_comida() {
            cout << nombre << " ha solicitado comida." << endl;
        }
        
        void llamada_emergencia() {
            cout << "¡Emergencia! El paciente " << nombre << " necesita atención urgente." << endl;
        }
};

// Clase Terminal que hereda de Paciente
class Terminal : public Paciente {
    private:
        int cantidad_dias;
        int visitas_programadas;
    
    public:
        Terminal() : Paciente() {
            cantidad_dias = 0;
            visitas_programadas = 0;
        }
        
        Terminal(string _nombre, int _edad, string _nacionalidad, string _enfermedad, 
                int _cantidad_dias, int _visitas_programadas) 
            : Paciente(_nombre, _edad, _nacionalidad, _enfermedad) {
            cantidad_dias = _cantidad_dias;
            visitas_programadas = _visitas_programadas;
        }

        void cambiarr_dias(int nuevos_dias) {
            cantidad_dias = nuevos_dias;
        }
        
        void muestraDatos() {
            show_paciente();
            cout << "Cantidad de días: " << cantidad_dias << endl;
            cout << "Visitas programadas: " << visitas_programadas << endl;
        }
};

// Clase NoTerminal que hereda de Paciente
class NoTerminal : public Paciente {
    private:
        string tratamiento;
        string operacion;
    
    public:
        NoTerminal() : Paciente() {
            tratamiento = "Sin tratamiento";
            operacion = "Sin operacion";
        }
        
        NoTerminal(string _nombre, int _edad, string _nacionalidad, string _enfermedad,
                  string _tratamiento, string _operacion) 
            : Paciente(_nombre, _edad, _nacionalidad, _enfermedad) {
            tratamiento = _tratamiento;
            operacion = _operacion;
        }

        void cambiarr_dias(int nuevos_dias) {
            cout << "Modificación de días no aplicable a pacientes no terminales." << endl;
        }
        
        void muestraDatos() {
            show_paciente();
            cout << "Tratamiento: " << tratamiento << endl;
            cout << "Operación: " << operacion << endl;
        }
};

