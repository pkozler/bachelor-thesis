program project;

(**
 * A Scanner class test utility.
 *
 * @author Petr Kozler (A13B0359P)
 *)

uses sysutils, ScannerTestUnit;

// a test method pointer array length
const TEST_METHOD_COUNT = 10;

type
  // a test method pointer
  TestMethod = procedure of object;

var
  // a test class
  testClass: ScannerTest;
  // an array of the test method pointers
  testMethods: array of TestMethod;
  n: longInt;

(*
  Prints help message if the specified method index is not valid.
*)
procedure usage;
begin
  writeLn('Zadejte platné číslo testovací metody. ('
  + intToStr(0) + ' - ' + intToStr(TEST_METHOD_COUNT - 1) + ')');
  halt(-1);
end;

(**
 * Calls the Scanner test method with the index specified in the command-line argument
 * and returns the count of errors found during the test as the exit status.
 *)
begin
  testClass := ScannerTest.create();
  setLength(testMethods, TEST_METHOD_COUNT);
  testMethods[0] := @(testClass.scannerTest);
  testMethods[1] := @(testClass.nextTest);
  testMethods[2] := @(testClass.nextBooleanTest);
  testMethods[3] := @(testClass.nextByteTest);
  testMethods[4] := @(testClass.nextShortTest);
  testMethods[5] := @(testClass.nextIntTest);
  testMethods[6] := @(testClass.nextLongTest);
  testMethods[7] := @(testClass.nextFloatTest);
  testMethods[8] := @(testClass.nextDoubleTest);
  testMethods[9] := @(testClass.nextLineTest);

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
  halt(testClass.errorsInMethodProperty);
end.
