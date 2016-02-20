unit ArraysUnit;

{$mode objfpc}{$H+}

interface

uses
  SystemUnit, StringUnit;

type
  PBoolean = ^boolean;
  PShortInt = ^shortInt;
  PAnsiChar = ^ansiChar;
  PDouble = ^double;
  PSingle = ^single;
  PLongInt = ^longInt;
  PInt64 = ^int64;
  PSmallInt = ^smallInt;

  BooleanArray = array of boolean;
  ShortIntArray = array of shortInt;
  AnsiCharArray = array of ansiChar;
  DoubleArray = array of double;
  SingleArray = array of single;
  LongIntArray = array of longInt;
  Int64Array = array of int64;
  SmallIntArray = array of smallInt;
  TObjectArray = array of TObject;

  EqualsFunction = function(a, b: pointer): boolean;
  TObjectEqualsFunction = function(o1, o2: TObject): boolean;
  ToStringFunction = function(a: pointer): String_;

  Arrays = class
    private
      class function binarySearchPointer(a: pointer; fromIndex, toIndex, size: longInt; key: pointer; c: CompareFunction) : longInt;
      class function binarySearchTObject(a: array of TObject; fromIndex, toIndex: longInt; key: TObject; c: TObjectCompareFunction) : longInt;
      class function copyOfRangePointer(original: pointer; length, size, from, to_: longInt) : pointer;
      class function copyOfRangeTObject(original: array of TObject; from, to_: longInt) : TObjectArray;
      class function equalsPointer(a: pointer; length: longInt; a2: pointer; length2, size: longInt; e: EqualsFunction) : boolean;
      class function equalsTObject(a: array of TObject; a2: array of TObject; e: TObjectEqualsFunction) : boolean;
      class procedure fillPointer(a: pointer; fromIndex, toIndex, size: longInt; val: pointer);
      class procedure fillTObject(a: array of TObject; fromIndex, toIndex: longInt; val: TObject);
      class procedure sortPointer(a: pointer; fromIndex, toIndex, size: longInt; c: CompareFunction);
      class procedure sortTObject(a: array of TObject; fromIndex, toIndex: longInt; c: TObjectCompareFunction);
      class function toStringPointer(a: pointer; length, size: longInt; ts: ToStringFunction) : String_;
      class function toStringTObject(a: array of TObject) : String_;
    public
      class function binarySearch(a: array of shortInt; key: shortInt) : longInt;
      class function binarySearch(a: array of shortInt; fromIndex: longInt; toIndex: longInt; key: shortInt) : longInt;
      class function binarySearch(a: array of ansiChar; key: ansiChar) : longInt;
      class function binarySearch(a: array of ansiChar; fromIndex: longInt; toIndex: longInt; key: ansiChar) : longInt;
      class function binarySearch(a: array of double; key: double) : longInt;
      class function binarySearch(a: array of double; fromIndex: longInt; toIndex: longInt; key: double) : longInt;
      class function binarySearch(a: array of single; key: single) : longInt;
      class function binarySearch(a: array of single; fromIndex: longInt; toIndex: longInt; key: single) : longInt;
      class function binarySearch(a: array of longInt; key: longInt) : longInt;
      class function binarySearch(a: array of longInt; fromIndex: longInt; toIndex: longInt; key: longInt) : longInt;
      class function binarySearch(a: array of int64; key: int64) : longInt;
      class function binarySearch(a: array of int64; fromIndex: longInt; toIndex: longInt; key: int64) : longInt;
      class function binarySearch(a: array of TObject; key: TObject; c: TObjectCompareFunction) : longInt;
      class function binarySearch(a: array of TObject; fromIndex: longInt; toIndex: longInt; key: TObject; c: TObjectCompareFunction) : longInt;
      class function binarySearch(a: array of smallInt; key: smallInt) : longInt;
      class function binarySearch(a: array of smallInt; fromIndex: longInt; toIndex: longInt; key: smallInt) : longInt;
      class function copyOf(original: array of boolean; newLength: longInt) : BooleanArray;
      class function copyOf(original: array of shortInt; newLength: longInt) : ShortIntArray;
      class function copyOf(original: array of ansiChar; newLength: longInt) : AnsiCharArray;
      class function copyOf(original: array of double; newLength: longInt) : DoubleArray;
      class function copyOf(original: array of single; newLength: longInt) : SingleArray;
      class function copyOf(original: array of longInt; newLength: longInt) : LongIntArray;
      class function copyOf(original: array of int64; newLength: longInt) : Int64Array;
      class function copyOf(original: array of smallInt; newLength: longInt) : SmallIntArray;
      class function copyOf(original: array of TObject; newLength: longInt) : TObjectArray;
      class function copyOfRange(original: array of boolean; from: longInt; to_: longInt) : BooleanArray;
      class function copyOfRange(original: array of shortInt; from: longInt; to_: longInt) : ShortIntArray;
      class function copyOfRange(original: array of ansiChar; from: longInt; to_: longInt) : AnsiCharArray;
      class function copyOfRange(original: array of double; from: longInt; to_: longInt) : DoubleArray;
      class function copyOfRange(original: array of single; from: longInt; to_: longInt) : SingleArray;
      class function copyOfRange(original: array of longInt; from: longInt; to_: longInt) : LongIntArray;
      class function copyOfRange(original: array of int64; from: longInt; to_: longInt) : Int64Array;
      class function copyOfRange(original: array of smallInt; from: longInt; to_: longInt) : SmallIntArray;
      class function copyOfRange(original: array of TObject; from: longInt; to_: longInt) : TObjectArray;
      class function equals(a: array of boolean; a2: array of boolean) : boolean;
      class function equals(a: array of shortInt; a2: array of shortInt) : boolean;
      class function equals(a: array of ansiChar; a2: array of ansiChar) : boolean;
      class function equals(a: array of double; a2: array of double) : boolean;
      class function equals(a: array of single; a2: array of single) : boolean;
      class function equals(a: array of longInt; a2: array of longInt) : boolean;
      class function equals(a: array of int64; a2: array of int64) : boolean;
      class function equals(a: array of TObject; a2: array of TObject) : boolean;
      class function equals(a: array of smallInt; a2: array of smallInt) : boolean;
      class procedure fill(a: array of boolean; val: boolean);
      class procedure fill(a: array of boolean; fromIndex: longInt; toIndex: longInt; val: boolean);
      class procedure fill(a: array of shortInt; val: shortInt);
      class procedure fill(a: array of shortInt; fromIndex: longInt; toIndex: longInt; val: shortInt);
      class procedure fill(a: array of ansiChar; val: ansiChar);
      class procedure fill(a: array of ansiChar; fromIndex: longInt; toIndex: longInt; val: ansiChar);
      class procedure fill(a: array of double; val: double);
      class procedure fill(a: array of double; fromIndex: longInt; toIndex: longInt; val: double);
      class procedure fill(a: array of single; val: single);
      class procedure fill(a: array of single; fromIndex: longInt; toIndex: longInt; val: single);
      class procedure fill(a: array of longInt; val: longInt);
      class procedure fill(a: array of longInt; fromIndex: longInt; toIndex: longInt; val: longInt);
      class procedure fill(a: array of int64; val: int64);
      class procedure fill(a: array of int64; fromIndex: longInt; toIndex: longInt; val: int64);
      class procedure fill(a: array of TObject; val: TObject);
      class procedure fill(a: array of TObject; fromIndex: longInt; toIndex: longInt; val: TObject);
      class procedure fill(a: array of smallInt; val: smallInt);
      class procedure fill(a: array of smallInt; fromIndex: longInt; toIndex: longInt; val: smallInt);
      class procedure sort(a: array of shortInt);
      class procedure sort(a: array of shortInt; fromIndex: longInt; toIndex: longInt);
      class procedure sort(a: array of ansiChar);
      class procedure sort(a: array of ansiChar; fromIndex: longInt; toIndex: longInt);
      class procedure sort(a: array of double);
      class procedure sort(a: array of double; fromIndex: longInt; toIndex: longInt);
      class procedure sort(a: array of single);
      class procedure sort(a: array of single; fromIndex: longInt; toIndex: longInt);
      class procedure sort(a: array of longInt);
      class procedure sort(a: array of longInt; fromIndex: longInt; toIndex: longInt);
      class procedure sort(a: array of int64);
      class procedure sort(a: array of int64; fromIndex: longInt; toIndex: longInt);
      class procedure sort(a: array of TObject; c: TObjectCompareFunction);
      class procedure sort(a: array of TObject; fromIndex: longInt; toIndex: longInt; c: TObjectCompareFunction);
      class procedure sort(a: array of smallInt);
      class procedure sort(a: array of smallInt; fromIndex: longInt; toIndex: longInt);
      class function toString(a: array of boolean) : String_;
      class function toString(a: array of shortInt) : String_;
      class function toString(a: array of ansiChar) : String_;
      class function toString(a: array of double) : String_;
      class function toString(a: array of single) : String_;
      class function toString(a: array of longInt) : String_;
      class function toString(a: array of int64) : String_;
      class function toString(a: array of TObject) : String_;
      class function toString(a: array of smallInt) : String_;
  end;

  function _compareB(a, b: pointer) : longInt;
  function _compareC(a, b: pointer) : longInt;
  function _compareD(a, b: pointer) : longInt;
  function _compareF(a, b: pointer) : longInt;
  function _compareI(a, b: pointer) : longInt;
  function _compareL(a, b: pointer) : longInt;
  function _compareS(a, b: pointer) : longInt;
  function _equalsBool(a, b: pointer) : boolean;
  function _equalsB(a, b: pointer) : boolean;
  function _equalsC(a, b: pointer) : boolean;
  function _equalsD(a, b: pointer) : boolean;
  function _equalsF(a, b: pointer) : boolean;
  function _equalsI(a, b: pointer) : boolean;
  function _equalsL(a, b: pointer) : boolean;
  function _equalsS(a, b: pointer) : boolean;
  function _toStringBool(a: pointer) : String_;
  function _toStringB(a: pointer) : String_;
  function _toStringC(a: pointer) : String_;
  function _toStringD(a: pointer) : String_;
  function _toStringF(a: pointer) : String_;
  function _toStringI(a: pointer) : String_;
  function _toStringL(a: pointer) : String_;
  function _toStringS(a: pointer) : String_;

