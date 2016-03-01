/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Character.
 *
 * @author Petr Kozler
 */
public class CharacterTest {
    
    public static Logger logger = LogManager.getLogger(CharacterTest.class.getName());
    
    public static void runTestSuite() {
        CharacterTest.characterTestCase();
        CharacterTest.charValueTestCase();
        CharacterTest.compareToTestCase();
        CharacterTest.equalsTestCase();
        CharacterTest.toStringTestCase();
        CharacterTest.toStringTestCase2();
        CharacterTest.isDigitTestCase();
        CharacterTest.isLetterTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void characterTestCase() {
        // otestováno pomocí testu získání hodnoty
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void charValueTestCase() {
        Character a;
        char b;
        // test velkého písmena
        a = new Character('A');
        b = a.charValue();
        logger.info(b);
        // test malého písmena
        a = new Character('a');
        b = a.charValue();
        logger.info(b);
        // test číslice
        a = new Character('0');
        b = a.charValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Character a, b;
        int c;
        // číslice a velké písmeno
        a = new Character('9');
        b = new Character('Z');
        c = a.compareTo(b);
        logger.info(c);
        // malé písmeno a číslice
        a = new Character('z');
        b = new Character('9');
        c = a.compareTo(b);
        logger.info(c);
        // malé a velké písmeno
        a = new Character('z');
        b = new Character('A');
        c = a.compareTo(b);
        logger.info(c);
        // velké a malé písmeno
        a = new Character('Z');
        b = new Character('a');
        c = a.compareTo(b);
        logger.info(c);
        // oba znaky velká písmena
        a = new Character('Z');
        b = new Character('Z');
        c = a.compareTo(b);
        logger.info(c);
        // oba znaky malá písmena
        a = new Character('a');
        b = new Character('a');
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Character a, b;
        boolean c;
        // číslice a velké písmeno
        a = new Character('9');
        b = new Character('Z');
        c = a.equals(b);
        logger.info(c);
        // malé písmeno a číslice
        a = new Character('z');
        b = new Character('9');
        c = a.equals(b);
        logger.info(c);
        // malé a velké písmeno
        a = new Character('z');
        b = new Character('A');
        c = a.equals(b);
        logger.info(c);
        // velké a malé písmeno
        a = new Character('Z');
        b = new Character('a');
        c = a.equals(b);
        logger.info(c);
        // oba znaky stejná velká písmena
        a = new Character('Z');
        b = new Character('Z');
        c = a.equals(b);
        logger.info(c);
        // oba znaky stejná malá písmena
        a = new Character('a');
        b = new Character('a');
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Character a;
        String b;
        // podpis číslice
        a = new Character('0');
        b = a.toString();
        logger.info(b);
        // podpis velkého písmena
        a = new Character('A');
        b = a.toString();
        logger.info(b);
        // podpis malého písmena
        a = new Character('a');
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Character a;
        String b;
        // podpis číslice
        a = new Character('0');
        b = Character.toString(a);
        logger.info(b);
        // podpis velkého písmena
        a = new Character('A');
        b = Character.toString(a);
        logger.info(b);
        // podpis malého písmena
        a = new Character('a');
        b = Character.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje zjištění, zda je znak číslice.
     */
    public static void isDigitTestCase() {
        Character a;
        boolean b;
        // malé písmeno
        a = new Character('a');
        b = Character.isDigit(a);
        logger.info(b);
        // velké písmeno
        a = new Character('Z');
        b = Character.isDigit(a);
        logger.info(b);
        // číslice
        a = new Character('0');
        b = Character.isDigit(a);
        logger.info(b);
        // jiná číslice
        a = new Character('9');
        b = Character.isDigit(a);
        logger.info(b);
        // bílý znak
        a = new Character(' ');
        b = Character.isDigit(a);
        logger.info(b);
    }
    
    /**
     * Otestuje zjištění, zda je znak písmeno.
     */
    public static void isLetterTestCase() {
        Character a;
        boolean b;
        // malé písmeno
        a = new Character('a');
        b = Character.isLetter(a);
        logger.info(b);
        // velké písmeno
        a = new Character('Z');
        b = Character.isLetter(a);
        logger.info(b);
        // číslice
        a = new Character('0');
        b = Character.isLetter(a);
        logger.info(b);
        // jiná číslice
        a = new Character('9');
        b = Character.isLetter(a);
        logger.info(b);
        // bílý znak
        a = new Character(' ');
        b = Character.isLetter(a);
        logger.info(b);
    }
    
}
