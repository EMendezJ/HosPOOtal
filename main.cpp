#include "hospital.cpp"
#include <iostream>
using namespace std;

int main() {
    // Crear un doctor
    Doctor dr("Juan Pérez", 45, "Mexicana", 25000.0, "10 años", "Cardiología", "CED12345");
    
    // Crear un enfermero
    Enfermero enf("María López", 35, "Mexicana", 15000.0, "5 años", "Pediatría", "Blanco");
    
    // Crear pacientes
    Terminal pacTerm("Carlos Sánchez", 60, "Mexicana", "Cáncer terminal", 30, 2);
    NoTerminal pacNoTerm("Ana García", 42, "Mexicana", "Apendicitis", "Antibióticos", "Apendicectomía");
    
    // Mostrar información del personal
    cout << "\n===== INFORMACIÓN DEL DOCTOR =====" << endl;
    dr.muestraDatos();
    dr.recetar();
    
    cout << "\n===== INFORMACIÓN DEL ENFERMERO =====" << endl;
    enf.muestraDatos();
    enf.darDeComer();
    
    // Mostrar información de pacientes
    cout << "\n===== INFORMACIÓN DEL PACIENTE TERMINAL =====" << endl;
    pacTerm.muestraDatos();
    pacTerm.solicitar_comida();
    
    cout << "\n===== INFORMACIÓN DEL PACIENTE NO TERMINAL =====" << endl;
    pacNoTerm.muestraDatos();
    pacNoTerm.llamada_emergencia();
    
    // Demostrar cambio de días para paciente terminal
    cout << "\n===== ACTUALIZACIÓN DE DÍAS DEL PACIENTE TERMINAL =====" << endl;
    pacTerm.cambiarr_dias(15);
    pacTerm.muestraDatos();
    
    return 0;
} 