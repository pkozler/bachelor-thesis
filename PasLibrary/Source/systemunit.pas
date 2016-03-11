unit SystemUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, Classes;

type
  (**
   * A PrintStream adds functionality to another output stream,
   * namely the ability to print representations of various data values conveniently.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  PrintStream = class
    private
      class function charArrayToString(s: array of ansiChar): ansiString;
    public
      procedure print(b: boolean);
      procedure print(c: ansiChar);
      procedure print(s: array of ansiChar);
      procedure print(d: double);
      procedure print(f: single);
      procedure print(i: longInt);
      procedure print(l: int64);
      procedure print(obj: TObject);
      procedure print(s: String_);
      procedure println();
      procedure println(x: boolean);
      procedure println(x: ansiChar);
      procedure println(x: array of ansiChar);
      procedure println(x: double);
      procedure println(x: single);
      procedure println(x: longInt);
      procedure println(x: int64);
      procedure println(x: TObject);
      procedure println(x: String_);
  end;

  (**
   * The System class contains several useful class fields and methods.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  System_ = class
    public
      class var
        (**
         * The "standard" input stream.
         *)
        in_: TObject;
        (**
         * The "standard" output stream.
         *)
        out_: PrintStream;
  end;

  CompareFunction = function(a, b: pointer) : longInt;
  TObjectCompareFunction = function(o1, o2: TObject) : longInt;

  _java = class
    private
      class procedure merge(arr, aux: array of TObject; left, right: longInt; compare: TObjectCompareFunction);
    public
      class procedure mergeSort(arr, aux: array of TObject; left, right: longInt; compare: TObjectCompareFunction);
      class procedure quickSort(x: pointer; left, right, size: longInt; compare: CompareFunction);
  end;

implementation

uses
  SysUtils;

class procedure _java.merge(arr, aux: array of TObject; left, right: longInt; compare: TObjectCompareFunction);
var
  middleIndex, leftIndex, rightIndex, auxIndex: longInt;
begin
  middleIndex := (left + right) div 2;
  leftIndex := left;
  rightIndex := middleIndex + 1;
  auxIndex := left;

  while (leftIndex <= middleIndex) and (rightIndex <= right) do begin
    if compare(arr[leftIndex], arr[rightIndex]) <= 0 then begin
      aux[auxIndex] := arr[leftIndex];
      inc(leftIndex);
    end
    else begin
      aux[auxIndex] := arr[rightIndex];
      inc(rightIndex);
    end;

    inc(auxIndex);
  end;

  while leftIndex <= middleIndex do begin
    aux[auxIndex] := arr[leftIndex];
    inc(leftIndex);
    inc(auxIndex);
  end;

  while rightIndex <= right do begin
    aux[auxIndex] := arr[rightIndex];
    inc(rightIndex);
    inc(auxIndex);
  end;
end;

class procedure _java.mergeSort(arr, aux: array of TObject; left, right: longInt; compare: TObjectCompareFunction);
var
  i, middleIndex: longInt;
begin
  if left = right then begin
    exit;
  end;

  middleIndex := (left + right) div 2;

  mergeSort(arr, aux, left, middleIndex, compare);
  mergeSort(arr, aux, middleIndex + 1, right, compare);
  merge(arr, aux, left, right, compare);

  for i := left to right do begin
    arr[i] := aux[i];
  end;
end;

class procedure _java.quickSort(x: pointer; left, right, size: longInt; compare: CompareFunction);
var
  i, j: longInt;
  tmpI, tmpJ, pivot: pointer;
  tmp: ^pointer;
begin
  i := left;
  j := right;
  pivot := x + ((left + right) div 2) * size;

  repeat
    while compare(pivot, x + i * size) > 0 do begin
      i := i + 1;
    end;

    while compare(pivot, x + j * size) < 0 do begin
      j := j - 1;
    end;

    if i <= j then begin
      tmp := nil;
      tmpI := x + i * size;
      tmpJ := x + j * size;

      move(tmpI, tmp, size);
      move(tmpJ, tmpI, size);
      move(tmp, tmpJ, size);

      j := j - 1;
      i := i + 1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j, size, compare);
  end;

  if i < right then begin
    quickSort(x, i, right, size, compare);
  end;
end;

class function PrintStream.charArrayToString(s: array of ansiChar): ansiString;
var
  str: ansiString;
  i: longInt;
begin
  str := '';

  for i := low(s) to high(s) do begin
    str := str + s[i];
  end;

  charArrayToString := str;
end;

(**
 * Prints a boolean value.
 *
 * @param b The boolean to be printed
 *)
procedure PrintStream.print(b: boolean);
begin
  write(b);
end;

(**
 * Prints a character.
 *
 * @param c The char to be printed
 *)
procedure PrintStream.print(c: ansiChar);
begin
  write(c);
end;

(**
 * Prints an array of characters.
 *
 * @param s The array of chars to be printed
 *)
procedure PrintStream.print(s: array of ansiChar);
begin
  write(charArrayToString(s));
end;

(**
 * Prints a double-precision floating-point number.
 *
 * @param d The double to be printed
 *)
procedure PrintStream.print(d: double);
begin
  write(d);
end;

(**
 * Prints a floating-point number.
 *
 * @param f The float to be printed
 *)
procedure PrintStream.print(f: single);
begin
  write(f);
end;

(**
 * Prints an integer.
 *
 * @param i The int to be printed
 *)
procedure PrintStream.print(i: longInt);
begin
  write(i);
end;

(**
 * Prints a long integer.
 *
 * @param l The long to be printed
 *)
procedure PrintStream.print(l: int64);
begin
  write(l);
end;

(**
 * Prints an object.
 *
 * @param obj The Object to be printed
 *)
procedure PrintStream.print(obj: TObject);
begin
  write(obj.toString);
end;

(**
 * Prints a string.
 *
 * @param s The String to be printed
 *)
procedure PrintStream.print(s: String_);
begin
  write(s.toString);
end;

(**
 * Terminates the current line by writing the line separator string.
 *)
procedure PrintStream.println();
begin
  writeLn;
end;

(**
 * Prints a boolean and then terminate the line.
 *
 * @param x The boolean to be printed
 *)
procedure PrintStream.println(x: boolean);
begin
  writeLn(x);
end;

(**
 * Prints a character and then terminate the line.
 *
 * @param x The char to be printed.
 *)
procedure PrintStream.println(x: ansiChar);
begin
  writeLn(x);
end;

(**
 * Prints an array of characters and then terminate the line.
 *
 * @param x an array of chars to print.
 *)
procedure PrintStream.println(x: array of ansiChar);
begin
  writeLn(charArrayToString(x));
end;

(**
 * Prints a double and then terminate the line.
 *
 * @param x The double to be printed.
 *)
procedure PrintStream.println(x: double);
begin
  writeLn(x);
end;

(**
 * Prints a float and then terminate the line.
 *
 * @param x The float to be printed.
 *)
procedure PrintStream.println(x: single);
begin
  writeLn(x);
end;

(**
 * Prints an integer and then terminate the line.
 *
 * @param x The int to be printed.
 *)
procedure PrintStream.println(x: longInt);
begin
  writeLn(x);
end;

(**
 * Prints a long and then terminate the line.
 *
 * @param x The long to be printed.
 *)
procedure PrintStream.println(x: int64);
begin
  writeLn(x);
end;

(**
 * Prints an Object and then terminate the line.
 *
 * @param x The Object to be printed.
 *)
procedure PrintStream.println(x: TObject);
begin
  writeLn(x.toString);
end;

(**
 * Prints a String and then terminate the line.
 *
 * @param x The String to be printed.
 *)
procedure PrintStream.println(x: String_);
begin
  writeLn(x.toString);
end;

end.