implementation

uses
  BooleanUnit, ByteUnit, DoubleUnit, FloatUnit, CharacterUnit, IntegerUnit, LongUnit, ShortUnit, SysUtils, Classes;

function _compareB(a, b: pointer) : longInt;
begin
  _compareB := PShortInt(a)^ - PShortInt(b)^;
end;

function _compareC(a, b: pointer) : longInt;
begin
  _compareC := shortInt(PAnsiChar(a)^) - shortInt(PAnsiChar(b)^);
end;

function _compareD(a, b: pointer) : longInt;
var
  d1, d2: Double_;
begin
  d1 := Double_.create(PDouble(a)^);
  d2 := Double_.create(PDouble(b)^);
  _compareD := d1.compareTo(d2);
  freeAndNil(d1);
  freeAndNil(d2);
end;

function _compareF(a, b: pointer) : longInt;
var
  f1, f2: Float;
begin
  f1 := Float.create(PSingle(a)^);
  f2 := Float.create(PSingle(b)^);
  _compareF := f1.compareTo(f2);
  freeAndNil(f1);
  freeAndNil(f2);
end;

function _compareI(a, b: pointer) : longInt;
begin
  _compareI := PLongInt(a)^ - PLongInt(b)^;
end;

function _compareL(a, b: pointer) : longInt;
begin
  _compareL := PInt64(a)^ - PInt64(b)^;
