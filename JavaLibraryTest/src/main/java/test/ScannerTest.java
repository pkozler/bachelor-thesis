/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Scanner.
 *
 * @author Petr Kozler
 */
public class ScannerTest {
    
    public static Logger logger = LogManager.getLogger(ScannerTest.class.getName());
    
    private static final String INITIAL_TEST = "src/main/resources/test.txt";
    private static final String NEXTLINE_TEST = "src/main/resources/nextLineTest.txt";
    private static final String NEXT_TEST = "src/main/resources/nextTest.txt";
    private static final String NEXTBOOLEAN_TEST = "src/main/resources/nextBooleanTest.txt";
    private static final String NEXTBYTE_TEST = "src/main/resources/nextByteTest.txt";
    private static final String NEXTSHORT_TEST = "src/main/resources/nextShortTest.txt";
    private static final String NEXTINT_TEST = "src/main/resources/nextIntTest.txt";
    private static final String NEXTLONG_TEST = "src/main/resources/nextLongTest.txt";
    private static final String NEXTFLOAT_TEST = "src/main/resources/nextFloatTest.txt";
    private static final String NEXTDOUBLE_TEST = "src/main/resources/nextDoubleTest.txt";
    private static final int NEXTLINE_TOKEN_COUNT = 8;
    private static final int NEXT_TOKEN_COUNT = 9;
    private static final int NEXTBOOLEAN_TOKEN_COUNT = 8;
    private static final int NEXTBYTE_TOKEN_COUNT = 10;
    private static final int NEXTSHORT_TOKEN_COUNT = 10;
    private static final int NEXTINT_TOKEN_COUNT = 10;
    private static final int NEXTLONG_TOKEN_COUNT = 10;
    private static final int NEXTFLOAT_TOKEN_COUNT = 30;
    private static final int NEXTDOUBLE_TOKEN_COUNT = 30;
    
    public static void runTestSuite() {
        ScannerTest.scannerTestCase();
        ScannerTest.nextTestCase();
        ScannerTest.nextBooleanTestCase();
        ScannerTest.nextByteTestCase();
        ScannerTest.nextShortTestCase();
        ScannerTest.nextIntTestCase();
        ScannerTest.nextLongTestCase();
        ScannerTest.nextFloatTestCase();
        ScannerTest.nextDoubleTestCase();
        ScannerTest.nextLineTestCase();
    }
    
    /*
        Načte data z testovacího soubor pro simulaci uživatelského vstupu.
    */
    private static void setInput(String testFileName) {
        try {
            String content = new Scanner(new File(testFileName)).useDelimiter("\\Z").next();
            System.setIn(new ByteArrayInputStream(content.getBytes()));
        }
        catch (FileNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
    }
    
    /**
     * Otestuje vytvoření scanneru.
     */
    public static void scannerTestCase() {
        setInput(INITIAL_TEST);
        Scanner a;
        String b;
        boolean c;
        long d;
        double e;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        b = a.next();
        logger.info(b);
        c = a.nextBoolean();
        logger.info(c);
        d = a.nextByte();
        logger.info(d);
        d = a.nextShort();
        logger.info(d);
        d = a.nextInt();
        logger.info(d);
        d = a.nextLong();
        logger.info(d);
        e = a.nextFloat();
        logger.info(e);
        e = a.nextDouble();
        logger.info(e);
        b = a.nextLine();
        logger.info(b);
    }
    
    /**
     * Otestuje načtení řetězce tokenu.
     */
    public static void nextTestCase() {
        setInput(NEXT_TEST);
        Scanner a;
        String b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXT_TOKEN_COUNT; i++) {
            b = a.next();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení logické hodnoty.
     */
    public static void nextBooleanTestCase() {
        setInput(NEXTBOOLEAN_TEST);
        Scanner a;
        boolean b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTBOOLEAN_TOKEN_COUNT; i++) {
            b = a.nextBoolean();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení 8-bitového celého čísla.
     */
    public static void nextByteTestCase() {
        setInput(NEXTBYTE_TEST);
        Scanner a;
        byte b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTBYTE_TOKEN_COUNT; i++) {
            b = a.nextByte();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení 16-bitového celého čísla.
     */
    public static void nextShortTestCase() {
        setInput(NEXTSHORT_TEST);
        Scanner a;
        short b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTSHORT_TOKEN_COUNT; i++) {
            b = a.nextShort();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení 32-bitového celého čísla.
     */
    public static void nextIntTestCase() {
        setInput(NEXTINT_TEST);
        Scanner a;
        int b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTINT_TOKEN_COUNT; i++) {
            b = a.nextInt();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení 64-bitového celého čísla.
     */
    public static void nextLongTestCase() {
        setInput(NEXTLONG_TEST);
        Scanner a;
        long b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTLONG_TOKEN_COUNT; i++) {
            b = a.nextLong();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení desetinného čísla s jednoduchou přesností.
     */
    public static void nextFloatTestCase() {
        setInput(NEXTFLOAT_TEST);
        Scanner a;
        float b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTFLOAT_TOKEN_COUNT; i++) {
            b = a.nextFloat();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení desetinného čísla s dvojitou přesností.
     */
    public static void nextDoubleTestCase() {
        setInput(NEXTDOUBLE_TEST);
        Scanner a;
        double b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTDOUBLE_TOKEN_COUNT; i++) {
            b = a.nextDouble();
            logger.info(b);
        }
    }
    
    /**
     * Otestuje načtení řetězce na řádce.
     */
    public static void nextLineTestCase() {
        setInput(NEXTLINE_TEST);
        Scanner a;
        String b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);
        
        for (int i = 0; i < NEXTLINE_TOKEN_COUNT; i++) {
            b = a.nextLine();
            logger.info(b);
        }
    }
    
}
