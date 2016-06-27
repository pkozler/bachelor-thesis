import java.util.Scanner;
import java.util.ArrayList;

/**
 * Reseni finalove ulohy PilsProg - Podil
 * @author Tomas Potuzak
 */ 
public class Podil {
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)   
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    String radka = null;
    int pocetRadek = sc.nextInt();
    sc.nextLine();
    
    for (int i = 0; i < pocetRadek; i++) {
      radka = sc.nextLine();
      zpracujRadku(radka);
    } 
  }
  
  /**
   * Zpracuje jednu nactenou radku - rozdeli ji podle dvojtecky na delenec a delitel, provede deleni s vyuzitim velkych cisel a vypise vysledek na samostatnou radku.
   */        
  public static void zpracujRadku(String radka) {
    int indexDvojtecky = radka.indexOf(" : ");
    VelkeCislo delenec = new VelkeCislo(radka.substring(0, indexDvojtecky));
    VelkeCislo delitel = new VelkeCislo(radka.substring(indexDvojtecky + 3, radka.length()));
       
    System.out.println(delenec.vydel(delitel));
  }
}

/**
 *
 * @author Tomas Potuzak
 */  
class VelkeCislo {
  /** Konstanta pro znamenko + */
  public static final int ZNAMENKO_PLUS = 1;
  /** Konstanta pro znamenko - */
  public static final int ZNAMENKO_MINUS = -1;
  /**  */
  public static final int POCET_DESETINNYCH_MIST_NAVIC = 400000;
  /**  */
  public static final int MAXIMALNI_DELKA_ZBYTKU = 1000;
  /** Znamenko velkeho cisla */
  private int znamenko;
  /** Cislice velkeho cisla */
  private int[] cislice;
  /**  */
  private boolean neniNula;

  /**
   * Vytvori instanci velkeho cisla na zaklada zadaneho retezce obsahujiho velke cislo
   * @param cisloStr velke cislo reprezentovane retezcem
   */        
  public VelkeCislo(String cisloStr) {
    neniNula = false;
    
    if (cisloStr.charAt(0) == '-') {
      znamenko = ZNAMENKO_MINUS;
      cislice = new int[cisloStr.length() - 1];
      
      for (int i = 0; i < cislice.length; i++) {
        cislice[i] = cisloStr.charAt(i + 1) - '0';
        
        if (cislice[i] != 0) {
          neniNula = true;
        }
      }
    }
    else {
      znamenko = ZNAMENKO_PLUS;
      cislice = new int[cisloStr.length()];
      
      for (int i = 0; i < cislice.length; i++) {
        cislice[i] = cisloStr.charAt(i) - '0';
        
        if (cislice[i] != 0) {
          neniNula = true;
        }
      }
    }
  }
  