end;

function _compareS(a, b: pointer) : longInt;
begin
  _compareS := PSmallInt(a)^ - PSmallInt(b)^;
end;

function _equalsBool(a, b: pointer) : boolean;
begin
  _equalsBool := PBoolean(a)^ = PBoolean(b)^;
end;

function _equalsB(a, b: pointer) : boolean;
begin
  _equalsB := PShortInt(a)^ = PShortInt(b)^;
end;

function _equalsC(a, b: pointer) : boolean;
begin
  _equalsC := PAnsiChar(a)^ = PAnsiChar(b)^;
end;

function _equalsD(a, b: pointer) : boolean;
var
  d1, d2: Double_;
begin
  d1 := Double_.create(PDouble(a)^);
  d2 := Double_.create(PDouble(b)^);
  _equalsD := d1.equals(d2);
  freeAndNil(d1);
  freeAndNil(d2);
end;

function _equalsF(a, b: pointer) : boolean;
var
  f1, f2: Float;
begin
  f1 := Float.create(PSingle(a)^);
  f2 := Float.create(PSingle(b)^);
  _equalsF := f1.equals(f2);
  freeAndNil(f1);
  freeAndNil(f2);
end;

function _equalsI(a, b: pointer) : boolean;
begin
  _equalsI := PLongInt(a)^ = PLongInt(b)^;
