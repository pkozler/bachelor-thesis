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
  SystemUnit,
  TestObjectUnit,
  TestObjectComparatorUnit;

var
  s : String_;
  sc : Scanner;
begin
  sc := Scanner.create(System_.in_);
  s := sc.next();
  System_.out_.println(s);
  s := sc.nextLine();
  System_.out_.println(s);

  ReadLn();
end.
