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
  SystemUnit, unit1;

var
  s1 : String_;
  o1 : Object_;
  sc : Scanner;
begin
  s1 := 'zeroth';
  o1 := Object_.create();

  System_.out_.println(s1);
  System_.out_.println(o1);

  sc := Scanner.create(System_.in_);
  sc.nextLine();
end.
