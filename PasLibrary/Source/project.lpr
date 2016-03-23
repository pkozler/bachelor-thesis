program project;

{$mode objfpc}{$H+}

uses
  Classes,
  SysUtils,
  ArrayListUnit,
  ArraysUnit,
  BooleanUnit,
  ByteUnit,
  CollectionsUnit,
  DoubleUnit,
  FloatUnit,
  CharacterUnit,
  IntegerUnit,
  LinkedListUnit,
  LongUnit,
  MathUnit,
  ScannerUnit,
  ShortUnit,
  StringBuilderUnit,
  StringTokenizerUnit,
  StringUnit,
  SystemUnit;

var
  str, str2, str3 : String_;
begin
  str := 'aaa';
  str2 := 'bbb';
  WriteLn(str.toString());
  WriteLn(str2.toString());
  //str3 := str + str2;
  WriteLn(str3.toString());
end.
