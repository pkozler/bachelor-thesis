program project;

{$mode objfpc}{$H+}

uses
  Classes,
  Math,
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
  sc: Scanner;
begin
    sc := Scanner.create(System_.in_);
    System_.out_.print(sc.nextDouble());
    readln();
end.