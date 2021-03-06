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
  PrintStream = class(Object_)
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
      procedure print(obj: Object_);
      procedure print(s: String_);
      procedure println();
      procedure println(x: boolean);
      procedure println(x: ansiChar);
      procedure println(x: array of ansiChar);
      procedure println(x: double);
      procedure println(x: single);
      procedure println(x: longInt);
      procedure println(x: int64);
      procedure println(x: Object_);
      procedure println(x: String_);
  end;

  (**
   * This abstract class is the superclass of all classes
   * representing an input stream of bytes.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  InputStream = class(Object_)
    // no code yet
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
        in_: InputStream;

        (**
         * The "standard" output stream.
         *)
        out_: PrintStream;
  end;

  // pointer to function for comparing the two specified values
  CompareFunction = function(a, b: pointer) : longInt;

  // comparator class for objects
  ObjectComparator = class(Comparator)
    public function compare(o1, o2: Object_) : longInt; override;
  end;

  // helper class containing the sorting algorithm implementations
  _java = class
    private
      class procedure merge(var arr, aux: array of Object_; left, right: longInt; c: Comparator);
    public
      class procedure mergeSort(var arr, aux: array of Object_; left, right: longInt; c: Comparator);
      class procedure quickSort(x: pointer; left, right, size: longInt; c: CompareFunction);
  end;

implementation

uses
  SysUtils;

(*
    Compares the two specified objects.
 *)
function ObjectComparator.compare(o1, o2: Object_) : longInt;
begin
  compare := (o1 as Comparable).compareTo(o2 as Comparable);
end;

(*
    Merges the specified subarrays for Merge sort.
 *)
class procedure _java.merge(var arr, aux: array of Object_; left, right: longInt; c: Comparator);
var
  middleIndex, leftIndex, rightIndex, auxIndex: longInt;
begin
  middleIndex := (left + right) div 2;
  leftIndex := left;
  rightIndex := middleIndex + 1;
  auxIndex := left;

  // moving elements to the auxilliary array until one of the indices leaves the specified boundary
  while (leftIndex <= middleIndex) and (rightIndex <= right) do begin
    // comparing the objects and setting the less one as the auxilliary array element
    if c.compare(arr[leftIndex], arr[rightIndex]) <= 0 then begin
      aux[auxIndex] := arr[leftIndex];
      inc(leftIndex);
    end
    else begin
      aux[auxIndex] := arr[rightIndex];
      inc(rightIndex);
    end;

    // incrementing the auxilliary array index
    inc(auxIndex);
  end;

  // setting the rest of the left subarray
  while leftIndex <= middleIndex do begin
    aux[auxIndex] := arr[leftIndex];
    inc(leftIndex);
    inc(auxIndex);
  end;

  // setting the rest of the right subarray
  while rightIndex <= right do begin
    aux[auxIndex] := arr[rightIndex];
    inc(rightIndex);
    inc(auxIndex);
  end;
end;

(*
    Implements the recursive Mergesort stable sorting algorithm for the object reference arrays.
 *)
class procedure _java.mergeSort(var arr, aux: array of Object_; left, right: longInt; c: Comparator);
var
  i, middleIndex: longInt;
begin
  if left = right then begin
    exit;
  end;

  // setting the middle index for splitting the specified array into subarrays
  middleIndex := (left + right) div 2;

  // sorting the left subarray recursively
  mergeSort(arr, aux, left, middleIndex, c);
  // sorting the right subarray recursively
  mergeSort(arr, aux, middleIndex + 1, right, c);
  // merging the sorted subarrays back into one array
  merge(arr, aux, left, right, c);

  // setting the values from the auxilliary array into original array
  for i := left to right do begin
    arr[i] := aux[i];
  end;
end;

(*
    Implements the recursive Quicksort unstable sorting algorithm for the primitive value arrays.
 *)
class procedure _java.quickSort(x: pointer; left, right, size: longInt; c: CompareFunction);
var
  i, j: longInt;
  tmpI, tmpJ, pivot: pointer;
  tmp: pointer;
begin
  i := left;
  j := right;
  // setting the pivot
  pivot := x + ((left + right) div 2) * size;

  // splitting the specified array into subarrays by the pivot
  repeat
    // comparing the values with the pivot to found the left boundary
    while c(pivot, x + i * size) > 0 do begin
      i := i + 1;
    end;

    // comparing the values with the pivot to found the right boundary
    while c(pivot, x + j * size) < 0 do begin
      j := j - 1;
    end;

    (* moving the elements so all the values to the left from the pivot are less
    and all the values to the right from the pivot are greater *)
    if i <= j then begin
      tmp := getmem(size);
      tmpI := x + i * size;
      tmpJ := x + j * size;

      move(tmpI^, tmp^, size);
      move(tmpJ^, tmpI^, size);
      move(tmp^, tmpJ^, size);

      j := j - 1;
      i := i + 1;
    end;
  until i > j;

  // sorting the left subarray recursively
  if left < j then begin
    quickSort(x, left, j, size, c);
  end;

  // sorting the right subarray recursively
  if i < right then begin
    quickSort(x, i, right, size, c);
  end;
end;

(*
    Converts the array of characters to the standard string.
 *)
class function PrintStream.charArrayToString(s: array of ansiChar): ansiString;
var
  str: ansiString;
  i: longInt;
begin
  str := '';

  // concatenating all the characters from the array to the string
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
  if b then begin
    write('true');
  end
  else begin
    write('false');
  end;
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
procedure PrintStream.print(obj: Object_);
begin
  write(obj.toString_().strProperty);
end;

(**
 * Prints a string.
 *
 * @param s The String to be printed
 *)
procedure PrintStream.print(s: String_);
begin
  write(s.strProperty);
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
  if x then begin
    writeLn('true');
  end
  else begin
    writeLn('false');
  end;
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
procedure PrintStream.println(x: Object_);
begin
  writeLn(x.toString_().strProperty);
end;

(**
 * Prints a String and then terminate the line.
 *
 * @param x The String to be printed.
 *)
procedure PrintStream.println(x: String_);
begin
  writeLn(x.strProperty);
end;

begin
  System_.in_ := InputStream.create();
  System_.out_ := PrintStream.create();
end.

