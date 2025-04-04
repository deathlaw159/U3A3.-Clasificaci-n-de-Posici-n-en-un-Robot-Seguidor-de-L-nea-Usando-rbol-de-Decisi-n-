// Definición de pines para los sensores 
const int s_i = 2;   // Sensor izquierdo
const int s_c = 4;   // Sensor central
const int s_d = 6;   // Sensor derecho
const int s_i_p = 3; // Sensor izquierdo previo
const int s_c_p = 5; // Sensor central previo
const int s_d_p = 7; // Sensor derecho previo

// Pines de los motores
const int motorIzqA = 9;
const int motorIzqB = 10;
const int motorDerA = 11;
const int motorDerB = 12;

void setup() {
    pinMode(s_i, INPUT);
    pinMode(s_c, INPUT);
    pinMode(s_d, INPUT);
    pinMode(s_i_p, INPUT);
    pinMode(s_c_p, INPUT);
    pinMode(s_d_p, INPUT);
    pinMode(motorIzqA, OUTPUT);
    pinMode(motorIzqB, OUTPUT);
    pinMode(motorDerA, OUTPUT);
    pinMode(motorDerB, OUTPUT);
    Serial.begin(9600);
}

int clasificarPosicion() {
    int si = digitalRead(s_i);
    int sc = digitalRead(s_c);
    int sd = digitalRead(s_d);
    int si_p = digitalRead(s_i_p);
    int sc_p = digitalRead(s_c_p);
    int sd_p = digitalRead(s_d_p);

    if (sc == 0) {
        if (si_p == 0) {
            if (si == 0) {
                return (sd == 0) ? 10 : 2;
            } else {
                return 10;
            }
        } else {
            return 10;
        }
    } else {
        if (sc_p == 0) {
            return (si_p == 0) ? 4 : 10;
        } else {
            if (si_p == 0) {
                return (si == 0) ? 5 : 6;
            } else {
                return (sd_p == 0) ? 6 : 0;
            }
        }
    }
}

void moverRobot(int clase) {
    switch (clase) {
        case 4: 
        case 5: 
            digitalWrite(motorIzqA, HIGH);
            digitalWrite(motorIzqB, LOW);
            digitalWrite(motorDerA, HIGH);
            digitalWrite(motorDerB, LOW);
            break;
        case 6: 
            digitalWrite(motorIzqA, LOW);
            digitalWrite(motorIzqB, HIGH);
            digitalWrite(motorDerA, HIGH);
            digitalWrite(motorDerB, LOW);
            break;
        case 2: 
            digitalWrite(motorIzqA, HIGH);
            digitalWrite(motorIzqB, LOW);
            digitalWrite(motorDerA, LOW);
            digitalWrite(motorDerB, HIGH);
            break;
        case 0: 
        case 10:
            digitalWrite(motorIzqA, LOW);
            digitalWrite(motorIzqB, LOW);
            digitalWrite(motorDerA, LOW);
            digitalWrite(motorDerB, LOW);
            break;
    }
}

void loop() {
    int clase = clasificarPosicion();
    Serial.print("Clase detectada: ");
    Serial.println(clase);
    moverRobot(clase);
    delay(100);
}
