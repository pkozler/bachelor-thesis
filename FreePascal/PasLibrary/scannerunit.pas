unit ScannerUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, SystemUnit, BooleanUnit, ByteUnit, ShortUnit, IntegerUnit, LongUnit, FloatUnit, DoubleUnit;

type
  (**
   * A simple text scanner which can parse primitive types and strings using regular expressions.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Scanner = class(Object_)
    private
      var line: ansiString;
      function readLine() : String_;
      function isEmptyOrWhiteSpace(l: ansiString) : boolean;
      function removeLineToWhiteSpace() : ansiString;
      function getNextToken() : String_;
    public
      constructor create(source: InputStream);
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

function Scanner.readLine() : String_;
var
  l: ansiString;
begin
  readLn(l);
  readLine := String_.create(l);
end;

function Scanner.isEmptyOrWhiteSpace(l: ansiString) : boolean;
var
  len, i: longInt;
begin
  len := length(l);

  if len = 0 then begin
    exit(true);
  end;

  for i := 1 to len do begin
    if l[i] > ' ' then begin
      exit(false);
    end;
  end;

  isEmptyOrWhiteSpace := true;
end;

function Scanner.removeLineToWhiteSpace() : ansiString;
var
  len, i: longInt;
  token: ansiString;
begin
  len := length(line);
  line := trimLeft(line);

  for i := 1 to len do begin
    if line[i] <= ' ' then begin
      break;
    end;
  end;

  token := copy(line, 1, i);
  delete(line, 1, i);
  removeLineToWhiteSpace := token;
end;

function Scanner.getNextToken() : String_;
var
  l: String_;

begin
  while isEmptyOrWhiteSpace(line) do begin
    l := readLine();
    line := trimLeft(l.strProperty);
    freeAndNil(l);
  end;

  getNextToken := String_.create(removeLineToWhiteSpace());
end;

(**
 * Constructs a new Scanner that produces values scanned from the specified
 * input stream.
 *
 * @param source An input stream to be scanned
 *)
constructor Scanner.create(source: InputStream);
begin
  line := '';
end;

(**
 * Finds and returns the next complete token from this scanner.
 *
 * @return the next token
 *)
function Scanner.next() : String_;
begin
  next := getNextToken();
end;

(**
 * Scans the next token of the input into a boolean value and returns that
 * value.
 *
 * @return the boolean scanned from the input
 *)
function Scanner.nextBoolean() : boolean;
begin
  nextBoolean := Boolean_.parseBoolean(getNextToken());
end;

(**
 * Scans the next token of the input as a byte.
 *
 * @return the byte scanned from the input
 *)
function Scanner.nextByte() : shortInt;
begin
  nextByte := Byte_.parseByte(getNextToken());
end;

(**
 * Scans the next token of the input as a short.
 *
 * @return the short scanned from the input
 *)
function Scanner.nextShort() : smallInt;
begin
  nextShort := Short.parseShort(getNextToken());
end;

(**
 * Scans the next token of the input as an int.
 *
 * @return the int scanned from the input
 *)
function Scanner.nextInt() : longInt;
begin
  nextInt := Integer_.parseInt(getNextToken());
end;

(**
 * Scans the next token of the input as a long.
 *
 * @return the long scanned from the input
 *)
function Scanner.nextLong() : int64;
begin
  nextLong := Long.parseLong(getNextToken());
end;

(**
 * Scans the next token of the input as a float.
 *
 * @return the float scanned from the input
 *)
function Scanner.nextFloat() : single;
begin
  nextFloat := Float.parseFloat(getNextToken());
end;

(**
 * Scans the next token of the input as a double.
 *
 * @return the double scanned from the input
 *)
function Scanner.nextDouble() : double;
begin
  nextDouble := Double_.parseDouble(getNextToken());
end;

(**
 * Advances this scanner past the current line and returns the input that was skipped.
 *
 * @return the line that was skipped
 *)
function Scanner.nextLine() : String_;
var
  str: String_;
begin
  if length(line) = 0 then begin
     exit(readLine());
  end;

  str := String_.create(line);
  line := '';
  nextLine := str;
end;

end.

