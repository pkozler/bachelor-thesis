/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.Arrays;

/**
 *
 * @author Petr Kozler
 */
public class Main {
    
    static {
        System.setProperty("log4j.configurationFile", "log4j-config.xml");
    }
    
    private static void printCompareTo(double d1, double d2) {
        System.out.printf("%f compareTo %f: %d\n", new Double(d1), new Double(d2), new Double(d1).compareTo(new Double(d2)));
    }
    
    private static void printEquals(double d1, double d2) {
        System.out.printf("%f equals %f: %b\n", new Double(d1), new Double(d2), new Double(d1).equals(new Double(d2)));
    }
    
    private static void printCompareToF(float f1, float f2) {
        System.out.printf("%f compareTo %f: %d\n", new Float(f1), new Float(f2), new Float(f1).compareTo(new Float(f2)));
    }
    
    private static void printEqualsF(float f1, float f2) {
        System.out.printf("%f equals %f: %b\n", new Float(f1), new Float(f2), new Float(f1).equals(new Float(f2)));
    }
    
    public static void main(String[] args) {
        Character a = 'a';
        Character b = 'Z';
        
        System.out.println(a.compareTo(b));
        System.out.println(a.compareTo(a));
        System.out.println(b.compareTo(a));
        
        /*Integer a = 5;
        Integer b = -5;
        
        System.out.println(a.compareTo(b));
        System.out.println(a.compareTo(a));
        System.out.println(b.compareTo(a));*/
        
        /*int[] a;
        int b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 8);
        System.out.println(b);
        b = Arrays.binarySearch(a, 4);
        System.out.println(b);
        
        System.out.println("\n=== Java compareTo Double ===");
        printCompareTo(1.0, 1.0);
        printCompareTo(1.0, -1.0);
        printCompareTo(-1.0, 1.0);
        printCompareTo(-1.0, -1.0);
        printCompareTo(0.0, 0.0);
        printCompareTo(0.0, -0.0);
        printCompareTo(-0.0, 0.0);
        printCompareTo(-0.0, -0.0);
        printCompareTo(Double.NaN, Double.POSITIVE_INFINITY);
        printCompareTo(Double.NaN, Double.NEGATIVE_INFINITY);
        printCompareTo(Double.POSITIVE_INFINITY, Double.NaN);
        printCompareTo(Double.NEGATIVE_INFINITY, Double.NaN);
        printCompareTo(Double.NaN, Double.NaN);
        printCompareTo(Double.NaN, -Double.NaN);
        
        System.out.println("\n=== Java equals Double ===");
        printEquals(1.0, 1.0);
        printEquals(1.0, -1.0);
        printEquals(-1.0, 1.0);
        printEquals(-1.0, -1.0);
        printEquals(0.0, 0.0);
        printEquals(0.0, -0.0);
        printEquals(-0.0, 0.0);
        printEquals(-0.0, -0.0);
        printEquals(Double.NaN, Double.POSITIVE_INFINITY);
        printEquals(Double.NaN, Double.NEGATIVE_INFINITY);
        printEquals(Double.POSITIVE_INFINITY, Double.NaN);
        printEquals(Double.NEGATIVE_INFINITY, Double.NaN);
        printEquals(Double.NaN, Double.NaN);
        printEquals(Double.NaN, -Double.NaN);
        
        System.out.println("\n=== Java compareTo Float ===");
        printCompareToF(1.0f, 1.0f);
        printCompareToF(1.0f, -1.0f);
        printCompareToF(-1.0f, 1.0f);
        printCompareToF(-1.0f, -1.0f);
        printCompareToF(0.0f, 0.0f);
        printCompareToF(0.0f, -0.0f);
        printCompareToF(-0.0f, 0.0f);
        printCompareToF(-0.0f, -0.0f);
        printCompareToF(Float.NaN, Float.POSITIVE_INFINITY);
        printCompareToF(Float.NaN, Float.NEGATIVE_INFINITY);
        printCompareToF(Float.POSITIVE_INFINITY, Float.NaN);
        printCompareToF(Float.NEGATIVE_INFINITY, Float.NaN);
        printCompareToF(Float.NaN, Float.NaN);
        printCompareToF(Float.NaN, -Float.NaN);
        
        System.out.println("\n=== Java equals Float ===");
        printEqualsF(1.0f, 1.0f);
        printEqualsF(1.0f, -1.0f);
        printEqualsF(-1.0f, 1.0f);
        printEqualsF(-1.0f, -1.0f);
        printEqualsF(0.0f, 0.0f);
        printEqualsF(0.0f, -0.0f);
        printEqualsF(-0.0f, 0.0f);
        printEqualsF(-0.0f, -0.0f);
        printEqualsF(Float.NaN, Float.POSITIVE_INFINITY);
        printEqualsF(Float.NaN, Float.NEGATIVE_INFINITY);
        printEqualsF(Float.POSITIVE_INFINITY, Float.NaN);
        printEqualsF(Float.NEGATIVE_INFINITY, Float.NaN);
        printEqualsF(Float.NaN, Float.NaN);
        printEqualsF(Float.NaN, -Float.NaN);*/

        /*
        PrintStreamTest.runTestSuite();
        StringTest.runTestSuite();
        ByteTest.runTestSuite();
        ShortTest.runTestSuite();
        IntegerTest.runTestSuite();
        LongTest.runTestSuite();
        FloatTest.runTestSuite();
        DoubleTest.runTestSuite();
        BooleanTest.runTestSuite();
        CharacterTest.runTestSuite();
        MathTest.runTestSuite();
        ArraysTest.runTestSuite();
        ArrayListTest.runTestSuite();
        LinkedListTest.runTestSuite();
        CollectionsTest.runTestSuite();
        StringTokenizerTest.runTestSuite();
        ScannerTest.runTestSuite();
        */
    }
    
}
