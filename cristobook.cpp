/*********************************************************************
 * PRACTICA DE PROGRAMACION DEL TRIMESTRE 2 DE 1ºDAM CURSO 2018/2020 *
 * 				AUTOR: MATEO JESUS CABELLO RODRIGUEZ				 *
 *********************************************************************/
/*
NOTA IMPORTANTE: En la practica no he filtrado las entradas por teclado
				 Si se introduce un caracter donde se espera un tipo int o
				 un espacio en los datos que introduce el usuario el programa
				 entrara en un bucle infinito....
				 Doy por entendido que ese tipo de cosas se tienen en cuenta
				 a la hora de ejecutar el programa.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;

/****************************
 * DEFINICION DEL TIPO FOTO *
 ****************************/

struct Foto{
	string ruta; //Ruta del archivo en el S.O. /home/picture.jpg
	string tipo; //Ej: jpgmpng
	unsigned long int tamanio; //Se va a guardar en bytes 1.024.000
};

/*******************************
 * DEFINICION DEL TIPO USUARIO *
 *******************************/

struct Usuario{
	string login; //Debe de ser unico
	string nombre; 
	string apellido; 
	string perfil_usuario; //Admin o User
	Foto *v_foto; //Vector dinamico
	int dim_vfoto;
	int totalfotosUsuario;

	unsigned long int tamanio; //Se va a guardar en bytes 1.024.000
};

/*************************************
 * DEFINICION DEL TIPO TablaUsuarios *
 *************************************/

struct TablaUsuarios{
	Usuario **punteroapuntero;
	int totalTuplas; //Numero de usuarios actuales en el sistema
};

/*********************************************
 * DEFINICION DE LOS PROTOTIPOS DE TIPO FOTO *
 *********************************************/

string getRutaFoto(const Foto f);
string getRutaFoto(const Foto f);
string getTipoFoto(const Foto f);
void setRutaFoto(Foto &f, string ruta);
void setTipoFoto(Foto &f, string tipo);
void setTamanioFoto(Foto &f, unsigned long int tamanio);
Foto* crearFoto();
void BorrarFoto(Foto &f);
void printFoto(Foto f);
/*********************************************
 * DEFINICION DE PORTORIPOS DEL TIPO USUARIO *
 *********************************************/

string getLoginUsuario(const Usuario user);
string getNombreUsuario(const Usuario user);
string getApellidoUsuario(const Usuario user);
string getPerfilUsuario(const Usuario user);
Foto* getVfotoUsuario(const Usuario user);
int getDimVfotoUsuario(const Usuario user);
int getTotalFotosUsuario(const Usuario user);

void setLoginUsuario(Usuario &user, string login);
void setNombreUsuario(Usuario &user, string nombre);
void setApellidoUsuario(Usuario &user, string apellido);
void setPerfilUsuario(Usuario &user, string perfil);
void crearVfotoUsuario(Usuario &user);
void setDimVfotoUsuario(Usuario &user, int dim);
void setTotalFotosUsuario(Usuario &user, int total);

void resizeVfotoUsuario(Usuario &user, int &dim_actual, int dim_nueva);
Usuario* crearUsuario();
void InsertarFotoUsuario(Usuario *user, string ruta, string tipo, unsigned long int tamanio);
void printFotosUsuario(Foto *f);
void eliminarFotosUsuario(Usuario *user); 
void borrarUsuario(Usuario *user); 
void asignarFoto(Foto a, Foto &b);

/******************************************************
 * DEFINICION DE LOS PROTOTIPOS DE TIPO TABLAUSUARIOS *
 ******************************************************/

void crearTabla(TablaUsuarios &tabla, int tuplas);
void setNumeroTuplas(TablaUsuarios &tabla, int tuplas);
int getNumeroTuplas(TablaUsuarios &tabla);
void resizeTablaUsuario(TablaUsuarios &tabla);
void EliminarUsuarioEnTabla(TablaUsuarios &tabla);
void borrarTabla(TablaUsuarios &tabla);

/********************************************************************
 * DEFINICION DE LOS PROTOTIPOS DE MODULOS/PROCEDIMIENTOS GENERICOS *
 ********************************************************************/

void UsuariosPlantilla(TablaUsuarios &tabla);
void inicializarUsuario(TablaUsuarios &tabla);
void InsertarUsuario(TablaUsuarios &tabla, string login, string nombre, string apellido, string perfil);
void printTablaUsuarios(TablaUsuarios &tabla);
void printUsuario(Usuario *user);
void menu(TablaUsuarios &tabla);
void InsertarUsuarioEnTabla(TablaUsuarios &tabla);
int BuscarUsuarioLogin(const TablaUsuarios &tabla, string login);
void ImprimeFotosPorLogin(const TablaUsuarios &tabla);
void ImprimeUsuarioPorLogin(const TablaUsuarios &tabla);
void OrdenacionLoginCombosort(TablaUsuarios &tabla);
void OrdenacionTotalFotosCombosort(TablaUsuarios &tabla);
void OrdenaUsuarios(TablaUsuarios &tabla);
void borrarFotoUsuario(TablaUsuarios &tabla);
void crearFotoUsuario(TablaUsuarios &tabla);
void BusquedaFichero(TablaUsuarios &tabla);
void EjecutarScriptSO();
void AddUsuarioSO(TablaUsuarios &tabla);

/****************************************
 * MODULOS/PROCEDIMIENTOS DEL TIPO FOTO *
 ****************************************/

/*
 * @brief Devuelve la ruta de un tipo Foto.
 * @param const Foto f. Se pasa la foto como una variable de tipo estatico.
 * @return Devuelve la ruta como un string
 * @Autor Mateo Jesus Cabello Rodriguez
 */
