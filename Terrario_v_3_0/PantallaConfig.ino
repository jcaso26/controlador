//void pantallaConfig(){
//  
//  boolean salir = false;
//  long x, y;
//  
//  mensajeDebug("::pantallaConfig::");
//  marcoYMenu();
//  pintarPantallaConfig();
//  
//  while (!salir){   
//      while (myTouch.dataAvailable() == true){
//        delay(100);
//        myTouch.read();
//        delay(100);
//        x = myTouch.getX();
//        y = myTouch.getY();   
//        
//        if((x!= -1) && (y!=-1)){
//          Serial.print("Valor de x: ");
//          Serial.println(x);
//          Serial.print("Valor de y: ");
//          Serial.println(y);
//          salir = true;
//        }
//        else{
//          Serial.println("NO POS. CORRECTA");
//        } 
//    }
//  }
//  
//  if((x >= 18) && (x <= 177)){
//    if((y >= 7) && (y <= 122)) {
//      mensajeDebug("CONFIGURACION DE PRIMAVERA");
//      cargarFicheroConfiguracion(ficheroPrimavera);
//    }
//  }
//  
//  if((x >= 191) && (x <= 349)){
//    if((y >= 7) && (y <= 116)) {
//      mensajeDebug("CONFIGURACION DE VERANO");
//      cargarFicheroConfiguracion(ficheroVerano);
//    }
//  }
//  
//  if((x >= 17) && (x <= 177)){
//    if((y >= 135) && (y <= 239 )) {
//      mensajeDebug("CONFIGURACION DE OTOÑO");
//      cargarFicheroConfiguracion(ficheroOtonio);
//      setHumedad(30);
//      setTemperatura(10);
//    }
//  }
//  
//  if((x >= 192) && (x <= 352)){
//    if((y >= 129) && (y <= 230)) {
//      mensajeDebug("CONFIGURACION DE INVIERNO");
//      cargarFicheroConfiguracion(ficheroInvierno);
//      setHumedad(20);
//      setTemperatura(25);
//    }
//  }
//  
//  if((x >= 358) && (x <= 378)){
//    if((y >= 9) && (y <= 109)){
//      myGLCD.clrScr();
//      mensajeDebug("Llamando pantalla Inicio");
//      pantallaInicio();
//    }
//  }
//}
//
//void pintarPantallaConfig(){
//  mensajeDebug("::pintarPantallaConfig::");
//  
//  myGLCD.setColor(VGA_YELLOW);
//  myGLCD.drawRoundRect(2,2,(tamX-32)/2,tamY/2);
// 
//  myGLCD.setColor(VGA_YELLOW);
//  myGLCD.drawRoundRect((tamX-32)/2,2,tamX-34,tamY/2); 
// 
//  myGLCD.setColor(VGA_YELLOW);
//  myGLCD.drawRoundRect(2,tamY/2,(tamX-32)/2,tamY-2);
// 
//  myGLCD.setColor(VGA_YELLOW);
//  myGLCD.drawRoundRect((tamX-32)/2,tamY/2,tamX-34,tamY-2); 
//  
//  myGLCD.setFont(BigFont);
//  myGLCD.setBackColor(VGA_BLACK);
//  myGLCD.setColor(VGA_GREEN);
//  
//  myGLCD.print("PRIMAVERA", 18, tamY/5);
//  
//  myGLCD.print("VERANO", (tamX/2)+30, tamY/5);
//  
//  myGLCD.print("OTONIO", 40, tamY-70);
//  
//  myGLCD.print("INVIERNO", (tamX/2)+10, tamY-70);
//  
//}
//
//void cargarFicheroConfiguracion(char *nombreFichero){
//  res=file.initFAT(); 
//  if (res!=NO_ERROR){
//    Serial.print("***** ERROR: ");
//    Serial.println(verboseError(res));
//    while (true) {};
//  }
//
//  Serial.println("This demo will display a textfile called 'TEXTFILE.TXT'");
//  Serial.println();
//  Serial.println("***** Send any character to start *****");
//  //while (!Serial.available()) {};
//  Serial.flush();
//  Serial.println();
//  Serial.println();
//  
//  if (file.exists(nombreFichero)){  
//    res=file.openFile(nombreFichero, FILEMODE_TEXT_READ);
//    if (res==NO_ERROR){
//      result=0;
//      while ((result!=EOF) and (result!=FILE_IS_EMPTY)){
//        result=file.readLn(textBuffer, 80);
//        if (result!=FILE_IS_EMPTY){
//          if (result==BUFFER_OVERFLOW){
//            Serial.print(textBuffer);
//            delay(1000);
//          }
//          else{
//            Serial.println(textBuffer);
//            setParametro(textBuffer);;
//          }
//        }
//        else
//          Serial.println("** ERROR: File is empty...");
//      }
//      Serial.println();
//      file.closeFile();
//    }
//    else{
//      switch(res){
//        case ERROR_ANOTHER_FILE_OPEN:
//          Serial.println("** ERROR: Another file is already open...");
//          break;
//        default:
//          Serial.print("** ERROR: ");
//          Serial.println(res, HEX);
//          break;
//      }
//    }
//  }
//  else
//    Serial.println("** ERROR: 'TEXTFILE.TXT' does not exist...");
//    
//  Serial.println();
//  Serial.println();
//  Serial.println("***** All done... *****");
//  
//
//}
//
//char *verboseError(byte err){
//	switch (err){
//	case ERROR_MBR_READ_ERROR:
//		return "Error reading MBR";
//		break;
//	case ERROR_MBR_SIGNATURE:
//		return "MBR Signature error";
//		break;
//	case ERROR_MBR_INVALID_FS:
//		return "Unsupported filesystem";
//		break;
//	case ERROR_BOOTSEC_READ_ERROR:
//		return "Error reading Boot Sector";
//		break;
//	case ERROR_BOOTSEC_SIGNATURE:
//		return "Boot Sector Signature error";
//		break;
//	default:
//		return "Unknown error";
//		break;
//	}
//}
//
//void setParametro(char *cadena){
//  boolean siguiente = false;
//  int len = strlen(cadena);
//  String valor = "";
//  for(int i=0;i<len;i++){
//    if(cadena[i]=='='){
//      siguiente = true;
//      i++;
//    }
//    if(siguiente){
//      valor = valor + cadena[i];
//    }
//  } 
//  Serial.println(valor);
//  delay(1000);
//}


