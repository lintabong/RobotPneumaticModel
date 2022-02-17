void mode0(){
  if (millis() - t0 >= tStrobo){
    digitalWrite(3, HIGH);
  }
  if (millis() - t0 >= tStrobo*2){
    digitalWrite(3, LOW);

    t0 = millis();
  }
}
