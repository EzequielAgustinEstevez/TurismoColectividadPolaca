int A = 12;
int pulsador = 0;
int vueltasR = 0;
int vueltasV = 0;
int vueltas = 0;
int bandera = 0;
int intento1 = 0;
int intento2 = 0;
int intento3 = 0;

void setup()
{
    for (int x = 2; x <= 11; x++)
    {
        pinMode(x, OUTPUT);
    }
    pinMode(12, INPUT);
};

void reinicio()
{
    pulsador = 0;
    vueltasR = 0;
    vueltasV = 0;
    vueltas = 0;
    bandera = 0;
    intento1 = 0;
    intento2 = 0;
    intento3 = 0;
};

void parpadeoRojo(int x)
{ //funcion para parpadear
    while (vueltasR < 5)
    {                          //se repite elciclo for hasta llegar a 30 vueltas
        digitalWrite(13, LOW); // led Verde
        delay(200);
        digitalWrite(x, HIGH);
        delay(200);
        digitalWrite(x, LOW);
        delay(200);
        vueltasR++;
    }
    vueltasR = 0; //se reiniciala el contador de vuetlas
};

void parpadeoVerde()
{
    while (vueltasV < 5)
    { //se repite elciclo for hasta llegar a 30 vueltas
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        vueltasV++;
    }
    vueltasV = 0; //se reiniciala el contador de vuetlas
};

void parpadeoGanador()
{
    digitalWrite(13, HIGH);
    for (int x = 2; x <= 11; x++)
    {
        if (x % 2 == 0)
        {
            digitalWrite(x, HIGH);
        }
        else
        {
            digitalWrite(x, LOW);
        }
    }
    delay(2000);
    for (int x = 2; x <= 11; x++)
    {
        if (x % 2 == !0)
        {
            digitalWrite(x, HIGH);
        }
        else
        {
            digitalWrite(x, LOW);
        }
    }
    delay(2000);
    for (int x = 2; x <= 11; x++)
    {
        if (x % 2 == 0)
        {
            digitalWrite(x, HIGH);
        }
        else
        {
            digitalWrite(x, LOW);
        }
    }
    delay(2500);
    digitalWrite(13, LOW);
    delay(500);
    reinicio();
};

void parpadeoPerdedor()
{
    for (int x = 2; x <= 11; x++)
    {
        digitalWrite(x, HIGH);
    }
    delay(5000);
    for (int x = 2; x <= 11; x++)
    {
        digitalWrite(x, LOW);
    }
    delay(1000);
    reinicio();
};

void loop()
{
    for (int x = 2; x <= 11; x++)
    {                              //recorre las luces
        pulsador = digitalRead(A); // verifica el estado del pulsador
        if (pulsador == HIGH)
        {                    //si esta pulsado llama a parpadeo
            parpadeoRojo(x); //parpadeo es una funcion que activa y  descativa las luces cada 200ms
            if (vueltas == bandera)
            {
                bandera++;
                intento1 = x;
            }
            else if (bandera == 1)
            {
                bandera++;
                intento2 = x;
                if (intento1 == intento2)
                {
                    parpadeoVerde();
                    parpadeoRojo(x);
                }
                else
                {
                    parpadeoPerdedor();
                }
            }
            else if (bandera == 2)
            {
                if (intento2 == x)
                {
                    parpadeoGanador();
                }
                else
                {
                    parpadeoPerdedor();
                }
            }
        }
        else
        { //de lo contrario prende la siguiente luz una vez
            digitalWrite(x, HIGH);
            delay(200);
            digitalWrite(x, LOW);
        }
        pulsador = 0; //se resetea el valor del pulsador
    }
};