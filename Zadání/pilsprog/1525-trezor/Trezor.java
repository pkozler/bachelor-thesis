import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Reseni finalove ulohy PilsProg - Trezor
 * @author Tomas Potuzak
 */  
public class Trezor {
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
    
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)   
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    int pocetTrezoru = sc.nextInt();
    sc.nextLine();
    String radka = null;
    JedenTrezor jedenTrezor = null;
        
    for (int i = 0; i < pocetTrezoru; i++) {
      radka = sc.nextLine();
      jedenTrezor = new JedenTrezor(radka);
      System.out.println(jedenTrezor.urciNejmensiPocetOtoceni());
    }
  }
}

/**
 * Trida obsahujici metody a promenne pro reseni jednoho trezoru
 * @author Tomas Potuzak
 */  
class JedenTrezor {
  /** Barva vrcholu pro DFS - bila */
  public static final int BILA = -1;
  /** Barva vrcholu pro DFS - seda */
  public static final int SEDA = -2;
  /** Barva vrcholu pro DFS - cerna */
  public static final int CERNA = -3;
  /** Delka klice k trezoru (pocet cislic) */
  public static final int DELKA_KLICE = 4;
  /** Maximalni mozny pocet otoceni */
  public static final int MAXIMALNI_POCET_OTOCENI = 10000;
  /** Vsechny klice k trezoru */
  private String[] klice;
  /** Prechody mezi klici - matice (neorientovanych) hran grafu, na hlavni diagonale je ulozena barva vrcholu, mimo hlavni diagonalu hodnata BILA znamena, ze tam neni hrana */
  private int[][] prechodyMeziKlici;
  /** Pocet vsech klicu */
  private int pocetKlicu;
  /** Pocet vsech neorientovanych hran (prechodu mezi klici) */
  private int pocetHran;
  /** Pole vsech hran (prechodu mezi klici) */
  private Hrana[] hrany;
  /** Promenna, do ktere DFS zaznamena, ze naslo cestu mezi dvema vrcholy */
  private boolean cestaExistuje;
    
  /**
   * Vytvori novou instanci trezoru ze zadaneho retezce klicu 
   * @param trezorStr retezec obsahujici vsechny klice (s poctem klicu jako prvni cislo)
   */        
  public JedenTrezor(String trezorStr) {
    StringTokenizer st = new StringTokenizer(trezorStr, " ");
    this.pocetKlicu = st.countTokens() - 1;
    
    klice = new String[pocetKlicu];
    st.nextToken(); //Zahozeni prvniho tokenu, obsahuje pocet klicu, ktery uz jsme si sami spocitali
    for (int i = 0; i < pocetKlicu; i++) {
      klice[i] = st.nextToken();
    } 
  }
  
