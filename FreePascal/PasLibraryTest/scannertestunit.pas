unit ScannerTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, SystemUnit, ScannerUnit, StringUnit,
  BooleanUnit, ByteUnit, ShortUnit, IntegerUnit, LongUnit, FloatUnit, DoubleUnit;

type
  ScanMethod = procedure(sc: Scanner);
  EqualsMethod = function(expected, actual: pointer): boolean;
  ToStringMethod = function(value: pointer): String_;

  ScannerTest = class(TTestCase)
  private
    var errorsInMethod: longInt;
    procedure assertEqualsPointer(name: ansiString; expected: pointer; sc: Scanner;
      scan: ScanMethod; e: EqualsMethod; ts: ToStringMethod);
    procedure assertEqualsString(name: ansiString; expected: String_; sc: Scanner;
      scan: ScanMethod);
    procedure nextAssertEquals(sc: Scanner; expected: String_);
    procedure nextBooleanAssertEquals(sc: Scanner; expected: boolean);
    procedure nextByteAssertEquals(sc: Scanner; expected: shortInt);
    procedure nextShortAssertEquals(sc: Scanner; expected: smallInt);
    procedure nextIntAssertEquals(sc: Scanner; expected: longInt);
    procedure nextLongAssertEquals(sc: Scanner; expected: int64);
    procedure nextFloatAssertEquals(sc: Scanner; expected: single);
    procedure nextDoubleAssertEquals(sc: Scanner; expected: double);
    procedure nextLineAssertEquals(sc: Scanner; expected: String_);
  public
    property errorsInMethodProperty: longInt read errorsInMethod;
    constructor create(); override;
    procedure scannerTest;
    procedure nextTest;
    procedure nextBooleanTest;
    procedure nextByteTest;
    procedure nextShortTest;
    procedure nextIntTest;
    procedure nextLongTest;
    procedure nextFloatTest;
    procedure nextDoubleTest;
    procedure nextLineTest;
  end;

implementation

type
  PBoolean = ^boolean;
  PShortInt = ^shortInt;
  PDouble = ^double;
  PSingle = ^single;
  PLongInt = ^longInt;
  PInt64 = ^int64;
  PSmallInt = ^smallInt;

  DataType = (BooleanType, ByteType, ShortType, IntType,
              LongType, FloatType, DoubleType, StringType);

  CurrentValue = record
    case value: DataType of
         BooleanType: (currentScannedBoolean: boolean);
         ByteType: (currentScannedByte: shortInt);
         ShortType: (currentScannedShort: smallInt);
         IntType: (currentScannedInt: longInt);
         LongType: (currentScannedLong: int64);
         FloatType: (currentScannedFloat: single);
         DoubleType: (currentScannedDouble: double);
         StringType: (currentScannedString: String_);
  end;

var
   currentScannedValue: CurrentValue;

function _equalsBool(a, b: pointer) : boolean;
var
  x, y: Boolean_;
begin
  x := Boolean_.create(PBoolean(a)^);
  y := Boolean_.create(PBoolean(b)^);
  _equalsBool := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _equalsB(a, b: pointer) : boolean;
var
  x, y: Byte_;
begin
  x := Byte_.create(PShortInt(a)^);
  y := Byte_.create(PShortInt(b)^);
  _equalsB := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _equalsD(a, b: pointer) : boolean;
var
  x, y: Double_;
begin
  x := Double_.create(PDouble(a)^);
  y := Double_.create(PDouble(b)^);
  _equalsD := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _equalsF(a, b: pointer) : boolean;
var
  x, y: Float;
begin
  x := Float.create(PSingle(a)^);
  y := Float.create(PSingle(b)^);
  _equalsF := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _equalsI(a, b: pointer) : boolean;
var
  x, y: Integer_;
begin
  x := Integer_.create(PLongInt(a)^);
  y := Integer_.create(PLongInt(b)^);
  _equalsI := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _equalsL(a, b: pointer) : boolean;
var
  x, y: Long;
begin
  x := Long.create(PInt64(a)^);
  y := Long.create(PInt64(b)^);
  _equalsL := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _equalsS(a, b: pointer) : boolean;
var
  x, y: Short;
begin
  x := Short.create(PSmallInt(a)^);
  y := Short.create(PSmallInt(b)^);
  _equalsS := x.equals(y);
  freeAndNil(x);
  freeAndNil(y);