end;

function _equalsL(a, b: pointer) : boolean;
begin
  _equalsL := PInt64(a)^ = PInt64(b)^;
end;

function _equalsS(a, b: pointer) : boolean;
begin
  _equalsS := PSmallInt(a)^ = PSmallInt(b)^;
end;

function _equalsObj(o1, o2: TObject) : boolean;
begin
  if o1 = nil then begin
    _equalsObj := (o2 = nil);
  end
  else begin
    _equalsObj := o1.Equals(o2);
  end;
end;

function _toStringBool(a: pointer) : String_;
begin
  _toStringBool := Boolean_.toString(PBoolean(a)^);
end;

function _toStringB(a: pointer) : String_;
begin
  _toStringB := Byte_.toString(PShortInt(a)^);
end;

function _toStringC(a: pointer) : String_;
begin
  _toStringC := Character.toString(PAnsiChar(a)^);
end;

function _toStringD(a: pointer) : String_;
begin
  _toStringD := Double_.toString(PDouble(a)^);
end;

function _toStringF(a: pointer) : String_;
begin
  _toStringF := Float.toString(PSingle(a)^);
end;

function _toStringI(a: pointer) : String_;
begin
  _toStringI := Integer_.toString(PLongInt(a)^);
end;

function _toStringL(a: pointer) : String_;
begin
  _toStringL := Long.toString(PInt64(a)^);
end;

function _toStringS(a: pointer) : String_;
begin
  _toStringS := Short.toString(PSmallInt(a)^);
end;

class function Arrays.binarySearchPointer(a: pointer; fromIndex, toIndex, size: longInt; key: pointer; c: CompareFunction) : longInt;
var
  l, m, h, index: longInt;
begin
  l := fromIndex;
  h := toIndex - 1;
  index := -1;

  while l <= h do begin
    m := (l + h) div 2;

    if c(a + m * size, key) > 0 then begin
      h := m - 1;
    end
    else if c(a + m * size, key) < 0 then begin
      l := m + 1;
    end
    else begin
      index := m;
      break;
    end;
  end;

  binarySearchPointer := index;
end;

class function Arrays.binarySearchTObject(a: array of TObject; fromIndex, toIndex: longInt; key: TObject; c: TObjectCompareFunction) : longInt;
var
  l, m, h, index: longInt;
