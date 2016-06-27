import java.util.Scanner;

/**
 * Reseni finalove ulohy PilsProg - Dekodovani pasky
 * @author Tomas Potuzak
 */  
public class DekodovaniPasky {
  /** Znak reprezentujici nulu */
  public static final char NULA = ' ';
  /** Znak reprezentujici jednicku */
  public static final char JEDNA = 'o';
  /** Znak reprezentujici konec kusu pasky */
  public static final char KONEC = '_';
  /**   */
  public static final int INDEX_ZACATEK = 2;
  /**  */
  public static final int INDEX_KONEC = 9;
  /**  */
  public static final int INDEX_VODICI_PAS = 6;
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)   
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    String radka = sc.nextLine(); //Nacteni prvni radky, kterou nevyuzijeme - obsahuje podtrzitka
    
    while ((radka = sc.nextLine()).charAt(0) != KONEC) {
      System.out.print(dekodujZnak(radka));
    } 
    
    System.out.println();
  }
  
  /**
   * Dekoduje a vrati znak z jedne radky derne pasky
   * @param radka radka derne pasky obsahujici jeden znak zaznamenany pomoci sedmi bitu
   * @return znak z jedne radky derne pasky   
   */        
  public static char dekodujZnak(String radka) {
    char znak = (char) 0;
    
    for (int i = INDEX_ZACATEK; i <= INDEX_KONEC; i++) {
      if (i != INDEX_VODICI_PAS) {
        znak <<= 1;
        
        if (radka.charAt(i) == JEDNA) {
          znak |= 1;
        }
      }
    }
    
    return znak;
  }
}