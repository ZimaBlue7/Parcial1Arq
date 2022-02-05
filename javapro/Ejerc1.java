package javapro;

import java.math.*;
//import javax.swing.text.StyledEditorKit.BoldAction;

/**
 * Ejerc1
 */
/**
 * Ejerc1
 */
public class Ejerc1 {

    float distanciaMedida = 0;
    double distanciaMedida2 = 0;
    float radio = 0.5f;
    double perimetroRueda = Math.floor((2 * 3.14159265f * radio) * 100 / 100);
    float perimetroRueda2 = 2 * 3.14159265f * radio;
    float distanciaAlarma = 5000;
    float distanciaAlarma2 = 10000;
    int vueltas = 0;
    Boolean alarma;

    public static void main(String[] args) {

        // System.out.println(float16.fromFloat(0.5f));
        Ejerc1 ej1 = new Ejerc1();
        ej1.vueltas1();
        System.out.println("-------------");
        ej1.vueltas2();
    }

    public void vueltas1() {
        while (distanciaMedida < 5000) {
            distanciaMedida += perimetroRueda;
            vueltas++;
        }

        // distanciaMedida2 = vueltas * perimetroRueda;
        distanciaMedida2 = Math.floor((vueltas * perimetroRueda) * 100 / 100);

        System.out.println("Vueltas: " + vueltas);
        System.out.println("Distancia Medida: " + distanciaMedida2);
        System.out.println("Diferencia: " + (distanciaMedida2 - distanciaAlarma));

        if (distanciaAlarma == distanciaMedida) {
            alarma = true;
            System.out.println("Se activo la alarma: " + alarma);
        } else {
            alarma = false;
            System.out.println("No se activo la alarma: " + alarma);
        }

    }

    public void vueltas2() {

        while (distanciaMedida < 10000) {
            distanciaMedida += perimetroRueda;
            vueltas++;
        }

        distanciaMedida2 = Math.floor((vueltas * perimetroRueda) * 100 / 100);

        System.out.println("Vueltas: " + vueltas);
        System.out.println("Distancia Medida: " + distanciaMedida2);
        System.out.println("Diferencia: " + (distanciaMedida2 - distanciaAlarma2));

        if (distanciaAlarma == distanciaMedida) {
            alarma = true;
            System.out.println("Se activo la alarma: " + alarma);
        } else {
            alarma = false;
            System.out.println("No se activo la alarma: " + alarma);
        }
    }

}

// int16 numerosGirosLlanta =0;