begin
  l := fromIndex;
  h := toIndex - 1;
  index := -1;

  while l <= h do begin
    m := (l + h) div 2;

    if c(a[m], key) > 0 then begin
      h := m - 1;
    end
    else if c(a[m], key) < 0 then begin
      l := m + 1;
    end
    else begin
      index := m;
      break;
    end;
  end;

  binarySearchTObject := index;
end;

class function Arrays.copyOfRangePointer(original: pointer; length, size, from, to_: longInt) : pointer;
var
  src, dest, a: pointer;
  i, zero: longInt;
begin
  a := getmem(size * (to_ - from));

  if to_ > length then begin
    for i := from to length - 1 do begin
      src := original + i * size;
      dest := a + (i - from) * size;
      move(src, dest, size);
    end;

    zero := 0;

    for i := length to to_ - 1 do begin
      src := @zero;
      dest := a + (i - from) * size;
      move(src, dest, size);
    end;
  end
  else begin
    for i := from to to_ - 1 do begin
      src := original + i * size;
      dest := a + (i - from) * size;
      move(src, dest, size);
    end;
  end;

  copyOfRangePointer := a;
end;

class function Arrays.copyOfRangeTObject(original: array of TObject; from, to_: longInt) : TObjectArray;
var
  a: array of TObject;
  len, i: longInt;
begin
  setLength(a, to_ - from);
  len := length(original);

  if to_ > len then begin
    for i := from to len - 1 do begin
      a[i - from] := original[i];
    end;

    for i := len to to_ - 1 do begin
      a[i - from] := nil;
    end;
  end
  else begin
    for i := from to to_ - 1 do begin
      a[i - from] := original[i];
    end;
  end;

  copyOfRangeTObject := a;
end;

class function Arrays.equalsPointer(a: pointer; length: longInt; a2: pointer; length2, size: longInt; e: EqualsFunction) : boolean;
var
  i: longInt;
begin
  if a = a2 then begin
    exit(true);
  end;

  if length2 <> length then begin
    exit(false);
  end;

  for i := 0 to length - 1 do begin
    if not e(a + i * size, a2 + i * size) then begin
      exit(false);
    end;
  end;

  equalsPointer := true;
end;

class function Arrays.equalsTObject(a: array of TObject; a2: array of TObject; e: TObjectEqualsFunction) : boolean;
var
  len, i: longInt;
begin
  if @a = @a2 then begin
    exit(true);
  end;

  len := length(a);

  if length(a2) <> len then begin
    exit(false);
  end;

  for i := 0 to len - 1 do begin
    if not e(a[i], a2[i]) then begin
      exit(false);
    end;
  end;

  equalsTObject := true;
end;

class procedure Arrays.fillPointer(a: pointer; fromIndex, toIndex, size: longInt; val: pointer);
var
  i: longInt;
  dest: pointer;
begin
  for i := fromIndex to toIndex - 1 do begin
    dest := a + i * size;
    move(val, dest, size);
  end;
end;

class procedure Arrays.fillTObject(a: array of TObject; fromIndex, toIndex: longInt; val: TObject);
var
  i: longInt;
begin
  for i := fromIndex to toIndex - 1 do begin
    a[i] := val;
  end;
end;

class procedure Arrays.sortPointer(a: pointer; fromIndex, toIndex, size: longInt; c: CompareFunction);
begin
  _java.quickSort(a, fromIndex, toIndex, size, c);
end;

class procedure Arrays.sortTObject(a: array of TObject; fromIndex, toIndex: longInt; c: TObjectCompareFunction);
var
  aux: array of TObject;
begin
  setLength(aux, toIndex - fromIndex);
  _java.mergeSort(a, aux, fromIndex, toIndex, c);
end;

class function Arrays.toStringPointer(a: pointer; length, size: longInt; ts: ToStringFunction) : String_;
var
  str, s: String_;
  buf: ansiString;
  i: longInt;
