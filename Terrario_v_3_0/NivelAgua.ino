void datosNivelAgua(){
  mensajeDebug("::datosNivelAgua::");
  // 1. Leer sensor
  // 2. Si lectura < nivelMinimoAgua
  // 3. Mensaje Error
  
  digitalWrite(TRIG_PIN_HCSR,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN_HCSR, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(ECHO_PIN_HCSR, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  nivelAguaActual = distancia;
  /*Monitorización en centímetros por el monitor serial*/
//  Serial.println("Distancia ");
//  Serial.println(nivelAguaActual);
//  Serial.println(" cm");
 // delay(1000);
}

void mostrarNivelAguaBajoEnPantalla(boolean borrar){
  mensajeDebug("::mostrarNivelAguaBajoEnPantalla::");
  
  if(borrar){
    myGLCD.setFont(BigFont);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.setBackColor(VGA_RED);
    myGLCD.print("NIVEL AGUA", ((tamX-32)*2), (tamY-160)/6);
  }               
  else{
    myGLCD.setFont(BigFont);
    myGLCD.setColor(VGA_BLACK);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.print("          ", ((tamX-32)*2), (tamY-160)/6);
  }
}
