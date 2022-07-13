#include "Persona.h"
#include"Menu.h"

Persona::Persona(){

	std::string vacio = " ";
	strcpy(nombre,vacio.c_str());
	strcpy(apellido, vacio.c_str());
	estado = true;
}
void Persona::cargar() {
	Menu reg;
	std::string palabra;
	estado = true;
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
	system("cls");
	Menu();
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
	reg.Menurectangulo(49, 8, 25, 3, "Nombre: ");
	std::cin.ignore();
	std::getline(std::cin,palabra);
	setNombre(palabra);
	reg.Menurectangulo(49, 11, 25, 3, "Apellido: ");
	std::getline(std::cin,palabra);
	setApellido(palabra);
	reg.Menurectangulo(49, 14, 25, 3, "DNI: ");
	std::cin >> dni;
	reg.Menurectangulo(49, 17, 25, 3, "Fecha de nacimiento: \n");
	fechaDeNacimiento.cargarFecha();
	//domicilio.cargar();
}
void Persona::mostrar() {
	std::cout << "Nombre y apellido: ";
	std::cout << nombre << " " << apellido << "\t";
	std::cout << "DNI: ";
	std::cout << dni << "\t";
	std::cout << "Fecha de nacimiento: ";
	fechaDeNacimiento.mostrarFecha(); std::cout<<"\t";
	//domicilio.mostrar();	
}


std::string Persona::getApellido() 
{
	std::string apellido = this->apellido;
    return apellido;
}

void Persona::setApellido(std::string apellido)
{
    strcpy(this->apellido,apellido.c_str());
}

std::string Persona::getNombre() 
{
	std::string nombre = this->nombre;
    return nombre;
}

void Persona::setNombre(std::string nombre)
{
    strcpy(this->nombre, nombre.c_str());
}

int Persona::getDni() const
{
    return dni;
}

void Persona::setDni(int dni)
{
    this->dni = dni;
}

FechaHora Persona::getFechaDeNacimiento() 
{
    return fechaDeNacimiento;
}

void Persona::setFechaDeNacimiento(FechaHora fechaDeNacimiento)
{
    this->fechaDeNacimiento = fechaDeNacimiento;
}
/*
Direccion Persona::getDomicilio() 
{
    return domicilio;
}

void Persona::setDomicilio(Direccion domicilio)
{
    this->domicilio = domicilio;
}
*/
bool Persona::getEstado()
{
	return estado;
}

void Persona::setEstado(bool estado)
{
	this->estado = estado;
}