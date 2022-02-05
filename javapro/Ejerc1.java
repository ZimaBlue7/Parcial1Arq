package javapro;

/**
 * Ejerc1
 */
/**
 * Ejerc1
 */
public class Ejerc1 {

    float distanciaMedida = 0;
    float radio = 0.5f;
    float perimetroRueda = 2 * 3.14159265f * radio;
    float distanciaAlarma = 5000;
    float distanciaAlarma2 = 10000;
    int vueltas = 0;

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
        System.out.println("Vueltas: " + vueltas);
        System.out.println("Distancia Medida: " + distanciaMedida);

        System.out.println("Diferencia: " + (distanciaMedida - distanciaAlarma));
    }

    public void vueltas2() {

        while (distanciaMedida < 10000) {
            distanciaMedida += perimetroRueda;
            vueltas++;
        }
        System.out.println("Vueltas: " + vueltas);
        System.out.println("Distancia Medida: " + distanciaMedida);

        System.out.println("Diferencia: " + (distanciaMedida - distanciaAlarma2));
    }

}

// int16 numerosGirosLlanta =0;
