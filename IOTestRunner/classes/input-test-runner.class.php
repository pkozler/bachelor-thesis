<?php

/**
 * This class provides method for performing the tests of the Scanner library,
 * which is used for reading the data from the standard input.
 *
 * @author Petr Kozler
 */
class InputTestRunner {

    // names of the test utility methods/functions
    private $tests = array(
        "scannerTest",
        "nextTest",
        "nextBooleanTest",
        "nextByteTest",
        "nextShortTest",
        "nextIntTest",
        "nextLongTest",
        "nextFloatTest",
        "nextDoubleTest",
        "nextLineTest",
    );
    // test utility executable file path
    private $inTestExecPath;
    // total errors found in the library
    private $errorsInClass;

    /**
     * Creates the new input test runner.
     *
     * @param $testedLibrary the tested library info
     */
    public function __construct($testedLibrary) {
        echoLine("=== Inicializuji spouštěč testů pro knihovnu Scanner ===");
        $this->errorsInClass = 0;
        $this->inTestExecPath = $testedLibrary->getInTestExecPath();
        echoLine("Spustitelný soubor testů pro Scanner: $this->inTestExecPath");
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

    /**
     * Executes the Scanner library testing utility repeatedly to run all of its
     * functions/methods (the index of the current test routine to call is passed
     * as the command-line argument) with redirecting its input to the corresponding
     * prepared test data file to simulate the user input.
     * During this process, the method prints the count of errors found in each
     * of the function/method. After that, it prints the total count of errors
     * found in the Scanner library.
     */
    public function runTests() {
        $n = count($this->tests);

        for ($i = 0; $i < $n; $i++) {
            // building the path of the test data file for the current test
            $inputFile = ROOT_PATH . "/" . INPUT_DIRECTORY . "/{$this->tests[$i]}.txt";

            // the test data file was not found
            if (!file_exists($inputFile)) {
                dieLine("Nenalezen soubor se vstupními daty: $inputFile");
            }

            echoLine("--- Spouštím testovací metodu/funkci \"{$this->tests[$i]}\" se vstupním souborem \"$inputFile\" ---");
            $output = array();
            $errorsInMethod = 0;

            /*
                Executing the testing utility with storing its printed output and the return value.
                If the test finished successfully (without unexpected failures), the return value
                represents the count of errors found durring the current testing method/function call.
             */
            exec("\"$this->inTestExecPath\" $i < \"$inputFile\"", $output, $errorsInMethod);

            // showing the printed output
            foreach ($output as $line) {
                echoLine($line);
            }

            echoLine();
            // printing the error count for the current method/function
            echoLine("--- Testovací metoda/funkce \"{$this->tests[$i]}\" dokončena - nalezeno chyb: $errorsInMethod ---");
            $this->errorsInClass += $errorsInMethod;
            echoLine();
        }

        // printing the total error count
        echoLine("=== Test knihovny Scanner dokončen - celkem chyb: $this->errorsInClass ===");
        $this->errorsInClass = 0;
        echoLine();
    }

}
