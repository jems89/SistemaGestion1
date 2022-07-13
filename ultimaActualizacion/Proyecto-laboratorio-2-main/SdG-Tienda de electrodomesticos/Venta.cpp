#include "Venta.h"
#include "Menu.h"

Venta::Venta() {
    // Valores por omisión
    cantidadComprada = cantidadCuotas = 0;
    metodoPago = '-';
    envioADomicilio = false;
    estado = true;

    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
    if (cantidadComprada<=25)
    {
        descuentoPorCantidad = cantidadComprada / 5 * 10;
    }
    else
    {
        descuentoPorCantidad = 50;
    }
    /*
    // Importe final de la compra
    costoFinal = productoComprado.getPrecio() * cantidadComprada - productoComprado.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;

    // Costo por cuota
    if (cantidadCuotas > 0) costoCuota = costoFinal / cantidadCuotas;
    else costoCuota = costoFinal;
    */
    // Numero de venta
    numeroVenta = contVentas() + 1;
}

int Venta::getCantidadComprada()
{
    return cantidadComprada;
}

void Venta::setCantidadComprada(int cantidadComprada)
{
    this->cantidadComprada = cantidadComprada;
}

int Venta::getCantidadCuotas()
{
    return cantidadCuotas;
}

void Venta::setCantidadCuotas(int cantidadCuotas)
{
    this->cantidadCuotas = cantidadCuotas;
}

int Venta::getDescuentoPorCantidad()
{
    return descuentoPorCantidad;
}
/*
void Venta::setDescuentoPorCantidad()
{
    
}

Direccion Venta::getDireccionLocal()
{
    return direccionLocal;
}

void Venta::setDireccionLocal(Direccion direccionLocal)
{
    this->direccionLocal = direccionLocal;
}
*/

FechaHora Venta::getFechaYHoraDeLaVenta()
{
    return fechaYHoraDeLaVenta;
}

void Venta::setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta)
{
    this->fechaYHoraDeLaVenta = fechaYHoraDeLaVenta;
}

char Venta::getMetodoPago()
{
    return metodoPago;
}

void Venta::setMetodoPago(char metodoPago)
{
    this->metodoPago = metodoPago;
}

bool Venta::getEnvioADomicilio()
{
    return envioADomicilio;
}

void Venta::setEnvioADomicilio(bool envioADomicilio)
{
    this->envioADomicilio = envioADomicilio;
}

bool Venta::buscarVendedor(int id)
{
    Empleado e;
    int pos = 0;
    while (e.leerDeDisco(pos++))
    {
        if (id == e.getID())return 1;
    }
    return 0;
}

Producto Venta::buscarProducto(int codigo)
{
    Producto p;
    int pos;
    while (true)
    {
        pos = 0;
        while (p.leerDeDisco(pos++))
        {
            if (p.getCodigo() == codigo) return p;
        }
        system("cls");
        std::cout << "No se ha encontrado el producto. Por favor ingrese un código existente: ";
        std::cin >> codigo;
        system("pause");
        system("cls");
    }
}

bool Venta::buscarCliente(int dni)
{
    Cliente c;
    int pos = 0;
    while (c.leerDeDisco(pos++))
    {
        if (c.getDni() == dni)return true;
    }
    return false;
}

Cliente Venta::cargarCliente(int dni)
{
    Cliente c;
    int pos = 0;
    while (c.leerDeDisco(pos++))
    {
        if (c.getDni() == dni) return c;
    }
}

Empleado Venta::cargarEmpleado(int id)
{
    Empleado e;
    int pos = 0;
    while (e.leerDeDisco(pos++))
    {
        if (e.getID() == id) return e;
    }
}


int Venta::contVentas()
{
    FILE* p;
    p = fopen("ventas.dat", "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, 2);
    fread(this, sizeof(Venta), 1, p);
    fclose(p);
    return numeroVenta;
}
bool Venta::grabarEnDisco()
{
    FILE* p = NULL;
    p = fopen("ventas.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Venta), 1, p);
    fclose(p);
    return 1;
}

bool Venta::leerDeDisco(int pos)
{
    FILE* p = NULL;
    p = fopen("ventas.dat", "rb+");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Venta), 0);
    fread(this, sizeof(Venta), 1, p);
    fclose(p);
    return 1;
}


