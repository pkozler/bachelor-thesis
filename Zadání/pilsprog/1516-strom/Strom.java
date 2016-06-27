import java.util.Scanner;

/**
 * Reseni kvalifikacni ulohy PilsProg - Strom
 * @author Tomas Potuzak
 */  
public class Strom {
  /** Scanner pro cteni ze standardniho vstupu */
  private static Scanner sc;
  /** Index v preorder vypisu stromu - je to promenna tridy kvuli vyuziti v rekurzivnim volani metody */
  private static int preorderIndex;
  
  /**
   * Vstupni bod programu
   * @param args parametry prikazove radky (nevyuzite)  
   */     
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    String radka = null;
    String preorder = null;
    String inorder = null;
    int pocetStromu = sc.nextInt();
    sc.nextLine();
    int indexMezery = 0;
    UzelStromu strom = null;
    
    for (int i = 0; i < pocetStromu; i++) {
      radka = sc.nextLine().trim();
      indexMezery = radka.indexOf(' ');
      preorder = radka.substring(0, indexMezery);
      inorder = radka.substring(indexMezery + 1, radka.length());
      strom = vytvorStrom(preorder, inorder);
      vypisPostorder(strom);
      System.out.println();
    }
    
  }
  
  /**
   * Vytvori a vrati strom na zaklade jeho preorder a inorder vypisu
   * @param preorder preorder vypis stromu
   * @param inorder inorder vypis stromu
   * @return koren vytvoreneho stromu    
   */        
  public static UzelStromu vytvorStrom(String preorder, String inorder) {
    preorderIndex = 0;

    return vytvorStrom(preorder, inorder, 0, inorder.length() - 1);
  }
  
  /**
   * Rekurzivne vytvori a vrati strom ze zadane casti preorder a inorder pruchodu
   * @param preoder preorder vypis stromu
   * @param inorder inorder vypis stromu
   * @param pocatecniIndex pocatecni index v inorder vypisu stromu
   * @param koncovyIndex koncovy index v inorder vypisu stromu
   * @return koren vytvoreneho stromu   
   */                 
  private static UzelStromu vytvorStrom(String preorder, String inorder, int pocatecniIndex, int koncovyIndex) {
    int inorderIndex = 0;
    
    if (pocatecniIndex > koncovyIndex) {
      return null;
    }
    
    UzelStromu uzelStromu = new UzelStromu(preorder.charAt(preorderIndex));
    preorderIndex++;
       
    if (pocatecniIndex == koncovyIndex) { //Je jen jeden prvek, neni zadny dalsi podstrom, rekurze konci
      return uzelStromu;
    }
    else { //Najde znak v inorder pruchodu (koren, ktery se postupne bere z preorder pruchodu) a rekurzivne zavola stejnou metodu pro prave a leve prvky od nalezeneho znaku
      inorderIndex = hledejZnak(inorder, uzelStromu.hodnota, pocatecniIndex, koncovyIndex);
      uzelStromu.levy = vytvorStrom(preorder, inorder, pocatecniIndex, inorderIndex - 1);
      uzelStromu.pravy = vytvorStrom(preorder, inorder, inorderIndex + 1, koncovyIndex);
      
      return uzelStromu; 
    }
  }
  
  /**
   * Hleda znak v retezci mezi indexy <code>pocatecniIndex</code> a <code>koncovyIndex</code>. Vrati index v retezci, pokud je znak nalezen. Jinak vrati -1.
   * @param retezec retezec, ve kterem se hleda znak
   * @param znak znak, ktery se hleda v retezci
   * @param pocatecniIndex pocatecni index, od ktereho se hleda znak v retezci
   * @param koncovyIndex koncovy index, do ktereho se hleda znak v retezci
   * @return index v retezci, pokud je znak nalezen, jinak vrati -1      
   */              
  private static int hledejZnak(String retezec, char znak, int pocatecniIndex, int koncovyIndex) {
    int index = -1;
    
    for (int i = pocatecniIndex; i <= koncovyIndex; i++) {
      if (znak == retezec.charAt(i)) {
        index = i;
        break;
      }
    }
    
    return index;
  }
  
  /**
   * Vypise strom postorderem
   * @param strom strom, ktery ma byt vypsan postorderem  
   */        
  public static void vypisPostorder(UzelStromu strom) {
    if (strom == null) {
      return;
    }
    else {
      vypisPostorder(strom.levy);
      vypisPostorder(strom.pravy);
      System.out.print(strom.hodnota);
    }
  }
}

/**
 * Uzel binarniho stromu
 * @author Tomas Potuzak
 */  
class UzelStromu {
  /** Hodnota uzlu */
  public char hodnota;
  /** Levy naslednik */
  public UzelStromu levy;
  /** Pravy naslednik */
  public UzelStromu pravy;
  
  /**
   * Vytvori novy uzel stromu
   * @param hodnota hodnota nove vytvareneho uzlu
   */        
  public UzelStromu(char hodnota) {
    this.hodnota = hodnota;
    
    levy = null;
    pravy = null;
  }
}