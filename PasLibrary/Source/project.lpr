program project;

{$mode objfpc}{$H+}

uses
  MathUnit, StringUnit, CharacterUnit, IntegerUnit, SystemUnit, ScannerUnit,
  StringTokenizerUnit, ArraysUnit, CollectionsUnit, ArrayListUnit,
  LinkedListUnit, BooleanUnit, ByteUnit, ShortUnit, LongUnit, FloatUnit,
DoubleUnit, stringbuilderuint, unit1;

{class procedure Arrays.quickSort(x: array of shortInt; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: shortInt;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    while pivot > x[i] do begin
      i := i + 1;
    end;

    while pivot < x[j] do begin
      j := j - 1;
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.quickSort(x: array of ansiChar; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: ansiChar;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    while pivot > x[i] do begin
      i := i + 1;
    end;

    while pivot < x[j] do begin
      j := j - 1;
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.quickSort(x: array of double; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: double;
  d1, d2: Double_;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    d1 := Double_.create(pivot);
    d2 := Double_.create(x[i]);

    while d1.compareTo(d2) > 0 do begin
      i := i + 1;
      d2 := Double_.create(x[i]);
    end;

    d2 := Double_.create(x[j]);

    while d1.compareTo(d2) < 0 do begin
      j := j - 1;
      d2 := Double_.create(x[j]);
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.quickSort(x: array of single; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: single;
  f1, f2: Float;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    f1 := Float.create(pivot);
    f2 := Float.create(x[i]);

    while f1.compareTo(f2) > 0 do begin
      i := i + 1;
      f2 := Float.create(x[i]);
    end;

    f2 := Float.create(x[j]);

    while f1.compareTo(f2) < 0 do begin
      j := j - 1;
      f2 := Float.create(x[j]);
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.quickSort(x: array of longInt; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: longInt;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    while pivot > x[i] do begin
      i := i + 1;
    end;

    while pivot < x[j] do begin
      j := j - 1;
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.quickSort(x: array of int64; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: int64;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    while pivot > x[i] do begin
      i := i + 1;
    end;

    while pivot < x[j] do begin
      j := j - 1;
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.quickSort(x: array of smallInt; left, right: longInt);
var
  i, j: longInt;
  tmp, pivot: smallInt;
begin
  i := left;
  j := right;
  pivot := x[(left + right) div 2];

  repeat
    while pivot > x[i] do begin
      i := i + 1;
    end;

    while pivot < x[j] do begin
      j := j - 1;
    end;

    if i <= j then begin
      tmp := x[i];
      x[i] := x[j];
      x[j] := tmp;
      j := j-1;
      i := i+1;
    end;
  until i > j;

  if left < j then begin
    quickSort(x, left, j);
  end;

  if i < right then begin
    quickSort(x, i, right);
  end;
end;

class procedure Arrays.merge(arr, aux: array of TObject; left, right: longInt; compare: CompareFunction);
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

class procedure Arrays.mergeSort(arr, aux: array of TObject; left, right: longInt; compare: CompareFunction);
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
end;}

const
  ARR_LEN = 5;

var
  i: longInt;
  arr: array of longInt;
begin
  setLength(arr, ARR_LEN);
  writeLn(length(arr));

  for i := 0 to ARR_LEN - 1 do begin
    read(arr[i]);
  end;

  readLn();

  for i := 0 to ARR_LEN - 1 do begin
    writeLn(arr[i]);
  end;

  writeLn(Math_.PI);
  readLn();
end.
