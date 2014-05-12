package adsaufgabe1;
import java.util.Arrays;

public class Testtreiber {
    public static void main (String[] args) {
	IBubblesort sort = new Bubblesort_MeinName();
	//IBubblesort sort = new Bubblesort_Musterloesung();
	String[] testfall1_in = { "aaa", "z", "ba", "ag" };
	int[] testfall1_soll = { 1, 3, 2, 0 };

	int[] ergebnis = sort.sortiere(testfall1_in);
	//for (int i=0; i<ergebnis.length; i++)
	    //System.out.print(testfall1_in[i]+" ");
	//System.out.println("");
	if (Arrays.equals(ergebnis, testfall1_soll))
	    System.out.println("Testfall 1: erfolgreich");
	else
	    System.out.println("Testfall 1: Fehler in der Implementation");
    }
}