#include <iostream>
#include "half_to_float.h"
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

unsigned static short arrayfloat[16];

void print_bits16(const ushort x)
{

    // cout << "a " << x << "\n";
    for (int i = 15; i >= 0; i--)
    {
        arrayfloat[i] = ((x >> i) & 1);
    }

    for (int i = 0; i <= 15; i++)
    {
        cout << arrayfloat[i];
    }

    cout << endl;
}

void print_bits32(const float x)
{
    uint b = *(uint *)&x;
    for (int i = 31; i >= 0; i--)
    {
        cout << ((b >> i) & 1);
        if (i == 31 || i == 23)
            cout << " ";
        if (i == 23)
            cout << "   ";
    }
    cout << endl;
}

void floatToDecimal(unsigned short arrayfloat[])
{
    unsigned static short arraySigno[1];
    unsigned static short arrayExpo[5];
    unsigned static short arrayManti[10];

    int operation = 0;
    int sesgo = 15;
    int total = 0;
    int contador = 0;
    int contador2 = 0;
    string sign;

    arraySigno[0] = arrayfloat[15];

    arrayExpo[0] = arrayfloat[14];
    arrayExpo[1] = arrayfloat[13];
    arrayExpo[2] = arrayfloat[12];
    arrayExpo[3] = arrayfloat[11];
    arrayExpo[4] = arrayfloat[10];

    arrayManti[0] = arrayfloat[9];
    arrayManti[1] = arrayfloat[8];
    arrayManti[2] = arrayfloat[7];
    arrayManti[3] = arrayfloat[6];
    arrayManti[4] = arrayfloat[5];
    arrayManti[5] = arrayfloat[4];
    arrayManti[6] = arrayfloat[3];
    arrayManti[7] = arrayfloat[2];
    arrayManti[8] = arrayfloat[1];
    arrayManti[9] = arrayfloat[0];

    if (arraySigno[0] == 1)
    {
        sign = "-";
    }
    else if (arraySigno[0] == 0)
    {
        sign = "";
    }

    cout << "sign" << sign;

    for (int i = 0; i > 6; i++)
    {
        if (arrayExpo[i] == 1)
        {
            contador++;
            cout << "contador: " << contador << "\n";
        }
    }
    int expos[contador];

    for (int i = 0; i > contador; i++)
    {
        if (arrayExpo[i] == 1)
        {
            int j = 0;
            expos[j] = i;
            j++;
        }
    }

    for (int i = 0; i > contador; i++)
    {
        operation += pow(2, expos[i]);
        cout << "\n "
             << "operation: " << operation;
    }

    total = operation - sesgo;

    cout << "\n "
         << "total: " << total;

    for (int i = 9; i >= 0; i--)
    {
        if (arrayManti[i] == 1)
        {

            contador2 = i;
            i = -1;
        }
    }
    // 1 ,1 0 0 0 1
    int arrayMantiC[contador2 + 2];

    for (int i = 0; i < contador2 + 2; i++)
    {
        arrayMantiC[0] = 1;
        if (i != 0)
        {
            arrayMantiC[i] = arrayManti[i];
        }
    }
    // quedamos por aca donde intentamos correr la coma para obtener el ultimo numero binario y asi pasarlo a decimal

    int corriendo = 0;

    if (total < 0)
    {
        corriendo = (-total); // 1,0000101 x2^-2 = 02010000101 = decimal
        int arrayAconver[corriendo + sizeof arrayMantiC + 1];
        for (int i = 0; i < corriendo; i++)
        {
            if (i = 1)
            {
                arrayAconver[i] = 2; //{0,2,0}
            }
            arrayAconver[i] = 0; //{0,0,0,0,ARRAYMATINC}
        }

        int cont = 0;
        for (int i = sizeof arrayAconver; i < sizeof arrayMantiC; i++)
        {
            arrayAconver[i] = arrayMantiC[cont];
            cont++;
        }
        int posiInt[8] = {1, 2, 4, 8, 16, 32, 64, 128};
        float posiDec[20];
        int entero = 0;
        for (int i = 0; i < 21; i++)
        {
            posiDec[i] = pow(2, -i);
        }

        for (int i = 0; i < sizeof arrayAconver + 1; i++)
        {
            // 1,011010
            if (arrayAconver[i] == 1)
            {
                while (arrayAconver[i] == 2 && i < 3)
                {
                    entero += posiInt[i];
                }
                if (arrayAconver[i] == 2 & i < 3)
                {
                }
            }

            if (arrayAconver[i] == 2)
            {
                i = 0;
            }

            if (arrayAconver[i] == 1)
            {
                entero += posiInt[i];
            }
        }
    }
    else if (total > 0)
    {
        corriendo = ((sizeof arrayMantiC) - total); // 1,0101101 x 2^9 corriendo = 7-9 = -2 // 8 -- 2
        int arrayConver[corriendo];
        int contadorX = sizeof arrayMantiC;

        for (int i = 0; i < corriendo; i++)
        {
            if (contadorX > 0)
            {
                arrayConver[i] = arrayMantiC[i]; // 7
                contadorX--;                     // 0
            }
            else if (contadorX == 0)
            {
                arrayConver[i] = 0;
            }
        }
    }
    else if (total == 0)
    {
        corriendo = total;
        // se trabaja con arrayMantic porque ya está normalizado
    }
}

int main()
{

    // const ushort x_compressed = float_to_half(x);
    // const float x_decompressed = half_to_float(x_compressed);

    float distanciaMedida = 0;
    float radio = 0.5f;
    const ushort radio_compressed = float_to_half(radio);

    float perimetroRueda = 2 * 3.14159265f * radio;
    const ushort perimetro_compressed = float_to_half(perimetroRueda);
    float distanciaAlarma = 5000;
    const ushort alarma_compressed = float_to_half(distanciaAlarma);

    float distanciaAlarma2 = 10000;
    const ushort alarma2_compressed = float_to_half(distanciaAlarma2);

    print_bits16(radio_compressed);
    floatToDecimal(arrayfloat);

    // int16 numerosGirosLlanta =0;
    /* cout << "Perimetro rueda "
         << "\n";
    cout << "32 bits: ";
    print_bits32(perimetroRueda);
    cout << "16 bits: ";
    print_bits16(perimetro_compressed);
    cout << "\n";
    cout << "Distancia Alarma"
         << "\n";
    cout << "32 bits: ";
    print_bits32(distanciaAlarma);
    cout << "16 bits: ";
    print_bits16(alarma_compressed);
    cout << "--- Distancia Alarma 2 ---"
         << "\n";
    cout << "32 bits: ";
    print_bits32(distanciaAlarma2);
    cout << "16 bits: ";
    print_bits16(alarma2_compressed); */
    // floatToDecimal(arrayfloat);
    //  print_bits32(x_decompressed);

    /* for (int j = 0; j < 16; j++)
    {
        cout << "array: " << arrayfloat[j] << "\n";
    } */

    return 0;
}
