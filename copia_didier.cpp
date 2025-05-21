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
    string get_enfermedad();

};

class Terminal: public Paciente{
    private:
    int cantidad_dias;
    int visitas_programadas;
    
    public:

    Terminal();
    Terminal(string, int, string, string, int, int);

    void show_terminal();
    void cambiar_visitas(int);
    int get_visitas();
    int get_dias();
    void cambiar_dias(int);
};

class NoTerminal: public Paciente{
    private:
    string tratamiento;
    string operacion;
    
    public:

    NoTerminal();
    NoTerminal(string, int, string, string, string, string);

    void cambiar_tratamiento(string);
    void cambiar_operacion(string);
    string get_tratamiento();
    string get_operacion();
    
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

Paciente::Paciente() : Humano() {
    enfermedad = "Desconocida";
}

Paciente::Paciente(string _nombre, int _edad, string _nacionalidad, string _enfermedad) : Humano(_nombre, _edad, _nacionalidad) {
    enfermedad = _enfermedad;
}

void Paciente::show_paciente() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Enfermedad: " << enfermedad << endl;
}

void Paciente::solicitar_comida() {
    cout << "Soy el paciente " << nombre << " y quiero comer" << endl;
}

void Paciente::llamada_emergencia() {
    cout << "Necesito ayuda urgente, soy el paciente " << nombre << endl;
}

string Paciente::get_enfermedad() {
    return enfermedad;
}

Terminal::Terminal() : Paciente() {
    cantidad_dias = 0;
    visitas_programadas = 0;
}
Terminal::Terminal(string _nombre, int _edad, string _nacionalidad, string _enfermedad, int _cantidad_dias, int _visitas_programadas) : Paciente(_nombre, _edad, _nacionalidad, _enfermedad) {
    cantidad_dias = _cantidad_dias;
    visitas_programadas = _visitas_programadas;
}
void Terminal::cambiar_dias(int _cantidad_dias) {
    cantidad_dias += _cantidad_dias;
}
void Terminal::cambiar_visitas(int _visitas_programadas) {
    visitas_programadas += _visitas_programadas;
}
int Terminal::get_visitas() {
    return visitas_programadas;
}
int Terminal::get_dias() {
    return cantidad_dias;
}
void Terminal::show_terminal() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Enfermedad: " << enfermedad << endl;
    cout << "Cantidad de días en el hospital: " << cantidad_dias << endl;
    cout << "Visitas programadas: " << visitas_programadas << endl;
}

NoTerminal::NoTerminal() : Paciente() {
    tratamiento = "Ninguno";
    operacion = "Ninguna";
}
NoTerminal::NoTerminal(string _nombre, int _edad, string _nacionalidad, string _enfermedad, string _tratamiento, string _operacion) : Paciente(_nombre, _edad, _nacionalidad, _enfermedad) {
    tratamiento = _tratamiento;
    operacion = _operacion;
}
void NoTerminal::cambiar_tratamiento(string _tratamiento) {
    tratamiento = _tratamiento;
}
void NoTerminal::cambiar_operacion(string _operacion) {
    operacion = _operacion;
}
string NoTerminal::get_tratamiento() {
    return tratamiento;
}
string NoTerminal::get_operacion() {
    return operacion;
}

int main() {
    //test default de Terminal
    Terminal terminalDefault;
    terminalDefault.show_terminal();
    terminalDefault.cambiar_dias(10);
    terminalDefault.cambiar_visitas(3);
    cout << "Días actualizados: " << terminalDefault.get_dias() << endl;
    cout << "Visitas actualizadas: " << terminalDefault.get_visitas() << endl;

    //Test de Terminal con argumentos
    Terminal terminalCustom("Carlos Ramirez", 65, "Mexicana", "Insuficiencia renal", 15, 2);
    terminalCustom.show_terminal();
    terminalCustom.cambiar_dias(5);
    terminalCustom.cambiar_visitas(1);
    cout << "Días actualizados: " << terminalCustom.get_dias() << endl;
    cout << "Visitas actualizadas: " << terminalCustom.get_visitas() << endl;

    // test default de NoTerminal
    NoTerminal noTerminalDefault;
    cout << "Tratamiento: " << noTerminalDefault.get_tratamiento() << endl;
    cout << "Operación: " << noTerminalDefault.get_operacion() << endl;
    noTerminalDefault.cambiar_tratamiento("Fisioterapia");
    noTerminalDefault.cambiar_operacion("Cirugía menor");
    cout << "Tratamiento actualizado: " << noTerminalDefault.get_tratamiento() << endl;
    cout << "Operación actualizada: " << noTerminalDefault.get_operacion() << endl;

    // Test de noTerminal con argumentos
    NoTerminal noTerminalCustom("Ana Torres", 30, "Mexicana", "Fractura", "Rehabilitación", "Cirugía ortopédica");
    cout << "Tratamiento: " << noTerminalCustom.get_tratamiento() << endl;
    cout << "Operación: " << noTerminalCustom.get_operacion() << endl;
    noTerminalCustom.cambiar_tratamiento("Terapia ocupacional");
    noTerminalCustom.cambiar_operacion("Revisión quirúrgica");
    cout << "Tratamiento actualizado: " << noTerminalCustom.get_tratamiento() << endl;
    cout << "Operación actualizada: " << noTerminalCustom.get_operacion() << endl;
    
    Paciente paciente1("Juan Perez", 45, "Mexicana", "Gripe");
    paciente1.show_paciente();
    paciente1.solicitar_comida();
    paciente1.llamada_emergencia();
    
    return 0;
}