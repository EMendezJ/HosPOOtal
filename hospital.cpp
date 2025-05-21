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
    Doctor();
    Doctor(string, int, string, float, string, string ,string);
    void muestraDoctor();
    void recetar(); //Para cambiar el tratamiento de un paciente terminal

};

class Enfermero: public Personal{
    private:
    string area_de_apoyo;
    string uniforme;
    
    public:

    Enfermero();
    Enfermero(string, int, string, float, string, string, string);

    void muestraEnfermero();
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

Personal::Personal() : Humano() {
    sueldo = 0.0;
    antiguedad = "Sin antigüedad";
}

Personal::Personal(string _nombre, int _edad, string _nacionalidad, float _sueldo, string _antiguedad) : Humano(_nombre, _edad, _nacionalidad) {
    sueldo = _sueldo;
    antiguedad = _antiguedad;
}

void Personal::muestraPersonal() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Sueldo: $" << sueldo << endl;
    cout << "Antigüedad: " << antiguedad << endl;
}

Doctor::Doctor() : Personal() {
    especialidad = "Sin especialidad";
    cedula_profesional = "Sin cédula";
}

Doctor::Doctor(string _nombre, int _edad, string _nacionalidad, float _sueldo, string _antiguedad, string _especialidad, string _cedula_profesional) : Personal(_nombre, _edad, _nacionalidad, _sueldo, _antiguedad) {
    especialidad = _especialidad;
    cedula_profesional = _cedula_profesional;
}

void Doctor::muestraDoctor() {
    muestraPersonal();
    cout << "Especialidad: " << especialidad << endl;
    cout << "Cédula Profesional: " << cedula_profesional << endl;
}

void Doctor::recetar() {
    cout << "El doctor " << nombre << " de especialidad " << especialidad << " está recetando un nuevo tratamiento" << endl;
}

Enfermero::Enfermero() : Personal() {
    area_de_apoyo = "Sin asignar";
    uniforme = "Estándar";
}

Enfermero::Enfermero(string _nombre, int _edad, string _nacionalidad, float _sueldo, string _antiguedad, string _area_de_apoyo, string _uniforme) : Personal(_nombre, _edad, _nacionalidad, _sueldo, _antiguedad) {
    area_de_apoyo = _area_de_apoyo;
    uniforme = _uniforme;
}

void Enfermero::muestraEnfermero() {
    muestraPersonal();
    cout << "Área de apoyo: " << area_de_apoyo << endl;
    cout << "Uniforme: " << uniforme << endl;
}

int main() {
    cout << "\n--- DEMOSTRACIÓN DE PACIENTE ---\n" << endl;
    Paciente paciente1("Juan ", 45, "Mexicana", "Gripe");
    paciente1.show_paciente();
    paciente1.solicitar_comida();
    paciente1.llamada_emergencia();
    cout << "Enfermedad: " << paciente1.get_enfermedad() << endl;
    
    cout << "\n--- DEMOSTRACIÓN DE PACIENTE TERMINAL ---\n" << endl;
    Terminal terminalCustom("Carlos ", 65, "Mexicana", "Insuficiencia renal", 15, 2);
    terminalCustom.show_terminal();
    terminalCustom.cambiar_dias(5);
    terminalCustom.cambiar_visitas(1);
    cout << "Días actualizados: " << terminalCustom.get_dias() << endl;
    cout << "Visitas actualizadas: " << terminalCustom.get_visitas() << endl;
    
    cout << "\n--- DEMOSTRACIÓN DE PACIENTE NO TERMINAL ---\n" << endl;
    NoTerminal noTerminalCustom("Ana ", 30, "Mexicana", "Fractura", "Rehabilitación", "Cirugía ortopédica");
    noTerminalCustom.show_paciente();
    cout << "Tratamiento inicial: " << noTerminalCustom.get_tratamiento() << endl;
    cout << "Operación inicial: " << noTerminalCustom.get_operacion() << endl;
    noTerminalCustom.cambiar_tratamiento("Terapia ocupacional");
    noTerminalCustom.cambiar_operacion("Revisión quirúrgica");
    cout << "Tratamiento actualizado: " << noTerminalCustom.get_tratamiento() << endl;
    cout << "Operación actualizada: " << noTerminalCustom.get_operacion() << endl;
    
    cout << "\n--- DEMOSTRACIÓN DE PERSONAL ---\n" << endl;
    Personal personal1("Roberto ", 40, "Mexicana", 15000.50, "5 años");
    personal1.muestraPersonal();
    
    cout << "\n--- DEMOSTRACIÓN DE DOCTOR ---\n" << endl;
    Doctor doctor1("Laura ", 38, "Mexicana", 35000.75, "10 años", "Cardiología", "MED-56789");
    doctor1.muestraDoctor();
    doctor1.recetar();
    
    cout << "\n--- DEMOSTRACIÓN DE ENFERMERO ---\n" << endl;
    Enfermero enfermero1("Miguel ", 29, "Mexicana", 12500.25, "3 años", "Urgencias", "Azul marino");
    enfermero1.muestraEnfermero();
    
    return 0;
}