  /**
   * Urci a vrati nejmensi pocet otoceni vedouci k otevreni trezoru pomoci postupneho pridavani vzestupne serazenych hran podle ohodnoceni do grafu bez hran. Hrana je pridana pouze, pokud mezi jejimi vrcholy v grafu zatim neexistuje cesta (zjistovano pomoci DFS)
   * @return nejmensi pocet otoceni vedouci k otevreni trezoru
   */        
  public int urciNejmensiPocetOtoceni() {
    naplnPrechodyMeziKlici();
    seradHrany();
    
    for (int i = 0; i < prechodyMeziKlici.length; i++) { //Smazat vsechny prechody mezi klici (tj. hrany)
      prechodyMeziKlici[i][i] = BILA;
            
      for (int j = i + 1; j < prechodyMeziKlici[i].length; j++) {
        prechodyMeziKlici[i][j] = BILA;
        prechodyMeziKlici[j][i] = BILA;
      }
    }
    
    Hrana hrana = null;
    int predchoziPocetDosazitelnychKlicu = 0;
    int pocetDosazitelnychKlicu = 0;
    int soucetPouzitychHran = 0;
    
    for (int i = 0; i < pocetHran; i++) { //Postupne doplnovat hrany, otestovat, zda uz neexistuje cesta mezi vrcholy doplnovane hrany (pokud existuje, hranu nedoplnime)
      hrana = hrany[i];
      
      pocetDosazitelnychKlicu = existujeCesta(hrana.index1, hrana.index2); 
      if (!cestaExistuje) {
        prechodyMeziKlici[hrana.index1][hrana.index2] = hrana.ohodnoceni;
        prechodyMeziKlici[hrana.index2][hrana.index1] = hrana.ohodnoceni;
        soucetPouzitychHran += hrana.ohodnoceni;
      }
      
      if (pocetDosazitelnychKlicu >= pocetKlicu) {  //Pokud jsme pri urcovani cesty narazili na vsechny klice (tj. vrcholy grafu), muzeme skoncit
        break;
      }
    }
    
    int nejmensiPocetOtoceni = MAXIMALNI_POCET_OTOCENI;
    int pocetOtoceni = 0;
    String pocatek = "0000";
    for (int i = 0; i < klice.length; i++) {  //Urceni nejmensiho poctu otoceni od pocatecniho nastaveni trezoru (0000) k jednomu z klicu
      pocetOtoceni = urciNejmensiPocetOtoceniMeziKlici(pocatek, klice[i]);
      if (pocetOtoceni < nejmensiPocetOtoceni) {
        nejmensiPocetOtoceni = pocetOtoceni;
      }
    }
    //System.out.println("Nejmensi pocet otoceni" + nejmensiPocetOtoceni);
    
    return soucetPouzitychHran + nejmensiPocetOtoceni;
  }
  
  /**
   * Naplni prechody mezi klici, tj. naplni graf klicu ohodnocenymi hranami prechodu mezi nimy (kazdy vrchol je propojen s kazdym)
   */     
  private void naplnPrechodyMeziKlici() {
    prechodyMeziKlici = new int[pocetKlicu][pocetKlicu];
    
    pocetHran = ((pocetKlicu - 1) * pocetKlicu) / 2;
    hrany = new Hrana[pocetHran];
    
    int indexHrany = 0;
    for (int i = 0; i < prechodyMeziKlici.length; i++) {
      prechodyMeziKlici[i][i] = BILA;
            
      for (int j = i + 1; j < prechodyMeziKlici[i].length; j++) {
        prechodyMeziKlici[i][j] = urciNejmensiPocetOtoceniMeziKlici(klice[i], klice[j]);
        prechodyMeziKlici[j][i] = prechodyMeziKlici[i][j];
        hrany[indexHrany] = new Hrana(prechodyMeziKlici[i][j], i, j);
        indexHrany++;
      }
    }
    
    /*for (int i = 0; i < prechodyMeziKlici.length; i++) {
      System.out.println(java.util.Arrays.toString(prechodyMeziKlici[i]));
    }
    System.out.println("Hrany " + java.util.Arrays.toString(hrany));
    */
  }
  
  /**
   * Seradi hrany vzestupne podle ohodnoceni
   */        
  private void seradHrany() {
    Hrana pomocna = null;
    
    /*java.util.Arrays.sort(hrany, new java.util.Comparator<Hrana>() {
      public int compare(Hrana h1, Hrana h2) {
        if (h1.ohodnoceni < h2.ohodnoceni) {
          return -1;
        }
        else if (h1.ohodnoceni > h2.ohodnoceni) {
          return 1;
        }
        else {
          return 0;
        }
      }
    });*/
    java.util.Arrays.sort(hrany);
    /*for (int i = 0; i < pocetHran - 1; i++) {
      for (int j = i; j < pocetHran; j++) {
        if (hrany[i].ohodnoceni > hrany[j].ohodnoceni) {
          pomocna = hrany[i];
          hrany[i] = hrany[j];
          hrany[j] = pomocna;
        }
      }
    }*/
    //System.out.println("Serazene hrany " + java.util.Arrays.toString(hrany));
  }
  
