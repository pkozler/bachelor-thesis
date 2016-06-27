<?php

/**
 * This class provides method for performing the tests of the PrintStream library,
 * which is used for writing the data to the standard output.
 *
 * @author Petr Kozler
 */
class OutputTestRunner {

    // names of the test utility methods/functions
    private $tests = array(
        "printTest",
        "printTest2",
        "printTest3",
        "printTest4",
        "printTest5",
        "printTest6",
        "printTest7",
        "printTest8",
        "printTest9",
        "printlnTest",
        "printlnTest2",
        "printlnTest3",
        "printlnTest4",
        "printlnTest5",
        "printlnTest6",
        "printlnTest7",
        "printlnTest8",
        "printlnTest9",
        "printlnTest10",
    );
    // test utility executable file path
    private $outTestExecPath;
    // lines printed by the current tested method/function to the standard output
    private $output;
    // errors found in the current tested method/function
    private $errorsInMethod;
    // total errors found in the library
    private $errorsInClass;

    /**
     * Creates the new output test runner.
     *
     * @param $testedLibrary the tested library info
     */
    public function __construct($testedLibrary) {
        echoLine("=== Inicializuji spouštěč testů pro knihovnu PrintStream ===");
        $this->errorsInMethod = 0;
        $this->errorsInClass = 0;
        $this->outTestExecPath = $testedLibrary->getOutTestExecPath();
        echoLine("Spustitelný soubor testů pro PrintStream: $this->outTestExecPath");
        echoLine();
    }

    /**
     * Returns the function/method name by the specified index.
     *
     * @param $index the index
     * @return the name
     */
    public function getTestMethodName($index) {
        return $this->tests[$index];
    }

    /*
        Verifies if the actual printed string is equal to
        the expected value. If not, increments the counter
        of the errors found in the current method/function.
     */
    private function assertEquals($method, $expected) {
        echoLine("\nTestovaná metoda/funkce: \"$method\"");
        echoLine("Očekávaná hodnota: \"$expected\"");
        // getting the first line of output and removing it from the array
        $actual = array_shift($this->output);

        if ($expected === $actual) {
            echoLine("OK");
        } else {
            echoLine("FAIL - skutečná hodnota: \"$actual\"");
            $this->errorsInMethod++;
        }
    }

    /*
        The test methods containing the 'assertEquals' method calls
        which are common for the corresponding 'print-' and 'println-'
        methods/functions (printing the same type of data).
     */

    private function printAssertEquals($name) {
        $this->assertEquals($name, "");
    }

    private function printBooleanAssertEquals($name) {
        $this->assertEquals($name, "true");
        $this->assertEquals($name, "false");
    }

    private function printCharAssertEquals($name) {
        $this->assertEquals($name, "a");
        $this->assertEquals($name, "z");
        $this->assertEquals($name, "A");
        $this->assertEquals($name, "Z");
        $this->assertEquals($name, "0");
        $this->assertEquals($name, "9");
    }

    private function printCharArrayAssertEquals($name) {
        $this->assertEquals($name, "");
        $this->assertEquals($name, "a");
        $this->assertEquals($name, "azAZ09");
    }

    private function printDoubleAssertEquals($name) {
        $this->assertEquals($name, "0.0");
        $this->assertEquals($name, "0.0");
        $this->assertEquals($name, "1.0");
        $this->assertEquals($name, "-1.0");
        $this->assertEquals($name, "1.7976931348623157E308");
        $this->assertEquals($name, "-1.7976931348623157E308");
        $this->assertEquals($name, "4.9E-324");
        $this->assertEquals($name, "-4.9E-324");
    }

    private function printFloatAssertEquals($name) {
        $this->assertEquals($name, "0.0");
        $this->assertEquals($name, "0.0");
        $this->assertEquals($name, "1.0");
        $this->assertEquals($name, "-1.0");
        $this->assertEquals($name, "3.4028235E38");
        $this->assertEquals($name, "-3.4028235E38");
        $this->assertEquals($name, "1.4E-45");
        $this->assertEquals($name, "-1.4E-45");
    }

    private function printIntAssertEquals($name) {
        $this->assertEquals($name, "0");
        $this->assertEquals($name, "1");
        $this->assertEquals($name, "-1");
        $this->assertEquals($name, "2147483647");
        $this->assertEquals($name, "-2147483648");
    }

