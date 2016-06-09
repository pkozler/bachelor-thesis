program project;

uses sysutils, PrintStreamTestUnit;

const TEST_METHOD_COUNT = 19;

type
  TestMethod = procedure of object;

var
  testClass: PrintStreamTest;
  testMethods: array of TestMethod;
  n: longInt;

procedure usage;
begin
  writeLn('Zadejte platné číslo testovací metody. ('
  + intToStr(0) + ' - ' + intToStr(length(testMethods) - 1) + ')');
  halt(-1);
end;

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
