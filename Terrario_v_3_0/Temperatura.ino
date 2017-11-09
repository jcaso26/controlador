//Bloque grafico de la temperatura
void bloqueTemperatura(int centroCabTemp){
  //Borde
  myGLCD.setColor(VGA_RED);
  myGLCD.drawRoundRect(2,tamY-158,((tamX-3)/2),tamY-80);
  //Cabecera
  myGLCD.fillRoundRect(2,tamY-158,((tamX-3)/2),tamY-138);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_RED);
//  myGLCD.print("TEMPERATURA (C)",centroCabTemp + 10,tamY-155);
myGLCD.print("TEMPERATURA (C)",centroCabTemp,tamY-155);
  //Simbolo temperatura (C)
//  myGLCD.setFont(BigFont);
//  myGLCD.setColor(VGA_AQUA);
//  myGLCD.setBackColor(VGA_BLACK);
//  myGLCD.print("C",((tamX-3)/2)-25,tamY-135);
}


void datosTemperatura(){
  //float t = dht.readTemperature(); //Se lee la temperatura
    
  float tempAbajo = dhtAbajo.readTemperature(); // se lee la temperatura
  float tempArriba = dhtArriba.readTemperature(); // se lee la temperatura
  
  int integerTempAbajo= (int)(tempAbajo);
  int integerTempArriba= (int)(tempArriba);
  //int decimalTemp = 10 * (temp - integerTemp);
  
  
  //String temperatura = String(temp);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setColor(VGA_AQUA);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.printNumI(integerTempAbajo,tamX-385,tamY-136);
//  myGLCD.setFont(BigFont);
//  myGLCD.print(".",tamX-333,tamY-103);
//  myGLCD.setFont(SevenSegNumFont);
//  myGLCD.printNumI(decimalTemp,tamX-323,tamY-136);
  
  
  //Temperatura 2
//  myGLCD.setFont(SevenSegNumFont);
//  myGLCD.setColor(VGA_AQUA);
//  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.printNumI(integerTempArriba,tamX-290,tamY-136);
//  myGLCD.setFont(BigFont);
 // myGLCD.print(".",tamX-250,tamY-103);
  //myGLCD.setFont(SevenSegNumFont);
  //myGLCD.printNumI(decimalTemp,tamX-323,tamY-136);
}
