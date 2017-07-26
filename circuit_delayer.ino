int circuit = 9;
void setup() {
  // put your setup code here, to run once:
 pinMode(circuit,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:

    int x = 0;
    while (x<15){
    digitalWrite(circuit, HIGH);
    delayMicroseconds(1300);
    digitalWrite(circuit,LOW);
    delayMicroseconds(1300);
    x++;
    }

    delayMicroseconds(39000);
}