end;

function _toStringBool(a: pointer) : String_;
begin
  _toStringBool := Boolean_.toString_(PBoolean(a)^);
end;

function _toStringB(a: pointer) : String_;
begin
  _toStringB := Byte_.toString_(PShortInt(a)^);
end;

function _toStringD(a: pointer) : String_;
begin
  _toStringD := Double_.toString_(PDouble(a)^);
end;

function _toStringF(a: pointer) : String_;
begin
  _toStringF := Float.toString_(PSingle(a)^);
end;

function _toStringI(a: pointer) : String_;
begin
  _toStringI := Integer_.toString_(PLongInt(a)^);
end;

function _toStringL(a: pointer) : String_;
begin
  _toStringL := Long.toString_(PInt64(a)^);
end;

function _toStringS(a: pointer) : String_;
begin
  _toStringS := Short.toString_(PSmallInt(a)^);
end;

procedure _scanBool(sc: Scanner);
begin
  currentScannedValue.currentScannedBoolean := sc.nextBoolean();
end;

procedure _scanB(sc: Scanner);
begin
  currentScannedValue.currentScannedByte := sc.nextByte();
end;

procedure _scanD(sc: Scanner);
begin
  currentScannedValue.currentScannedDouble := sc.nextDouble();
end;

procedure _scanF(sc: Scanner);
begin
  currentScannedValue.currentScannedFloat := sc.nextFloat();
end;

procedure _scanI(sc: Scanner);
begin
  currentScannedValue.currentScannedInt := sc.nextInt();
end;

procedure _scanL(sc: Scanner);
begin
  currentScannedValue.currentScannedLong := sc.nextLong();
end;

procedure _scanS(sc: Scanner);
begin
  currentScannedValue.currentScannedShort := sc.nextShort();
end;

procedure _scanStr(sc: Scanner);
begin
  currentScannedValue.currentScannedString := sc.next().strProperty;
end;

procedure _scanStrLn(sc: Scanner);
begin
  currentScannedValue.currentScannedString := sc.nextLine().strProperty;
end;

procedure ScannerTest.assertEqualsPointer(name: ansiString; expected: pointer; sc: Scanner;
  scan: ScanMethod; e: EqualsMethod; ts: ToStringMethod);
var
  actual: pointer;
begin
    writeLn();
    writeLn('Testovaná metoda: "' + name + '"');
    writeLn('Očekávaná hodnota: "' + ts(expected).strProperty + '"');

    scan(sc);
    actual := @currentScannedValue;

    if e(expected, actual) then begin
        writeLn('OK');
    end
    else begin
        writeLn('FAIL - skutečná hodnota: "' + ts(actual).strProperty + '"');
        inc(errorsInMethod);
    end;
end;

procedure ScannerTest.assertEqualsString(name: ansiString; expected: String_; sc: Scanner; scan: ScanMethod);
var
  actual: String_;
begin
    writeLn();
    writeLn('Testovaná metoda: "' + name + '"');
    writeLn('Očekávaná hodnota: "' + expected.toString_().strProperty + '"');

    scan(sc);
    actual := currentScannedValue.currentScannedString;

    if expected.equals_(actual) then begin
        writeLn('OK');
    end
    else begin
        writeLn('FAIL - skutečná hodnota: "' + actual.toString_().strProperty + '"');
        inc(errorsInMethod);
    end;
end;

procedure ScannerTest.nextAssertEquals(sc: Scanner; expected: String_);
begin
    assertEqualsString('next', expected, sc, @_scanStr);
end;

procedure ScannerTest.nextBooleanAssertEquals(sc: Scanner; expected: boolean);
begin
    assertEqualsPointer('nextBoolean', @expected, sc, @_scanBool, @_equalsB, @_toStringB);
end;

procedure ScannerTest.nextByteAssertEquals(sc: Scanner; expected: shortInt);
begin
    assertEqualsPointer('nextByte', @expected, sc, @_scanB, @_equalsB, @_toStringB);
end;

procedure ScannerTest.nextShortAssertEquals(sc: Scanner; expected: smallInt);
begin
    assertEqualsPointer('nextShort', @expected, sc, @_scanS, @_equalsS, @_toStringS);
end;

