#include "Producto.h"
#include "Menu.h"

Producto::Producto() {
    std::string vacio = " ";
    categoria = 0;
    codigo = 0;
    precio = 0;
    stock = 0;
    estado = true;
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
    ob.Menurectangulo(49, 9, 25, 3, "");
    std::cout << "Codigo: ";///CODIGO INTERNO DE LA COMPANYA
    std::cin >> codigo;
    
    
    ob.Menurectangulo(40, 12, 17, 3, "Categoria:");
    ob.Menurectangulo(57, 12, 20, 3, "1-Linea Blanca");

    ob.Menurectangulo(77, 12, 17, 3, "2-Electronica");

    ob.Menurectangulo(94, 12, 17, 3, "3-Accesorios");
    rlutil::locate(53, 13);                           ///3 TIPOS DE CATEGORIA 1 LINEA BLANCA / 2 ELECTRONICA / 3 ACCESORIOS
    std::cin >> categoria;

    while (categoria > 3 || categoria< 1) {
     system("cls");
     rlutil::locate(53, 10);
     std::cout << " **ERROR POR FAVOR INGRESE UN NUMERO ENTRE 1 Y 3 **";
    ob.Menurectangulo(40, 12, 17, 3, "Categoria:");
    ob.Menurectangulo(57, 12,20, 3,"1-Linea Blanca");
  
    ob.Menurectangulo(77, 12, 17, 3, "2-Electronica");
    
    ob.Menurectangulo(94, 12, 17, 3, "3-Accesorios");
    
    rlutil::locate(53, 13);                           ///3 TIPOS DE CATEGORIA 1 LINEA BLANCA / 2 ELECTRONICA / 3 ACCESORIOS
    std::cin >> categoria;
    
    }
        
    ob.Menurectangulo(49, 15, 25, 3, "");
    std::cout << "Marca: ";
    std::cin.ignore();
    std::cin.getline(marca, 50);
    ob.Menurectangulo(49, 18, 25, 3, "");
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 50);
    ob.Menurectangulo(49, 21, 25, 3, "");
    std::cout << "Descripción: ";
    std::cin.getline(descripcion, 50);
    ob.Menurectangulo(49, 24, 25, 3, "");
    std::cout << "Precio: $";
    std::cin >> precio;
    ob.Menurectangulo(49, 27, 25, 3, "");
    std::cout << "Stock: ";
    std::cin >> stock;
    estado = true;

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
void Producto::mostrar(int n) {
    Menu ob;
    int D = 24;
    if (n == 0) {
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        ob.Menurectangulo(49, 8 , 25, 3, "");
        std::cout << "Codigo: ";
        std::cout << codigo << std::endl;
        ob.Menurectangulo(49, 11, 25, 3, "");
        std::cout << "Categoria: ";
        std::cout << categoria << std::endl;
        ob.Menurectangulo(49, 14, 25, 3, "");
        std::cout << "Marca: ";
        std::cout << marca << std::endl;
        ob.Menurectangulo(49, 17, 25, 3, "");
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
        ob.Menurectangulo(49, 20, 25, 3, "");
        std::cout << "Descripción: ";
        std::cout << descripcion << std::endl;
        ob.Menurectangulo(49, 23, 25, 3, "");
        std::cout << "Precio: $";
        std::cout << precio << std::endl;
        ob.Menurectangulo(49, 26, 25, 3, "");
        std::cout << "Stock: ";
        std::cout << stock << std::endl;
    }
    else {
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        ob.Menurectangulo(49, 8+(D*n), 25, 3, "");
        std::cout << "Codigo: ";
        std::cout << codigo << std::endl;
        ob.Menurectangulo(49, 11 + (D * n), 25, 3, "");
        std::cout << "Categoria: ";
        std::cout << categoria << std::endl;
        ob.Menurectangulo(49, 14 + (D * n), 25, 3, "");
        std::cout << "Marca: ";
        std::cout << marca << std::endl;
        ob.Menurectangulo(49, 17 + (D * n), 25, 3, "");
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
        ob.Menurectangulo(49, 20 + (D * n), 25, 3, "");
        std::cout << "Descripción: ";
        std::cout << descripcion << std::endl;
        ob.Menurectangulo(49, 23 + (D * n), 25, 3, "");
        std::cout << "Precio: $";
        std::cout << precio << std::endl;
        ob.Menurectangulo(49, 26 + (D * n), 25, 3, "");
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




int Producto::BuscarProducto(int codi)
{
    int codigoProducto = -1;
    int pos = 0;
    while (leerDeDisco(pos++) == true)
    {
        if (getCodigo() == codi)
        {
            codigoProducto = getCodigo();
        }

    }
    return codigoProducto;
}

int Producto::ContarRegistross()
{
    FILE* p;
    p = fopen("productos.dat", "rb");
    if (p == NULL) { return -1; system("cls"); std::cout << "ERROR FATAL"; }
    size_t bytes;
    int cantidad;
    fseek(p, 0, 2);
    bytes = ftell(p);
    fclose(p);
    cantidad = bytes / sizeof(Producto);
    return cantidad;
}

int Producto::ContarRegistros(Producto reg)
{
    int pos = 0;
    int contar = 0;
    while (reg.leerDeDisco(pos++))
    {
        contar++;

    }

    return contar;
}

void Producto::ListarTodosLosProductos()
{
    system("cls");
    
    bool leyo = false;
    for (int i = 0 ; i < ContarRegistross(); i++) {
        rlutil::locate(54, 7+(i*24));
        std::cout << "REGISTRO N "; std::cout << i + 1 << std::endl;
        if (getEstado()==true) {
            leerDeDisco(i);
            mostrar(i);
            std::cout<<std::endl;

           
            leyo = true;
            
        }
    }
    
    if (leyo) {
        
        std::cout << "\t\t\t\t\tLOS REGISTRO MOSTRADOS CORRECTAMENTE SON " << ContarRegistross(); std::cout<<std::endl; system("pause");
    }
    else {
        std::cout << "LOS REGISTROS SON " << ContarRegistross(); std::cout<<" NUMEROS"<< std::endl; system("pause");
    }
}
