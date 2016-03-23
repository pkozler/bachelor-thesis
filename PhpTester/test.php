<?php

	define('ROOT_PATH', dirname(__FILE__));
	define('INPUT_DIRECTORY', 'input');

	require_once(ROOT_PATH . "/functions.inc.php");
	require_once(ROOT_PATH . "/tested-library.class.php");
	require_once(ROOT_PATH . "/input-test-runner.class.php");
	require_once(ROOT_PATH . "/output-test-runner.class.php");

	$testedLibraries = array(
		new TestedLibrary("C", "CLibrary", "", ""),
		new TestedLibrary("C++", "CppLibrary", "", ""),
		new TestedLibrary("C#", "CsLibrary", "ScannerTest/bin/Debug/ScannerTest.exe", "SystemTest/bin/Debug/SystemTest.exe"),
		new TestedLibrary("Free Pascal", "PasLibrary", "", ""),
	);

	if (count($argv) < 2 || !is_numeric($argv[1])) {
		dieLine("Enter the valid tested library number:
			\t0 - {$testedLibraries[0]}
			\t1 - {$testedLibraries[1]}
			\t2 - {$testedLibraries[2]}
			\t3 - {$testedLibraries[3]}");
	}

	$inputTestRunner = new InputTestRunner($testedLibraries[$argv[1]]);
	$inputTestRunner->runTests();
	$outputTestRunner = new OutputTestRunner($testedLibraries[$argv[1]]);
	$outputTestRunner->runTests();