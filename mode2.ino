void mode1(){
  if (millis() - t1 >= tTirai){
    digitalWrite(4, LOW);
  }
  if (millis() - t1 >= tMaju){
    digitalWrite(5, LOW);
  }
}
