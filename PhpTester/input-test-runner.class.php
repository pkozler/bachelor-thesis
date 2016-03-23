<?php

	class InputTestRunner
	{
		private $tests = array(
			"scannerTest",
            "nextTest",
            "nextBooleanTest",
            "nextByteTest",
            "nextShortTest",
            "nextIntTest",
            "nextLongTest",
            "nextFloatTest",
            "nextDoubleTest"
        );

		private $inTestExecPath;
		private $errorsInClass;

		public function __construct($testedLibrary)
		{
			echoLine("=== Initializing Scanner class test runner ===");
			$this->errorsInClass = 0;
			$this->inTestExecPath = $testedLibrary->getInTestExecPath();
			echoLine("Input test executable path: $this->inTestExecPath");
			echoLine();
		}

		public function getTestMethodName($index) {
			return $this->tests[$index];
		}

		public function runTests()
		{
			$n = count($this->tests);

			for ($i = 0; $i < $n; $i++) {
				$inputFile = ROOT_PATH . "/" . INPUT_DIRECTORY . "/{$this->tests[$i]}.txt";

				if (!file_exists($inputFile)) {
					dieLine("Input file not found: $inputFile");
				}

				echoLine("--- Executing \"{$this->tests[$i]}\" method with input file \"$inputFile\" ---");
				$output = array();
				$errorsInMethod = 0;
				exec("\"$this->inTestExecPath\" $i < \"$inputFile\"", $output, $errorsInMethod);

				foreach ($output as $line) {
					echoLine($line);
				}

				echoLine();
				echoLine("--- Test method \"{$this->tests[$i]}\" completed - errors found: $errorsInMethod ---");
				$this->errorsInClass += $errorsInMethod;
				echoLine();
			}

			echoLine("=== Scanner class test completed - total errors: $this->errorsInClass ===");
			$this->errorsInClass = 0;
			echoLine();
		}
	}