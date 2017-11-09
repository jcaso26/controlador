//Bloque grafico de los reles
void bloqueReles(int centroCabTemp){
  graficosReleLuz();  
  graficosReleCalor();
  graficosReleCeramica();
  graficosReleLluvia();
}

//Graficos Rele Luz
void graficosReleLuz(){
  //Borde
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.drawRoundRect(2,tamY-78,((tamX-3)/4),tamY-3);
  //Cabecera
  myGLCD.fillRoundRect(2,tamY-78,((tamX-3)/4)-2,tamY-58);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_YELLOW);
  myGLCD.print("LUZ",(((tamX-3)/4)/3)+4,tamY-75); 
}

//Graficos Rele Calor
void graficosReleCalor(){
  //Borde
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.drawRoundRect(((tamX-3)/4)-2,tamY-78,((tamX-3)/2),tamY-3);
  //Cabecera
  myGLCD.fillRoundRect(((tamX-3)/4),tamY-78,((tamX-3)/2)-2,tamY-58);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_YELLOW);
  myGLCD.print("CALOR",((tamX-3)/4)+25,tamY-75); 
}

//Graficos Rele Ceramica
void graficosReleCeramica(){
  //Borde
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.drawRoundRect(((tamX-3)/2)-2,tamY-78,(((tamX-3)/2)+((tamX-3)/4)),tamY-3);
  //Cabecera
  myGLCD.fillRoundRect(((tamX-3)/2),tamY-78,(((tamX-3)/2)+((tamX-3)/4)),tamY-58);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_YELLOW);
  myGLCD.print("CERAMICA",((tamX-3)/2)+15,tamY-75); 
}

//Graficos Rele Lluvia
void graficosReleLluvia(){
  //Borde
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.drawRoundRect((((tamX-3)/2)+((tamX-3)/4))+2,tamY-78,tamX-3,tamY-3);
  //Cabecera
  myGLCD.fillRoundRect((((tamX-3)/2)+((tamX-3)/4))+2,tamY-78,tamX-3,tamY-58);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_YELLOW);
  myGLCD.print("LLUVIA",(((tamX-3)/2)+((tamX-3)/4))+25,tamY-75); 
}

void datosRelesLuz(boolean flagLuz){
  if(!flagLuz){
    //Serial.println("Dentro de flagLuz -> false");
    //myFiles.loadBitmap((tamX-3)/18, tamY-55, tamImLed, tamImLed, ledsImagenes[0]);
    digitalWrite(PIN_RELE_LUZ, HIGH);
    myGLCD.setColor(VGA_RED);
    myGLCD.fillCircle((tamX-32)/7, tamY-29, 22);
    flagLuz = true;
    
  }
  else{
    //Serial.println("Dentro de flagLuz -> true");
    digitalWrite(PIN_RELE_LUZ, LOW);
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillCircle((tamX-32)/7, tamY-29, 22);
    flagLuz = false;
  }
}

void datosRelesLluvia(boolean flagLluvia){
  if(!flagLluvia){
    //Serial.println("Dentro de flagCalor -> false");
    //myFiles.loadBitmap(((tamX-3)/3)-10, tamY-55, tamImLed, tamImLed, ledsImagenes[0]);
    digitalWrite(PIN_RELE_LLUVIA, HIGH);
    myGLCD.setColor(VGA_RED);
    myGLCD.fillCircle(tamX-55, tamY-29, 22);
    flagLluvia = true;
  }
  else{
    //Serial.println("Dentro de flagCalor -> true");
    //myFiles.loadBitmap(((tamX-3)/3)-10, tamY-55, tamImLed, tamImLed, ledsImagenes[1]);
    digitalWrite(PIN_RELE_LLUVIA, LOW);
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillCircle(tamX-55, tamY-29, 22);
    flagLluvia = false;
  }
}

void datosRelesCeramica(boolean flagCeramica){
  if(!flagCeramica){
    //Serial.println("Dentro de flagCeramica -> false");
    //myFiles.loadBitmap(((tamX-3)/2)+20, tamY-55, tamImLed, tamImLed, ledsImagenes[0]);
    digitalWrite(PIN_RELE_CERAMICA, HIGH);
    myGLCD.setColor(VGA_RED);
    myGLCD.fillCircle(tamX-155, tamY-29, 22);  
    flagCeramica = true;
  }
  else{
    //Serial.println("Dentro de flagCeramica -> true");
    //myFiles.loadBitmap(((tamX-3)/2)+20, tamY-55, tamImLed, tamImLed, ledsImagenes[1]);
    digitalWrite(PIN_RELE_CERAMICA, LOW);
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillCircle(tamX-155, tamY-29, 22);  
    flagCeramica = false;
  }
}

void datosRelesCalor(boolean flagCalor){
  if(!flagCalor){
    //Serial.println("Dentro de flagLluvia -> false");
    //myFiles.loadBitmap((tamX-75), tamY-55, tamImLed, tamImLed, ledsImagenes[0]);
    digitalWrite(PIN_RELE_CALOR, HIGH);
    myGLCD.setColor(VGA_RED);
    myGLCD.fillCircle(tamX-250, tamY-29, 22);    
    flagCalor = true;
  }
  else{
    //Serial.println("Dentro de flagLluvia -> true");
    //myFiles.loadBitmap((tamX-75), tamY-55, tamImLed, tamImLed, ledsImagenes[1]);
    digitalWrite(PIN_RELE_LUZ, LOW);
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillCircle(tamX-250, tamY-29, 22);
    flagCalor = false;
  }
}
