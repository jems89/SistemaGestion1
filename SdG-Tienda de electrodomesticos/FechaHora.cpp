#include "FechaHora.h"
#include "Menu.h"
#include <ctime>
using namespace std;

int  FechaHora::getDia() {
    return _dia;
}
int  FechaHora::getMes() {
    return _mes;
}
int  FechaHora::getAnio() {
    return _anio;
}
int  FechaHora::getHora() {
    return _hora;
}
int  FechaHora::getMinuto() {
    return _minuto;
}
void FechaHora::setDia(int dia) {
    
    _dia = dia;
}
void FechaHora::setMes(int mes) {
    _mes = mes;
}
void FechaHora::setAnio(int anio) {
    _anio = anio;
}
void FechaHora::setHora(int hora) {
    _hora = hora;
}
void FechaHora::setMinuto(int minuto) {
    _minuto = minuto;
}
FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto) {
    _dia = dia;
    _mes = mes;
    _anio = anio;
    _hora = hora;
    _minuto = minuto;
}
FechaHora::FechaHora() {
    time_t rawtime;
    struct tm timeinfo;

    time(&rawtime);
    timeinfo = *(localtime(&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
    _hora = timeinfo.tm_hour;
    _minuto = timeinfo.tm_min;
}
void FechaHora::cargarFecha() {
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::GREEN);
    Menu reg;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::GREEN);
    reg.Menurectangulo(49, 20,10, 3, "D?a:");
    cin >> _dia;
    reg.Menurectangulo(59, 20, 10, 3, "Mes:");
    cin >> _mes;
    reg.Menurectangulo(69, 20, 10, 3, "A?o:");
    cin >> _anio;
}

void FechaHora::mostrarFecha() {
    if (_dia < 10)cout << '0';
    cout << _dia << '/';
    if (_mes < 10)cout << '0';
    cout << _mes << '/';
    cout << _anio;
}

void FechaHora::mostrarHora() {
    if (_hora < 10)cout << '0';
    cout << _hora << ':';
    if (_minuto < 10)cout << '0';
    cout << _minuto;
}