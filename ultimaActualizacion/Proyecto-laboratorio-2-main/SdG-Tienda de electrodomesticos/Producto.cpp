#include "Producto.h"
#include "Menu.h"

Producto::Producto() {
    std::string vacio = " ";
    categoria = 0;
    codigo = 0;
    precio = 0;
    stock = 0;
    estado = 1;
    strcpy(nombre, vacio.c_str());
    strcpy(descripcion, vacio.c_str());
    strcpy(marca, vacio.c_str());
}

std::string Producto::getNombre() 
{
    std::string nombre = this->nombre;
    return nombre;
}

void Producto::setNombre(std::string nombre)
{
    strcpy(this->nombre, nombre.c_str());
}

std::string Producto::getMarca() 
{
    std::string marca = this->marca;
    return marca;
}

void Producto::setMarca(std::string marca)
{
    strcpy(this->marca , marca.c_str());
}

std::string Producto::getDescripcion() 
{
    std::string descripcion = this->descripcion;
    return descripcion;
}

void Producto::setDescripcion(std::string descripcion)
{
    strcpy(this->descripcion , descripcion.c_str());
}

int Producto::getCodigo() 
{
    return codigo;
}

void Producto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

bool Producto::getEstado() 
{
    return estado;
}

void Producto::setEstado(bool estado)
{
    this->estado = estado;
}

int Producto::getCategoria() 
{
    return categoria;
}

void Producto::setCategoria(int categoria)
{
    this->categoria = categoria;
}

int Producto::getStock() 
{
    return stock;
}

void Producto::setStock(int stock)
{
    this->stock = stock;
}

float Producto::getPrecio() 
{
    return precio;
}

void Producto::setPrecio(float precio)
{
    this->precio = precio;
}

void Producto::cargar() {
    Menu ob;

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    system("cls");
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    ob.Menurectangulo(49, 8, 25, 3, "");
    std::cout << "Codigo: ";///CODIGO INTERNO DE LA COMPANYA
    std::cin >> codigo;
    ob.Menurectangulo(49, 12,17, 3, "Categoria:");
    do {
    ob.Menurectangulo(63, 12,17, 3,"1-Linea Blanca");
  
    ob.Menurectangulo(77, 12, 17, 3, "2-Electronica");
    
    ob.Menurectangulo(91, 12, 14, 3, "3-Accesorios");
    
    ob.Menurectangulo(61,12,14, 3, "");                                 ///3 TIPOS DE CATEGORIA 1 LINEA BLANCA / 2 ELECTRONICA / 3 ACCESORIOS
    std::cin >> categoria;


    } while (categoria > 3 && categoria != 0);
        
    ob.Menurectangulo(49, 18, 25, 3, "");
    std::cout << "Marca: ";
    std::cin.ignore();
    std::cin.getline(marca, 50);
    ob.Menurectangulo(49, 21, 25, 3, "");
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 50);
    ob.Menurectangulo(49, 24, 25, 3, "");
    std::cout << "Descripción: ";
    std::cin.getline(descripcion, 50);
    ob.Menurectangulo(49, 27, 25, 3, "");
    std::cout << "Precio: $";
    std::cin >> precio;
    ob.Menurectangulo(49, 30, 25, 3, "");
    std::cout << "Stock: ";
    std::cin >> stock;

    if (grabarEnDisco())
    {
        system("cls");
        ob.Menurectangulo(49, 8, 30, 3, "Producto guardado con exito");
        std::cout<< std::endl;
        ob.Menurectangulo(49,11, 30, 3, "");
        system("pause");
        system("cls");
    }
}
void Producto::mostrar() {
    Menu ob;
    if (estado) {

        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        ob.Menurectangulo(49, 8, 25, 3, "");
        std::cout << "Codigo: ";
        std::cout << codigo << std::endl;
        ob.Menurectangulo(49, 12, 25, 3, "");
        std::cout << "Categoria: ";
        std::cout << categoria << std::endl;
        ob.Menurectangulo(49, 16, 25, 3, "");
        std::cout << "Marca: ";
        std::cout << marca << std::endl;
        ob.Menurectangulo(49, 20, 25, 3, "");
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
        ob.Menurectangulo(49, 24, 25, 3, "");
        std::cout << "Descripción: ";
        std::cout << descripcion << std::endl;
        ob.Menurectangulo(49, 28, 25, 3, "");
        std::cout << "Precio: $";
        std::cout << precio << std::endl;
        ob.Menurectangulo(49, 32, 25, 3, "");
        std::cout << "Stock: ";
        std::cout << stock << std::endl;
    }
}

bool Producto::grabarEnDisco() {
    FILE* p = NULL;
    bool grabar = false;
    p = fopen("productos.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return false;
    }
    grabar=fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return grabar;
}
bool Producto::leerDeDisco(int pos) {
    FILE* p = NULL;
    bool leyo=false;

    p = fopen("productos.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Producto), 0);
    leyo=fread(this, sizeof(Producto), 1, p);
    fclose(p);
    return leyo;
}