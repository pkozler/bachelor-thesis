import java.util.Scanner;

/**
 * Reseni kvalifikacni ulohy PilsProg - Domnenka
 * @author Tomas Potuzak
 */  
public class Domnenka {
  /** Horni mez vstupnich cisel */
  public static final int HORNI_MEZ = 1000000;
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  /** Priznaky, zda zadane cislo (tj. index) je prvocislo */
  private static boolean[] jePrvocislo;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)  
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    naplnJePrvocislo();
    
    int vstupniCislo = sc.nextInt();
    sc.nextLine();
    
    while (vstupniCislo != 0) {  //Dokud neni cislo 0 (ukoncovaci hodnota)
      najdiAVypisRozkladCisla(vstupniCislo);
      vstupniCislo = sc.nextInt();
      sc.nextLine();
    }
  }
  
  /**
   * Naplni pole indikace prvocisel s vyuzitim Eratosthenova sita   
   */     
  public static void naplnJePrvocislo() {
    jePrvocislo = new boolean[HORNI_MEZ];
    for (int i = 0; i < jePrvocislo.length; i++) {
      jePrvocislo[i] = true; //Predpokladam, ze vse jsou prvocisla
    }
    jePrvocislo[0] = false; //0 neni prvocislo 
    jePrvocislo[1] = false; //1 neni prvocislo
        
    for (int i = 2; i <= Math.sqrt(jePrvocislo.length); i++) {
      if (jePrvocislo[i]) { //Pokud najdu prvocislo, vyradim vsechny jeho nasobky
        for (int j = 2 * i; j < jePrvocislo.length; j += i) {
          jePrvocislo[j] = false;
        }
      }
    }
  }
  
  /**
   * Nalezne a vypise na standarni vystup rozklad zadaneho cisla na soucet prvocisel. Pokud rozklad neni nalezen, vypise "Neplati!"
   * @param vstupniCislo cislo, pro ktere se hleda rozklad na prvocisla
   */        
  public static void najdiAVypisRozkladCisla(int vstupniCislo) {
    int cisloA = 1;
    int cisloB = vstupniCislo - 1;
    boolean nalezeno = false;
    
    while (cisloA < cisloB) { //Projdu vsechny mozne scitance, dokud nenaleznu dva prvociselne
      if (jePrvocislo[cisloA] && jePrvocislo[cisloB]) {
        nalezeno = true;
        break;
      }
      
      cisloA++;
      cisloB--;
    }
    
    if (nalezeno) {
      System.out.println("" + vstupniCislo + " = " + cisloA + " + " + cisloB);
    }
    else {
      System.out.println("Neplati!");
    }
  }
}