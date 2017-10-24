typedef struct
{
    int idDuenio;
    char nombreyapellido[50];
    char direccion[30];
    int numTarjeta;
    int estado;
} eDuenio;
typedef struct
{
    char patente[20];
    int marca;
    int horario;
    int estado;
    char descripcion[15];
    int idDuenio;
} eAutomovil;

/**
*   Obtiene los duenios y el tamaño.
*   @param Inicializa todos los parametros de la escructura en 0 y lo repite por la cantidad de estructuras.
*/
void inicializarvector(eDuenio duenio[],int tam);

/**
*   Obtiene los automoviles y el tamaño.
*   @param Inicializa todos los parametros de la escructura en 0 y lo repite por la cantidad de estructuras.
*/
void inicializarvectorAutomovil(eAutomovil automovil[],int tam);

/**
 *  Obtiene el indice que coincide con el id pasado por parametro.
 *  @param Busca espacio.
 *  @return El numero de estructura que esta disponible.
 */
int buscarLibre(eDuenio duenio[],int tam);

/**
 *  Obtiene el indice que coincide con la patente pasado por parametro.
 *  @param Busca espacio.
 *  @return El numero de estructura que esta disponible.
 */
int buscarLibreAutomovil(eAutomovil automovil[],int tam);

/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 *  @param Busca el ID y que el duenio este "activo".
 *  @return El numero de estructura donde se encuentra dicha id.
 */
int buscarId(int id, eDuenio duenio[],int tam);

/**
 * Obtiene el indice que coincide con la patente pasado por parametro.
 *  @param Busca la patente y que el automovil este "activo".
 *  @return El numero de estructura donde se encuentra dicha patente.
 */
int buscarPatente(char patente[], eAutomovil automovil[],int tam);

/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 *  @param Da valores a los parametros de la estructura eDuenio y pone su estado en 1.
 */
void altaDuenio(eDuenio duenio[],int tam);

/**
 * Obtiene el indice que coincide con la patente pasado por parametro.
 *  @param Da valores a los parametros de la estructura eAutomovil y pone su estado en 1.
 */
void altaAutomovil(eAutomovil automovil[],int tamA,eDuenio duenio[],int tamD);

/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 *  @param Cambia numTarjeta de la estructura eDuenio.
 */
void modificacionTarjeta(eDuenio duenio[],int tam);

/**
* Lista los autos estacionados con sus dueños.
* @param Los ordena por hora de entrada (horario)y patente.
*/
void organizarpersonas(eAutomovil automovil[],int tamA,eDuenio duenio[],int tamD);

/**
*
* @param Lista los Duenios que tengan de propietario un automovil "Audi".
*/
void propietariosAudi(eDuenio duenio[],int tamD,eAutomovil automovil[],int tamA);

/**
 *  Obtiene el indice que coincide con la patente pasado por parametro.
 *  @param Deja la estructura en estado 0. Lo que la da de "baja".
 *  @return El valor por cantidad de horas que haya estado el automovil segun su marca.
 */
int bajaAutomovil(eAutomovil automovil[], int tamA,eDuenio duenio[],int tamD,int recaudacionxMarca[]);
