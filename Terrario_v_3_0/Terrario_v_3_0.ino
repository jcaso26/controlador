//Control Terrario v.3.0
//Sin pantalla táctil
//13-08-2015

#ifdef DEBUG
#define DEBUG_PRINT(x)  Serial.print(x)
#else
#define DEBUG_PRINT(x)
#endif

#include <UTFT.h>
#include <UTouch.h>
#include <tinyFAT.h>
#include <avr/pgmspace.h>
#include <UTFT_tinyFAT.h>

#include <Wire.h> 
#include "RTClib.h"

#include "DHT.h" 

#define DHTPIN_ABAJO 8
#define DHTPIN_ARRIBA 9
#define DHTTYPE DHT11 

#define ECHO_PIN_HCSR 10
#define TRIG_PIN_HCSR 11

#define PIN_RELE_LLUVIA A0
#define PIN_RELE_CERAMICA A1
#define PIN_RELE_LUZ A2
#define PIN_RELE_CALOR A3

// Declaramos tamanio de letra
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Modelo TFT con pines Arduino Mega
UTFT myGLCD(ILI9327, 38,39,40,41);
//Configuracion táctil
UTouch  myTouch( 6, 5, 4, 3, 2);
//Configuracion SD
UTFT_tinyFAT myFiles(&myGLCD);
//Reloj
RTC_DS1307 RTC;
//Humedad y Temperatura
DHT dhtAbajo(DHTPIN_ABAJO, DHTTYPE); 

DHT dhtArriba(DHTPIN_ARRIBA, DHTTYPE); 

int color = 0;
word colorlist[] = {VGA_WHITE, VGA_BLACK, VGA_RED, VGA_BLUE, VGA_GREEN, VGA_FUCHSIA, VGA_YELLOW, VGA_AQUA};
char* ledsImagenes[] = {"red50.raw", "green50.raw"};
int tamImLed = 50;
int tamX;
int tamY;

boolean inicio = true;

boolean flagLuz = false;
boolean flagCalor = false;
boolean flagCeramica = false;
boolean flagLluvia = false;  

const boolean DEBUG = true;

byte res;
word result;
char textBuffer[81];

long distancia;
long tiempo;


float humedadMax = 90;
float humedadMin = 70;

int horaApagarLucesDia = 20;
int horaEncenderLucesDia = 8;
int horaApagarLucesNoche = 8;

//Apagado luces dia 19:58
int horaEncenderLucesNoche = 19;
int minutosEncenderLucesNoche = 58; 

float temperaturaMinima = 25;
float temperaturaMaxima = 40;

float nivelMinAgua = 10; //calcular TODO


//float humedadMinima;
//float humedadMaxima

float humedadActualArriba;
float humedadActualAbajo;
float temperaturaMaxDia;
float temperaturaMinDia;
float temperaturaMaxNoche;
float temperaturaMinNoche;
float temperaturaActualArriba;
float temperaturaActualAbajo;
float nivelAguaActual;
int horaActual;
int minActual;

boolean luz;
boolean calor;
boolean ceramica;
boolean lluvia;
//boolean fecha;
//int horaActual;

void setup(){
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(VGA_BLACK);
  
//Tamanio de pantalla
  tamX = myGLCD.getDisplayXSize();
  tamY = myGLCD.getDisplayYSize();

//Iniciamos los ficheros de la tarjeta SD  
  file.initFAT();

//Iniciamos el tactil  
//  myTouch.InitTouch();
//  myTouch.setPrecision(PREC_HI);

  Wire.begin(); // Inicia el puerto I2C
  RTC.begin(); // Inicia la comunicación con el RTC
  RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
  dhtAbajo.begin(); //Se inicia el sensor de temperatura
  dhtArriba.begin(); //Se inicia el sensor de temperatura
  
  //Sensor HCSR
  pinMode(TRIG_PIN_HCSR, OUTPUT); /*activación del pin 11 como salida: para el pulso ultrasónico*/
  pinMode(ECHO_PIN_HCSR, INPUT); /*activación del pin 10 como entrada: tiempo del rebote del ultrasonido*/
  
  Serial.begin(115200);
  
//  pantallaConfig();
  myGLCD.clrScr();
  pantallaInicio();
  
  digitalWrite(TRIG_PIN_HCSR,LOW); /* Por cuestión de estabilización del sensor*/
  //delayMicroseconds(5);

  pinMode(PIN_RELE_LLUVIA, OUTPUT);  
  pinMode(PIN_RELE_CERAMICA, OUTPUT);  
  pinMode(PIN_RELE_LUZ, OUTPUT);  
  pinMode(PIN_RELE_CALOR, OUTPUT);  

  digitalWrite(PIN_RELE_LLUVIA, LOW);
  digitalWrite(PIN_RELE_CERAMICA, LOW);
  digitalWrite(PIN_RELE_LUZ, LOW);
  digitalWrite(PIN_RELE_CALOR, LOW);  
}

void loop(){
  int buf[398];
  int posX, posX2;
  int posY, posY2;
  
  
  obtenerDatos();
  pantallaDatos();
  delay(60000);
  //pantallaPPal();

}

void marcoYMenu(){
   mensajeDebug("::marcoYMenu::");
   myGLCD.clrScr();
   myGLCD.setFont(BigFont);
   myGLCD.setColor(VGA_BLUE);
   myGLCD.drawRect(0,0,tamX-1,tamY-1);
}