    private function printLongAssertEquals($name) {
        $this->assertEquals($name, "0");
        $this->assertEquals($name, "1");
        $this->assertEquals($name, "-1");
        $this->assertEquals($name, "9223372036854775807");
        $this->assertEquals($name, "-9223372036854775808");
    }

    private function printObjectAssertEquals($name) {
        $this->assertEquals($name, "TestObject [str=, i=0]");
        $this->assertEquals($name, "TestObject [str=0, i=1]");
        $this->assertEquals($name, "TestObject [str=9, i=-1]");
        $this->assertEquals($name, "TestObject [str=Aa, i=2147483647]");
        $this->assertEquals($name, "TestObject [str=Zz, i=-2147483648]");
    }

    private function printStringAssertEquals($name) {
        $this->assertEquals($name, "");
        $this->assertEquals($name, "a");
        $this->assertEquals($name, "azAZ09");
    }

    /*
        The test methods for comparing the actual printed values
        with the expected values:
     */

    public function printTest() {
        $name = "print (boolean)";
        $this->printBooleanAssertEquals($name);
    }

    public function printTest2() {
        $name = "print (char)";
        $this->printCharAssertEquals($name);
    }

    public function printTest3() {
        $name = "print (char[])";
        $this->printCharArrayAssertEquals($name);
    }

    public function printTest4() {
        $name = "print (double)";
        $this->printDoubleAssertEquals($name);
    }

    public function printTest5() {
        $name = "print (float)";
        $this->printFloatAssertEquals($name);
    }

    public function printTest6() {
        $name = "print (int)";
        $this->printIntAssertEquals($name);
    }

    public function printTest7() {
        $name = "print (long)";
        $this->printLongAssertEquals($name);
    }

    public function printTest8() {
        $name = "print (Object)";
        $this->printObjectAssertEquals($name);
    }

    public function printTest9() {
        $name = "print (String)";
        $this->printStringAssertEquals($name);
    }

    public function printlnTest() {
        $name = "println";
        $this->printAssertEquals($name);
    }

    public function printlnTest2() {
        $name = "println (boolean)";
        $this->printBooleanAssertEquals($name);
    }

    public function printlnTest3() {
        $name = "println (char)";
        $this->printCharAssertEquals($name);
    }

    public function printlnTest4() {
        $name = "println (char[])";
        $this->printCharArrayAssertEquals($name);
    }

    public function printlnTest5() {
        $name = "println (double)";
        $this->printDoubleAssertEquals($name);
    }

    public function printlnTest6() {
        $name = "println (float)";
        $this->printFloatAssertEquals($name);
    }

    public function printlnTest7() {
        $name = "println (int)";
        $this->printIntAssertEquals($name);
    }

    public function printlnTest8() {
        $name = "println (long)";
        $this->printLongAssertEquals($name);
    }

    public function printlnTest9() {
        $name = "println (Object)";
        $this->printObjectAssertEquals($name);
    }

    public function printlnTest10() {
        $name = "println (String)";
        $this->printStringAssertEquals($name);
    }

    /**
     * Executes the PrintStream library testing utility repeatedly to run all of its
     * functions/methods (the index of the current test routine to call is passed
     * as the command-line argument) with comparing the actual strings printed by them
     * with the predefined expected values.
     * During this process, the method prints the count of errors found in each
     * of the function/method. After that, it prints the total count of errors
     * found in the PrintStream library.
     */
    public function runTests() {
        $n = count($this->tests);

        for ($i = 0; $i < $n; $i++) {
            echoLine("--- Spouštím testovací metodu/funkci \"{$this->tests[$i]}\" ---");
            $this->output = array();

            // executing the testing utility with storing its printed output
            exec("\"$this->outTestExecPath\" $i", $this->output);
            // calling the corresponding method for comparing the results
            call_user_func(array($this, $this->tests[$i]));
            echoLine();
            // printing the error count for the current method/function
            echoLine("--- Testovací metoda/funkce \"{$this->tests[$i]}\" dokončena - nalezeno chyb: $this->errorsInMethod ---");
            $this->errorsInClass += $this->errorsInMethod;
            $this->errorsInMethod = 0;
            echoLine();
        }

        // printing the total error count
        echoLine("=== Test knihovny PrintStream dokončen - celkem chyb: $this->errorsInClass ===");
        $this->errorsInClass = 0;
        echoLine();
    }

}
