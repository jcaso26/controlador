//Bloque grafico de la Hora y la Fecha
void bloqueHoraYFecha(){
  myGLCD.setColor(VGA_AQUA);
  myGLCD.drawRoundRect(2,2,tamX-3,tamY-160); 
}

//Datos de la Fecha y la Hora
void datosHoraYFecha(){
  
    DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  
   //HORA
   myGLCD.setColor(VGA_GREEN);
   myGLCD.setBackColor(VGA_BLACK);
   
   int centro = (tamY-160)/4;
   int posXHora = 29;
   int posXMin = 104;
   int posXDosPuntos = ((tamX-32)/4);
   int hora = now.hour();
   horaActual = hora;
   int minutos = now.minute();
   minActual = minutos;
   String dosPuntos = ":";
   
   myGLCD.setFont(SevenSegNumFont);
   myGLCD.printNumI(hora, posXHora, centro);
   myGLCD.setFont(BigFont);
   myGLCD.print(dosPuntos, posXDosPuntos, centro*2);
   myGLCD.setFont(SevenSegNumFont);
   if(minutos <10){
     myGLCD.printNumI(0, posXMin, centro);
     myGLCD.printNumI(minutos, posXMin + 35, centro);
   }
   else{
     myGLCD.printNumI(minutos, posXMin, centro);
   }
   
   //FECHA
   String barra = "/";
   int anio = now.year();
   int mes = now.month();
   int dia = now.day();
   myGLCD.setFont(BigFont);
   if(dia <10){
     myGLCD.printNumI(0, ((tamX-32)/2)+14, centro*2);
     myGLCD.printNumI(dia, ((tamX-32)/2)+30, centro*2);
   }
   else{
     myGLCD.printNumI(dia, ((tamX-32)/2)+14, centro*2);
   }
   myGLCD.print(barra, ((tamX-32)/2)+45, centro*2);
   
   if(mes <10){
     myGLCD.printNumI(0, ((tamX-32)/2)+60, centro*2);
     myGLCD.printNumI(mes, ((tamX-32)/2)+74, centro*2);
   }
   else{
     myGLCD.printNumI(mes, ((tamX-32)/2)+60, centro*2);
   }
   
   //myGLCD.printNumI(mes, ((tamX-32)/2)+60, centro*2);
   myGLCD.print(barra, ((tamX-32)/2)+90, centro*2);
   myGLCD.printNumI(anio, ((tamX-32)/2)+105, centro*2);  
}
