void pantallaPPal(){
  mensajeDebug("::pantallaPPal::");
  long x, y;
    
  unsigned long led1LastMillis = 0;
  unsigned int cycle = 6000;
    
  boolean finCiclo = false;
  long cont = 0;
  
  while (!finCiclo){   
    while (myTouch.dataAvailable() == true){
      delay(100);
      myTouch.read();
      delay(100);
      x = myTouch.getX();
      y = myTouch.getY();   
      
      if((x!= -1) && (y!=-1)){
        Serial.print("Valor de x: ");
        Serial.println(x);
        Serial.print("Valor de y: ");
        Serial.println(y);
      }
      else{
        Serial.println("NO POS. CORRECTA");
      }
      
      if(cycleCheck(&led1LastMillis, cycle)){
          Serial.println("Ciclo true");          
          finCiclo = true;
          led1LastMillis = 0;
      }

    }
    cont++;
    if(cont == 900000){
      Serial.println("Dentro del if del contador");
       finCiclo = true;
       obtenerDatos();
       cont = 0;
    }   
  }

  if((x >= 13) && (x <= 85)){
    if((y >= 181) && (y <= 239)) {
      mensajeDebug("Llamando a rele luz");
      datosRelesLuz(flagLuz);
    }
  }
  
  if((x >= 97) && (x <= 169)){
    if((y >= 173) && (y <= 239)) {
      mensajeDebug("Llamando a rele calor");
      datosRelesCalor(flagCalor);
    }
  }
  
  if((x >= 186) && (x <= 258)){
    if((y >= 177) && (y <= 237 )) {
      mensajeDebug("Llamando a rele ceramica");
      datosRelesCeramica(flagCeramica);
    }
  }
  
  if((x >= 272) && (x <= 344)){
    if((y >= 169) && (y <= 229)) {
      mensajeDebug("Llamando a rele lluvia");
      datosRelesLluvia(flagLluvia);
    }
  }
  
  if((x >= 358) && (x <= 378)){
    if((y >= 9) && (y <= 109)){
      myGLCD.clrScr();
      mensajeDebug("Llamando pantalla Inicio");
      pantallaInicio();
    }
  }  
  
//  if((x >= 358) && (x <= 378)){
//    if((y >= 125) && (y <= 226)){
//      mensajeDebug("Llamando pantalla Config");
//      pantallaConfig();
//    }
//  }
}
