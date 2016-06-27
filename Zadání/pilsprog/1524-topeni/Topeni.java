import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;

/**
 * Reseni finalove ulohy PilsProg - Topeni
 * @author Tomas Potuzak
 */  
public class Topeni {
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
    
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)   
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    int pocetTechniku = sc.nextInt();
    sc.nextLine();
    String radka = null;
    
    int[][] technici = new int[pocetTechniku][pocetTechniku];
    for (int i = 0; i < technici.length; i++) {
      for (int j = 0; j < technici[i].length; j++) {
        technici[i][j] = 0;
      }
    }
     
    for (int i = 0; i < pocetTechniku; i++) {
      radka = sc.nextLine();
      zapisTechnika(i, radka, technici);
    }
    
    /*for (int i = 0; i < technici.length; i++) {
      System.out.println(java.util.Arrays.toString(technici[i]));
    }*/
    
    boolean nalezeno = false;
    boolean poprve = true;
    //boolean[] vysledek = urciPotrebneTechnikyBruteForce(technici);
    boolean[] vysledek = urciPotrebneTechniky(technici);
    for (int i = 0; i < vysledek.length; i++) {
      if (vysledek[i]) {
        nalezeno = true;
        if (poprve) {
          System.out.print("" + (i + 1));
          poprve = false;
        }
        else {
          System.out.print(" " + (i + 1));
        }
      }
    }
    
    if (!nalezeno) {
      System.out.println("-1");
    } 
        
  }
  
  /**
   * Zpracuje radku s jednim technikem a zaznamena jeho ventily do pole techniku
   * @param indexTechnika index, na ktery se ma technik ulozit  
   * @param technik radka obsahujici ventily technika
   * @param technici pole techniku (a jejich ventilu), do ktereho se ventily technika zaznamenaji    
   */        
  public static void zapisTechnika(int indexTechnika, String technik, int[][] technici) {
    StringTokenizer st = new StringTokenizer(technik, " ");
    int pocetVentilu = st.countTokens() - 1;
    int ventil = 0;
       
    for (int i = 0; i < pocetVentilu; i++) {
      ventil = Integer.parseInt(st.nextToken());
      technici[indexTechnika][ventil - 1] = 1;
    }     
  }
  
  /**
   * Urci a vrati potrebne techniky s vyuzitim Gauss-Jordanovy eliminace
   * @param technici matice techniku (radky) a jejich ventilu (sloupce)
   * @return potrebne techniky 
   */        
  public static boolean[] urciPotrebneTechniky(int[][] technici) {
    int[] praveStrany = new int[technici.length];
    int[] indexySloupcu = new int[technici.length];
    boolean[] vysledek = new boolean[technici.length];
    for (int i = 0; i < praveStrany.length; i++) {
      praveStrany[i] = 1;
      indexySloupcu[i] = i;
      vysledek[i] = false;
    }
  
    for (int i = 0; i < technici.length; i++) { //Overovani, zda na diagonale jsou 1
      if (technici[i][indexySloupcu[i]] != 1) { //Pokud neni na diagonale 1
        if (!prohod(technici, indexySloupcu, i)) {  //pokusi se ji tam doplnit prohozenim s jinym sloupcem (matice je obracene, misto radkovych operaci delame sloupcove, vypliva z ulozeni techniku)
          return vysledek; //Pokud to nejde, reseni neexsituje, vratime pole plne <code>false</code>
        }
      }
      
      for (int j = i + 1; j < technici.length; j++) { //Nulovani prvku pod diagonalou v prislusne radce
        if (technici[i][indexySloupcu[j]] == 1) {
          praveStrany[indexySloupcu[j]] = (praveStrany[indexySloupcu[i]] + praveStrany[indexySloupcu[j]]) % 2;
          for (int k = 0; k < technici.length; k++) {
            technici[k][indexySloupcu[j]] =(technici[k][indexySloupcu[i]] + technici[k][indexySloupcu[j]]) % 2; 
          }
        }
      }
    }
    
    for (int i = technici.length - 1; i >= 0; i--) { //Nulovani prvku nad diagonalou 
      for (int j = i - 1; j >= 0; j--) {
        if (technici[i][indexySloupcu[j]] == 1) {
          praveStrany[indexySloupcu[j]] = (praveStrany[indexySloupcu[i]] + praveStrany[indexySloupcu[j]]) % 2;
          for (int k = 0; k < technici.length; k++) {
            technici[k][indexySloupcu[j]] = (technici[k][indexySloupcu[i]] + technici[k][indexySloupcu[j]]) % 2; 
          }
        }
      }
    }
    
    for (int i = 0; i < technici.length; i++) {
      if (praveStrany[indexySloupcu[i]] == 1) {
        vysledek[i] = true;
      }
      else {
        vysledek[i] = false;
      }
    }
    
    return vysledek;
  }
  
  /**
   * Prohodi sloupce matice techniku tak, aby na prislusne pozici na diagonale byla 1. Vrati <code>true</code>, pokud uspeje, jinak <code>false</code>.
   * @param technici matice techniku a jejich ventilu 
   * @param indexySloupcu pole obsahujici indexy sloupcu, diky nemu je mozne slouce prehazovat, aniz se prvky realne kopirovaly
   * @param index pozice na diagonale, na ktere se ma vyrobit 1
   * @return <code>true</code>, pokud uspeje, jinak <code>false</code>.       
   */           
  private static boolean prohod(int[][] technici, int[] indexySloupcu, int index) {
    boolean lzeProhodit = false;
    int indexSloupce = 0;
    int pomocna = 0;
    
    for (int i = index + 1; i < technici.length; i++) {
      if (technici[index][indexySloupcu[i]] == 1) {
        lzeProhodit = true;
        indexSloupce = i;
        break;
      }
    }
    
    if (lzeProhodit) {
      pomocna = indexySloupcu[indexSloupce];
      indexySloupcu[indexSloupce] = indexySloupcu[index];
      indexySloupcu[index] = pomocna;
    }
    
    return lzeProhodit;
  }
  
  /**
   * Urci potrebne techniky pruchodem vsech jejich kombinaci - pouzitelne pouze pro velmi male vstupy (cca do 20ti techniku)
   * @param technici matice techniku a jejich ventilu   
   * @return potrebne techniky
   */        
  public static boolean[] urciPotrebneTechnikyBruteForce(int[][] technici) {
    int[] poctyOtevreni = new int[technici.length];
    boolean carry = false;
    boolean[] nejmeneTechniku = new boolean[technici.length];
    int nejmensiPocetTechniku = technici.length;
    boolean[] aktualniTechnici = new boolean[technici.length];
    int aktualniPocetTechniku = 0;
    for (int i = 0; i < aktualniTechnici.length; i++) {
      aktualniTechnici[i] = false;
      nejmeneTechniku[i] = false;
    }
            
    while (true) {
      aktualniTechnici[0] = !aktualniTechnici[0];
      carry = !aktualniTechnici[0];
      aktualniPocetTechniku = (aktualniTechnici[0]) ? 1 : 0; 
      for (int i = 1; i < aktualniTechnici.length; i++) {
        if (carry) {
          aktualniTechnici[i] = !aktualniTechnici[i];
          carry = !aktualniTechnici[i];
        }
        aktualniPocetTechniku += (aktualniTechnici[i]) ? 1 : 0;
      }
      
      if (carry) {  //Preteklo, byly tedy uz vyzkousene vsechny moznosti
        break;
      }
      
      if (aktualniPocetTechniku < nejmensiPocetTechniku) {
        boolean nejakeSude = false;
        for (int i = 0; i < poctyOtevreni.length; i++) {
          poctyOtevreni[i] = 0;
          
          for (int j = 0; j < technici.length; j++) {
            if (aktualniTechnici[j] && technici[j][i] == 1) {
              poctyOtevreni[i]++;
            }
          }
          
          if (poctyOtevreni[i] % 2 == 0) {
            nejakeSude = true;
            break;
          }
        }
        
        if (!nejakeSude) { //Vsechny kohouty otevreny
          nejmensiPocetTechniku = aktualniPocetTechniku;
          for (int i = 0; i < aktualniTechnici.length; i++) {
            nejmeneTechniku[i] = aktualniTechnici[i];
          }
        }
      }
    }
    
    return nejmeneTechniku;
  }
}