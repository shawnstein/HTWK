package adsaufgabe1;
import java.io.*;

public class Bubblesort_MeinName implements IBubblesort {
    public int[] sortiere(String[] eingabe) {
	// Hier steht Ihr Bubblesort, das nebenbei die Permutation berechnet
	// Bitte keine Ausgaben per Print hier einfuegen
        for (int i = 0, temp; i < eingabe.length-1; i++) {
            for(int j = 0; j < eingabe.length-1; j++) {
                 if (eingabe[j+1] < eingabe[j]) {
                 } else {
                     temp = eingabe[j];
                     eingabe[j] = eingabe[j+1];
                     eingabe[j+1] = temp;
                }
            }
        }
	// Ich liefere eine falsche Ausgabe
	int[] erg = new int[eingabe.length];
	return erg;
    }
}