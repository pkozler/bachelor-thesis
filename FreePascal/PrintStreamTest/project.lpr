program project;

(**
 * A PrintStream class test utility.
 *
 * @author Petr Kozler (A13B0359P)
 *)

uses sysutils, PrintStreamTestUnit;

// a test method pointer array length
const TEST_METHOD_COUNT = 19;

type
  // a test method pointer
  TestMethod = procedure of object;

var
  // a test class
  testClass: PrintStreamTest;
  // an array of the test method pointers
  testMethods: array of TestMethod;
  n: longInt;

(*
  Prints help message if the specified method index is not valid.
*)
procedure usage;
begin
  writeLn('Zadejte platné číslo testovací metody. ('
  + intToStr(0) + ' - ' + intToStr(length(testMethods) - 1) + ')');
  halt(-1);
end;

(**
 * Calls the PrintStream test method with the index specified in the command-line argument
 * and returns the count of errors found during the test as the exit status.
 *)
begin
  testClass := PrintStreamTest.create();
  setLength(testMethods, TEST_METHOD_COUNT);
  testMethods[0] := @(testClass.printTest);
  testMethods[1] := @(testClass.printTest2);
  testMethods[2] := @(testClass.printTest3);
  testMethods[3] := @(testClass.printTest4);
  testMethods[4] := @(testClass.printTest5);
  testMethods[5] := @(testClass.printTest6);
  testMethods[6] := @(testClass.printTest7);
  testMethods[7] := @(testClass.printTest8);
  testMethods[8] := @(testClass.printTest9);
  testMethods[9] := @(testClass.printlnTest);
  testMethods[10] := @(testClass.printlnTest2);
  testMethods[11] := @(testClass.printlnTest3);
  testMethods[12] := @(testClass.printlnTest4);
  testMethods[13] := @(testClass.printlnTest5);
  testMethods[14] := @(testClass.printlnTest6);
  testMethods[15] := @(testClass.printlnTest7);
  testMethods[16] := @(testClass.printlnTest8);
  testMethods[17] := @(testClass.printlnTest9);
  testMethods[18] := @(testClass.printlnTest10);

  if paramcount < 1 then begin
    usage();
  end;

  try
    n := strToInt(paramStr(1));
  except
    on e: EConvertError do begin
      usage();
    end;
  end;

  testMethods[n]();
end.
