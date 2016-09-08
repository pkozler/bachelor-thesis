import java.util.Scanner;

/**
 * Reseni kvalifikacni ulohy PilsProg - Seznam slov
 * @author Tomas Potuzak
 */  
public class SeznamSlov {
  /** Maximalni pocet ruznych slov ziskanych ze vstupniho textu */
  public static final int MAXIMALNI_POCET_RUZNYCH_SLOV = 25000;
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  /** Ruzna slova ziskana ze vstupniho tetu */
  private static String[] ruznaSlova;
  /** Pocet ruznych slov ziskanych ze vstupniho textu */
  private static int pocetRuznychSlov;
   
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)  
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    ruznaSlova = new String[MAXIMALNI_POCET_RUZNYCH_SLOV];
    pocetRuznychSlov = 0;
    
    String radka = sc.nextLine().trim();
    while (!radka.equals(".")) {  //Dokud neni nalezena samotna tecka na samotne radce
      zpracujRadku(radka);
      radka = sc.nextLine().trim();
    }
    
    seradRuznaSlova();
    vypisRuznaSlova();
  }
  
  /**
   * Zpracuje zadanou radku textu - najde vsechna slova (skupiny pismen) a vlozi je do pole slov, pokud tato slova jeste nejsou v poli obsazena
   * @param radka radka texti, z niz se maji ziskat slova
   */        
  public static void zpracujRadku(String radka) {
    String slovo;
    int zacatekSlova = -1;
    int pocetZnaku = -1;
        
    for (int i = 0; i < radka.length(); i++)  {
      if (pocetZnaku <= 0 && Character.isLetter(radka.charAt(i))) { //Slovo zacina pismenem
        zacatekSlova = i;
        pocetZnaku = 1;
      }
      else if (pocetZnaku > 0 && Character.isLetter(radka.charAt(i))) { //Pismena uvnitr slova
        pocetZnaku++;
        
        if (i == radka.length() - 1) { // Pro slova na konci radky
          slovo = radka.substring(zacatekSlova, zacatekSlova + pocetZnaku);
          zaradSlovo(slovo.toLowerCase());
          zacatekSlova = -1;
          pocetZnaku = -1;
        }
      }
      else if (pocetZnaku > 0 && !Character.isLetter(radka.charAt(i))) { //Slovo konci nepismenem
        slovo = radka.substring(zacatekSlova, zacatekSlova + pocetZnaku);
        zaradSlovo(slovo.toLowerCase());
        zacatekSlova = -1;
        pocetZnaku = -1;
      }
    }
  }
  
  /**
   * Vlozi zadane slovo do pole ruznych slov, pokud toto slovo v poli jeste neni obsazene
   * @param slovo slovo, ktere ma byt vlozeno do pole ruznych slov
   */        
  public static void zaradSlovo(String slovo) {
    //System.out.println(slovo);
    
    boolean nalezeno = false;
    for (int i = 0; i < pocetRuznychSlov; i++) {
      if (ruznaSlova[i].equals(slovo)) {
        nalezeno = true;
        break;
      }
    }
    
    if (!nalezeno) {
      ruznaSlova[pocetRuznychSlov] = slovo;
      pocetRuznychSlov++;
    }
  }
  
  /**
   * Seradi naplnene pole ruznych slov pomoci SelectSort
   */     
  public static void seradRuznaSlova() {
    java.util.Arrays.sort(ruznaSlova, 0, pocetRuznychSlov);
    /*int index = 0;
    String pom = null;
    
    for (int i = 0; i < pocetRuznychSlov - 1; i++) {
      index = i;
      
      for (int j = i; j < pocetRuznychSlov; j++) {
        if (ruznaSlova[j].compareTo(ruznaSlova[index]) < 0) {
          index = j;
        }
      }
      
      if (index != i) {
        pom = ruznaSlova[i];
        ruznaSlova[i] = ruznaSlova[index];
        ruznaSlova[index] = pom;
      }
    }*/
  }
  
  /**
   *  Vypise pole ruznych slov na standardni vystup (jedno slovo na jeden radek)
   */     
  public static void vypisRuznaSlova() {
    for (int i = 0; i < pocetRuznychSlov; i++) {
      System.out.println(ruznaSlova[i]);
    }
  }
}