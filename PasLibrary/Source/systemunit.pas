unit SystemUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, Classes;

type
  PrintStream = class
    private
      class function charArrayToString(s: array of ansiChar): ansiString;
    public
      constructor create();
      destructor destroy(); override;
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
      procedure println(b: boolean);
      procedure println(c: ansiChar);
      procedure println(s: array of ansiChar);
      procedure println(d: double);
      procedure println(f: single);
      procedure println(i: longInt);
      procedure println(l: int64);
      procedure println(obj: TObject);
      procedure println(s: String_);
  end;

  System_ = class
    public
      class var
        in_: TObject;
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

constructor PrintStream.create();
begin
end;

destructor PrintStream.destroy();
begin
  inherited;
end;

procedure PrintStream.print(b: boolean);
begin
  write(b);
end;

procedure PrintStream.print(c: ansiChar);
begin
  write(c);
end;

procedure PrintStream.print(s: array of ansiChar);
begin
  write(charArrayToString(s));
end;

procedure PrintStream.print(d: double);
begin
  write(d);
end;

procedure PrintStream.print(f: single);
begin
  write(f);
end;

procedure PrintStream.print(i: longInt);
begin
  write(i);
end;

procedure PrintStream.print(l: int64);
begin
  write(l);
end;

procedure PrintStream.print(obj: TObject);
begin
  write(obj.toString);
end;

procedure PrintStream.print(s: String_);
begin
  write(s.toString);
end;

procedure PrintStream.println();
begin
  writeLn;
end;

procedure PrintStream.println(b: boolean);
begin
  writeLn(b);
end;

procedure PrintStream.println(c: ansiChar);
begin
  writeLn(c);
end;

procedure PrintStream.println(s: array of ansiChar);
begin
  writeLn(charArrayToString(s));
end;

procedure PrintStream.println(d: double);
begin
  writeLn(d);
end;

procedure PrintStream.println(f: single);
begin
  writeLn(f);
end;

procedure PrintStream.println(i: longInt);
begin
  writeLn(i);
end;

procedure PrintStream.println(l: int64);
begin
  writeLn(l);
end;

procedure PrintStream.println(obj: TObject);
begin
  writeLn(obj.toString);
end;

procedure PrintStream.println(s: String_);
begin
  writeLn(s.toString);
end;

end.