begin
  buf := '[';

  if length > 0 then begin
    s := ts(a);
    buf += s.toString();
    freeAndNil(s);
  end;

  for i := 1 to length - 1 do begin
    s := ts(a + i);
    buf += ', ' + s.toString();
    freeAndNil(s);
  end;

  buf += ']';
  str.create(buf);
  toStringPointer := str;
end;

class function Arrays.toStringTObject(a: array of TObject) : String_;
var
  str, s: String_;
  buf: ansiString;
  len, i: longInt;
begin
  len := length(a);
  buf := '[';

  if len > 0 then begin
    s := a[0].toString();
    buf += s.toString();
    freeAndNil(s);
  end;

  for i := 1 to len - 1 do begin
    s := a[i].toString();
    buf += ', ' + s.toString();
    freeAndNil(s);
  end;

  buf += ']';
  str.create(buf);
  toStringTObject := str;
end;

class function Arrays.binarySearch(a: array of shortInt; key: shortInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(shortInt), @key, @_compareB);
end;

class function Arrays.binarySearch(a: array of shortInt; fromIndex: longInt; toIndex: longInt; key: shortInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(shortInt), @key, @_compareB);
end;

class function Arrays.binarySearch(a: array of ansiChar; key: ansiChar) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(ansiChar), @key, @_compareC);
end;

class function Arrays.binarySearch(a: array of ansiChar; fromIndex: longInt; toIndex: longInt; key: ansiChar) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(ansiChar), @key, @_compareC);
end;

class function Arrays.binarySearch(a: array of double; key: double) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(double), @key, @_compareD);
end;

class function Arrays.binarySearch(a: array of double; fromIndex: longInt; toIndex: longInt; key: double) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(double), @key, @_compareD);
end;

class function Arrays.binarySearch(a: array of single; key: single) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(single), @key, @_compareF);
end;

class function Arrays.binarySearch(a: array of single; fromIndex: longInt; toIndex: longInt; key: single) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(single), @key, @_compareF);
end;

class function Arrays.binarySearch(a: array of longInt; key: longInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(longInt), @key, @_compareI);
end;

class function Arrays.binarySearch(a: array of longInt; fromIndex: longInt; toIndex: longInt; key: longInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(longInt), @key, @_compareI);
end;

class function Arrays.binarySearch(a: array of int64; key: int64) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(int64), @key, @_compareL);
end;

class function Arrays.binarySearch(a: array of int64; fromIndex: longInt; toIndex: longInt; key: int64) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(int64), @key, @_compareL);
end;

class function Arrays.binarySearch(a: array of TObject; key: TObject; c: TObjectCompareFunction) : longInt;
begin
  binarySearch := binarySearchTObject(a, 0, length(a), key, c);
end;

class function Arrays.binarySearch(a: array of TObject; fromIndex: longInt; toIndex: longInt; key: TObject; c: TObjectCompareFunction) : longInt;
begin
  binarySearch := binarySearchTObject(a, fromIndex, toIndex, key, c);
end;

class function Arrays.binarySearch(a: array of smallInt; key: smallInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(smallInt), @key, @_compareS);
end;

class function Arrays.binarySearch(a: array of smallInt; fromIndex: longInt; toIndex: longInt; key: smallInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(smallInt), @key, @_compareS);
end;

class function Arrays.copyOf(original: array of boolean; newLength: longInt) : BooleanArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(boolean), 0, newLength);
end;

class function Arrays.copyOf(original: array of shortInt; newLength: longInt) : ShortIntArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(shortInt), 0, newLength);
end;

class function Arrays.copyOf(original: array of ansiChar; newLength: longInt) : AnsiCharArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(ansiChar), 0, newLength);
end;

class function Arrays.copyOf(original: array of double; newLength: longInt) : DoubleArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(double), 0, newLength);
end;

class function Arrays.copyOf(original: array of single; newLength: longInt) : SingleArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(single), 0, newLength);
end;

class function Arrays.copyOf(original: array of longInt; newLength: longInt) : LongIntArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(longInt), 0, newLength);
end;

