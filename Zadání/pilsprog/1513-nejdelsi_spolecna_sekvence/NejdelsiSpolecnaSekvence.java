import java.util.Scanner;

/**
  * Reseni kvalifikacni ulohy PilsProg - Nejdelsi spolecna sekvence
  * @author Tomas Potuzak
  */
public class NejdelsiSpolecnaSekvence {
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite) 
   */
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    
    int pocetTestovacichPripadu = sc.nextInt();
    sc.nextLine();
    String retezec1 = null;
    String retezec2 = null;
    
    for (int i = 0; i < pocetTestovacichPripadu; i++) {
      retezec1 = sc.nextLine();
      retezec2 = sc.nextLine();
      System.out.println(najdiDelkuNejdelsiSpolecneSekvence(retezec1, retezec2));
    }
  }
  
  /**
   * Najde a vrati delku nejdelsi spolecne sekvence zadanych retezcu s vyuzitim dynamickeho programovani
   * @param retezec1 prvni retezec
   * @param retezec2 druhy retezec
   * @return delka nejdelsi spolecne sekvence zadanych retezcu
   */              
  public static int najdiDelkuNejdelsiSpolecneSekvence(String retezec1, String retezec2) {
    if (retezec1 == null || retezec1.length() == 0 || retezec2 == null || retezec2.length() == 0) {
      return 0;
    }
    else {
      int[][] tabulkaDelek = new int[retezec1.length() + 1][retezec2.length() + 1];
      //Vynulovani nulte radky
      for (int i = 0; i < tabulkaDelek[0].length; i++) {
        tabulkaDelek[0][i] = 0;
      }
      //Vynulovani nulteho sloupce
      for (int i = 0; i < tabulkaDelek.length; i++) {
        tabulkaDelek[i][0] = 0;
      }
      
      //Vyplneni tabulky po postupne po radcich - pokud jsou si znaky reprezentujici radek a sloupec rovny, vezme se cislo o radek a sloupec vys a pricte se k nemu jednicka
      for (int i = 0; i < retezec1.length(); i++) {
        for (int j = 0; j < retezec2.length(); j++) {
          if (retezec1.charAt(i) == retezec2.charAt(j)) {
            tabulkaDelek[i + 1][j + 1] = tabulkaDelek[i][j] + 1;
          }
          else {
            tabulkaDelek[i + 1][j + 1] = Math.max(tabulkaDelek[i][j + 1], tabulkaDelek[i + 1][j]);
          }
        }
      }
      
      //Vypis vyplnene tabulky
      /*for (int i = 0; i < tabulkaDelek.length; i++) {
        for (int j = 0; j < tabulkaDelek[i].length; j++) {
          System.out.print(" " + tabulkaDelek[i][j]);
        }
        System.out.println();
      }*/
      
      //Vraceni hodnoty z praveho dolniho rohu tabulky (vysledek)
      return tabulkaDelek[retezec1.length()][retezec2.length()];
    }
  }
}