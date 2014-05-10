package adsaufgabe1;

public interface IBubblesort {

    /*
      Die Funktion erhaelt ein Feld A[0..(n-1)] mit n Strings.
      Sie sortiert das Feld aufsteigend - dabei gelte fuer zwei
      Strings S1 < S2 falls S1.length < S2.length; im Falle von
      Strings gleicher Laenge sei S1 kleiner als S2, falls der 
      erste Buchstabe von S1 frueher im Alphabet steht als der von
      S2. Vereinfachend koennen Sie von Strings mit ausschliesslich
      Kleinbuchstaben und ohne Zahlen bzw. Sonderzeichen ausgehen. 
      Strings mit gleicher Laenge und gleichem Anfangsbuchstaben gelten
      als gleich. Neben der Sortierung berechnet die Funktiondie
      Permutation mit der das urspruengliche Feld sortiert 
      wurde (vgl. Def. des Sortierproblems in der Vorlesung). Dieses
      wird als Rueckgabewert geliefert und bei meinen Tests geprueft.
      Vorsicht: Die Indizes der Permutation starten hier Java-typisch 
      bei 0. Ein Beispiel ist in Testtreiber.java gegeben.
     */
    public int[] sortiere(String[] eingabe);
}