string getRutaFoto(const Foto f){
	return f.ruta;
}	

/*
 * @brief Devuelve el tipo de un tipo Foto.
 * @param const Foto f. Se pasa la foto como una variable de tipo estatico.
 * @return Devuelve el tipo como un string
 * @Autor Mateo Jesus Cabello Rodriguez
 */
string getTipoFoto(const Foto f){
	return f.tipo;
}	

/*
 * @brief Devuelve el tamaño de un tipo Foto;
 * @param const Foto f. Se pasa la foto como una variable de tipo estatico.
 * @return Devuelve el tamaño (en bytes) como un unsigned long int
 * @Autor Mateo Jesus Cabello Rodriguez
 */
unsigned long int getTamanioFoto(const Foto f){
	return f.tamanio;
}

/*
 * @brief Introduce el valor de la ruta a un tipo Foto
 * @param Foto f (S). Se pasa la foto como una variable de tipo estatico.
 * @param string ruta (E). 
 * @pre La foto debe de estar inicializada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setRutaFoto(Foto &f, string ruta){
	f.ruta = ruta;
}

/*
 * @brief Introduce el valor del tipo a un tipo Foto.
 * @param Foto f (S). Se pasa la foto como una variable de tipo estatico.
 * @param string tipo(E). 
 * @pre La foto debe de estar inicializada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setTipoFoto(Foto &f, string tipo){
	f.tipo = tipo;
}

/*
 * @brief Introduce el valor de la ruta a un tipo Foto
 * @param Foto f (S). Se pasa la foto como una variable de tipo estatico.
 * @param string ruta (E). 
 * @pre La foto debe de estar inicializada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setTamanioFoto(Foto &f, unsigned long int tamanio){
	f.tamanio = tamanio;
}

/*
 * @brief Crear un tipo Foto.
 * @return Devuelve el tipo Foto.
 * @post Si no hay memoria suficiente saldra un mensaje por pantalla y acabará el programa.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
Foto* crearFoto(){
	Foto *f = new Foto;
    if (f == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    return f;
}

/*
 * @brief Pone los valores del tipo Foto a 0/null.
 * @param Foto f(E/S).
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void BorrarFoto(Foto &f){
	f.tamanio = 0;
	f.tipo = " ";
	f.ruta = " ";
}

/*
 * @brief Imprime una foto
 * @param const Foto f(E).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void printFoto(const Foto f){
	cout << getRutaFoto(f) << "." << getTipoFoto(f) << " " << getTamanioFoto(f) << endl;
}


/*******************************************
 * MODULOS/PROCEDIMIENTOS DEL TIPO USUARIO *
 *******************************************/

/*
 * @brief Devuelve el login del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Deielve una cadena de tipo string con el login
 * @Autor Mateo Jesus Cabello Rodriguez
 */
string getLoginUsuario(const Usuario user){
	return user.login;
}

/*
 * @brief Devuelve el nombre del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Devuelve una cadena de tipo string con el nombre
 * @Autor Mateo Jesus Cabello Rodriguez
 */
string getNombreUsuario(const Usuario user){
	return user.nombre;
}

/*
 * @brief Devuelve el apellido del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Devuelve una cadena de tipo string con el apellido
 * @Autor Mateo Jesus Cabello Rodriguez
 */
string getApellidoUsuario(const Usuario user){
	return user.apellido;
}

/*
 * @brief Devuelve el perfil del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Devuelve una cadena de tipo string con el perfil
 * @Autor Mateo Jesus Cabello Rodriguez
 */
string getPerfilUsuario(const Usuario user){
	return user.perfil_usuario;
}

