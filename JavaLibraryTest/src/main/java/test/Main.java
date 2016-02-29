/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

/**
 *
 * @author Petr Kozler
 */
public class Main {
    
    static {
        System.setProperty("log4j.configurationFile", "log4j-config.xml");
    }
    
    public static void main(String[] args) {
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
    }
    
}
