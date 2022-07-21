#include "Menu.h"
#include "rlutil.h"
#include <iostream>

void showItem(const char* texto, int x, int y, bool seleccionar)
{
    if (seleccionar) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    else { rlutil::setBackgroundColor(rlutil::BLACK); }

    rlutil::locate(x, y);
    std::cout << texto << std::endl;

}
void Menu::Menurectangulo(int x, int y, int ancho, int alto, const char* texto)
{



    for (int i = x; i <= x + ancho; i++) {

        gotoxy(i, y);
        std::cout << "*";
        gotoxy(i, y + alto);
        std::cout << "*";
    }
    for (int i = y; i <= y + alto; i++) {
        gotoxy(x, i);
        std::cout << "*";
        gotoxy(x + ancho, i);
        std::cout << "*";
    }
    gotoxy(x + 2, y + alto / 2);
    std::cout << texto;



}
Menu::Menu()
{
    color = 1 + rand() % 10;
    if (color == 0) { rlutil::setColor(rlutil::WHITE); }
    if (color == 15 || color == 14 || color == 7) { rlutil::setColor(rlutil::BLACK); }
    rlutil::setBackgroundColor(color);
    Menurectangulo(40, 1, 44, 5, " BIENVENIDOS A TIENDA DE ELECTROCOMPRAME ");
}
void Menu::menuPrincipal() {
    int opcion;
    bool salir = true;
    char salirdelSistema;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
    while (salir)
    {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLUE);
        Menurectangulo(32, 7, 60, 16, "");
        // int x = 40;
        rlutil::locate(40, 9);
        std::cout << "MENU PRINCIPAL DE GESTION " << std::endl;
        rlutil::locate(40, 10);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "1 - VENTAS" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "2 - COMPRAS " << std::endl;
        rlutil::locate(40, 13);
        std::cout << "3 - EMPLEADOS " << std::endl;
        rlutil::locate(40, 14);
        std::cout << "4 - CLIENTES " << std::endl;
        rlutil::locate(40, 15);
        std::cout << "5 - REPORTES " << std::endl;
        rlutil::locate(40, 16);
        std::cout << "6 - PRODUCTOS " << std::endl;
        rlutil::locate(40, 17);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 18);
        std::cout << "0 - SALIR" << std::endl;
        rlutil::locate(38, 19);
        std::cout << "> ";
        std::cin >> opcion;
        switch (opcion) {

        case 1:menuVentas();
            break;
        case 2: menuCompras();
            system("cls");
            break;
        case 3:menuEmpleados();
            system("cls");
            break;
        case 4:menuClientes();
            system("cls");
            break;
        case 5:menuReportes();
            system("cls");
            break;
        case 6:menuProducto();
            system("cls");
            break;
        case 0:
            system("cls");
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::WHITE);
            Menurectangulo(40,20, 30, 3, " CONFIRMAR SALIDA? S/N \0"); std::cout << std::endl;
            // rlutil::locate(40, 2);
             //std::cout << " CONFIRMAR SALIDA? S/N " << std::endl;
            rlutil::locate(53,22);
            std::cin >> salirdelSistema;
            if (tolower(salirdelSistema) == 's') { salir = false; }
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE);
            system("cls");
            break;
        }
    }
}
void Menu::menuVentas() {
    Venta venta;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR VENTA" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR VENTA" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR VENTA" << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR VENTA/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion) {
        case 1: venta.cargar();
            
            break;
        case 2:venta.modificarVenta();
            break;
        case 3:venta.eliminarVenta();
            break;
        case 4:venta.listarVenta();
            break;
        default:
            rlutil::cls();
            if (opcion != 0) {

                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");

                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
            }
            break;
        }
    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}