/*
 * @brief Devuelve el vector de fotos del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Devuelve la posicion de memoria del vector de tipo Foto.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
Foto* getVfotoUsuario(const Usuario user){
	return user.v_foto;
}

/*
 * @brief Devuelve la dimension del vector de fotos del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Devuelve la dimension como un tipo int.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
int getDimVfotoUsuario(const Usuario user){
	return user.dim_vfoto;
}
/*
 * @brief Devuelve el total de fotos del usuario.
 * @param const Usuario user(E).
 * @pre El usuario debe estar creado.
 * @return Devuelve total de fotos como un tipo int.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
int getTotalFotosUsuario(const Usuario user){
	return user.totalfotosUsuario;
}

/*
 * @brief Introduce el valor login del usuario.
 * @param Usuario &user(S).
 * @param string login(E). Valor de entrada.
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setLoginUsuario(Usuario &user, string login){
	user.login = login;
}

/*
 * @brief Introduce el valor nombre del usuario.
 * @param Usuario &user(S).
 * @param string nombre(E). Valor de entrada.
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setNombreUsuario(Usuario &user, string nombre){
	user.nombre = nombre;
}

/*
 * @brief Introduce el valor apellido del usuario.
 * @param Usuario &user(S).
 * @param string apellido(E). Valor de entrada.
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setApellidoUsuario(Usuario &user, string apellido){
	user.apellido = apellido;
}

/*
 * @brief Introduce el valor perfil del usuario.
 * @param Usuario &user(S).
 * @param string perfil(E). Valor de entrada.
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setPerfilUsuario(Usuario &user, string perfil){
	user.perfil_usuario = perfil;
}

/*
 * @brief Crea el vector dinamico de fotos para el usuario.
 * @param Usuario &user(S).
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void crearVfotoUsuario(Usuario &user){
	setDimVfotoUsuario(user,0);
	setTotalFotosUsuario(user,0);
	user.v_foto = new Foto[user.dim_vfoto];
}

/*
 * @brief Asigna la dimension del vector de fotos del usuario.
 * @param Usuario &user(S).
 * @param int dim(E). Entrada de la nueva dimension
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setDimVfotoUsuario(Usuario &user, int dim){
	user.dim_vfoto = dim;
}

/*
 * @brief Asigna el total de fotos del usuario.
 * @param Usuario &user(S).
 * @param int total(E). Entrada de la nueva dimension
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setTotalFotosUsuario(Usuario &user, int total){
	user.totalfotosUsuario = total;
}

/*
 * @brief Redimensiona un vector dinamico de tipo Foto
 * @param Foto *v_foto(E).
 * @param unsigned int dim_actual(E/S).
 * @param int dim_nueva(E).
 * @pre El vector dinamico de tipo foto debe estar creado.
 * @return Devuelve la direccion de memoria del vector redimensionado
 * @post Debe guardarse la posicion de memoria devuelta en la variable del vector de entrada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void resizeVfotoUsuario(Usuario &user, int &dim_actual, int dim_nueva){
	Foto *aux = 0; //Vector auxiliar para copiar el viejo. 
	aux = new Foto[dim_nueva]; //Se asigna una nueva posicion de memoria de tipo Foto.
	unsigned int limite = 0;
	if (dim_nueva > dim_actual)
	{
		limite = dim_actual;
	}else{
		limite = dim_nueva;
	}
	for (int i = 0; i < limite; ++i)
	{
		aux[i] = user.v_foto[i];
	}
	if (dim_nueva >= 0)
	{
		eliminarFotosUsuario(&user);
		user.dim_vfoto = dim_nueva;
		user.v_foto = aux;
	}
	aux = 0;
}

/*
 * @brief Crear un tipo Usuario.
 * @return Devuelve la posicion de memoria del puntero de tipo Usuario.
 * @post Si no hay memoria suficiente saldra un mensaje por pantalla y acabará el programa.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
Usuario* crearUsuario(){
	Usuario *user = new Usuario;
    if (user == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    crearVfotoUsuario(*user);
    return user;
}

/*
 * @brief Inserta una foto a un usuario.
 * @param Usuario *user(E/S).
 * @param string ruta(E).
 * @param string tipo(E).
 * @param unsigned long int tamanio(E).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void InsertarFotoUsuario(Usuario *user, string ruta, string tipo, unsigned long int tamanio){
	resizeVfotoUsuario(*user,user->dim_vfoto,user->dim_vfoto+1);
	//cout << red << "DEBUG: Valor de user.v_foto: " << user->v_foto << " DIM: " << user->dim_vfoto << white << endl;
	setRutaFoto(user->v_foto[user->dim_vfoto-1],ruta);
	setTipoFoto(user->v_foto[user->dim_vfoto-1],tipo);
	setTamanioFoto(user->v_foto[user->dim_vfoto-1],tamanio);
	user->totalfotosUsuario = user->dim_vfoto;
}

/*
 * @brief Imprime las fotos de un Usuario.
 * @param Usuario *user(E).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void printFotosUsuario(Usuario *user){
	for (int i = 0; i < user->dim_vfoto; ++i)
	{
		cout << "\\_____" << i << "[";
		printFoto(user->v_foto[i]);
	}
}

/*
 * @brief Elimina todas las fotos de un usuario.
 * @param const Foto f(E).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void eliminarFotosUsuario(Usuario *user){
	for (int i = 0; i < user->dim_vfoto; ++i)
	{
		//cout << red << "DEBUG_ELIMINARFOTOSUSUARIO1: " << user->v_foto[i].ruta << white << endl;
		BorrarFoto(user->v_foto[i]);
		//cout << red << "DEBUG_ELIMINARFOTOSUSUARIO2: " << user->v_foto[i].ruta << white << endl;
	}
	delete [] user->v_foto;
	user->v_foto = 0;
}

/*
 * @brief Elimina una foto de un usuario.
 * @param const Foto f(E).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void borrarUsuario(Usuario *user){
	user->login = " ";
	user->nombre = " ";
	user->apellido = " ";
	user->perfil_usuario = " ";
	//cout << red << "DEBUG_BORRARUSURIO1: " << user->v_foto << white << endl;
	eliminarFotosUsuario(user);
	//cout << red << "DEBUG_BORRARUSURIO2: " << user->v_foto << white << endl;
	user->dim_vfoto = 0;
	user->totalfotosUsuario = 0;
}

/*
 * @brief Asigna una Foto A a la Foto B.
 * @param const Foto a(E).
 * @param const Foto b(S).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void asignarFoto(Foto a, Foto &b){
	b.ruta = a.ruta;
	b.tipo = a.tipo;
	b.tamanio = a.tamanio;
}


/*************************************************
 * MODULOS/PROCEDIMIENTOS DEL TIPO TABLAUSUARIOS *
 *************************************************/

