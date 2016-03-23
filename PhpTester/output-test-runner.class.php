<?php

	class OutputTestRunner
	{
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
			"printlnTest10"
        );

		private $outTestExecPath;
		private $output;

		private $errorsInMethod;
		private $errorsInClass;

		public function __construct($testedLibrary)
		{
			echoLine("=== Initializing PrintStream class test runner ===");
			$this->errorsInMethod = 0;
			$this->errorsInClass = 0;
			$this->outTestExecPath = $testedLibrary->getOutTestExecPath();
			echoLine("Output test executable path: $this->outTestExecPath");
			echoLine();
		}

		public function getTestMethodName($index) {
			return $this->tests[$index];
		}

		private function assertEquals($method, $expected) {
		    echoLine("\nTested method: \"$method\"");
            echoLine("Expected value: \"$expected\"");
            $actual = array_shift($this->output);

            if ($expected === $actual)
            {
                echoLine("OK");
            }
            else
            {
                echoLine("FAIL - actual value: \"$actual\"");
                $this->errorsInMethod++;
            }
		}

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

		public function printTest()
		{
			$name = "print (boolean)";
			$this->printBooleanAssertEquals($name);
		}

		public function printTest2()
		{
			$name = "print (char)";
			$this->printCharAssertEquals($name);
		}

		public function printTest3()
		{
			$name = "print (char[])";
			$this->printCharArrayAssertEquals($name);
		}

		public function printTest4()
		{
			$name = "print (double)";
			$this->printDoubleAssertEquals($name);
		}

		public function printTest5()
		{
			$name = "print (float)";
			$this->printFloatAssertEquals($name);
		}

		public function printTest6()
		{
			$name = "print (int)";
			$this->printIntAssertEquals($name);
		}

		public function printTest7()
		{
			$name = "print (long)";
			$this->printLongAssertEquals($name);
		}

		public function printTest8()
		{
			$name = "print (Object)";
			$this->printObjectAssertEquals($name);
		}

		public function printTest9()
		{
			$name = "print (String)";
			$this->printStringAssertEquals($name);
		}

		public function printlnTest()
		{
			$name = "println";
			$this->printAssertEquals($name);
		}

		public function printlnTest2()
		{
			$name = "println (boolean)";
			$this->printBooleanAssertEquals($name);
		}

		public function printlnTest3()
		{
			$name = "println (char)";
			$this->printCharAssertEquals($name);
		}

		public function printlnTest4()
		{
			$name = "println (char[])";
			$this->printCharArrayAssertEquals($name);
		}

		public function printlnTest5()
		{
			$name = "println (double)";
			$this->printDoubleAssertEquals($name);
		}

		public function printlnTest6()
		{
			$name = "println (float)";
			$this->printFloatAssertEquals($name);
		}

		public function printlnTest7()
		{
			$name = "println (int)";
			$this->printIntAssertEquals($name);
		}

		public function printlnTest8()
		{
			$name = "println (long)";
			$this->printLongAssertEquals($name);
		}

		public function printlnTest9()
		{
			$name = "println (Object)";
			$this->printObjectAssertEquals($name);
		}

		public function printlnTest10()
		{
			$name = "println (String)";
			$this->printStringAssertEquals($name);
		}

		public function runTests()
		{
			$n = count($this->tests);

			for ($i = 0; $i < $n; $i++) {
				echoLine("--- Executing \"{$this->tests[$i]}\" method. ---");
				$this->output = array();
				exec("\"$this->outTestExecPath\" $i", $this->output);
				call_user_func(array($this, $this->tests[$i]));
				echoLine();
				echoLine("--- Test method \"{$this->tests[$i]}\" completed - errors found: $this->errorsInMethod ---");
				$this->errorsInClass += $this->errorsInMethod;
				$this->errorsInMethod = 0;
				echoLine();
			}

			echoLine("=== PrintStream class test completed - total errors: $this->errorsInClass ===");
			$this->errorsInClass = 0;
			echoLine();
		}
	}