  /**
   * Urci, zda existuje cesta mezi prvnim a druhym vrcholem pomoci DFS a ulozi vysledek do promenne <code>cestaExistuje</code>. Vrati pocet navstivenych vrcholu.
   * @param vrchol1 prvni vrchol
   * @param vrchol2 druhy vrchol
   * @return pocet navstivenych vrcholu     
   */                   
  private int existujeCesta(int vrchol1, int vrchol2) {
    int pocetNavstivenychVrcholu = 0;
    
    for (int i = 0; i < prechodyMeziKlici.length; i++) {
      prechodyMeziKlici[i][i] = BILA;
    }
    cestaExistuje = false;
    pocetNavstivenychVrcholu = dfs(vrchol1, vrchol2);
    
    return pocetNavstivenychVrcholu;
  }
  
  /**
   * Provede prohledani do hloubky z prvniho do druheho vrcholu. Skocni, kdyz se dostane do druheho vrcholu, nebo kdyz projde vsechny vrcholy. Vrati pocet nasvtivenych vrcholu
   * @param vrchol1 prvni vrchol
   * @param vrchol2 druhy vrchol
   * @return pocet nasvtivenych vrcholu      
   */        
  private int dfs(int vrchol1, int vrchol2) {
    if (cestaExistuje) {
      return 1;
    }
    
    prechodyMeziKlici[vrchol1][vrchol1] = SEDA;
    int pocetNavstivenychVrcholu = 1;
    
    
    if (vrchol1 == vrchol2) {
      cestaExistuje = true;
      return pocetNavstivenychVrcholu; 
    }
    
    for (int i = 0; i < prechodyMeziKlici.length; i++) {
      if (prechodyMeziKlici[vrchol1][i] > BILA && prechodyMeziKlici[i][i] == BILA) {
        pocetNavstivenychVrcholu += dfs(i, vrchol2);
      }
    }
    prechodyMeziKlici[vrchol1][vrchol1] = CERNA;
    
    return pocetNavstivenychVrcholu;
  }
      
  /**
   * Urci a vrati nejmensi mozny pocet otoceni, kterym se z prvniho klice stane druhy klic
   * @param klic1 prvni klic                                                                
   * @param klic2 druhy klic
   * @return nejmensi mozny pocet otoceni, kterym se z prvniho klice stane druhy klic   
   */           
  private int urciNejmensiPocetOtoceniMeziKlici(String klic1, String klic2) {
    int celkovyPocetOtoceni = 0;
    int pocetOtoceniCislice = 0;
    
    for (int i = 0; i < DELKA_KLICE; i++) {
      pocetOtoceniCislice = Math.abs((klic1.charAt(i) - '0') - (klic2.charAt(i) - '0'));
      
      if (pocetOtoceniCislice > 5) {
        pocetOtoceniCislice = 10 - pocetOtoceniCislice;
      }
      
      celkovyPocetOtoceni += pocetOtoceniCislice;
    }
    
    return celkovyPocetOtoceni;
  }
}

/**
 * Trida reprezentujici hranu grafu
 * @author Tomas Potuzak
 */  
class Hrana implements Comparable<Hrana> {
  /** Ohodnoceni hrany */
  public int ohodnoceni;
  /** Index prvniho vrcholu */
  public int index1;
  /** Index druheho vrcholu */
  public int index2;
  
  /**
   * Vytvori novou instanci hrany
   * @param ohodnoceni ohodnoceni hrany
   * @param index1 index prvniho vrcholu
   * @param index2 index druheho vrcholu  
   */           
  public Hrana(int ohodnoceni, int index1, int index2) {
    this.ohodnoceni = ohodnoceni;
    this.index1 = index1;
    this.index2 = index2;
  }
  
  @Override
  public int compareTo(Hrana h) {
    if (ohodnoceni < h.ohodnoceni) {
      return -1;
    }
    else if (ohodnoceni > h.ohodnoceni) {
      return 1;
    }
    else {
      return 0;
    }
  }
  
  /*@Override
  public String toString() {
    return "(" + ohodnoceni + ", " + index1 + " <-> " + index2 + ")"; 
  }*/
}