/*
 * @brief Crear un vector de Usuarios puntero a puntero dentro de una variable de tipo TablaUsuarios.
 * @param TablaUsuarios &tabla(S).
 * @param int tuplas(E). Numero
 * @post Si no hay memoria suficiente saldra un mensaje por pantalla y acabará el programa.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void crearTabla(TablaUsuarios &tabla, int tuplas){
	tabla.totalTuplas = tuplas;
	tabla.punteroapuntero = new Usuario*[tabla.totalTuplas];
	if (tabla.punteroapuntero == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
}

/*
 * @brief Asigna la dimension del vector puntero a puntero de Tipo Usuario.
 * @param TablaUsuarios &tabla(S).
 * @param int tuplas(E). Entrada de la nueva dimension.
 * @pre la tabla debe estar creada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void setNumeroTuplas(TablaUsuarios &tabla, int tuplas){
	tabla.totalTuplas = tuplas;
}

/*
 * @brief Asigna la dimension del vector de fotos del usuario.
 * @param Usuario &user(S).
 * @param int dim(E). Entrada de la nueva dimension
 * @pre El usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
int getNumeroTuplas(TablaUsuarios &tabla){
	return tabla.totalTuplas;
}

/*
 * @brief Redimensiona el vector dinamico puntero a puntero del tipo TablaUsuarios
 * @param TablaUsuarios &tabla(E/S).
 * @pre El vector dinamico de tipo **Usuario debe estar creado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void resizeTablaUsuario(TablaUsuarios &tabla, unsigned int dim_nueva){
	Usuario **aux = 0;
	unsigned int limite = 0;
	aux = new Usuario*[dim_nueva];
	//cout << red << "DEBUG_RESIZEUSUARIO_DIM_VIEJA: " << tabla.totalTuplas << white << endl;
	//cout << red << "DEBUG_RESIZEUSUARIO_DIM_NUEVA: " << dim_nueva << white << endl;
	if (aux == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
	if (dim_nueva > tabla.totalTuplas)
	{
		limite = tabla.totalTuplas;
	}else{
		limite = dim_nueva;
	}
	if (dim_nueva < 0)
	{
		cout << "ERROR DE REDIMENSION. TABLA VACIA!" << endl;
	}else{
		for (int i = 0; i < limite; ++i)
		{
			aux[i] = tabla.punteroapuntero[i];
			//cout << red << "DEBUG_RESIZE_ASIG: " << aux[i] << " - " << tabla.punteroapuntero[i] << white << endl;
		}
		tabla.totalTuplas = dim_nueva;
		//cout << red << "DEBUG: " << "punteroapuntero = " << tabla.punteroapuntero << white << endl;
		//cout << red << "DEBUG_RESIZEUSUARIO_DIM_FINAL: " << tabla.totalTuplas << white << endl;
		delete [] tabla.punteroapuntero;
		tabla.punteroapuntero = 0;
		tabla.punteroapuntero = aux;
		//cout << red << "DEBUG: " << "aux = " << aux << ". punteroapuntero = " << tabla.punteroapuntero << white << endl;
		aux = 0;
	}
}

/*
 * @brief Borra un vector de Usuarios puntero a puntero dentro de una variable de tipo TablaUsuarios.
 * @param TablaUsuarios &tabla(S).
 * @pre La tabla debe estar creada.
 * @post El valor del punteroapuntero sera 0/null.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void borrarTabla(TablaUsuarios &tabla){
	for (int i = 0; i < tabla.totalTuplas; ++i)
	{
		borrarUsuario(tabla.punteroapuntero[i]);
		tabla.punteroapuntero[i] = 0;
	}
	tabla.totalTuplas = 0;
	delete [] tabla.punteroapuntero;
	tabla.punteroapuntero = 0;
	cout << "Tabla eliminada!" << endl;
}


/************************************
 * MODULOS/PROCEDIMIENTOS GENERICOS *
 ************************************/