class function Arrays.copyOf(original: array of int64; newLength: longInt) : Int64Array;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(int64), 0, newLength);
end;

class function Arrays.copyOf(original: array of smallInt; newLength: longInt) : SmallIntArray;
begin
  copyOf := copyOfRangePointer(@original[0], length(original), sizeOf(smallInt), 0, newLength);
end;

class function Arrays.copyOf(original: array of TObject; newLength: longInt) : TObjectArray;
begin
  copyOf := copyOfRangeTObject(original, 0, newLength);
end;

class function Arrays.copyOfRange(original: array of boolean; from: longInt; to_: longInt) : BooleanArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(boolean), from, to_);
end;

class function Arrays.copyOfRange(original: array of shortInt; from: longInt; to_: longInt) : ShortIntArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(shortInt), from, to_);
end;

class function Arrays.copyOfRange(original: array of ansiChar; from: longInt; to_: longInt) : AnsiCharArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(ansiChar), from, to_);
end;

class function Arrays.copyOfRange(original: array of double; from: longInt; to_: longInt) : DoubleArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(double), from, to_);
end;

class function Arrays.copyOfRange(original: array of single; from: longInt; to_: longInt) : SingleArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(single), from, to_);
end;

class function Arrays.copyOfRange(original: array of longInt; from: longInt; to_: longInt) : LongIntArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(longInt), from, to_);
end;

class function Arrays.copyOfRange(original: array of int64; from: longInt; to_: longInt) : Int64Array;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(int64), from, to_);
end;

class function Arrays.copyOfRange(original: array of smallInt; from: longInt; to_: longInt) : SmallIntArray;
begin
  copyOfRange := copyOfRangePointer(@original[0], length(original), sizeOf(smallInt), from, to_);
end;

class function Arrays.copyOfRange(original: array of TObject; from: longInt; to_: longInt) : TObjectArray;
begin
  copyOfRange := copyOfRangeTObject(original, from, to_);
end;

class function Arrays.equals(a: array of boolean; a2: array of boolean) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(boolean), @_equalsBool);
end;

class function Arrays.equals(a: array of shortInt; a2: array of shortInt) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(shortInt), @_equalsB);
end;

class function Arrays.equals(a: array of ansiChar; a2: array of ansiChar) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(ansiChar), @_equalsC);
end;

class function Arrays.equals(a: array of double; a2: array of double) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(double), @_equalsD);
end;

class function Arrays.equals(a: array of single; a2: array of single) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(single), @_equalsF);
end;

class function Arrays.equals(a: array of longInt; a2: array of longInt) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(longInt), @_equalsI);
end;

class function Arrays.equals(a: array of int64; a2: array of int64) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(int64), @_equalsL);
end;

class function Arrays.equals(a: array of TObject; a2: array of TObject) : boolean;
begin
  equals := equalsTObject(a, a2, @_equalsObj);
end;

class function Arrays.equals(a: array of smallInt; a2: array of smallInt) : boolean;
begin
  equals := equalsPointer(@a[0], length(a), @a2[0], length(a2), sizeOf(smallInt), @_equalsS);
end;

class procedure Arrays.fill(a: array of boolean; val: boolean);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(boolean), @val);
end;

class procedure Arrays.fill(a: array of boolean; fromIndex: longInt; toIndex: longInt; val: boolean);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(boolean), @val);
end;

class procedure Arrays.fill(a: array of shortInt; val: shortInt);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(shortInt), @val);
end;

class procedure Arrays.fill(a: array of shortInt; fromIndex: longInt; toIndex: longInt; val: shortInt);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(shortInt), @val);
end;

class procedure Arrays.fill(a: array of ansiChar; val: ansiChar);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(ansiChar), @val);
end;

class procedure Arrays.fill(a: array of ansiChar; fromIndex: longInt; toIndex: longInt; val: ansiChar);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(ansiChar), @val);
end;

