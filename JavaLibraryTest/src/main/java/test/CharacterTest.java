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
        Character a;
        char b;
        a = new Character('A');
        b = a.charValue();
        logger.info(b);
        a = new Character('a');
        b = a.charValue();
        logger.info(b);
        a = new Character('0');
        b = a.charValue();
        logger.info(b);
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void charValueTestCase() {
        Character a;
        char b;
        a = new Character('0');
        b = a.charValue();
        logger.info(b);
        a = new Character((char)48);
        b = a.charValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Character a, b;
        int c;
        a = new Character('9');
        b = new Character('Z');
        c = a.compareTo(b);
        logger.info(c);
        a = new Character('z');
        b = new Character('9');
        c = a.compareTo(b);
        logger.info(c);
        a = new Character('z');
        b = new Character('A');
        c = a.compareTo(b);
        logger.info(c);
        a = new Character('Z');
        b = new Character('a');
        c = a.compareTo(b);
        logger.info(c);
        a = new Character('Z');
        b = new Character('Z');
        c = a.compareTo(b);
        logger.info(c);
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
        a = new Character('9');
        b = new Character('Z');
        c = a.equals(b);
        logger.info(c);
        a = new Character('z');
        b = new Character('9');
        c = a.equals(b);
        logger.info(c);
        a = new Character('z');
        b = new Character('A');
        c = a.equals(b);
        logger.info(c);
        a = new Character('Z');
        b = new Character('a');
        c = a.equals(b);
        logger.info(c);
        a = new Character('Z');
        b = new Character('Z');
        c = a.equals(b);
        logger.info(c);
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
        a = new Character('A');
        b = a.toString();
        logger.info(b);
        a = new Character('0');
        b = a.toString();
        logger.info(b);
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
        a = new Character('A');
        b = Character.toString(a);
        logger.info(b);
        a = new Character('0');
        b = Character.toString(a);
        logger.info(b);
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
        a = new Character('a');
        b = Character.isDigit(a);
        logger.info(b);
        a = new Character('Z');
        b = Character.isDigit(a);
        logger.info(b);
        a = new Character('0');
        b = Character.isDigit(a);
        logger.info(b);
        a = new Character('9');
        b = Character.isDigit(a);
        logger.info(b);
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
        a = new Character('a');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character('Z');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character('0');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character('9');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character(' ');
        b = Character.isLetter(a);
        logger.info(b);
    }
    
}