/*
 * @brief Menu del programa.
 * @param TablaUsuarios &tabla(E/S).
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void menu(TablaUsuarios &tabla){
	int opcion = 0;
	bool exit = false, tabla_check = false, program_command = false;
	do
	{
		cout << blue << "Bienvenido a CristoBook!" << white << endl;
		cout << blue << "Pulse la tecla que desee para realizar una de las siguientes acciones: " << white << endl;
		if (tabla_check == true)
		{
			cout << red;
		}
		cout << "1) Crear Tabla de Usuarios." << white <<endl;
		if (tabla_check == false)
		{
			cout << red;
		}
		cout << "2) Eliminar Tabla de Usuarios." << endl;
		cout << "3) Imprimir Tabla de Usuarios." << endl;
		cout << "4) Insertar Usuario en Tabla de Usuarios." << endl;
		cout << "5) Eliminar Usuario en Tabla Usuarios." << endl;
		cout << "6) Buscar Usuario por Atributo login en la Tabla Usuarios" << endl;
		cout << "7) Ordenar Tabla Usuarios por Atributo totalfotosUsuario o login." << endl;
		cout << "8) Añadir fotografia a Usuario." << endl;
		cout << "9) Eliminar fotografia a Usuario." << endl;
		cout << "10) Imprimir fotografias de un Usuario." << white << endl;
		cout << "11) Salir." << endl;
		cout << yellow << "12) BUSQUEDA PARCIAL [EJERCICIO EXTRA]."<< white << endl;
		cout << yellow << "13) EJECUTAR SCRIPT [EJERCICIO EXTRA]."<< white << endl;
		cout << yellow << "14) CREAR USUARIO EN LINUX [EJERCICIO EXTRA]."<< white << endl;
		cout << "OPCION: ";
		cin >> opcion;
		if (tabla_check == false)
		{
			switch ( opcion )
			{
				case 1:
					crearTabla(tabla,0);
					//cout << red << "DEBUG: " << "El numero de usuarios es: " << tabla.totalTuplas << white << endl;
					UsuariosPlantilla(tabla);
					//cout << red << "DEBUG: " << "El numero de usuarios es: " << tabla.totalTuplas << white << endl;
		            tabla_check = true;
		            break;
		        case 11:
		        	//Salida del programa
		            exit = true;
		            break;
		        default:
		            cout << cyan << "La tabla no esta creada..." << white << endl;
			}
		}else{
			switch ( opcion )
			{
				case 1:
					cout << cyan << "La tabla ya esta creada!" << white << endl;
					break;
				case 2:
						borrarTabla(tabla);
		            	tabla_check = false;
		            break;
		        case 3:
		            printTablaUsuarios(tabla);
		            break;
				case 4:
					//cout << red << "DEBUG: " << tabla.totalTuplas << white << endl;
					InsertarUsuarioEnTabla(tabla);
					//cout << red << "DEBUG: " << tabla.totalTuplas << white << endl;
					break;
				case 5:
					EliminarUsuarioEnTabla(tabla);
					break;
				case 6:
					ImprimeUsuarioPorLogin(tabla);
					break;
				case 7:
					OrdenaUsuarios(tabla);
					break;
				case 8:
					crearFotoUsuario(tabla);
					break;
				case 9:
					borrarFotoUsuario(tabla);
					break;
				case 10:
					ImprimeFotosPorLogin(tabla);
					break;
		        case 11:
		            if (tabla_check == true)
		            {
		            	borrarTabla(tabla);
		            }
		            exit = true;
		            break;
		        case 12:
		            BusquedaFichero(tabla);
		            break;
		        case 13:
		            EjecutarScriptSO();
		            program_command = true;
		            break;
		        case 14:
		            AddUsuarioSO(tabla);
		            program_command = true;
		            break;
		        default:
		            cout << "La opción introducida no es valida..." << endl;
			}
		}
		if (program_command == true)
		{
			cin.get(); //Forzado de desbordamiento despues de ejecutar EjecutarScriptSO()
			cin.clear(); //Limpiar entrada de errores del estado en cin
			cin.ignore(256, '\n'); //Ignorar desbordamiento en salto de linea
			program_command = false;
		}
	} while (exit == false);
	
}

/*
 * @brief Inicializa un usuario dentro de la tabla.
 * @param TablaUsuarios &tabla(E/S).
 * @pre La tabla debe estar creada.
 * @post el total de tuplas de la tabla se vera incrementado en 1.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void inicializarUsuario(TablaUsuarios &tabla){
	resizeTablaUsuario(tabla,tabla.totalTuplas+1);
	//cout << red << "DEBUG: " << "punteroapuntero = " << tabla.punteroapuntero << ". totalTuplas = " << tabla.totalTuplas <<  white << endl;
	tabla.punteroapuntero[tabla.totalTuplas-1] = crearUsuario();
	//cout << "punteroapuntero[" << (tabla.totalTuplas-1) << "] CREADO CON EXITO!" << endl;
}

/*
 * @brief Inserta un usuario.
 * @param Usuario *user(E/S).
 * @param string login
 * @param string nombre
 * @param string apellido
 * @param string perfil
 * @pre La tabla debe estar creada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void InsertarUsuario(Usuario *user, string login, string nombre, string apellido, string perfil){
	user->login = login;
	user->nombre = nombre;
	user->apellido = apellido;
	user->perfil_usuario = perfil;
	user->dim_vfoto = 0;
	user->totalfotosUsuario = 0;
}

/*
 * @brief Inserta un usuario en la tabla.
 * @param TablaUsuarios &tabla(E/S).
 * @pre La tabla debe estar creada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void InsertarUsuarioEnTabla(TablaUsuarios &tabla){
	string login = " ",nombre = " ",apellido = " ",perfil = " ";
	bool check_usuario = false; //Posicion de memoria de un usuario que existe
	int user = 0, opcion_perfil = 0;
	bool perfil_check = false;
	inicializarUsuario(tabla);
	//cout << red << "DEBUG: " << "El numero de usuarios es: " << tabla.totalTuplas << white << endl;
	cout << "Introduce los datos del usuario sin espacios..." << endl;
	do
	{
		cout << "Login: ";
		cin >> login;
		user = BuscarUsuarioLogin(tabla,login);
		if (user >= 0)
		{
			check_usuario = true;
			cout << "El usuario ya existe.." << endl;
		}else{
			check_usuario = false;
		}
	} while (check_usuario == true);
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Apellido: ";
	cin >> apellido;
	do
	{
		cin.clear(); //Limpiar entrada de errores del estado en cin
		cin.ignore(256, '\n'); //Ignorar desbordamiento en salto de linea
		cout << "Tipo Perfil [1]->Admin | [2]->User]: ";
		cin >> opcion_perfil;
		if (opcion_perfil == 1)
		{
			perfil = "Admin";
			perfil_check = true;
		}else if(opcion_perfil == 2){
			perfil = "User";
			perfil_check = true;
		}else{
			perfil_check = false;
		}
	} while (perfil_check == false);
	InsertarUsuario(tabla.punteroapuntero[(tabla.totalTuplas-1)],login,nombre,apellido,perfil);
}

/*
 * @brief Crea 7 usuarios plantilla dentro de la tabla
 * @param TablaUsuarios &tabla(E/S).
 * @pre La tabla debe estar creada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void UsuariosPlantilla(TablaUsuarios &tabla){
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 0! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[0], "@MattJCR", "MateoJCR", "Cabello", "Admin");
	InsertarFotoUsuario(tabla.punteroapuntero[0],"/home/MateoJCR/imagenes/foto1","jpg",102234);
	InsertarFotoUsuario(tabla.punteroapuntero[0],"/home/MateoJCR/imagenes/foto2","png",7345123);
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 1! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[1], "@CristoRey", "CristoRey", "CES", "User");
	InsertarFotoUsuario(tabla.punteroapuntero[1],"/home/CristoRey/imagenes/foto1","png",7234653);
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 2! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[2], "@Anonimo1", "Anonimo1", "Void", "User");
	InsertarFotoUsuario(tabla.punteroapuntero[2],"/home/Anonimo1/imagenes/foto111","png",9239345);
	InsertarFotoUsuario(tabla.punteroapuntero[2],"/home/Anonimo1/imagenes/foto16","jpg",134644465);
	InsertarFotoUsuario(tabla.punteroapuntero[2],"/home/Anonimo1/imagenes/foto129","png",9112345);
	InsertarFotoUsuario(tabla.punteroapuntero[2],"/home/Anonimo1/imagenes/foto41","png",9789755);
	InsertarFotoUsuario(tabla.punteroapuntero[2],"/home/Anonimo1/imagenes/foto13","jpg",13756465);
	InsertarFotoUsuario(tabla.punteroapuntero[2],"/home/Anonimo1/imagenes/foto113","png",91575745);
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 3! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[3], "@Anonimo2", "Anonimo2", "Void", "User");
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 4! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[4], "@Anonim3", "Anonimo3", "Void", "User");
	InsertarFotoUsuario(tabla.punteroapuntero[4],"/home/Anonim3/imagenes/foto11","png",9789345);
	InsertarFotoUsuario(tabla.punteroapuntero[4],"/home/Anonim3/imagenes/foto15","jpg",13452465);
	InsertarFotoUsuario(tabla.punteroapuntero[4],"/home/Anonim3/imagenes/foto123","png",91235745);
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 5! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[5], "@Anonim4", "Anonimo3", "Void", "User");
	InsertarFotoUsuario(tabla.punteroapuntero[5],"/home/Anonim4/imagenes/foto129","png",9535745);
	InsertarFotoUsuario(tabla.punteroapuntero[5],"/home/Anonim4/imagenes/foto41","png",9789345);
	InsertarFotoUsuario(tabla.punteroapuntero[5],"/home/Anonim4/imagenes/foto13","jpg",9782465);
	InsertarFotoUsuario(tabla.punteroapuntero[5],"/home/Anonim4/imagenes/foto113","png",9785745);
	
	inicializarUsuario(tabla);
	//cout << cyan << "DEBUG: INSERTA 6! - " << tabla.totalTuplas << white << endl;
	InsertarUsuario(tabla.punteroapuntero[6], "@Anonim5", "Anonimo3", "Void", "User");
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto19","png",9123745);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto1","png",534345);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto3","jpg",9787665);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto13","png",9737645);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto11","png",869345);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto6","jpg",432644465);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto29","png",1212345);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto4","png",3769755);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto131","jpg",3256465);
	InsertarFotoUsuario(tabla.punteroapuntero[6],"/home/Anonim5/imagenes/foto113","png",7975745);
	cout << cyan << "Se han insertado 7 Usuarios con EXITO por defecto." << white << endl;
}

/*
 * @brief Imprime un Usuario
 * @param Usuario *user(E).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void printUsuario(Usuario *user){
	cout << getLoginUsuario(*user) << " " << "	" << getNombreUsuario(*user) << " " << "	"<< getApellidoUsuario(*user) << "	" << " 	" << getPerfilUsuario(*user) << endl;
	printFotosUsuario(user);
}

/*
 * @brief Imprime todos los usuarios de una tabla
 * @param TablaUsuarios &tabla(E).
 * @pre La tabla debe estar creada.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void printTablaUsuarios(TablaUsuarios &tabla){
	if (tabla.totalTuplas > 0)
	{
		cout << cyan << "LOGIN	" << "	NOMBRE	" << "	APELLIDO " << "	PERFIL	" << white << endl;
		for (int i = 0; i < tabla.totalTuplas; ++i)
		{
			//cout << red << "DEBUG_PRINT_TABLA [" << i << "]: " << tabla.punteroapuntero[i] << white << endl;
			if (i%2 == 0)
			{
				cout << yellow;
			}else{
				cout << green;
			}
			printUsuario(tabla.punteroapuntero[i]);
		}
		cout << white;
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
	
}
/**
 * @brief Busca un usuario dentro de la tabla.
 * @param const TablaUsuarios &tabla(E)
 * @param string login(E)
 * @return Devuelve la posicion del usuario en el vector punteroapuntero. Devuelve -1 si no lo encuentra.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
int BuscarUsuarioLogin(const TablaUsuarios &tabla, string login){
	int aux = -1;
	bool check = false;
	for (int i = 0; i < tabla.totalTuplas && check == false; ++i)
	{
		//cout << red << "DEBUG: " << tabla.punteroapuntero[i]->login << endl;
		if (tabla.punteroapuntero[i]->login == login)
		{
			aux = i;
			check = true;
		}
	}
	return aux;
}

/**
 * @brief Busca un usuario dentro de la tabla e imprime sus fotos.
 * @param const TablaUsuarios &tabla(E).
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void ImprimeFotosPorLogin(const TablaUsuarios &tabla){
	string login = " ";
	if (tabla.totalTuplas > 0)
	{
		cout << "Introduce el login del usuario: ";
		cin >> login;
		int user = BuscarUsuarioLogin(tabla,login);
		if (user >= 0)
		{
			cout << cyan << login << endl;
			printFotosUsuario(tabla.punteroapuntero[user]);
			cout << white;
		}else{
			cout << "No existe el Usuario " << login << endl;
		}
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
}

/**
 * @brief Busca un usuario dentro de la tabla e imprime sus fotos.
 * @param const TablaUsuarios &tabla(E)
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void ImprimeUsuarioPorLogin(const TablaUsuarios &tabla){
	string login = " ";
	if (tabla.totalTuplas > 0)
	{
		cout << "Introduce el login del usuario: ";
		cin >> login;
		int user = BuscarUsuarioLogin(tabla,login);
		if (user >= 0)
		{
			cout << cyan << endl;
			printUsuario(tabla.punteroapuntero[user]);
			cout << white;
		}else{
			cout << "No existe el Usuario " << login << endl;
		}
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
}

/**
 * @brief Ordena los usuarios de la tabla por el login mediante el metodo combosort.
 * @param const TablaUsuarios &tabla(E)
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void OrdenacionLoginCombosort(TablaUsuarios &tabla){
	double shrink = 1.3;
	int gap = tabla.totalTuplas;
	bool check = false;
	Usuario *aux = 0;
	while(!check){
		gap = (gap/shrink);
		if (gap <= 1)
		{
			gap = 1;
			check = true;
		}
		for (int i = 0; i+gap < tabla.totalTuplas; ++i)
		{
			if (tabla.punteroapuntero[i]->login > tabla.punteroapuntero[i+gap]->login)
			{
				check = false;
				aux = tabla.punteroapuntero[i];
				tabla.punteroapuntero[i] = tabla.punteroapuntero[i+gap];
				tabla.punteroapuntero[i+gap] = aux;
			}
		}
	}
}

/**
 * @brief Ordena los usuarios de la tabla por el login mediante el metodo combosort.
 * @param const TablaUsuarios &tabla(E)
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void OrdenacionTotalFotosCombosort(TablaUsuarios &tabla){
	double shrink = 1.3;
	int gap = tabla.totalTuplas;
	bool check = false;
	Usuario *aux = 0;
	while(!check){
		gap = (gap/shrink);
		if (gap <= 1)
		{
			gap = 1;
			check = true;
		}
		for (int i = 0; i+gap < tabla.totalTuplas; ++i)
		{
			if (tabla.punteroapuntero[i]->totalfotosUsuario > tabla.punteroapuntero[i+gap]->totalfotosUsuario)
			{
				check = false;
				aux = tabla.punteroapuntero[i];
				tabla.punteroapuntero[i] = tabla.punteroapuntero[i+gap];
				tabla.punteroapuntero[i+gap] = aux;
			}
		}
	}
}

/**
 * @brief Ordena los usuarios de la tabla por el login mediante el metodo seleccionado.
 * @param const TablaUsuarios &tabla(E)
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void OrdenaUsuarios(TablaUsuarios &tabla){
	int opcion = 0;
	if (tabla.totalTuplas > 0)
	{
		cout << "Selecciona por que quieres ordenar la tabla: " << endl;
		cout << "1) Login" << endl;
		cout << "2) totalfotosUsuario" << endl;
		cin >> opcion;
		switch ( opcion )
		{
			case 1:
				OrdenacionLoginCombosort(tabla);
	            break;
	        case 2:
	        	OrdenacionTotalFotosCombosort(tabla);
	            break;
	        default:
	            cout << "Opcion no valida." << endl;
	            cout << "Volviendo al menu principal..." << endl;
		}
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
}

/**
 * @brief Elimina un usuario de la tabla por el login.
 * @param const TablaUsuarios &tabla(E)
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void EliminarUsuarioEnTabla(TablaUsuarios &tabla){
	int posicion = 0;
	string login = " ";
	if (tabla.totalTuplas > 0)
	{
		printTablaUsuarios(tabla);
		cout << "Que usuario quieres borrar?";
		cin >> login;
		posicion = BuscarUsuarioLogin(tabla,login);
		cout << red << "DEBUG_ELIMINAR_USUARIO_POSICION: " << posicion << white << endl;
		if (posicion >= 0)
		{
			borrarUsuario(tabla.punteroapuntero[posicion]);
			//cout << red << "DEBUG_ELIMINAR_USUARIO_DIRECCION1: " << tabla.punteroapuntero[posicion] << white << endl;
			for (int i = posicion; i < tabla.totalTuplas && posicion+1 < tabla.totalTuplas; ++i)
			{
					tabla.punteroapuntero[i] = tabla.punteroapuntero[i+1];
			}
			//cout << red << "DEBUG_ELIMINAR_USUARIO_DIRECCION2: " << tabla.punteroapuntero[posicion] << white << endl;
			//cout << red << "DEBUG_ELIMINAR_USUARIO1: " << tabla.totalTuplas << white << endl;
			resizeTablaUsuario(tabla,(tabla.totalTuplas-1));
			//cout << red << "DEBUG_ELIMINAR_USUARIO1: " << tabla.totalTuplas << white << endl;
		}else{
			cout << "El usuario a borrar no existe..." << endl;
		}
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
	
}

/*
 * @brief Programa para borrar una foto a un usuario.
 * @param TablaUsuarios &tabla(E/S).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void borrarFotoUsuario(TablaUsuarios &tabla){
	string login = " ";
	int posicion = 0, posicion_foto = 0;
	Usuario *user_aux = 0; //Auxiliar para copiar la posicion de memoria y acceder a su contendio
	if (tabla.totalTuplas > 0)
	{
		printTablaUsuarios(tabla);
		cout << "Selecciona un Usuario por su login: ";
		cin >> login;
		posicion = BuscarUsuarioLogin(tabla,login);
		if (posicion >= 0)
		{
			printUsuario(tabla.punteroapuntero[posicion]);
			if (tabla.punteroapuntero[posicion]->totalfotosUsuario > 0)
			{
				cout << "Selecciona la foto a borrar por su posicion: ";
				cin >> posicion_foto;
				if (posicion_foto >= 0 && posicion_foto < tabla.punteroapuntero[posicion]->totalfotosUsuario)
				{
					BorrarFoto(tabla.punteroapuntero[posicion]->v_foto[posicion_foto]);
					asignarFoto(tabla.punteroapuntero[posicion]->v_foto[(tabla.punteroapuntero[posicion]->dim_vfoto)-1],tabla.punteroapuntero[posicion]->v_foto[posicion_foto]);
					user_aux = tabla.punteroapuntero[posicion];
					resizeVfotoUsuario(*user_aux,tabla.punteroapuntero[posicion]->dim_vfoto,(tabla.punteroapuntero[posicion]->dim_vfoto)-1);
					user_aux = 0;
				}else{
					cout << "La foto seleccionada no existe..." << endl;
				}
			}else{
				cout << "El usuario no dispone de fotos..." << endl;
			}
		}else{
			cout << "El usuario a borrar no existe..." << endl;
		}
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
}

/*
 * @brief Programa para crear una foto a un usuario.
 * @param TablaUsuarios &tabla(E/S).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void crearFotoUsuario(TablaUsuarios &tabla){
	string login = " ", ruta = " ", tipo = " ";
	long int tamanio = 0;
	bool check_tamanio = false;
	int posicion = 0;
	Usuario *user_aux = 0; //Auxiliar para copiar la posicion de memoria y acceder a su contendio
	printTablaUsuarios(tabla);
	if (tabla.totalTuplas > 0)
	{
		cout << "Selecciona un Usuario por su login: ";
		cin >> login;
		posicion = BuscarUsuarioLogin(tabla,login);
		if (posicion >= 0)
		{
			printUsuario(tabla.punteroapuntero[posicion]);
			if (tabla.punteroapuntero[posicion]->totalfotosUsuario >= 0)
			{
				cout << "Introduce la ruta de la foto: ";
				cin >> ruta;
				cout << "Introduce la tipo de la foto: ";
				cin >> tipo;
				do
				{
					cout << "Introduce el tamanio de la foto: ";
					cin >> tamanio;
					if (tamanio > 0)
					{
						check_tamanio = true;
					}else{
						cout << red << "Tamaño no valido o nulo..." << white << endl;
					}
				} while (check_tamanio == false);
				
				InsertarFotoUsuario(tabla.punteroapuntero[posicion], ruta, tipo, tamanio);
			}else{
				cout << "El usuario no dispone de fotos...";
			}
		}else{
			cout << "El usuario a borrar no existe..." << endl;
		}
	}else{
		cout << "No existe el Usuario " << login << endl;
	}
}

/*
 * @brief Programa para buscar un fichero de forma parcial.
 * @param TablaUsuarios &tabla(E/S).
 * @pre El usuario debe estar inicializado.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void BusquedaFichero(TablaUsuarios &tabla){
	string busqueda = " ", aux = " ";
	bool check_palabra = false;
	int n = 0; //Util auxiliar para comprobar la cadena
	if (tabla.totalTuplas > 0)
	{
		cout << "Introduce el fichero a buscar: ";
		cin >> busqueda;
		for (int i = 0; i < tabla.totalTuplas; ++i) //For de recorrido de usuarios
		{
			for (int j = 0; j < tabla.punteroapuntero[i]->dim_vfoto; ++j)// For de recorrido de fotos
			{
				check_palabra = false;
				aux = tabla.punteroapuntero[i]->v_foto[j].ruta;
				for (int k = aux.size(); k >= 0 && (aux[k-1] != '/') && check_palabra == false; --k)//For de recorrido de cadena
				{
					int l = busqueda.size(); //Util de busqueda
					if (aux[k-1] == busqueda[l-1])//For de precomprobacion de cadena
					{
						n = k-1;
						check_palabra = false; //Comprueba si ya ha aparecido la parcialidad
						for (int m = l; m > 0; --m) //For de comprobacion de cadena
						{
							//cout << red << "DEBUG " << "n: " << aux[n] << " m: " << busqueda[m-1] << white <<endl;
							if (aux[n] == busqueda[m-1])
							{
								check_palabra = true;
							}else{
								check_palabra = false;
							}
							--n;
						}
						if (check_palabra == true)
						{
							cout << cyan << "El usuario " << tabla.punteroapuntero[i]->login << " tiene la foto: " << aux << white << endl;
						}
					}
				}
			}
		}
	}else{
		cout << cyan << "No existen usuarios..." << white << endl;
	}
}

/*
 * @brief Ejecuta un script llamando al sistema operativo.
 * @Autor Mateo Jesus Cabello Rodriguez
 */
