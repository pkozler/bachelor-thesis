<?php

class InputTestRunner {

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
    private $inTestExecPath;
    private $errorsInClass;

    public function __construct($testedLibrary) {
        echoLine("=== Inicializuji spouštěč testů pro třídu/modul Scanner ===");
        $this->errorsInClass = 0;
        $this->inTestExecPath = $testedLibrary->getInTestExecPath();
        echoLine("Spustitelný soubor testů pro Scanner: $this->inTestExecPath");
        echoLine();
    }

    public function getTestMethodName($index) {
        return $this->tests[$index];
    }

    public function runTests() {
        $n = count($this->tests);

        for ($i = 0; $i < $n; $i++) {
            $inputFile = ROOT_PATH . "/" . INPUT_DIRECTORY . "/{$this->tests[$i]}.txt";

            if (!file_exists($inputFile)) {
                dieLine("Nenalezen soubor se vstupními daty: $inputFile");
            }

            echoLine("--- Spouštím testovací metodu/funkci \"{$this->tests[$i]}\" se vstupním souborem \"$inputFile\" ---");
            $output = array();
            $errorsInMethod = 0;
            exec("\"$this->inTestExecPath\" $i < \"$inputFile\"", $output, $errorsInMethod);

            foreach ($output as $line) {
                echoLine($line);
            }

            echoLine();
            echoLine("--- Testovací metoda/funkce \"{$this->tests[$i]}\" dokončena - nalezeno chyb: $errorsInMethod ---");
            $this->errorsInClass += $errorsInMethod;
            echoLine();
        }

        echoLine("=== Test třídy/modulu Scanner dokončen - celkem chyb: $this->errorsInClass ===");
        $this->errorsInClass = 0;
        echoLine();
    }

}