void Venta::cargar() {
    Cliente cliente;
    Producto producto;
    Menu obj;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    system("cls");
    Menu();
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    obj.Menurectangulo(37, 7, 49, 14, "");
    rlutil::locate(43, 9);
    std::cout << "Código del producto: ";
    std::cin >> codigoProducto;
    //producto = buscarProducto(codigoProducto);
    rlutil::locate(43, 10);
    std::cout << "Cantidad comprada: ";
    std::cin >> cantidadComprada;
    rlutil::locate(43, 11);
    std::cout << "Cuotas: ";
    std::cin >> cantidadCuotas;
    rlutil::locate(43, 12);
    std::cout << "Método de pago (e - efectivo/t - tarjeta): ";
    std::cin >> metodoPago;
    rlutil::locate(43, 13);
    std::cout << "¿Se envía al domicilio del cliente? (1 o 2 ): ";
    std::cin >> envioADomicilio;
    rlutil::locate(43, 14);
    std::cout << "ID del vendedor: ";
    std::cin >> IDVendedor;
    /*while (!buscarVendedor(IDVendedor))
    {
        system("cls");
        std::cout << "Error. Por favor ingrese un ID de vendedor válido." << std::endl;
        system("pause");
        system("cls");
        std::cout << "ID del vendedor: ";
        std::cin >> IDVendedor;
    }*/
    rlutil::locate(43, 15);
    std::cout << "DNI del cliente: ";
    std::cin >> dniCliente;
    /*if (!buscarCliente(dniCliente))
    {
        system("cls");
        std::cout << "NUEVO CLIENTE:" << std::endl << std::endl;
        cliente.cargar();
    }*/

    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
    if (cantidadComprada <= 25)
        descuentoPorCantidad = cantidadComprada / 5 * 10;
    else descuentoPorCantidad = 50;

    // Importe final de la compra
    costoFinal = producto.getPrecio() * cantidadComprada - producto.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;

    // Costo por cuota
    if (cantidadCuotas > 0) costoCuota = costoFinal / cantidadCuotas;
    else costoCuota = costoFinal;

    system("cls");
    rlutil::locate(43, 16);
    if (grabarEnDisco()) std::cout << "Venta cargada con exito." << std::endl;
    system("pause");
}



void Venta::mostrar() {
    if (estado)
    {
        Producto producto = buscarProducto(codigoProducto);
        Cliente cliente = cargarCliente(dniCliente);
        Empleado vendedor = cargarEmpleado(IDVendedor);
        std::cout << "Venta N°" << numeroVenta << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << "Producto: " << producto.getNombre() << std::endl;
        std::cout << "Cantidad: " << cantidadComprada << std::endl;
        if (metodoPago == tolower('e')) std::cout << "Metodo de pago: Efectivo";
        else std::cout << "Metodo de pago: Tarjeta";
        if (cantidadCuotas > 0)
            std::cout << cantidadCuotas << " cuotas de $" << costoCuota << std::endl;
        if (descuentoPorCantidad > 0) std::cout << "Descuento por cantidad de productos comprados: " << descuentoPorCantidad << std::endl << std::endl;
        std::cout << "Importe total: " << costoFinal << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << cliente.getNombre() << ' ' << cliente.getApellido() << std::endl;
        std::cout << "DNI: " << cliente.getDni() << std::endl << std::endl;
        std::cout << "Envío a domicilio: ";
        if (envioADomicilio) std::cout << "Sí";
        else std::cout << "No";
        std::cout << std::endl << std::endl << "Venta a cargo de: " << vendedor.getNombre() << ' ' << vendedor.getApellido() << std::endl;
        std::cout << "Vendedor N°: " << vendedor.getID() << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << "Fecha: \t";
        fechaYHoraDeLaVenta.mostrarFecha();
        std::cout << std::endl << "Hora: \t";
        fechaYHoraDeLaVenta.mostrarHora();
    }
}

/* int cantidadComprada, cantidadCuotas, descuentoPorCantidad;
	Direccion direccionLocal;
	Producto productoComprado;
	FechaHora fechaYHoraDeLaVenta;
	Cliente cliente;
	Empleado vendedor;
	char metodoPago;
	bool envioADomicilio; */