procedure ScannerTest.nextIntAssertEquals(sc: Scanner; expected: longInt);
begin
    assertEqualsPointer('nextInt', @expected, sc, @_scanI, @_equalsI, @_toStringI);
end;

procedure ScannerTest.nextLongAssertEquals(sc: Scanner; expected: int64);
begin
    assertEqualsPointer('nextLong', @expected, sc, @_scanL, @_equalsL, @_toStringL);
end;

procedure ScannerTest.nextFloatAssertEquals(sc: Scanner; expected: single);
begin
    assertEqualsPointer('nextFloat', @expected, sc, @_scanF, @_equalsF, @_toStringF);
end;

procedure ScannerTest.nextDoubleAssertEquals(sc: Scanner; expected: double);
begin
    assertEqualsPointer('nextDouble', @expected, sc, @_scanD, @_equalsD, @_toStringD);
end;

procedure ScannerTest.nextLineAssertEquals(sc: Scanner; expected: String_);
begin
    assertEqualsString('nextLine', expected, sc, @_scanStrLn);
end;

constructor ScannerTest.create();
begin
    errorsInMethod := 0;
end;

(**
 * Tests the constructor.
 *)
procedure ScannerTest.scannerTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    // random test of different type values scanning
    nextAssertEquals(a, 'a');
    nextBooleanAssertEquals(a, false);
    nextByteAssertEquals(a, 0);
    nextShortAssertEquals(a, 0);
    nextIntAssertEquals(a, 0);
    nextLongAssertEquals(a, 0);
    nextFloatAssertEquals(a, 0.1);
    nextDoubleAssertEquals(a, 0.1);
    nextLineAssertEquals(a, ' ');
end;

(**
 * Tests the next method.
 *)
procedure ScannerTest.nextTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    // scanning of strings delimited by different counts of whitespaces
    nextAssertEquals(a, 'test1');
    nextAssertEquals(a, 'test2');
    nextAssertEquals(a, 'test3');
    nextAssertEquals(a, 'test4');
    nextAssertEquals(a, 'test5');
    nextAssertEquals(a, 'true');
    nextAssertEquals(a, '1');
    nextAssertEquals(a, '1.0');
    nextAssertEquals(a, '.');
end;

(**
 * Tests the nextBoolean method.
 *)
procedure ScannerTest.nextBooleanTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    // scanning of strings representing boolean values
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, false);
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, false);
    nextBooleanAssertEquals(a, false);
    nextBooleanAssertEquals(a, true);
    nextBooleanAssertEquals(a, false);
end;

(**
 * Tests the nextByte method.
 *)
procedure ScannerTest.nextByteTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    // scanning of integers (zeroes, ones, positive and negative minimal and maximal values)
    nextByteAssertEquals(a, shortInt(0));
    nextByteAssertEquals(a, shortInt(0));
    nextByteAssertEquals(a, shortInt(0));
    nextByteAssertEquals(a, shortInt(1));
    nextByteAssertEquals(a, shortInt(1));
    nextByteAssertEquals(a, shortInt(-1));
    nextByteAssertEquals(a, shortInt(127));
    nextByteAssertEquals(a, shortInt(127));
    nextByteAssertEquals(a, shortInt(-127));
    nextByteAssertEquals(a, shortInt(-128));
end;

(**
 * Tests the nextShort method.
 *)
procedure ScannerTest.nextShortTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    nextShortAssertEquals(a, smallInt(0));
    nextShortAssertEquals(a, smallInt(0));
    nextShortAssertEquals(a, smallInt(0));
    nextShortAssertEquals(a, smallInt(1));
    nextShortAssertEquals(a, smallInt(1));
    nextShortAssertEquals(a, smallInt(-1));
    nextShortAssertEquals(a, smallInt(32767));
    nextShortAssertEquals(a, smallInt(32767));
    nextShortAssertEquals(a, smallInt(-32767));
    nextShortAssertEquals(a, smallInt(-32768));
end;

(**
 * Tests the nextInt method.
 *)
procedure ScannerTest.nextIntTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    nextIntAssertEquals(a, longInt(0));
    nextIntAssertEquals(a, longInt(0));
    nextIntAssertEquals(a, longInt(0));
    nextIntAssertEquals(a, longInt(1));
    nextIntAssertEquals(a, longInt(1));
    nextIntAssertEquals(a, longInt(-1));
    nextIntAssertEquals(a, longInt(2147483647));
    nextIntAssertEquals(a, longInt(2147483647));
    nextIntAssertEquals(a, longInt(-2147483647));
    nextIntAssertEquals(a, longInt(-2147483648));