  /**
   * Vydeli toto velke cislo delitelem (realne, ne celociselne). Predpoklada se, ze obe cisla jsou cela (bez desetinne casti)
   * Funguje to pomoci odcitani - odecitam delitelele od delenece a pricitam 1 do vysledku, dokud neni delitel mensi nez delenec
   * Potom posunu delence smerem vlevo, abych ziskal cislo vetsi nez delitel a o stejny pocet mist posunu vysledek
   * Opakuji, dokud neni cislo cele vydelene nebo dokud zbyva zbytek
   * Zbytek muze zbyvat porad, je treba detekovat periodicky rozvoj - zapamatuji si vsechny zbytky a pri kazdem dalsim zbytku hledam, jetli uz jsem ho nemel. Kdyz jo, je perioda. Navic, abz se urcil presne zacatek, provedu vypocet po dobu dvou period, tim zjistim presne delku periody a porovnanim cislic ve vysledku i presny zacatek periody.
   * Viz http://www.builder.cz/cz/forum/tema-1283658-deleni-velkych-cisel-po-cifre/              
   * @param delitel delitel, kterym se ma toto velke cislo vydelit  
   * @return podil tohoto cisla a delitele (vysledek deleni) 
   */        
  public String vydel(VelkeCislo delitel) {
    if (!neniNula) {  //Delenec je nulovy
      return "0";
    }
  
    int[] vysledek = new int[cislice.length + POCET_DESETINNYCH_MIST_NAVIC]; 
    int[] delenec = new int[cislice.length + POCET_DESETINNYCH_MIST_NAVIC];
    ArrayList<int[]> zbytky = new ArrayList<int[]>();
    int pocetZbytku = 0;
    int[] zbytek = null;
    for (int i = 0; i < cislice.length; i++) {
      delenec[i] = cislice[i];
      vysledek[i] = 0;
    } 
    
    for (int i = cislice.length; i < delenec.length; i++) {
      delenec[i] = 0;
      vysledek[i] = 0;
    }
    
    int posunDelenec = 0;
    int poziceDelenec = 0;
    int poziceDelitel = 0;
    int cisliceOdcitani = 0;
    int cislicePrenosu = 0;
    int indexCisliceVysledku = 0;
    int porovnani = 0;
    
    int indexZacatkuPeriody = 0;
    int indexDesetinneTecky = 0;
    boolean perioda = false;
    int delkaPeriody = -1;
    boolean uzJsemTuByl = false;
       
    //Transformace delence (posun vravo), aby byl pri prvnim deleni vetsi nez delitel. Pokud vyjde posun zaporny, znamena to, ze delenec je vetsi nez delitel a pak vyuzijeme jen cast delence   
    int pocatecniPosunDelenec = delitel.cislice.length - cislice.length;
    indexDesetinneTecky = -pocatecniPosunDelenec;
    if (porovnej(delenec, 0, delitel.cislice, delitel.cislice.length) == 1) {  //Delitel je vetsi kdyz vezmu stejny pocet cislic delence - uprava o jedno misto
      //System.out.println("Jsem tu");
      pocatecniPosunDelenec++;
      posunDelenec++;
      indexDesetinneTecky--;
    }
     
    while (true) {
      while ((porovnani = porovnej(delenec, posunDelenec, delitel.cislice, delitel.cislice.length)) <= 0) { //Dokud je delenec vetsi nebo stejny nez delitel, odecitej delitele od delence
        cislicePrenosu = 0; 
        for (int i = delitel.cislice.length - 1; i >= 0; i--) {  //Jedno odecteni delitele od delence
          cisliceOdcitani = delenec[i + posunDelenec] - (delitel.cislice[i] + cislicePrenosu);
          
          if (cisliceOdcitani < 0) {
            cisliceOdcitani += 10;
            cislicePrenosu = 1;
          } 
          else {
            cislicePrenosu = 0;
          }
          
          delenec[i + posunDelenec] = cisliceOdcitani;
        }
        if (cislicePrenosu > 0) {
          delenec[posunDelenec - 1] -= cislicePrenosu;
        }
        
        vysledek[indexCisliceVysledku]++;
        
      }
      //System.out.println("Vysledek" + vysledek[indexCisliceVysledku]);
      
      boolean nulovyDelenec = true;
      //System.out.println("No " + Math.max(delitel.cislice.length, cislice.length) + " posunDelenec " + posunDelenec);
      //System.out.print("delenec ");
      int i = 0;
      /*for (i = 0; i < Math.max(delitel.cislice.length, cislice.length); i++) {
        System.out.print(delenec[posunDelenec + i]);
      }*/
      
      for (i = 0; i < Math.max(delitel.cislice.length, cislice.length); i++) {
        if (delenec[posunDelenec + i] != 0) {
          nulovyDelenec = false;
          posunDelenec += i;
          indexCisliceVysledku += i;
          break;
        }
      }
      
      //System.out.println("\nNene: " + indexCisliceVysledku);
      //System.out.println("Nulovy delenec " + nulovyDelenec);
      
      if (nulovyDelenec) { //Nezbyl zadny zbytek
        break;
      }
      else  {  //Nejaky zbytek zbyl, ulozim si ho do pole zbytku
        zbytek = new int[Math.max(delitel.cislice.length, cislice.length) - i];
  
        for (int j = 0; j < delitel.cislice.length - i; j++) {
          zbytek[j] = delenec[posunDelenec + j];
        }
        
        if (posunDelenec >= cislice.length - delitel.cislice.length) {
        
          int shodnyZbytekIndex = -1;            
          for (int j = 0; j < zbytky.size(); j++) { //Prohledani zbytku, zda uz novy zbytek neni obsazen
            if (jsouZbytkyShodne(zbytek, zbytky.get(j))) {
              if (!uzJsemTuByl) {
                zbytky.clear();
                pocetZbytku = 0;
                uzJsemTuByl = true;
                delkaPeriody = posunDelenec;
              }
              else {
                delkaPeriody = posunDelenec - delkaPeriody;
                shodnyZbytekIndex = j;  
                break;
              }
            }
          }
          if (shodnyZbytekIndex < 0) {
            zbytky.add(zbytek);
            pocetZbytku++;
          }
          else { //Novy zbytek uz je obsazen - detekovana perioda
            perioda = true;
            break;
          }
        }
      }
      
      if (porovnej(delenec, posunDelenec, delitel.cislice, delitel.cislice.length) == 1) {
        posunDelenec++;
        indexCisliceVysledku++;
      }
    }
    
    String vysledekStr = (znamenko == delitel.znamenko) ? "" : "-";
    
    int puvodniIndexDesetinneTecky = indexDesetinneTecky;
    
    if (indexDesetinneTecky < 0) {
      vysledekStr += "0.";
      
      indexDesetinneTecky++;
      while (indexDesetinneTecky < 0) {
        vysledekStr += "0";
        indexDesetinneTecky++;
      }
      indexDesetinneTecky = -1; //Abych uz se ji nezabyval v nasledujicim cyklu
    }
    else if (indexDesetinneTecky == 0) {
      if (delitel.cislice.length > cislice.length || (delitel.cislice.length == cislice.length && porovnej(cislice, 0, delitel.cislice, delitel.cislice.length) == 1)) {  //Delitel je vetsi nez delenec
        vysledekStr += "0.";
      }
      else {
        indexDesetinneTecky++;
      }
    }
    
    if (puvodniIndexDesetinneTecky > 0) {
      indexDesetinneTecky++;
    }
    
    for (int i = 0; i <= indexCisliceVysledku; i++) {
      if (indexDesetinneTecky > 0) {
        if (i == indexDesetinneTecky) {
          vysledekStr += ".";
        }
      }
      
      vysledekStr += vysledek[i];
    }
    
    if (delkaPeriody >= 0) {
      int tecka = vysledekStr.indexOf('.');
      
      for (int i = 0; i < vysledekStr.length() - tecka; i++) {
        boolean nalezeno = true;
        
        for (int j = 0; j < delkaPeriody; j++) {
          if (((j + tecka + 1 + delkaPeriody + i) >= vysledekStr.length()) || (vysledekStr.charAt(j + tecka + 1 + i) != vysledekStr.charAt(j + tecka + 1 + delkaPeriody + i))) {
            nalezeno = false;
            break;
          }
        }
        
        if (nalezeno) {
          indexZacatkuPeriody = (i + tecka + 1);
          break;
        }
      }
      
      vysledekStr = vysledekStr.substring(0, indexZacatkuPeriody) + "(" + vysledekStr.substring(indexZacatkuPeriody, indexZacatkuPeriody + delkaPeriody) + ")"; 
    }
    
    
    
    return vysledekStr;
  }
  