int Venta::getIDVendedor()
{
    return IDVendedor;
}

void Venta::setIDVendedor(int IDVendedor)
{
    this->IDVendedor = IDVendedor;
}

int Venta::getCodigoProducto()
{
    return codigoProducto;
}

void Venta::setCodigoProducto(int codigoProducto)
{
    this->codigoProducto = codigoProducto;
}

int Venta::getDniCliente()
{
    return dniCliente;
}

void Venta::setDniCliente(int dniCliente)
{
    this->dniCliente = dniCliente;
}

void Venta::modificarVenta() {
    int opcion;
    bool bandera;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    do {
        system("cls");
        Menu obj;
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        obj.Menurectangulo(37, 8, 49, 14, "");
        rlutil::locate(43, 9);
        std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
        rlutil::locate(43, 10);
        std::cout << "1-Cantidad Comprada" << std::endl;
        rlutil::locate(43, 11);
        std::cout << "2-Cantidad de cuotas" << std::endl;
        rlutil::locate(43, 12);
        std::cout << "3-Vendedor" << std::endl;
        rlutil::locate(43, 13);
        std::cout << "4-Producto/s" << std::endl; // NO OLVIDARSE DE PERMITIR COMPRAR MAS DE UN PRODUCTO
        rlutil::locate(43, 14);
        std::cout << "5-Cliente" << std::endl;
        rlutil::locate(43, 15);
        std::cout << "6-Método de pago" << std::endl;
        rlutil::locate(43, 16);
        std::cout << "7-Envío a domicilio" << std::endl;
        rlutil::locate(43, 17);
        std::cout << "-------------------" << std::endl;
        rlutil::locate(43, 18);
        std::cout << "------------------" << std::endl;
        rlutil::locate(43, 19);
        std::cout << "0-Volver" << std::endl << std::endl;
        rlutil::locate(40, 20);
        std::cout << "> ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            system("cls");
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Ingrese el nuevo monto de cantidad comprada: ";
            std::cin >> cantidadComprada;
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Cantidad modificada con exito." << std::endl;
            break;
        case 2:
            system("cls");
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Ingrese la cantidad de cuotas a pagar:" ;
            std::cin >> cantidadCuotas;
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Cantidad de cuotas modificada con exito." << std::endl;
            break;
        case 3:
            system("cls");
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Ingrese ID de vendedor: ";
            std::cin >> IDVendedor;
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Vendedor modificado con exito." << std::endl;
            break;
        case 4:
            system("cls");
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Ingrese ID de producto: ";
            std::cin >> codigoProducto;
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Producto modificado con exito." << std::endl;
            break;
        case 5:
            system("cls");
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Ingrese DNI del cliente: ";
            std::cin >> dniCliente;
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Cliente modificado con exito." << std::endl;
            break;
        case 6:
            bandera = false;
            do
            {
                system("cls");
                obj.Menurectangulo(37, 14, 55, 4, "");
                std::cout << "Ingrese el nuevo método de pago: " ;
                std::cin >> metodoPago;
                if (tolower(metodoPago) == 'e' || tolower(metodoPago) == 't') bandera = true;
                else
                {
                    rlutil::cls();
                    obj.Menurectangulo(37, 14, 55, 4, "");
                    std::cout << "Error. Por favor ingrese una opción válida." << std::endl;
                    rlutil::anykey();
                }
            } while (!bandera);
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Método de pago modificado con éxito." << std::endl;
            break;
        case 7:
            if (envioADomicilio == false) {
                envioADomicilio = true;
                system("cls");
                obj.Menurectangulo(37, 14, 55, 4, "");
                std::cout << "Modificación exitosa. La venta se envía al domicilio.";
                rlutil::anykey();
            }
            else { envioADomicilio = false; }
            rlutil::cls();
            obj.Menurectangulo(37, 14, 55, 4, "");
            std::cout << "Cliente modificado con exito." << std::endl;
            break;
        default:
            if (opcion != 0)
            {
                system("cls");
                obj.Menurectangulo(37, 14, 55, 4, "");
                std::cout << "Por favor ingrese una opción correcta.";
            }
            break;
        }
        if (opcion != 0)rlutil::anykey();
    } while (opcion != 0);
}

