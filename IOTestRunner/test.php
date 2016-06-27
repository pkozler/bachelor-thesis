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

// printing usage info if command-line args was invalid
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

// running the input library tests of the chosen programming language
$inputTestRunner = new InputTestRunner($testedLibraries[$argv[1]]);
$inputTestRunner->runTests();
// running the output library tests of the chosen programming language
$outputTestRunner = new OutputTestRunner($testedLibraries[$argv[1]]);
$outputTestRunner->runTests();