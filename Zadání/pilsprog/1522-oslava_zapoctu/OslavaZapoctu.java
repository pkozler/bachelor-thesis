import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;

/**
 * Reseni finalove ulohy PilsProg - Oslava zapoctu
 * @author Tomas Potuzak
 */  
public class OslavaZapoctu {
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)   
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    String radka = null;
    
    while (!(radka = sc.nextLine()).equals("0")) {
      System.out.println(zpracujRadku(radka));
    } 
  }
  
  /**
   * Zpracuje radku s kapacitou holek a silou jednotlivych drinku a vrati maximalni pocet drinku, ktere holky muzou vypit
   * @return maximalni pocet drinku, ktere holky muzou vypit
   */        
  public static int zpracujRadku(String radka) {
    StringTokenizer st = new StringTokenizer(radka, " ");
    int pocetDrinku = st.countTokens() - 2;
    int[] silyDrinku = new int[pocetDrinku];
    int kapacitaHolky = Integer.parseInt(st.nextToken());
        
    for (int i = 0; i < pocetDrinku; i++) {
      silyDrinku[i] = Integer.parseInt(st.nextToken());
    }

    return urciPocetDrinku(kapacitaHolky, silyDrinku);
  }
  
  /**
   * Urci a vrati celkovy pocet drinku obou holek dynamickym programovanim 
   * @param kapacitaHolky kapacita jedne holky (kolik snese jednotek alkoholu)
   * @param silyDrinku sily jednotlivych drinku, postupne jak prichazeji (jak je holky piji)
   * @return celkovy pocet drinku obou holek              
   */   
  public static int urciPocetDrinku(int kapacitaHolky, int[] silyDrinku) {
    int[][] tabulka = new int[silyDrinku.length][kapacitaHolky + 1];
    ArrayList<Integer> mnozinaTatoIterace = new ArrayList<Integer>();
    ArrayList<Integer> mnozinaDalsiIterace = new ArrayList<Integer>();
    ArrayList<Integer> pomocnaMnozina = null;
    int celkemVypito = 0;
    int pocetVypitychDrinku = 0;
    int pomocna = 0;
    
    mnozinaTatoIterace.add(0);
    
    for (pocetVypitychDrinku = 0; pocetVypitychDrinku < silyDrinku.length; pocetVypitychDrinku++) {
      celkemVypito += silyDrinku[pocetVypitychDrinku];
      
      for (int i = 0; i < mnozinaTatoIterace.size(); i++) {
        if (celkemVypito - mnozinaTatoIterace.get(i) <= kapacitaHolky && tabulka[pocetVypitychDrinku][mnozinaTatoIterace.get(i)] == 0) {
          mnozinaDalsiIterace.add(mnozinaTatoIterace.get(i));
          tabulka[pocetVypitychDrinku][mnozinaTatoIterace.get(i)] = mnozinaTatoIterace.get(i);
        }
        
        pomocna = mnozinaTatoIterace.get(i) + silyDrinku[pocetVypitychDrinku];
        if (pomocna <= kapacitaHolky && tabulka[pocetVypitychDrinku][pomocna] == 0) {
          mnozinaDalsiIterace.add(pomocna);
          tabulka[pocetVypitychDrinku][pomocna] = mnozinaTatoIterace.get(i);
           
        }
      }
      
      if (mnozinaDalsiIterace.isEmpty()) {
        break;
      }
      else {
        mnozinaTatoIterace.clear();
        pomocnaMnozina = mnozinaTatoIterace;
        mnozinaTatoIterace = mnozinaDalsiIterace;
        mnozinaDalsiIterace = pomocnaMnozina;
      }
    }
    
    return pocetVypitychDrinku;
  }  
}