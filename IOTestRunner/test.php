<?php

/*
 *	Main script file of the input/output library automatic testing tool.
 *  This tool performs an automatic testing of all the methods
 *  or functions provided by the libraries performing the IO operations
 *  (Java-like Scanner and PrintStream library), which are written for
 *  the language specified by the index passed as the command-line argument,
 *  by running the test routines of the corresponding testing utilities.
 *
 *  @author Petr Kozler
 */

// the script root folder path
define('ROOT_PATH', dirname(__FILE__));
// the name of the folder with testing data files
define('INPUT_DIRECTORY', 'data');

require_once(ROOT_PATH . "/include/functions.inc.php");
require_once(ROOT_PATH . "/classes/tested-library.class.php");
require_once(ROOT_PATH . "/classes/input-test-runner.class.php");
require_once(ROOT_PATH . "/classes/output-test-runner.class.php");

// setting the UTF-8 codepage
exec("chcp 65001");

// relative paths to the testing utilities of each supported programming language
$testedLibraries = array(
    new TestedLibrary("C", "C", "ScannerTest/dist/Debug/Cygwin-Windows/scannertest.exe", "PrintStreamTest/dist/Debug/Cygwin-Windows/printstreamtest.exe"),
    new TestedLibrary("C++", "CPlusPlus", "ScannerTest/dist/Debug/Cygwin-Windows/scannertest.exe", "PrintStreamTest/dist/Debug/Cygwin-Windows/printstreamtest.exe"),
    new TestedLibrary("C#", "CSharp", "ScannerTest/bin/Debug/ScannerTest.exe", "PrintStreamTest/bin/Debug/PrintStreamTest.exe"),
    new TestedLibrary("Free Pascal", "FreePascal", "ScannerTest/project.exe", "PrintStreamTest/project.exe"),
);

// input library testing flag
$isInputTestingEnabled = true;
// output library testing flag
$isOutputTestingEnabled = true;

// printing usage info if command-line args was invalid
if (count($argv) < 2 || !is_numeric($argv[1])) {
    echoLine("\n=== Nástroj pro automatické spouštění testů knihoven pro vstup a výstup ===\n");
    echoLine("--- Nápověda: ---\n");
    echoLine("Zadejte platné číslo programovacího jazyka pro otestování jeho obalových knihoven pro IO operace jako první parametr příkazové řádky při spuštění programu:\n"
			. "\t0 - {$testedLibraries[0]}\n"
			. "\t1 - {$testedLibraries[1]}\n"
			. "\t2 - {$testedLibraries[2]}\n"
			. "\t3 - {$testedLibraries[3]}\n");
    echoLine("Jako druhý parametr může poté následovat jeden z platných volitelných příznaků pro omezení typu testovaných operací:\n"
			. "\ti - pouze testy vstupu\n"
			. "\to - pouze testy výstupu\n");
    echoLine("Pokud volitelný druhý parametr není uveden, budou provedeny všechny podporované testy knihoven zvoleného jazyka, tzn. budou otestovány jak vstupní, tak i výstupní operace.\n");
    echoLine("--- O programu: ---\n");
    dieLine("Tento nástroj byl vytvořen jako součást bakalářské práce "
            . "\"Vytvoření knihoven s definovaným rozhraním v jazycích C, C++, C# a FreePascal\" "
            . "v oboru Informatika na Fakultě aplikovaných věd Západočeské univerzity v Plzni.\n\n"
            . "Copyright © Petr Kozler, 2016");
}

// optional disabling the input our output testing according to the next argument
if (count($argv) > 2) {
	$flag = strtolower($argv[2]);

	switch ($flag) {
		case 'i':
			$isOutputTestingEnabled = false;
			break;
		case 'o':
			$isInputTestingEnabled = false;
			break;
	}
}

// running the input library tests of the chosen programming language (if enabled)
if ($isInputTestingEnabled) {
	$inputTestRunner = new InputTestRunner($testedLibraries[$argv[1]]);
	$inputTestRunner->runTests();
}

// running the output library tests of the chosen programming language (if enabled)
if ($isOutputTestingEnabled) {
	$outputTestRunner = new OutputTestRunner($testedLibraries[$argv[1]]);
	$outputTestRunner->runTests();
}