  /**
   * Porovna dve sady cislic tvorici cisla a vrati -1, pokud je prvni sada vetsi, 1 pokud je druha sada vetsi, nebo 0, pokud jsou shodne 
   * @param cislice1 sada cislic 1
   * @param posun1 posun v sade cislic 1
   * @param cislice2 sada cislic 2
   * @param delka2 delka sady cislic 2       
   * @return -1, pokud je prvni sada vetsi, 1 pokud je druha sada vetsi, nebo 0, pokud jsou shodne
   */              
  private int porovnej(int[] cislice1, int posun1, int[] cislice2, int delka2) {
    if (posun1 - 1 >= 0) {
      if (cislice1[posun1 - 1] > 0) {
        return -1;
      }
    }
  
    int i = 0;
    for (i = 0; i < delka2; i++) {
      if (cislice1[i + posun1] != cislice2[i]) {
        break;
      }
    }
    if (i == delka2) {
      i--;
    }
    
    if (cislice1[i + posun1] > cislice2[i]) {
      return -1;
    }
    else if (cislice1[i + posun1] < cislice2[i]){
      return 1;
    }
    else {
      return 0;
    }
  }
  
  /**
   *
   * @param zbytek1   
   * @param zbytek2
   * @return   
   */        
  private boolean jsouZbytkyShodne(int[] zbytek1, int[] zbytek2) {
    if (zbytek1.length != zbytek2.length) {
      return false;
    }
    else {
      boolean shodne = true;
      for (int i = 0; i < zbytek1.length; i++) {
        if (zbytek1[i] != zbytek2[i]) {
          shodne = false;
          break;
        }
      }
      
      return shodne;
    }
  }
  
  @Override
  public String toString() {
    String s = "";
    if (znamenko == ZNAMENKO_MINUS) {
      s += "-";
    }
    
    return s;
  } 
}