program fpcunitproject;

{$mode objfpc}{$H+}

uses
  Classes, consoletestrunner, MathTestUnit, ArraysTestUnit, CollectionsTestUnit,
  ArrayListTestUnit, LinkedListTestUnit, StringTestUnit, StringTokenizerTestUnit,
  StringBuilderTestUnit, ScannerTestUnit, PrintStreamTestUnit,
  BooleanTestUnit, CharacterTestUnit, ByteTestUnit, ShortTestUnit,
  IntegerTestUnit, LongTestUnit, FloatTestUnit, DoubleTestUnit;

type

  { TLazTestRunner }

  TMyTestRunner = class(TTestRunner)
  protected
  // override the protected methods of TTestRunner to customize its behavior
  end;

var
  Application: TMyTestRunner;

begin
  Application := TMyTestRunner.Create(nil);
  Application.Initialize;
  Application.Run;
  Application.Free;
end.