void Menu::menuCompras() {
    Compra compra;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR COMPRA" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR COMPRA" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR COMPRA " << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR COMPRA/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion) {
        case 1: compra.Cargar();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            if (opcion != 0) {
                system("cls");
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
                rlutil::setColor(rlutil::WHITE);
            }
            break;
        }
    } while (opcion !=0);
    system("cls");
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);

}
void Menu::menuEmpleados() {
    Empleado empleado;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::GREEN);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::GREEN);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR EMPLEADO" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR EMPLEADO" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR EMPLEADO" << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR EMPLEADO/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            empleado.cargar();
            break;
        case 2: empleado.modificarEmpleado();
            break;
        case 3: //empleado.eliminarEmpleado();
            break;
        case 4: empleado.listarEmpleado();
            break;
        default:
            if (opcion != 0) {
                system("cls");
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::GREEN);
                rlutil::setColor(rlutil::WHITE);
            }

        }

    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}
void Menu::menuClientes() {
    Cliente cliente;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR CLIENTE" << std::endl;
        Menurectangulo(49,11,25, 3, "");
        std::cout << "2 - MODIFICAR CLIENTE" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR CLIENTE " << std::endl;
        Menurectangulo(49,17, 25, 3, "");
        std::cout << "4 - LISTAR CLIENTE/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";

        std::cin >> opcion;
        rlutil::cls();
        switch (opcion) {
        case 1:
            cliente.cargar();
            break;
        case 2:
            cliente.modificarCliente();
            break;
        case 3: cliente.eliminarCliente();
            break;
        case 4: cliente.listarCliente();
            break;
        default:
            if (opcion != 0) {
                system("cls");
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::MAGENTA);
                rlutil::setColor(rlutil::WHITE);
            }
            break;
        }

    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}
