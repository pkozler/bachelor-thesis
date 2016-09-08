import java.util.Scanner;

/**
 * Reseni kvalifikacni ulohy PilsProg - Palindromy
 * @author Tomas Potuzak
 */  
public class Palindromy {
  /** Povolene znaky, ktere se na vtsupu mohou objevit a zaroven maji svuj znak opacny */
  public static final char[] ZNAKY = {'1', '2', '3', '5', '8', 'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  /** Opacne znaky */
  public static final char[] ZNAKY_OPACNE = {'1', 'S', 'E', 'Z', '8', 'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite) 
   */
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    int pocetRetezcu = sc.nextInt();
    sc.nextLine();
    String retezec = null;
    
    for (int i = 0; i < pocetRetezcu; i++) {
      retezec = sc.nextLine();
      
      System.out.println(urciTypRetezce(retezec));
      System.out.println();
    }
  }
  
  /**
   * Urci typ retezce (retezec, palindrom, zrcadlovy retezec, zrcadlovy palindrom) a vrati ho spolecne s retezcem
   * @param retezec retezec, u ktereho ma byt urcten typ
   * @return typ retezce (retezec, palindrom, zrcadlovy retezec, zrcadlovy palindrom) spolecne s retezcem
   */           
  public static String urciTypRetezce(String retezec) {
    boolean palindrom = false;
    boolean zrcadlovy = false;
    
    //Urceni palindromu
    boolean chybaPalindrom = false;
    boolean chybaZrcadlovy = false;
    for (int i = 0; i < retezec.length(); i++) {
       if (retezec.charAt(i) != retezec.charAt(retezec.length() - 1 - i)) {
         chybaPalindrom = true;
       }
       
       if (!jsouZnakyOpacne(retezec.charAt(i), retezec.charAt(retezec.length() - 1 - i))) {
         chybaZrcadlovy = true;
       }
       
       if (chybaPalindrom && chybaZrcadlovy) {  //Predcasne ukonceni cyklu, kdyz uz je jasne, ze se jedna pouze o obycejny retezec
         break;
       }
    }
    
    palindrom = !chybaPalindrom;
    zrcadlovy = !chybaZrcadlovy;
    
    String vysledek = retezec + ": ";
    
    if (!palindrom && !zrcadlovy) {
      vysledek += "retezec";
    }
    else if (palindrom && !zrcadlovy) {
      vysledek += "palindrom";
    }
    else if (!palindrom && zrcadlovy) {
      vysledek += "zrcadlovy retezec";
    }
    else {
      vysledek += "zrcadlovy palindrom";
    }
    
    return vysledek;
  }
  
  /**
   * Vrati <code>true</code>, pokud znak1 je opacny ke znaku znak2 (a naopak). Jinak vraci <code>false</code>.
   * @param znak1 prvni znak
   * @param znak2 druhy znak
   * @return <code>true</code>, pokud znak1 je opacny ke znaku znak2 (a naopak). Jinak <code>false</code>.
   */              
  public static boolean jsouZnakyOpacne(char znak1, char znak2) {
    int index = najdiIndexZnaku(znak1);
    
    if (index >= 0) {
      return (ZNAKY_OPACNE[index] == znak2);
    }
    else {
      return false;
    }
  }
  
  /**
   * Najde a vrati index zadaneho znaku v poli znaku, ktere jsou povolene a zaroven maji znaky opacne
   * @param znak znak, ktery ma byt nalezen v poli znaku
   * @return index zadaneho znaku v poli znaku, nebo -1, pokud znak nebyl v poli znaku nalezen   
   */        
  public static int najdiIndexZnaku(char znak) {
    int dolniMez = 0;
    int horniMez = ZNAKY.length - 1;
    int stred = 0;
    
    while (dolniMez <= horniMez) {
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
}