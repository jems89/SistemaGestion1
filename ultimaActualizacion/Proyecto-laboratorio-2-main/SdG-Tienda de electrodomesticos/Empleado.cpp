#include "Empleado.h"
#include "Menu.h"

int Empleado::getID()
{
    return ID;
}

void Empleado::setID(int ID)
{
    this->ID = ID;
}

int Empleado::getCategoria()
{
    return categoria;
}

void Empleado::setCategoria(int categoria)
{
    this->categoria = categoria;
}

char Empleado::getTurno()
{
    return turno;
}

void Empleado::setTurno(char turno)
{
    this->turno = turno;
}

FechaHora Empleado::getFechaDeIngreso()
{
    return fechaDeIngreso;
}

void Empleado::setFechaDeIngreso(FechaHora fechaDeIngreso)
{
    this->fechaDeIngreso = fechaDeIngreso;
}

char Empleado::getTipoJornada()
{
    return tipoJornada;
}

void Empleado::setTipoJornada(char tipoJornada)
{
    this->tipoJornada = tipoJornada;
}

float Empleado::getSueldo()
{
    return sueldo;
}

void Empleado::setSueldo(float sueldo)
{
    this->sueldo = sueldo;
}

void Empleado::cargar() {
	Menu me;
	Persona::cargar();
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
	do {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
		me.Menurectangulo(49, 23, 35, 3, "");
		std::cout << "Categoria";
		me.Menurectangulo(49, 26, 35, 3, "");
		std::cout << "1-Gerente/2-Cajero/3-Vendedor/4-Auxiliar de Limpieza): ";
		std::cin >> categoria;
		if (categoria < 1 || categoria>4)
		{
			rlutil::cls();
			std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 || categoria>4);
	int dia, mes, anio;
	me.Menurectangulo(49, 29, 35, 3, "");
	std::cout << "Fecha de ingreso:\n";
	me.Menurectangulo(49, 32, 10, 3, "");
	std::cout << "Dia:";
	std::cin >> dia;
	fechaDeIngreso.setDia(dia);
	me.Menurectangulo(59, 32, 10, 3, "");
	std::cout << "Mes:";
	std::cin >> mes;
	fechaDeIngreso.setMes(mes);
	me.Menurectangulo(69, 32, 10, 3, "");
	std::cout << "Anio:";
	std::cin >> anio;
	fechaDeIngreso.setAnio(anio);
	do
	{
		me.Menurectangulo(49, 35, 45, 3, "");
		std::cout << "Tipo de jornada(f-Full-time/p-Part-time): ";
		std::cin >> tipoJornada;
		if (tolower(tipoJornada) != 'f' && tolower(tipoJornada) != 'p')
		{
			rlutil::cls();
			std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
			rlutil::anykey();
			rlutil::cls();
		}
	} while (tolower(tipoJornada) != 'f' && tolower(tipoJornada) != 'p');
	do {
		me.Menurectangulo(49, 38, 45, 3, "");
		std::cout << "Turno (M-Mañana/T-Tarde/N-Noche): ";
		std::cin >> turno;
		if (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n')
		{
			rlutil::cls();
			me.Menurectangulo(49, 8, 45, 3, "Error. Por favor ingrese un valor válido.");
			
			rlutil::anykey();
			rlutil::cls();
		}
	} while (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n');
	do {
		me.Menurectangulo(49, 41, 45, 3, "");
		std::cout << "Sueldo: ";
		std::cin >> sueldo;
		if (sueldo<=0)
		{
			rlutil::cls();
			me.Menurectangulo(49, 8, 45, 3, "Error. Por favor ingrese un sueldo válido.");
			
			rlutil::anykey();
			rlutil::cls();
		}
	} while (sueldo<=0);
	ID = contRegistros()+1;
	if (grabarEnDisco())
	{
		system("cls");
		me.Menurectangulo(49, 8, 45, 3, "Empleado guardado con exito."); 
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		me.Menurectangulo(49,12, 45, 3, "");
		system("pause");
		system("cls");
		
	}
}

void Empleado::mostrar() {
    if (estado)
    {
        Persona::mostrar();

		std::cout << std::endl;
        std::cout << "ID: " << ID << "\t";
        std::cout << "Categoria: " << categoria << "\t";
        std::cout << "Fecha de ingreso:";
		fechaDeIngreso.mostrarFecha(); std::cout <<std::endl;
        std::cout << "Tipo de jornada: ";
        if (tolower(tipoJornada) == 'p')
        {
            std::cout << "Part-time" << "\t";
        }
        else
        {
            std::cout << "Full-time" << "\t";
        }
        std::cout << "Turno: ";
        switch (tolower(turno))
        {
        case 'm':
            std::cout << "Mañana" << "\t";
            break;
        case 't':
			std::cout << "Tarde" << "\t";
            break;
        default:
            std::cout << "Noche" << "\t";
            break;
        }
        std::cout << "Sueldo: $" << sueldo << std::endl << std::endl << std::endl << std::endl;
    }
}

bool Empleado::grabarEnDisco() {
    FILE* p = NULL;
    p = fopen("empleados.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Empleado), 1, p);
    fclose(p);
    return 1;
}
bool Empleado::leerDeDisco(int pos) {
    FILE* p = NULL;

	bool ok=false;
    p = fopen("empleados.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return false;
    }
    fseek(p, pos * sizeof(Empleado), 0);
    ok=fread(this, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

int Empleado::contRegistros()
{
	size_t bytes;
	int cant_reg;

	FILE* p = fopen("empleados.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	
	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Empleado);
	return cant_reg;
}

void Empleado::modificarEmpleado() {

	int opcion, ingreso;
	bool ingresoCorrecto = true;
	FechaHora nuevaFecha;
	std::string palabra;
	do
	{
		std::cout << "Ingrese el ID del empleado o 0 para volver atras: ";
		std::cin >> ingreso;
		rlutil::cls();
		if (buscarRegistro(ingreso) == -1 && ingreso != 0)
		{
			std::cout << "No se ha encontrado el empleado. Por favor vuelva a intentarlo.";
			rlutil::anykey();
			rlutil::cls();
			ingresoCorrecto = false;
		}
		else leerDeDisco(ingreso);
	} while (!ingresoCorrecto);
	if (ingreso != 0)
	{
		
		do {
			
			std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
			std::cout << "1-DNI" << std::endl;
			std::cout << "2-Fecha de nacimiento" << std::endl;
			std::cout << "3-Nombre" << std::endl;
			std::cout << "4-Apellido" << std::endl;
			std::cout << "5-Categoría" << std::endl;
			std::cout << "6-Tipo de jornada" << std::endl;
			std::cout << "7-Turno" << std::endl;
			std::cout << "8-Sueldo" << std::endl;
			std::cout << "-------------------" << std::endl;
			std::cout << "------------------" << std::endl;
			std::cout << "0-Volver" << std::endl << std::endl;
			std::cout << "Ingrese una opción: ";
			std::cin >> opcion;
			rlutil::cls();
			switch (opcion)
			{
			case 1:
				std::cout << "Ingrese un nuevo DNI: ";
				std::cin >> dni;
				rlutil::cls();
				std::cout << "DNI modificado con exito." << std::endl;
				break;
			case 2:
				std::cout << "Ingrese nueva fecha de nacimiento:" << std::endl;
				nuevaFecha.cargarFecha();
				setFechaDeNacimiento(nuevaFecha);
				rlutil::cls();
				std::cout << "Fecha de nacimiento modificada con exito." << std::endl;
				break;
			case 3:
				std::cout << "Ingrese el nombre nuevo: ";
				std::cin.ignore();
				std::getline(std::cin, palabra);
				setNombre(palabra);
				rlutil::cls();
				std::cout << "Nombre modificado con exito." << std::endl;
				break;
			case 4:
				std::cout << "Ingrese el apellido nuevo: ";
				std::cin.ignore();
				std::getline(std::cin, palabra);
				setApellido(palabra);
				rlutil::cls();
				std::cout << "Apellido modificado con exito." << std::endl;
				break;
			case 5:
				std::cout << "Ingrese la categoría nueva: " << std::endl;
				std::cin >> categoria;
				rlutil::cls();
				std::cout << "Categoría modificada con exito." << std::endl;
				break;
			case 6:
				std::cout << "Ingrese el nuevo tipo de jornada (p-Part time/f-Full time): " << std::endl;
				std::cin >> tipoJornada;
				rlutil::cls();
				std::cout << "Tipo de jornada modificada con exito." << std::endl;
				break;
			case 7:
				std::cout << "Ingrese el nuevo turno (m-Mañana/t-Tarde/n-Noche): " << std::endl;
				std::cin >> turno;
				rlutil::cls();
				std::cout << "Turno modificado con exito." << std::endl;
				break;
			case 8:
				std::cout << "Ingrese el nuevo sueldo: " << std::endl;
				std::cin >> sueldo;
				rlutil::cls();
				std::cout << "Sueldo modificado con exito." << std::endl;
				break;
			default:
				if (opcion != 0)
				{
					std::cout << "Por favor ingrese una opción correcta.";
				}
				break;
			}
			if (opcion != 0) {
				rlutil::anykey();
				modificarEnDisco(ingreso);
			}
			//modificarEnDisco()
		} while (opcion != 0);
	}
	rlutil::cls();
}

int Empleado::eliminarEmpleado() {
	FILE* p;
	int escribio;
	int id;
	bool bandera = false;
	p = fopen("empleados.dat", "rb+");
	if (p == NULL)
	{
		std::cout << "Error de archivo";
		return -1;
	}
		std::cout << "Ingrese el ID del empleado a eliminar o presione 0 para volver atras: ";
		std::cin >> id;
		while (fread(this, sizeof(Empleado), 1, p) == 1)
		{
			if (id == ID)
			{
				estado = false;
				// se cambia el valor del campo estado
				fseek(p, ftell(p) - sizeof(Empleado), 0);
				//desplazamiento de part un registro hacia atrás
				escribio = fwrite(this, sizeof(Empleado), 1, p);
				// escritura del registro modificado
				fclose(p);
				return escribio;

			}
		}
		fclose(p);
	return -2;
}


void Empleado::listarEmpleado() {
	int opcion, d, pos;
	bool bandera = false;
	do
	{
		pos = 0;
		std::cout << "1-Listar todos los empleados" << std::endl;
		std::cout << "2-Listar un empleado" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "0-Volver" << std::endl << std::endl;
		std::cout << "Ingrese una opción: ";
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			for (int i = 0; i < contRegistros(); i++)
			{
				leerDeDisco(i);
				mostrar();
				if(estado)std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el ID del empleado que quiere listar: ";
			std::cin >> d;
			rlutil::cls();
			for (int i = 0; i < contRegistros(); i++)
			{
				leerDeDisco(i);
				if (d == ID)
				{
					mostrar();
					bandera = true;
					i = contRegistros();
				}
			}
			if (!bandera)std::cout << "No se ha podido encontrar el empleado." << std::endl;
			break;
		default:
			if (opcion != 0)
			{
				std::cout << "Por favor ingrese una opción correcta.";
			}
			break;
		}
		bandera = false;
		if (opcion != 0)rlutil::anykey();
		rlutil::cls();
	} while (opcion != 0);
}
bool Empleado::modificarEnDisco(int pos) {
	
	FILE* p = NULL;
	bool modifico = false;
	p = fopen("empleados.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Empleado), 0);
	modifico=fwrite(this, sizeof(Empleado), 1, p);
	fclose(p);
	return modifico;
}

int Empleado::buscarRegistro(int id) {
	for (int i = 0; i < contRegistros(); i++)
	{
		if (id == ID) return i;
	}
	return -1;
}