end;

(**
 * Tests the nextLong method.
 *)
procedure ScannerTest.nextLongTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    nextLongAssertEquals(a, int64(0));
    nextLongAssertEquals(a, int64(0));
    nextLongAssertEquals(a, int64(0));
    nextLongAssertEquals(a, int64(1));
    nextLongAssertEquals(a, int64(1));
    nextLongAssertEquals(a, int64(-1));
    nextLongAssertEquals(a, int64(9223372036854775807));
    nextLongAssertEquals(a, int64(9223372036854775807));
    nextLongAssertEquals(a, int64(-9223372036854775807));
    nextLongAssertEquals(a, int64(-9223372036854775808));
end;

(**
 * Tests the nextFloat method.
 *)
procedure ScannerTest.nextFloatTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    (*
     scanning of decimal values
     (with and without sign and decimal dot and with omission of digits on different positions,
     scanning of zeroes, ones, minimal and maximal absolute values)
     *)
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(-0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(-0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(-0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(0.0));
    nextFloatAssertEquals(a, single(-0.0));
    nextFloatAssertEquals(a, single(1.0));
    nextFloatAssertEquals(a, single(1.0));
    nextFloatAssertEquals(a, single(-1.0));
    nextFloatAssertEquals(a, single(1.0));
    nextFloatAssertEquals(a, single(1.0));
    nextFloatAssertEquals(a, single(-1.0));
    nextFloatAssertEquals(a, single(0.1));
    nextFloatAssertEquals(a, single(0.1));
    nextFloatAssertEquals(a, single(-0.1));
    nextFloatAssertEquals(a, single(0.1));
    nextFloatAssertEquals(a, single(0.1));
    nextFloatAssertEquals(a, single(-0.1));
    nextFloatAssertEquals(a, single(3.4028235E38));
    nextFloatAssertEquals(a, single(3.4028235E38));
    nextFloatAssertEquals(a, single(-3.4028235E38));
    nextFloatAssertEquals(a, single(1.4E-45));
    nextFloatAssertEquals(a, single(1.4E-45));
    nextFloatAssertEquals(a, single(-1.4E-45));
end;

(**
 * Tests the nextDouble method.
 *)
procedure ScannerTest.nextDoubleTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(-0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(-0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(-0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(0.0));
    nextDoubleAssertEquals(a, double(-0.0));
    nextDoubleAssertEquals(a, double(1.0));
    nextDoubleAssertEquals(a, double(1.0));
    nextDoubleAssertEquals(a, double(-1.0));
    nextDoubleAssertEquals(a, double(1.0));
    nextDoubleAssertEquals(a, double(1.0));
    nextDoubleAssertEquals(a, double(-1.0));
    nextDoubleAssertEquals(a, double(0.1));
    nextDoubleAssertEquals(a, double(0.1));
    nextDoubleAssertEquals(a, double(-0.1));
    nextDoubleAssertEquals(a, double(0.1));
    nextDoubleAssertEquals(a, double(0.1));
    nextDoubleAssertEquals(a, double(-0.1));
    nextDoubleAssertEquals(a, double(1.7976931348623157E308));
    nextDoubleAssertEquals(a, double(1.7976931348623157E308));
    nextDoubleAssertEquals(a, double(-1.7976931348623157E308));
    nextDoubleAssertEquals(a, double(4.9E-324));
    nextDoubleAssertEquals(a, double(4.9E-324));
    nextDoubleAssertEquals(a, double(-4.9E-324));
end;

(**
 * Tests the nextLine method.
 *)
procedure ScannerTest.nextLineTest;
var
  a: Scanner;
begin
    a := Scanner.create(System_.in_);

    // scanning of lines with different types of ansiString
    nextLineAssertEquals(a, '');
    nextLineAssertEquals(a, ' ');
    nextLineAssertEquals(a, '   ');
    nextLineAssertEquals(a, 'test');
    nextLineAssertEquals(a, 'this is another test');
    nextLineAssertEquals(a, ' this is another test ');
    nextLineAssertEquals(a, '   this is another test   ');
    nextLineAssertEquals(a, '   this is   another test   ');
end;

initialization

  //RegisterTest(ScannerTest);
end.