void pantallaDatos(){
  mensajeDebug("::pantallaDatos::");
  int centroRealPantalla = (tamX-32)/2;
  int centroCabTemp = centroRealPantalla/4;
  
//Bloque Hora y Fecha
  bloqueHoraYFecha();

//Bloque Temperatura    
  bloqueTemperatura(centroCabTemp);
 
//Bloque Humedad
  bloqueHumedad(centroCabTemp);

//Bloque Reles    
  bloqueReles(centroCabTemp);
  
//Mensaje Error nivel agua
  if(nivelAguaActual >= nivelMinAgua){
    mostrarNivelAguaBajoEnPantalla(false);
  }
  else{
    mostrarNivelAguaBajoEnPantalla(true);
  }
  
  //Si tenemos buen nivel de agua y la humedad es menor que la minima, activamos aspersores
  if(nivelAguaActual >= nivelMinAgua){
    if((getHumedadArriba() < humedadMin) || (getHumedadAbajo() < humedadMin)){
      datosRelesLluvia(true);
    }
    else{//
      datosRelesLluvia(false);
    }
  }
  else{
      datosRelesLluvia(false);
  }
  if(flagLluvia){
    if((getHumedadArriba() >= humedadMax) || (getHumedadAbajo() >= humedadMax)){
      datosRelesLluvia(false);
    }
  }
    
  //Si es hora de encender la ceramica de noche
  if((horaActual == horaEncenderLucesNoche) && (minActual == minutosEncenderLucesNoche)){
      datosRelesCeramica(true);
  }
  
  if(horaActual == horaApagarLucesDia){
    datosRelesLuz(false);
  }
  
  if(horaActual == horaApagarLucesNoche){
    datosRelesCeramica(false);
  }
  
  if(horaActual == horaEncenderLucesDia){
    datosRelesLuz(true);
    datosRelesCalor(true);
  }
  
  if((horaActual >= horaApagarLucesDia) && (horaActual <= 23)){
    if(horaActual >= 0 && horaActual < horaApagarLucesNoche){
      datosRelesLuz(false);
      datosRelesCalor(false);
      if(((temperaturaActualArriba + temperaturaActualAbajo)/2) < temperaturaMinNoche){
        datosRelesCeramica(true);
      }
      else{
        if(((temperaturaActualArriba + temperaturaActualAbajo)/2) > temperaturaMaxNoche){
          datosRelesCeramica(false);
        }
      }
    }
  }
  if((horaActual >= horaApagarLucesNoche) && (horaActual < horaApagarLucesDia)){
      datosRelesCeramica(false);
      datosRelesLuz(true);
      if(((temperaturaActualArriba + temperaturaActualAbajo)/2) < temperaturaMinDia){
        datosRelesCalor(true);
      }
      else{
        if(((temperaturaActualArriba + temperaturaActualAbajo)/2) > temperaturaMaxDia){
          datosRelesCalor(false);
        }
     }
  }  
}

boolean cycleCheck(unsigned long *lastMillis, unsigned int cycle){
 unsigned long currentMillis = millis();
 if(currentMillis - *lastMillis >= cycle){
   *lastMillis = currentMillis;
   return true;
 }
 else
   return false;
}

void obtenerDatos(){
  mensajeDebug("::obtenerDatos::");
  //Serial.println("Obteniendo datos de sensores");
  datosHoraYFecha();
  datosTemperatura();
  datosHumedad();
  datosNivelAgua();
}

void pantallaInicio(){
  mensajeDebug("::pantallaInicio::");
  //Marco y menu derecho 
  //marcoYMenu();
  //Diseño Pantalla de Datos  
  pantallaDatos();
//  datosHoraYFecha();
//  datosTemperatura();
//  datosHumedad();
//  
//  //Control de horas
//  if((getHoraActual() >= horaApagarLuces) && (getHoraActual() <= horaEncenderLuces)){
//    datosRelesLuz(false);
//  }
//  else{
//      if(getHoraActual() == horaEncenderLuces){
//        datosRelesLuz(true);
//      }
//  }
//  
//  
//  //TODO: QUEDA LAS HORAS Y TODO EL JALEO ESTE
//  datosRelesCalor(flagCalor);
//  datosRelesCeramica(flagCeramica);
//  
//  //Si tenemos buen nivel de agua, seguimos normal
//  Serial.println("Antes");
//  Serial.println(nivelAguaActual);
//  if(nivelAguaActual >= nivelMinAgua){
//    Serial.println(nivelAguaActual);
//    Serial.println("SEguimos bien");
//    if((getHumedadArriba() < humedadMin) || (getHumedadAbajo() < humedadMin)){// y la humedad de abajo???
//      Serial.println("Que llueva");
//      datosRelesLluvia(true);
//    }
//    else{
//      Serial.println("No puede llover");
//      datosRelesLluvia(false);
//    }
//  }
//  else{
//      datosRelesLluvia(false);
//  }
//  if(flagLluvia){
//    if((getHumedadArriba() >= humedadMax) || (getHumedadAbajo() >= humedadMax)){
//      datosRelesLluvia(false);
//    }
//  }
    
}

void mensajeDebug(String mensaje){
  if(DEBUG){
    Serial.println(mensaje);
    delay(1000);
  }
} 
 