class procedure Arrays.fill(a: array of double; val: double);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(double), @val);
end;

class procedure Arrays.fill(a: array of double; fromIndex: longInt; toIndex: longInt; val: double);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(double), @val);
end;

class procedure Arrays.fill(a: array of single; val: single);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(single), @val);
end;

class procedure Arrays.fill(a: array of single; fromIndex: longInt; toIndex: longInt; val: single);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(single), @val);
end;

class procedure Arrays.fill(a: array of longInt; val: longInt);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(longInt), @val);
end;

class procedure Arrays.fill(a: array of longInt; fromIndex: longInt; toIndex: longInt; val: longInt);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(longInt), @val);
end;

class procedure Arrays.fill(a: array of int64; val: int64);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(int64), @val);
end;

class procedure Arrays.fill(a: array of int64; fromIndex: longInt; toIndex: longInt; val: int64);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(int64), @val);
end;

class procedure Arrays.fill(a: array of TObject; val: TObject);
begin
  fillTObject(a, 0, length(a), val);
end;

class procedure Arrays.fill(a: array of TObject; fromIndex: longInt; toIndex: longInt; val: TObject);
begin
  fillTObject(a, fromIndex, toIndex, val);
end;

class procedure Arrays.fill(a: array of smallInt; val: smallInt);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(smallInt), @val);
end;

class procedure Arrays.fill(a: array of smallInt; fromIndex: longInt; toIndex: longInt; val: smallInt);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(smallInt), @val);
end;

class procedure Arrays.sort(a: array of shortInt);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(shortInt), @_compareB);
end;

class procedure Arrays.sort(a: array of shortInt; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(shortInt), @_compareB);
end;

class procedure Arrays.sort(a: array of ansiChar);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(ansiChar), @_compareC);
end;

class procedure Arrays.sort(a: array of ansiChar; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(ansiChar), @_compareC);
end;

class procedure Arrays.sort(a: array of double);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(double), @_compareD);
end;

class procedure Arrays.sort(a: array of double; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(double), @_compareD);
end;

class procedure Arrays.sort(a: array of single);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(single), @_compareF);
end;

class procedure Arrays.sort(a: array of single; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(single), @_compareF);
end;

class procedure Arrays.sort(a: array of longInt);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(longInt), @_compareI);
end;

class procedure Arrays.sort(a: array of longInt; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(longInt), @_compareI);
end;

class procedure Arrays.sort(a: array of int64);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(int64), @_compareL);
end;

class procedure Arrays.sort(a: array of int64; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(int64), @_compareL);
end;

class procedure Arrays.sort(a: array of TObject; c: TObjectCompareFunction);
begin
  sortTObject(a, 0, length(a), c);
end;

class procedure Arrays.sort(a: array of TObject; fromIndex: longInt; toIndex: longInt; c: TObjectCompareFunction);
begin
  sortTObject(a, fromIndex, toIndex, c);
end;

class procedure Arrays.sort(a: array of smallInt);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(smallInt), @_compareS);
end;

class procedure Arrays.sort(a: array of smallInt; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(smallInt), @_compareS);
end;

class function Arrays.toString(a: array of boolean) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(boolean), @_toStringBool);
end;

class function Arrays.toString(a: array of shortInt) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(shortInt), @_toStringB);
end;

class function Arrays.toString(a: array of ansiChar) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(ansiChar), @_toStringC);
end;

class function Arrays.toString(a: array of double) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(double), @_toStringD);
end;

class function Arrays.toString(a: array of single) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(single), @_toStringF);
end;

class function Arrays.toString(a: array of longInt) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(longInt), @_toStringI);
end;

class function Arrays.toString(a: array of int64) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(int64), @_toStringL);
end;

class function Arrays.toString(a: array of TObject) : String_;
begin
  toString := toStringTObject(a);
end;

class function Arrays.toString(a: array of smallInt) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(smallInt), @_toStringS);
end;

end.
