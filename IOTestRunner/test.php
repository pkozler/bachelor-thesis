<?php

define('ROOT_PATH', dirname(__FILE__));
define('INPUT_DIRECTORY', 'data');

require_once(ROOT_PATH . "/include/functions.inc.php");
require_once(ROOT_PATH . "/classes/tested-library.class.php");
require_once(ROOT_PATH . "/classes/input-test-runner.class.php");
require_once(ROOT_PATH . "/classes/output-test-runner.class.php");

exec("chcp 65001");

$testedLibraries = array(
    new TestedLibrary("C", "C", "", ""),
    new TestedLibrary("C++", "CPlusPlus", "", ""),
    new TestedLibrary("C#", "CSharp", "ScannerTest/bin/Debug/ScannerTest.exe", "PrintStreamTest/bin/Debug/PrintStream.exe"),
    new TestedLibrary("Free Pascal", "FreePascal", "", ""),
);

if (count($argv) < 2 || !is_numeric($argv[1])) {
    echoLine("=== Nástroj pro automatické spouštění testů knihoven pro vstup a výstup ===");
    echoLine("\nTento nástroj byl vytvořen jako součást bakalářské práce "
            . "\"Vytvoření knihoven s definovaným rozhraním v jazycích C, C++, C# a FreePascal\" "
            . "v oboru Informatika na Fakultě aplikovaných věd Západočeské univerzity v Plzni.\n\n"
            . "Copyright © Petr Kozler, 2016");
    dieLine("\nZadejte platné číslo testované knihovny:
			\t0 - {$testedLibraries[0]}
			\t1 - {$testedLibraries[1]}
			\t2 - {$testedLibraries[2]}
			\t3 - {$testedLibraries[3]}");
}

$inputTestRunner = new InputTestRunner($testedLibraries[$argv[1]]);
$inputTestRunner->runTests();
$outputTestRunner = new OutputTestRunner($testedLibraries[$argv[1]]);
$outputTestRunner->runTests();