void EjecutarScriptSO(){
	pid_t pid = fork();
	if (pid < 0)
	{
		cout << red << "Error al abrir el fichero." << white << endl;
	}else if (pid == 0)
	{
		execl("/bin/sh","sh", "./script.sh",(const char *)0);
		exit(-1);
	}
}

/*
 * @brief Crea un usuario del programa en el SO
 * @param TablaUsuarios &tabla(E/S).
 * @Autor Mateo Jesus Cabello Rodriguez.
 * @post El directorio Home del usuario se creara con su nombre.
 * @post La contraseña del usuario sera su Apellido.
 */
void AddUsuarioSO(TablaUsuarios &tabla){
	int usuario = 0;
	string login = " ", command_aux = " ";
	cout << "Introduce el login del usuario a añadir: ";
	cin >> login;
	usuario = BuscarUsuarioLogin(tabla,login);
	if (usuario >= 0)
	{
		command_aux = ("yes josegras | sudo useradd -d /home/" + 
						getNombreUsuario(*tabla.punteroapuntero[usuario]) + " " + 
						getLoginUsuario(*tabla.punteroapuntero[usuario]) + 
						" && yes " + getNombreUsuario(*tabla.punteroapuntero[usuario]) + 
						" | sudo passwd " +  getApellidoUsuario(*tabla.punteroapuntero[usuario]) + " 2> /dev/null");
		const char *command = command_aux.c_str(); //Debe ser const char para que funcione la funcion system
		usuario = system(command);
		//cout << usuario << endl;
		if (usuario == 256)
		{
			cout << cyan << "Usuario creado con exito!" << white << endl;
		}
	}else{
		cout << red << "El usuario no esta en el programa..." << white << endl;
	}
}

int main(){
	TablaUsuarios tabla; //Declaración de la tabla
	menu(tabla);
}
