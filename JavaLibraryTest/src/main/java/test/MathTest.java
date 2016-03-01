/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Math.
 *
 * @author Petr Kozler
 */
public class MathTest {
    
    public static Logger logger = LogManager.getLogger(MathTest.class.getName());
    
    public static void runTestSuite() {
        MathTest.absTestCase();
        MathTest.absTestCase2();
        MathTest.absTestCase3();
        MathTest.absTestCase4();
        MathTest.maxTestCase();
        MathTest.maxTestCase2();
        MathTest.maxTestCase3();
        MathTest.maxTestCase4();
        MathTest.minTestCase();
        MathTest.minTestCase2();
        MathTest.minTestCase3();
        MathTest.minTestCase4();
        MathTest.powTestCase();
        MathTest.sqrtTestCase();
        MathTest.logTestCase();
        MathTest.log10TestCase();
        MathTest.sinTestCase();
        MathTest.cosTestCase();
        MathTest.tanTestCase();
        MathTest.asinTestCase();
        MathTest.acosTestCase();
        MathTest.atanTestCase();
        MathTest.roundTestCase();
        MathTest.roundTestCase2();
    }
    
    /**
     * Otestuje výpočet absolutní hodnoty desetinného čísla s dvojitou přesností.
     */
    public static void absTestCase() {
        double a, b;
        // test pro záporné číslo
        a = Double.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        // test pro nulu
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        // test pro kladné číslo
        a = Double.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet absolutní hodnoty desetinného čísla s jednoduchou přesností.
     */
    public static void absTestCase2() {
        float a, b;
        a = Float.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        a = Float.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet absolutní hodnoty 32-bitového celého čísla.
     */
    public static void absTestCase3() {
        int a, b;
        a = Integer.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        a = Integer.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet absolutní hodnoty 64-bitového celého čísla.
     */
    public static void absTestCase4() {
        long a, b;
        a = Long.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        a = Long.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }
    
    /**
     * Otestuje určení většího ze dvou desetinných čísel s dvojitou přesností.
     */
    public static void maxTestCase() {
        double a, b, c;
        // záporné a kladné číslo
        a = Double.MIN_VALUE;
        b = Double.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        // kladné a záporné číslo
        a = Double.MAX_VALUE;
        b = Double.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        // záporné a kladné číslo (menší rozdíl)
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        // kladné a záporné číslo (menší rozdíl)
        a = 1;
        b = -1;
        c = Math.max(a, b);
        // stejná čísla
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení většího ze dvou desetinných čísel s jednoduchou přesností.
     */
    public static void maxTestCase2() {
        float a, b, c;
        a = Float.MIN_VALUE;
        b = Float.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = Float.MAX_VALUE;
        b = Float.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.max(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení většího ze dvou 32-bitových celých čísel.
     */
    public static void maxTestCase3() {
        int a, b, c;
        a = Integer.MIN_VALUE;
        b = Integer.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = Integer.MAX_VALUE;
        b = Integer.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.max(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení většího ze dvou 64-bitových celých čísel.
     */
    public static void maxTestCase4() {
        long a, b, c;
        a = Long.MIN_VALUE;
        b = Long.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = Long.MAX_VALUE;
        b = Long.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.max(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení menšího ze dvou desetinných čísel s dvojitou přesností.
     */
    public static void minTestCase() {
        double a, b, c;
        // záporné a kladné číslo
        a = Double.MIN_VALUE;
        b = Double.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        // kladné a záporné číslo
        a = Double.MAX_VALUE;
        b = Double.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        // záporné a kladné číslo (menší rozdíl)
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        // kladné a záporné číslo (menší rozdíl)
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        // stejná čísla
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení menšího ze dvou desetinných čísel s jednoduchou přesností.
     */
    public static void minTestCase2() {
        float a, b, c;
        a = Float.MIN_VALUE;
        b = Float.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Float.MAX_VALUE;
        b = Float.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení menšího ze dvou 32-bitových celých čísel.
     */
    public static void minTestCase3() {
        int a, b, c;
        a = Integer.MIN_VALUE;
        b = Integer.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Integer.MAX_VALUE;
        b = Integer.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje určení menšího ze dvou 64-bitových celých čísel.
     */
    public static void minTestCase4() {
        long a, b, c;
        a = Long.MIN_VALUE;
        b = Long.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Long.MAX_VALUE;
        b = Long.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje výpočet zadané mocniny.
     */
    public static void powTestCase() {
        double a, b, c;
        // kladná mocnina kladného čísla
        a = 10;
        b = 2;
        c = Math.pow(a, b);
        logger.info(c);
        // kladná mocnina záporného čísla
        a = -10;
        b = 2;
        c = Math.pow(a, b);
        logger.info(c);
        // záporná mocnina kladného čísla
        a = 10;
        b = -2;
        c = Math.pow(a, b);
        // nultá mocnina
        logger.info(c);
        a = 10;
        b = 0;
        c = Math.pow(a, b);
        logger.info(c);
        // mocnina nuly
        a = 0;
        b = 10;
        c = Math.pow(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje výpočet odmocniny.
     */
    public static void sqrtTestCase() {
        double a, b;
        // odmocnina většího čísla
        a = 100;
        b = Math.sqrt(a);
        logger.info(b);
        // odmocnina jedné
        a = 1;
        b = Math.sqrt(a);
        logger.info(b);
        // odmocnina nuly
        a = 0;
        b = Math.sqrt(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet přirozeného logaritmu.
     */
    public static void logTestCase() {
        double a, b;
        // logaritmus druhé mocniny E
        a = Math.E * Math.E;
        b = Math.log(a);
        logger.info(b);
        // logaritmus E
        a = Math.E;
        b = Math.log(a);
        logger.info(b);
        // logaritmus 1
        a = 1;
        b = Math.log(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet desítkového logaritmu.
     */
    public static void log10TestCase() {
        double a, b;
        // logaritmus druhé mocniny 10
        a = 100;
        b = Math.log10(a);
        logger.info(b);
        // logaritmus 10
        a = 10;
        b = Math.log10(a);
        logger.info(b);
        // logaritmus 1
        a = 1;
        b = Math.log10(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet sinu.
     */
    public static void sinTestCase() {
        double a, b;
        // sinus PÍ
        a = Math.PI;
        b = Math.sin(a);
        logger.info(b);
        // sinus -PÍ
        a = -Math.PI;
        b = Math.sin(a);
        logger.info(b);
        // sinus 0
        a = 0;
        b = Math.sin(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet kosinu.
     */
    public static void cosTestCase() {
        double a, b;
        // kosinus PÍ
        a = Math.PI;
        b = Math.cos(a);
        logger.info(b);
        // kosinus -PÍ
        a = -Math.PI;
        b = Math.cos(a);
        logger.info(b);
        // kosinus 0
        a = 0;
        b = Math.cos(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet tangentu.
     */
    public static void tanTestCase() {
        double a, b;
        // tangens PÍ
        a = Math.PI;
        b = Math.tan(a);
        logger.info(b);
        // tangens -PÍ
        a = -Math.PI;
        b = Math.tan(a);
        logger.info(b);
        // tangens 0
        a = 0;
        b = Math.tan(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet úhlu ze sinu.
     */
    public static void asinTestCase() {
        double a, b;
        // arkus sinus 1
        a = 1;
        b = Math.asin(a);
        logger.info(b);
        // arkus sinus -1
        a = -1;
        b = Math.asin(a);
        logger.info(b);
        // arkus sinus 0
        a = 0;
        b = Math.asin(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet úhlu z kosinu.
     */
    public static void acosTestCase() {
        double a, b;
        // arkus kosinus 1
        a = 1;
        b = Math.acos(a);
        logger.info(b);
        // arkus kosinus -1
        a = -1;
        b = Math.acos(a);
        logger.info(b);
        // arkus kosinus 0
        a = 0;
        b = Math.acos(a);
        logger.info(b);
    }
    
    /**
     * Otestuje výpočet úhlu z tangentu.
     */
    public static void atanTestCase() {
        double a, b;
        // arkus tangens 1
        a = 1;
        b = Math.atan(a);
        logger.info(b);
        // arkus tangens -1
        a = -1;
        b = Math.atan(a);
        logger.info(b);
        // arkus tangens 0
        a = 0;
        b = Math.atan(a);
        logger.info(b);
    }
    
    /**
     * Otestuje zaokrouhlení desetinného čísla s dvojitou přesností.
     */
    public static void roundTestCase() {
        double a, b;
        // zaokrouhlení k sudému číslu
        a = 1.5;
        b = Math.round(a);
        logger.info(b);
        // zaokrouhlení k lichému číslu
        a = 0.5;
        b = Math.round(a);
        logger.info(b);
        // zaokrouhlení záporného čísla
        a = -0.5;
        b = Math.round(a);
        logger.info(b);
    }
    
    /**
     * Otestuje zaokrouhlení desetinného čísla s jednoduchou přesností.
     */
    public static void roundTestCase2() {
        float a, b;
        a = 1.5f;
        b = Math.round(a);
        logger.info(b);
        a = 0.5f;
        b = Math.round(a);
        logger.info(b);
        a = -0.5f;
        b = Math.round(a);
        logger.info(b);
    }
    
}
