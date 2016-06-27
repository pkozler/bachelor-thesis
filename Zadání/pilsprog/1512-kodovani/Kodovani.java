import java.util.Scanner;

/**
 * Reseni kvalifikacni ulohy PilsProg - Kodovani
 * @author Tomas Potuzak
 */  
public class Kodovani {
  /** ASCII kody povolenych znaku */
  public static final int[] KODY = {32, 33, 44, 46, 58, 59, 63, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
  /** Povolene znaky */
  public static final char[] ZNAKY = {' ', '!', ',', '.', ':', ';', '?', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)  
   */        
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    
    //System.out.println("Znaky: " + ZNAKY.length);
    //System.out.println("Kody: " + KODY.length);
    
    int pocetRadek = sc.nextInt();
    sc.nextLine();
    String radka = null;
    
    for (int i = 0; i < pocetRadek; i++) {
      //System.out.println("" + i);
      radka = sc.nextLine();
      zpracujRadku(radka);
    }
  }
  
  /**
   * Zpracuje jednu radku. Podle prvniho znaku na radce bud zpravu zakoduje nebo dekoduje a vysledek vypise na standarni vystup.
   */     
  public static void zpracujRadku(String radka) {
    if (radka != null && radka.length() > 0) {
      if (Character.isDigit(radka.charAt(0))) {
        dekoduj(radka);
      }
      else {
        zakoduj(radka);
      }
    }
    else {
      System.out.println();
    }
  }
  
  /**
   * Zakoduje zadanou zpravu a vrati ji
   * @param zprava zprava, ktera se ma zakodovat
   * @return zakodovana zprava  
   */        
  public static void zakoduj(String zprava) {
    int index = -1;
    int kod = 0;
    String kodStr = null;
    
    for (int i = zprava.length() - 1; i >= 0; i--) {
      //System.out.println("  " + i);
      index = najdiIndexZnaku(zprava.charAt(i));
      
      if (index >= 0) {
        kod = KODY[index];
        kodStr = "" + kod;
        
        for (int j = kodStr.length() - 1; j >= 0; j--) {
          System.out.print(kodStr.charAt(j));
        }
      }
      else {
        System.out.print("X");  //Znak nebyl nalezen - nejedna se o platny znak, vypisu do vystupu X (tj. mezi cisla) jako indikaci chyby
      }
    }
    System.out.println();
  }
  
  /**
   * Dekoduje zadanou zakodovanou zpravu a vrati puvodni (dekodovanou) zpravu
   * @param kodovanaZprava zakodovana zprava, ktera se ma dekodovat
   * @return puvodni (dekodovana) zprava   
   */        
  public static void dekoduj(String kodovanaZprava) {
    char[] zpravaObracene = new char[kodovanaZprava.length()]; //Zprava bude kratsi nez kodovana, takze velikost bohate staci
    int pocetZnaku = 0;
    char znak1 = '0';
    char znak2 = '0';
    char znak3 = '0';
    int kod = 0;
    int indexKodovaneZpravy = 0;
    int indexKodu = 0;
    
    while (indexKodovaneZpravy + 1 < kodovanaZprava.length()) {
      znak1 = kodovanaZprava.charAt(indexKodovaneZpravy);
      znak2 = kodovanaZprava.charAt(indexKodovaneZpravy + 1);
      kod = 10 * (znak2 - '0') + (znak1 - '0');
      indexKodu = najdiIndexKodu(kod);
      
      if (indexKodu >= 0) { //Kod nalezen, dva znaky tedy byly cely kod
        zpravaObracene[pocetZnaku] = ZNAKY[indexKodu];
        indexKodovaneZpravy += 2;
      }
      else { //Kod nenalezen, pridame treti znak
        if (indexKodovaneZpravy + 2 < kodovanaZprava.length()) { // Treti znak je dostupny
          znak3 = kodovanaZprava.charAt(indexKodovaneZpravy + 2);
          kod = 100 * (znak3 - '0') + 10 * (znak2 - '0') + (znak1 - '0');
          indexKodu = najdiIndexKodu(kod);
          
          if (indexKodu >= 0) {
            zpravaObracene[pocetZnaku] = ZNAKY[indexKodu];
          }
          else { //Kod nenalezen ani se tretim znakem - chyba
            zpravaObracene[pocetZnaku] = '0';
          }
        }
        else { //Treti znak neni dostupny - chyba
          zpravaObracene[pocetZnaku] = '0';
        }
        indexKodovaneZpravy += 3;
      }
      
      pocetZnaku++;
    }
    
    for (int i = pocetZnaku - 1; i >= 0; i--) {
      System.out.print(zpravaObracene[i]);
    }
    System.out.println();
    
  }
  
  /**
   * Najde a vrati index znaku v poli povolenych znaku pomoci binarniho vyhledavani
   * @param znak znak, ktery ma byt nalezen v poli povolenych znaku 
   * @return index nalezeneho znaku v poli povolenych znaku, nebo -1, pokud znak neni nalezen 
   */        
  private static int najdiIndexZnaku(char znak) {
    int dolniMez = 0;
    int horniMez = ZNAKY.length - 1;
    int stred = 0;
    
    while (dolniMez <= horniMez) {
      //System.out.println("D: " + dolniMez + ", H: " + horniMez);
      stred = (dolniMez + horniMez) / 2;
      
      if (ZNAKY[stred] < znak) {
        dolniMez = stred + 1;
      } 
      else if (ZNAKY[stred] > znak) {
        horniMez = stred - 1;
      }                       
      else {
        return stred;
      }
    }
    
    return -1;
  }
  
  /**
   * Najde a vrati index ASCII kodu v poli kodu pomoci binaarniho vyhledavani
   * @param kod ASCII kod, ktery ma byt nalezen v poli kodu
   * @return index nalezeneho znaku v poli kodu, nebo -1, pokud kod neni nalezen     
   */        
  private static int najdiIndexKodu(int kod) {
    int dolniMez = 0;
    int horniMez = KODY.length - 1;
    int stred = 0;
    
    while (dolniMez <= horniMez) {
      stred = (dolniMez + horniMez) / 2;
      
      if (KODY[stred] < kod) {
        dolniMez = stred + 1;
      } 
      else if (KODY[stred] > kod) {
        horniMez = stred - 1;
      }                       
      else {
        return stred;
      }
    }
    
    return -1;
  }
}