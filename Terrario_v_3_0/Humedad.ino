//Bloque grafico de la humedad
void bloqueHumedad(int centroCabTemp){
  //Borde
  myGLCD.setColor(VGA_RED);
  myGLCD.drawRoundRect(((tamX-3)/2)+2,tamY-158,(tamX-3),tamY-80);
  //Cabecera
  myGLCD.fillRoundRect(((tamX-3)/2)+2,tamY-158,(tamX-3),tamY-138);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_RED);
  myGLCD.print("HUMEDAD (%)",(centroCabTemp * 6)-20,tamY-155);//-10
  //Simbolo humedad (%)
  //myGLCD.setFont(BigFont);
  //myGLCD.setColor(VGA_AQUA);
  //myGLCD.setBackColor(VGA_BLACK);
  //myGLCD.print("%",(tamX-3)-25,tamY-135);
}

void datosHumedad(){
  float humAbajo = dhtAbajo.readHumidity(); //se lee la humedad
  float humArriba = dhtArriba.readHumidity(); //se lee la humedad
  
  int integerHumAbajo= (int)(humAbajo);
  setHumedadAbajo(humAbajo);
  int integerHumArriba= (int)(humArriba);
  setHumedadArriba(humArriba);
  //int decimalHum = 10 * (hum - integerHum);
  
  //String temperatura = String(temp);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setColor(VGA_AQUA);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.printNumI(integerHumAbajo,((tamX-3)/2)+20,tamY-136);
//  myGLCD.setFont(BigFont);
//  myGLCD.print(".",((tamX-3)/2)+66,tamY-103);
//  myGLCD.setFont(SevenSegNumFont);
//  myGLCD.printNumI(decimalHum,((tamX-3)/2)+76,tamY-136);

  myGLCD.printNumI(integerHumArriba,((tamX-3)/2)+120,tamY-136);
}
