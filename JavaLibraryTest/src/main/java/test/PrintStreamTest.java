/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny PrintStream.
 *
 * @author Petr Kozler
 */
public class PrintStreamTest {
    
    public static Logger logger = LogManager.getLogger(PrintStreamTest.class.getName());
    
    public static void runTestSuite() {
        PrintStreamTest.printTestCase();
        PrintStreamTest.printTestCase2();
        PrintStreamTest.printTestCase3();
        PrintStreamTest.printTestCase4();
        PrintStreamTest.printTestCase5();
        PrintStreamTest.printTestCase6();
        PrintStreamTest.printTestCase7();
        PrintStreamTest.printTestCase8();
        PrintStreamTest.printTestCase9();
        PrintStreamTest.printlnTestCase();
        PrintStreamTest.printlnTestCase2();
        PrintStreamTest.printlnTestCase3();
        PrintStreamTest.printlnTestCase4();
        PrintStreamTest.printlnTestCase5();
        PrintStreamTest.printlnTestCase6();
        PrintStreamTest.printlnTestCase7();
        PrintStreamTest.printlnTestCase8();
        PrintStreamTest.printlnTestCase9();
        PrintStreamTest.printlnTestCase10();
    }
    
    /**
     * Otestuje výpis logické hodnoty.
     */
    public static void printTestCase() {
        boolean a;
        a = true;
        System.out.print(a);
        System.out.println();
        a = false;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis znaku.
     */
    public static void printTestCase2() {
        char a;
        a = 'a';
        System.out.print(a);
        System.out.println();
        a = 'z';
        System.out.print(a);
        System.out.println();
        a = 'A';
        System.out.print(a);
        System.out.println();
        a = 'Z';
        System.out.print(a);
        System.out.println();
        a = '0';
        System.out.print(a);
        System.out.println();
        a = '9';
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis pole znaků.
     */
    public static void printTestCase3() {
        char[] a;
        a = new char[]{};
        System.out.print(a);
        System.out.println();
        a = new char[]{'a'};
        System.out.print(a);
        System.out.println();
        a = new char[]{'a', 'z', 'A', 'Z', '0', '9'};
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis desetinného čísla s dvojitou přesností.
     */
    public static void printTestCase4() {
        double a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis desetinného čísla s jednoduchou přesností.
     */
    public static void printTestCase5() {
        float a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis 32-bitového celého čísla.
     */
    public static void printTestCase6() {
        int a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Integer.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Integer.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis 64-bitového celého čísla.
     */
    public static void printTestCase7() {
        long a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Long.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Long.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis textové reprezentace objektu.
     */
    public static void printTestCase8() {
        DummyObject a;
        a = new DummyObject("", 0);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("0", 1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("9", -1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Aa", Integer.MAX_VALUE);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Zz", Integer.MIN_VALUE);
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis řetězce.
     */
    public static void printTestCase9() {
        String a;
        a = "";
        System.out.print(a);
        System.out.println();
        a = "a";
        System.out.print(a);
        System.out.println();
        a = "azAZ09";
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis ukončení řádky.
     */
    public static void printlnTestCase() {
        System.out.println();
    }
    
    /**
     * Otestuje výpis logické hodnoty s ukončením řádky.
     */
    public static void printlnTestCase2() {
        boolean a;
        a = true;
        System.out.print(a);
        System.out.println();
        a = false;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis znaku s ukončením řádky.
     */
    public static void printlnTestCase3() {
        char a;
        a = 'a';
        System.out.print(a);
        System.out.println();
        a = 'z';
        System.out.print(a);
        System.out.println();
        a = 'A';
        System.out.print(a);
        System.out.println();
        a = 'Z';
        System.out.print(a);
        System.out.println();
        a = '0';
        System.out.print(a);
        System.out.println();
        a = '9';
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis pole znaků s ukončením řádky.
     */
    public static void printlnTestCase4() {
        char[] a;
        a = new char[]{};
        System.out.print(a);
        System.out.println();
        a = new char[]{'a'};
        System.out.print(a);
        System.out.println();
        a = new char[]{'a', 'z', 'A', 'Z', '0', '9'};
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis desetinného čísla s dvojitou přesností s ukončením řádky.
     */
    public static void printlnTestCase5() {
        double a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis desetinného čísla s jednoduchou přesností s ukončením řádky.
     */
    public static void printlnTestCase6() {
        float a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis 32-bitového celého čísla s ukončením řádky.
     */
    public static void printlnTestCase7() {
        int a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Integer.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Integer.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis 64-bitového celého čísla s ukončením řádky.
     */
    public static void printlnTestCase8() {
        long a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Long.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Long.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis textové reprezentace objektu s ukončením řádky.
     */
    public static void printlnTestCase9() {
        DummyObject a;
        a = new DummyObject("", 0);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("0", 1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("9", -1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Aa", Integer.MAX_VALUE);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Zz", Integer.MIN_VALUE);
        System.out.print(a);
        System.out.println();
    }
    
    /**
     * Otestuje výpis řetězce s ukončením řádky.
     */
    public static void printlnTestCase10() {
        String a;
        a = "";
        System.out.print(a);
        System.out.println();
        a = "a";
        System.out.print(a);
        System.out.println();
        a = "azAZ09";
        System.out.print(a);
        System.out.println();
    }
    
}
