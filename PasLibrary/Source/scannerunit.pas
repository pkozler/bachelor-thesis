unit ScannerUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit;

type
  (**
   * A simple text scanner which can parse primitive types and strings using regular expressions.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Scanner = class
    public
      constructor create(source: TObject);
      function next() : String_;
      function nextBoolean() : boolean;
      function nextByte() : shortInt;
      function nextShort() : smallInt;
      function nextInt() : longInt;
      function nextLong() : int64;
      function nextFloat() : single;
      function nextDouble() : double;
      function nextLine() : String_;
  end;

implementation

uses
  SysUtils;

(**
 * Constructs a new Scanner that produces values scanned from the specified
 * input stream.
 *
 * @param source An input stream to be scanned
 *)
constructor Scanner.create(source: TObject);
begin
end;

(**
 * Finds and returns the next complete token from this scanner.
 *
 * @return the next token
 *)
function Scanner.next() : String_;
var
  s: ansiString;
  str: String_;
begin
  read(s);
  str.create(s);
  next := str; // TODO nacist retezec do prvniho bileho znaku
end;

(**
 * Scans the next token of the input into a boolean value and returns that
 * value.
 *
 * @return the boolean scanned from the input
 *)
function Scanner.nextBoolean() : boolean;
var
  s: ansiString;
begin
  read(s);
  nextBoolean := strToBool(s);
end;

(**
 * Scans the next token of the input as a byte.
 *
 * @return the byte scanned from the input
 *)
function Scanner.nextByte() : shortInt;
var
  b: shortInt;
begin
  read(b);
  nextByte := b;
end;

(**
 * Scans the next token of the input as a short.
 *
 * @return the short scanned from the input
 *)
function Scanner.nextShort() : smallInt;
var
  s: smallInt;
begin
  read(s);
  nextShort := s;
end;

(**
 * Scans the next token of the input as an int.
 *
 * @return the int scanned from the input
 *)
function Scanner.nextInt() : longInt;
var
  i: longInt;
begin
  read(i);
  nextInt := i;
end;

(**
 * Scans the next token of the input as a long.
 *
 * @return the long scanned from the input
 *)
function Scanner.nextLong() : int64;
var
  l: int64;
begin
  read(l);
  nextLong := l;
end;

(**
 * Scans the next token of the input as a float.
 *
 * @return the float scanned from the input
 *)
function Scanner.nextFloat() : single;
var
  f: single;
begin
  read(f);
  nextFloat := f;
end;

(**
 * Scans the next token of the input as a double.
 *
 * @return the double scanned from the input
 *)
function Scanner.nextDouble() : double;
var
  d: double;
begin
  read(d);
  nextDouble := d;
end;

(**
 * Advances this scanner past the current line and returns the input that was skipped.
 *
 * @return the line that was skipped
 *)
function Scanner.nextLine() : String_;
var
  s: ansiString;
  str: String_;
begin
  readLn(s);
  str.create(s);
  nextLine := str;
end;

end.

