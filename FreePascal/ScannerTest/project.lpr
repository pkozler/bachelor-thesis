program project;

uses sysutils, ScannerTestUnit;

const TEST_METHOD_COUNT = 10;

type
  TestMethod = procedure of object;

var
  testClass: ScannerTest;
  testMethods: array of TestMethod;
  n: longInt;

procedure usage;
begin
  writeLn('Zadejte platné číslo testovací metody. ('
  + intToStr(0) + ' - ' + intToStr(TEST_METHOD_COUNT - 1) + ')');
  halt(-1);
end;

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
