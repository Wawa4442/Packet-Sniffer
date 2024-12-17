#include "help.h"
#include "ui_help.h"
#include <QFont>  // Incluir para usar QFont

help::help(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::help)
{
    ui->setupUi(this);

    // Configura el QTextEdit para mostrar la ayuda
    ui->textEdit->setReadOnly(true);  // Hacemos el texto de solo lectura

    // Hacer el QTextEdit de solo lectura
    ui->textEdit->setReadOnly(true);

    // Establecer la fuente y tamaño del texto a 12
    QFont font = ui->textEdit->font();   // Obtener la fuente actual
    font.setPointSize(18);               // Establecer el tamaño a 12
    ui->textEdit->setFont(font);         // Aplicar la fuente al QTextEdit

    // Poner el texto de ayuda directamente
    ui->textEdit->setText(
        "1. **Primer Paso:**\n"
        "El primer paso del programa será elegir en la combo box que tienes en la parte de en medio "
        "el dispositivo que deseas consultar. Al hacer clic en ella podrás ver cómo se despliegan distintas opciones. "
        "Bajo nuestra recomendación, es preferible que uses tu tarjeta de red para probar el programa, "
        "ya que esta es la que está asegurada de que funcionará a la perfección y podrás evitar errores de otras tarjetas de red.\n\n"

        "2. **Más Ayuda:**\n"
        "Si necesitas consultar más acerca de nuestro proyecto, puedes hacerlo en la sección de donde dice 'Manual', "
        "el cual te ayudará a descargar el manual de usuario que fue creado específicamente para tus necesidades.\n\n"

        "3. **Comenzar y Parar:**\n"
        "El programa, una vez se seleccionó la tarjeta de red, cuenta con 2 botones principales para la captura de paquetes, "
        "los cuales son 'Start' y 'Stop'. Estos botones, bajo su mismo nombre, deben permitirte iniciar con la captura de paquetes "
        "y parar la captura de paquetes por si se desea consultar información más a fondo de un paquete específico. "
        "A su vez, mientras se muestra la información de los paquetes en la tabla junto con información más específica de cada paquete, "
        "como su información raw o información extra que no se puede ver por la rapidez de captura de los paquetes.\n\n"

        "4. **Información Específica al Hacer Clic:**\n"
        "Cuando paras la captura, puedes moverte por la tabla para ver qué paquetes han sido capturados, "
        "los cuales, al hacer doble clic en alguno de ellos, podrás apreciar más a fondo su información específica de cada paquete.\n\n"

        "5. **Filtros:**\n"
        "En el apartado de 'Captura', en la parte superior izquierda, contarás con 2 opciones: 'Filtros' y 'Exportar a CSV'. "
        "En este caso, al apretar 'Filtros' podrás desplegar qué filtros quieres que se apliquen en la captura, como 'Protocolo', "
        "'IP Fuente', 'IP Destino', 'Puerto', 'Cancelar Filtros'. Primero, debes activar la casilla de 'activar filtros' y después "
        "seleccionar qué filtro se quiere usar. Solo se puede usar un filtro a la vez, ya que el programa no cuenta con suficiente "
        "capacidad para aguantar varios filtros a la vez.\n\n"

        "6. **Exportar Captura:**\n"
        "En este caso, al hacer clic en 'Captura' podrás ver nuevamente 2 opciones: 'Filtros' y 'Exportar Captura'. "
        "Al hacer clic en esta última, puedes crear un archivo CSV con formato de Excel, el cual nos podrá exportar todos los "
        "paquetes obtenidos hasta el momento. Te recomendamos primero parar el programa para evitar fallos."
        );
}

help::~help()
{
    delete ui;
}