void Venta::eliminarVenta() {
    bool bandera = false;
    int ingreso, pos;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    do {
        system("cls");
        Menu obj;
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        obj.Menurectangulo(37, 8, 49, 14, "");
        rlutil::locate(43, 9);
        std::cout << "1-Eliminar venta" << std::endl;
        rlutil::locate(43, 10);
        std::cout << "2-Eliminar todas las ventas" << std::endl;
        rlutil::locate(43, 11);
        std::cout << "-------------------------------" << std::endl;
        rlutil::locate(43, 12);
        std::cout << "-------------------------------" << std::endl;
        rlutil::locate(43, 13);
        std::cout << "0-Volver atras" << std::endl;
        rlutil::locate(40, 14);
        std::cout << "> ";
        std::cin >> ingreso;
        rlutil::cls();
        switch (ingreso)
        {
        case 1:
            do
            {
                pos = 0;
                system("cls");
                obj.Menurectangulo(37, 14, 55, 4, "");
                std::cout << "Ingrese el N° de venta a eliminar o presione 0 para volver para atras: ";
                std::cin >> ingreso;
                if (ingreso != 0)
                {
                    while (leerDeDisco(pos++) && !bandera)
                    {
                        if (numeroVenta == ingreso)
                        {
                            estado = false;
                            bandera = true;
                            rlutil::cls();
                            std::cout << "Venta eliminada con exito." << std::endl;
                            rlutil::anykey();
                        }
                    }
                    ingreso = 0;
                }
                if (ingreso != 0 && !bandera)
                {
                    rlutil::cls();
                    std::cout << "Error. No se ha podido encontrar la venta. Por favor ingrese nuevamente el N° de venta." << std::endl;
                    rlutil::anykey();
                }
                rlutil::cls();
            } while (ingreso != 0);
            break;
        case 2:
            do
            {
                system("cls");
                obj.Menurectangulo(37, 12, 55, 4, "");
                std::cout << "¿Quiere eliminar todas las ventas?" << std::endl;
                obj.Menurectangulo(37, 16, 55, 4, "");
                std::cout << "Pulse 1 Para 'si' " << std::endl;
                obj.Menurectangulo(37, 20, 55, 4, "");
                std::cout << "Pulse 2 para 'No' " << std::endl << std::endl;
                obj.Menurectangulo(37, 24, 55, 4, "");
                std::cout << "Ingrese una opción: ";
                std::cin >> ingreso;
                rlutil::cls();
                if (ingreso < 1 || ingreso > 2) {
                    system("cls");
                    obj.Menurectangulo(37, 12, 55, 4, "");
                    std::cout << "Error. Por favor ingrese una opción válida." << std::endl;
                    rlutil::anykey();
                    rlutil::cls();
                }
            } while (ingreso < 1 || ingreso > 2);
            if (ingreso == 1)
            {
                pos = 0;
                while (leerDeDisco(pos++)) {
                    estado = 0;
                }
                system("cls");
                obj.Menurectangulo(37, 12, 55, 4, "");
                std::cout << "Todas las ventas han sido eliminadas con exito." << std::endl;
                rlutil::anykey();
            }
            break;
        default:
            if (ingreso != 0)
            {
                system("cls");
                obj.Menurectangulo(37, 14, 55, 4, "");
                std::cout << "Por favor ingrese una opción válida." << std::endl;
            }
            break;
        }
    } while (ingreso != 0);
}

void Venta::listarVenta() {
    int opcion, n, pos;
    bool bandera = false;
    do
    {
        pos = 0;
        std::cout << "1-Listar todas las ventas";
        std::cout << "2-Listar una venta";
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0-Volver" << std::endl << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            while (leerDeDisco(pos++)) {
                mostrar();
                std::cout << std::endl << std::endl;
            }
            break;
        case 2:
            std::cout << "Ingrese el N° de venta que quiere listar: ";
            std::cin >> n;
            rlutil::cls();
            while (leerDeDisco(pos++) && !bandera)
            {
                if (n == numeroVenta)
                {
                    mostrar();
                    bandera = true;
                }
            }
            if (!bandera)std::cout << "No se ha podido encontrar la venta." << std::endl;
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
    } while (opcion != 0);
}