void Menu::menuReportes() { /// reporte de ventas
    bool salir = true;
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    while (salir)
    {
        system("cls");
        Menu();
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        rlutil::setColor(rlutil::WHITE);
        Menurectangulo(40, 8, 42, 3, "  MENÚ PRINCIPAL DE REPORTES ");
        Menurectangulo(40, 11, 52, 3, "");
        std::cout << "1 -NOMBRE DEL PRODUCTO MAS VENDIDO EN EL 2022" << std::endl;///refiere a clase venta
        Menurectangulo(40, 14, 52, 3, "");
        std::cout << "2 - NOMBRE DEL VENDOR CON MAS VENTAS EN EL MES" << std::endl;/// refiere clase pruduto dentro venta contar el producto mas vendido
        Menurectangulo(40, 17, 52, 3, "");
        std::cout << "3 -INGRESOS MENSUALES DE LA TIENDA " << std::endl;///refiere a clase venta
        Menurectangulo(40, 20, 52, 3, "");
        std::cout << "4 - CLIENTE CON MAS COMPRAS EN EL ANIO" << std::endl;
        Menurectangulo(40, 23, 52, 3, "");
        std::cout << "5 - EMPLEADO CON MAYOR SUELDO " << std::endl;//refiere a clase venta
        Menurectangulo(40, 26, 52, 3, "");
        std::cout << "6 - PATRIMONIO NETO " << std::endl;
        Menurectangulo(40, 29, 52, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        int pos;
        Menurectangulo(40, 32, 52, 3, "");
        std::cout << "> ";
        std::cin >> pos;

        switch (pos)
        {
            int ok;
        case 1:const char * FuncionProductoMasVendido(FechaHora anio);
            break;
        case 2:  const char* FuncionVendedorConMasVentas(FechaHora mes);
            break;
        case 3: float FuncionIngresosEnVentasXmes(FechaHora mes);
            break;
        case 4: const char* FuncionClienteConMasVentas(Venta registro);
            break;
        case 5: const char* FuncionEmpleadoConMayorSueldo();
            break;
        case 6: float FuncionPatrimonioNeto(Compra registro);
            break;
        case 0: 
            system("cls");
            
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
            rlutil::setColor(rlutil::WHITE);
            Menurectangulo(40, 11, 42, 3, "");
            std::cout << "Seguro que quier salir ?" << std::endl;
            Menurectangulo(40, 14, 42, 3, "");
            std::cout << "1/ SI " << std::endl;
            Menurectangulo(40, 17, 42, 3, "");
            std::cout << "2/ NO " << std::endl;
            Menurectangulo(40, 20, 42, 3, "");
            std::cin >>ok;
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
            rlutil::setColor(rlutil::WHITE);
            while (!(ok==1 || ok==2)){
                system("cls");
                rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(40, 8, 42, 3, "");
                std::cout << "Ingrese un numero valido PorFavor " << std::endl;
                Menurectangulo(40, 11, 42, 3, "");
                std::cout << "Seguro que quier salir ?" << std::endl;
                Menurectangulo(40, 14, 42, 3, "");
                std::cout << "1/ SI " << std::endl;
                Menurectangulo(40, 17, 42, 3, "");
                std::cout << "2/ NO " << std::endl;
                Menurectangulo(40, 20, 52, 3, "");
                std::cin >> ok;
            }
            if (ok == 1) { salir = false; }
            else {
                salir = true; menuReportes();
            }

            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE); salir = false;
            break;
        }
    }
}
/* void Menu::menuPrincipal() {
    int opcion;
    bool salir = true;
    while (salir)
    {
        std::cout << "MENÚ PRINCIPAL DE GESTIÓN " << std::endl;
        std::cout << "1 - VENTAS" << std::endl;//Lucho
        std::cout << "2 - COMPRAS " << std::endl;//Jony
        std::cout << "3 - EMPLEADOS " << std::endl;//Lucho
        std::cout << "4 - CLIENTES " << std::endl;//Lucho
        std::cout << "5 - REPORTES " << std::endl;//Jony
        std::cout << "------------------" << std::endl;
        std::cout << "0 - SALIR" << std::endl;
        std::cout << "INGRESE UNA OPCION " << std::endl;
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1: menuVentas();
            break;
        case 2: menuCompras();
            break;
        case 3: menuEmpleados();
            break;
        case 4: menuClientes();
            break;
        case 5: menuReportes();
            break;
        case 0: salir = false;
            break;
        default:
            std::cout << "Por favor ingrese una opción correcta." << std::endl;
            rlutil::anykey();
        }
    }
}*/
void Menu::menuProducto() {
    Producto producto;
    int opcion;
    bool ok = true;
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR PRODUCTO" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR PRODUCTO" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR PRODUCTO" << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR PRODUCTOS " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            producto.cargar();

            break;
        case 2: 
            producto.ModificarProducto();

            break;
        case 3: //empleado.eliminarEmpleado();
            break;

        case 4:
            rlutil::setColor(rlutil::BLACK);
            rlutil::setBackgroundColor(rlutil::WHITE);
            while (ok)
            {
             
                system("cls");
                Menu ob;
                
                rlutil::setColor(rlutil::BLACK);
                rlutil::setBackgroundColor(rlutil::WHITE);
                int opc, cod;
                ob.Menurectangulo(49, 8, 25, 3, "");
                std::cout << "Seleccion una opcion" << std::endl;
                ob.Menurectangulo(49, 11, 25, 3, "");
                std::cout << "1 Listar Todos" << std::endl;
                ob.Menurectangulo(49, 14, 25, 3, "");
                std::cout << "2 Listar por Codigo " << std::endl;
                ob.Menurectangulo(49, 17, 25, 3, "");
                std::cout << "0 Volver " << std::endl;
                ob.Menurectangulo(49, 20, 25, 3, "");
                std::cin >> opc;
                switch (opc)
                {
                case 1:producto.ListarTodosLosProductos();
                    break;
                case 2:
                    system("cls");
                    rlutil::setColor(rlutil::BLACK);
                    rlutil::setBackgroundColor(rlutil::WHITE);
                    ob.Menurectangulo(49, 8, 25, 3, "");
                    std::cout << "Ingrese Codigo a Buscar" << std::endl;
                    ob.Menurectangulo(49, 11, 25, 3, "");
                    std::cout << "0 - Volver " << std::endl;
                    ob.Menurectangulo(49, 14, 25, 3, "");
                    std::cin >> cod;
                    producto.ListarPorCodigo(cod);
                    break;
                case 0: ok = false;

                    break;
                default: std::cout << " Ingrese un numero correcto ";
                    break;
                }

            }

        }
    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}