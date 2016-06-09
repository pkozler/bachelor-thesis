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
  ObjectArray = array of Object_;

  EqualsFunction = function(a, b: pointer): boolean;
  ToStringFunction = function(a: pointer): String_;

  (**
   * This class contains various methods for manipulating arrays (such as sorting and searching).
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Arrays = class
    private
      class function binarySearchPointer(a: pointer; fromIndex, toIndex, size: longInt; key: pointer; c: CompareFunction) : longInt;
      class function binarySearchObject(var a: array of Object_; fromIndex, toIndex: longInt; key: Object_; c: Comparator) : longInt;
      class function copyOfRangePointer(original, copyArray: pointer; length, size, from, to_: longInt; defaultValue: pointer) : pointer;
      class function copyOfRangeObject(var original: array of Object_; from, to_: longInt) : ObjectArray;
      class function equalsPointer(a: pointer; length: longInt; a2: pointer; length2, size: longInt; e: EqualsFunction) : boolean;
      class function equalsObject(var a: array of Object_; a2: array of Object_) : boolean;
      class procedure fillPointer(a: pointer; fromIndex, toIndex, size: longInt; val: pointer);
      class procedure fillObject(var a: array of Object_; fromIndex, toIndex: longInt; val: Object_);
      class procedure sortPointer(a: pointer; fromIndex, toIndex, size: longInt; c: CompareFunction);
      class procedure sortObject(var a: array of Object_; fromIndex, toIndex: longInt; c: Comparator);
      class function toStringPointer(a: pointer; length, size: longInt; ts: ToStringFunction) : String_;
      class function toStringObject(var a: array of Object_) : String_;
    public
      class function binarySearch(var a: array of shortInt; key: shortInt) : longInt;
      class function binarySearch(var a: array of shortInt; fromIndex: longInt; toIndex: longInt; key: shortInt) : longInt;
      class function binarySearch(var a: array of ansiChar; key: ansiChar) : longInt;
      class function binarySearch(var a: array of ansiChar; fromIndex: longInt; toIndex: longInt; key: ansiChar) : longInt;
      class function binarySearch(var a: array of double; key: double) : longInt;
      class function binarySearch(var a: array of double; fromIndex: longInt; toIndex: longInt; key: double) : longInt;
      class function binarySearch(var a: array of single; key: single) : longInt;
      class function binarySearch(var a: array of single; fromIndex: longInt; toIndex: longInt; key: single) : longInt;
      class function binarySearch(var a: array of longInt; key: longInt) : longInt;
      class function binarySearch(var a: array of longInt; fromIndex: longInt; toIndex: longInt; key: longInt) : longInt;
      class function binarySearch(var a: array of int64; key: int64) : longInt;
      class function binarySearch(var a: array of int64; fromIndex: longInt; toIndex: longInt; key: int64) : longInt;
      class function binarySearch(var a: array of Object_; key: Object_) : longInt;
      class function binarySearch(var a: array of Object_; fromIndex: longInt; toIndex: longInt; key: Object_) : longInt;
      class function binarySearch(var a: array of smallInt; key: smallInt) : longInt;
      class function binarySearch(var a: array of smallInt; fromIndex: longInt; toIndex: longInt; key: smallInt) : longInt;
      class function binarySearch(var a: array of Object_; key: Object_; c: Comparator) : longInt;
      class function binarySearch(var a: array of Object_; fromIndex: longInt; toIndex: longInt; key: Object_; c: Comparator) : longInt;
      class function copyOf(var original: array of boolean; newLength: longInt) : BooleanArray;
      class function copyOf(var original: array of shortInt; newLength: longInt) : ShortIntArray;
      class function copyOf(var original: array of ansiChar; newLength: longInt) : AnsiCharArray;
      class function copyOf(var original: array of double; newLength: longInt) : DoubleArray;
      class function copyOf(var original: array of single; newLength: longInt) : SingleArray;
      class function copyOf(var original: array of longInt; newLength: longInt) : LongIntArray;
      class function copyOf(var original: array of int64; newLength: longInt) : Int64Array;
      class function copyOf(var original: array of smallInt; newLength: longInt) : SmallIntArray;
      class function copyOf(var original: array of Object_; newLength: longInt) : ObjectArray;
      class function copyOfRange(var original: array of boolean; from: longInt; to_: longInt) : BooleanArray;
      class function copyOfRange(var original: array of shortInt; from: longInt; to_: longInt) : ShortIntArray;
      class function copyOfRange(var original: array of ansiChar; from: longInt; to_: longInt) : AnsiCharArray;
      class function copyOfRange(var original: array of double; from: longInt; to_: longInt) : DoubleArray;
      class function copyOfRange(var original: array of single; from: longInt; to_: longInt) : SingleArray;
      class function copyOfRange(var original: array of longInt; from: longInt; to_: longInt) : LongIntArray;
      class function copyOfRange(var original: array of int64; from: longInt; to_: longInt) : Int64Array;
      class function copyOfRange(var original: array of smallInt; from: longInt; to_: longInt) : SmallIntArray;
      class function copyOfRange(var original: array of Object_; from: longInt; to_: longInt) : ObjectArray;
      class function equals(a: array of boolean; a2: array of boolean) : boolean;
      class function equals(a: array of shortInt; a2: array of shortInt) : boolean;
      class function equals(a: array of ansiChar; a2: array of ansiChar) : boolean;
      class function equals(a: array of double; a2: array of double) : boolean;
      class function equals(a: array of single; a2: array of single) : boolean;
      class function equals(a: array of longInt; a2: array of longInt) : boolean;
      class function equals(a: array of int64; a2: array of int64) : boolean;
      class function equals(a: array of Object_; a2: array of Object_) : boolean;
      class function equals(a: array of smallInt; a2: array of smallInt) : boolean;
      class procedure fill(var a: array of boolean; val: boolean);
      class procedure fill(var a: array of boolean; fromIndex: longInt; toIndex: longInt; val: boolean);
      class procedure fill(var a: array of shortInt; val: shortInt);
      class procedure fill(var a: array of shortInt; fromIndex: longInt; toIndex: longInt; val: shortInt);
      class procedure fill(var a: array of ansiChar; val: ansiChar);
      class procedure fill(var a: array of ansiChar; fromIndex: longInt; toIndex: longInt; val: ansiChar);
      class procedure fill(var a: array of double; val: double);
      class procedure fill(var a: array of double; fromIndex: longInt; toIndex: longInt; val: double);
      class procedure fill(var a: array of single; val: single);
      class procedure fill(var a: array of single; fromIndex: longInt; toIndex: longInt; val: single);
      class procedure fill(var a: array of longInt; val: longInt);
      class procedure fill(var a: array of longInt; fromIndex: longInt; toIndex: longInt; val: longInt);
      class procedure fill(var a: array of int64; val: int64);
      class procedure fill(var a: array of int64; fromIndex: longInt; toIndex: longInt; val: int64);
      class procedure fill(var a: array of Object_; val: Object_);
      class procedure fill(var a: array of Object_; fromIndex: longInt; toIndex: longInt; val: Object_);
      class procedure fill(var a: array of smallInt; val: smallInt);
      class procedure fill(var a: array of smallInt; fromIndex: longInt; toIndex: longInt; val: smallInt);
      class procedure sort(var a: array of shortInt);
      class procedure sort(var a: array of shortInt; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of ansiChar);
      class procedure sort(var a: array of ansiChar; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of double);
      class procedure sort(var a: array of double; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of single);
      class procedure sort(var a: array of single; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of longInt);
      class procedure sort(var a: array of longInt; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of int64);
      class procedure sort(var a: array of int64; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of Object_);
      class procedure sort(var a: array of Object_; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of smallInt);
      class procedure sort(var a: array of smallInt; fromIndex: longInt; toIndex: longInt);
      class procedure sort(var a: array of Object_; c: Comparator);
      class procedure sort(var a: array of Object_; fromIndex: longInt; toIndex: longInt; c: Comparator);
      class function toString(var a: array of boolean) : String_;
      class function toString(var a: array of shortInt) : String_;
      class function toString(var a: array of ansiChar) : String_;
      class function toString(var a: array of double) : String_;
      class function toString(var a: array of single) : String_;
      class function toString(var a: array of longInt) : String_;
      class function toString(var a: array of int64) : String_;
      class function toString(var a: array of Object_) : String_;
      class function toString(var a: array of smallInt) : String_;
  end;

implementation

uses
  BooleanUnit, ByteUnit, DoubleUnit, FloatUnit, CharacterUnit, IntegerUnit, LongUnit, ShortUnit, StringBuilderUnit, SysUtils, Classes;

var
  defaultBoolean: boolean = false;
  defaultByte: shortInt = 0;
  defaultShort: smallInt = 0;
  defaultInt: longInt = 0;
  defaultLong: int64 = 0;
  defaultFloat: single = 0;
  defaultDouble: double = 0;
  defaultChar: ansiChar = #0;

function _compareB(a, b: pointer) : longInt;
begin
  _compareB := Byte_.compare(PShortInt(a)^, PShortInt(b)^);
end;

function _compareC(a, b: pointer) : longInt;
begin
  _compareC := Character.compare(PAnsiChar(a)^, PAnsiChar(b)^);
end;

function _compareD(a, b: pointer) : longInt;
begin
  _compareD := Double_.compare(PDouble(a)^, PDouble(b)^);
end;

function _compareF(a, b: pointer) : longInt;
begin
  _compareF := Float.compare(PSingle(a)^, PSingle(b)^);
end;

function _compareI(a, b: pointer) : longInt;
begin
  _compareI := Integer_.compare(PLongInt(a)^, PLongInt(b)^);
end;

function _compareL(a, b: pointer) : longInt;
begin
  _compareL := Long.compare(PInt64(a)^, PInt64(b)^);
end;

function _compareS(a, b: pointer) : longInt;
begin
  _compareS := Short.compare(PSmallInt(a)^, PSmallInt(b)^);
end;

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

function _equalsC(a, b: pointer) : boolean;
var
  x, y: Character;
begin
  x := Character.create(PAnsiChar(a)^);
  y := Character.create(PAnsiChar(b)^);
  _equalsC := x.equals(y);
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

function _equalsObj(o1, o2: Object_) : boolean;
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
  _toStringBool := Boolean_.toString_(PBoolean(a)^);
end;

function _toStringB(a: pointer) : String_;
begin
  _toStringB := Byte_.toString_(PShortInt(a)^);
end;

function _toStringC(a: pointer) : String_;
begin
  _toStringC := Character.toString_(PAnsiChar(a)^);
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

class function Arrays.binarySearchPointer(a: pointer; fromIndex, toIndex, size: longInt; key: pointer; c: CompareFunction) : longInt;
var
  lower, upper, middle : longInt;
  middleValue : pointer;
begin
  lower := fromIndex;
  upper := toIndex - 1;

  while lower <= upper do begin
    middle := lower + ((upper - lower) div 2);
    middleValue := a + middle * size;

    if c(middleValue, key) < 0 then begin
      lower := middle + 1;
    end
    else if c(middleValue, key) > 0 then begin
      upper := middle - 1;
    end
    else begin
      exit(middle);
    end;
  end;

  binarySearchPointer := -(lower + 1);
end;

class function Arrays.binarySearchObject(var a: array of Object_; fromIndex, toIndex: longInt; key: Object_; c: Comparator) : longInt;
var
  lower, upper, middle : longInt;
  middleValue : Object_;
begin
  lower := fromIndex;
  upper := toIndex - 1;

  while lower <= upper do begin
    middle := lower + ((upper - lower) div 2);
    middleValue := a[middle];

    if c.compare(middleValue, key) < 0 then begin
      lower := middle + 1;
    end
    else if c.compare(middleValue, key) > 0 then begin
      upper := middle - 1;
    end
    else begin
      exit(middle);
    end;
  end;

  binarySearchObject := -(lower + 1);
end;

class function Arrays.copyOfRangePointer(original, copyArray: pointer; length, size, from, to_: longInt; defaultValue: pointer) : pointer;
var
  src, dest: pointer;
  i: longInt;
begin
  if to_ > length then begin
    for i := from to length - 1 do begin
      src := original + i * size;
      dest := copyArray + (i - from) * size;
      move(src^, dest^, size);
    end;

    for i := length to to_ - 1 do begin
      src := defaultValue;
      dest := copyArray + (i - from) * size;
      move(src^, dest^, size);
    end;
  end
  else begin
    for i := from to to_ - 1 do begin
      src := original + i * size;
      dest := copyArray + (i - from) * size;
      move(src^, dest^, size);
    end;
  end;

  copyOfRangePointer := copyArray;
end;

class function Arrays.copyOfRangeObject(var original: array of Object_; from, to_: longInt) : ObjectArray;
var
  a: array of Object_;
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

  copyOfRangeObject := a;
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

class function Arrays.equalsObject(var a: array of Object_; a2: array of Object_) : boolean;
var
  len, i: longInt;
  e: boolean;
begin
  len := length(a);

  if length(a2) <> len then begin
    exit(false);
  end;

  for i := 0 to len - 1 do begin
    if a[i] = nil then begin
      e := a2[i] = nil;
    end
    else begin
      e := a[i].equals_(a2[i]);
    end;

    if not e then begin
      exit(false);
    end;
  end;

  equalsObject := true;
end;

class procedure Arrays.fillPointer(a: pointer; fromIndex, toIndex, size: longInt; val: pointer);
var
  i: longInt;
  dest: pointer;
begin

  for i := fromIndex to toIndex - 1 do begin
    dest := a + i * size;
    move(val^, dest^, size);
  end;
end;

class procedure Arrays.fillObject(var a: array of Object_; fromIndex, toIndex: longInt; val: Object_);
var
  i: longInt;
begin
  for i := fromIndex to toIndex - 1 do begin
    a[i] := val;
  end;
end;

class procedure Arrays.sortPointer(a: pointer; fromIndex, toIndex, size: longInt; c: CompareFunction);
begin
  _java.quickSort(a, fromIndex, toIndex - 1, size, c);
end;

class procedure Arrays.sortObject(var a: array of Object_; fromIndex, toIndex: longInt; c: Comparator);
var
  aux: array of Object_;
begin
  setLength(aux, toIndex - fromIndex);
  _java.mergeSort(a, aux, fromIndex, toIndex - 1, c);
end;

class function Arrays.toStringPointer(a: pointer; length, size: longInt; ts: ToStringFunction) : String_;
var
  sb: StringBuilder;
  str: String_;
  i: longInt;
begin
  sb := StringBuilder.create();
  str := String_.create('[');
  sb.append(str);
  freeAndNil(str);

  if length > 0 then begin
    str := ts(a);
    sb.append(str);
    freeAndNil(str);
  end;

  for i := 1 to length - 1 do begin
    str := String_.create(', ');
    sb.append(str);
    freeAndNil(str);
    str := ts(a + i * size);
    sb.append(str);
    freeAndNil(str);
  end;

  str := String_.create(']');
  sb.append(str);
  freeAndNil(str);
  str := sb.toString_();
  freeAndNil(sb);
  toStringPointer := str;
end;

class function Arrays.toStringObject(var a: array of Object_) : String_;
var
  sb: StringBuilder;
  str: String_;
  len, i: longInt;
begin
  len := length(a);
  sb := StringBuilder.create();
  str := String_.create('[');
  sb.append(str);
  freeAndNil(str);

  if len > 0 then begin
    if a[0] = nil then begin
      str := String_.create('null');
    end
    else begin
      str := a[0].toString_();
    end;

    sb.append(str);
    freeAndNil(str);
  end;

  for i := 1 to len - 1 do begin
    str := String_.create(', ');
    sb.append(str);
    freeAndNil(str);

    if a[i] = nil then begin
      str := String_.create('null');
    end
    else begin
      str := a[i].toString_();
    end;

    sb.append(str);
    freeAndNil(str);
  end;

  str := String_.create(']');
  sb.append(str);
  freeAndNil(str);
  str := sb.toString_();
  freeAndNil(sb);
  toStringObject := str;
end;

(**
 * Searches the specified array of bytes for the specified value using the
 * binary search algorithm
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of shortInt; key: shortInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(shortInt), @key, @_compareB);
end;

(**
 * Searches a range of the specified array of bytes for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of shortInt; fromIndex: longInt; toIndex: longInt; key: shortInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(shortInt), @key, @_compareB);
end;

(**
 * Searches the specified array of chars for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of ansiChar; key: ansiChar) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(ansiChar), @key, @_compareC);
end;

(**
 * Searches a range of the specified array of chars for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of ansiChar; fromIndex: longInt; toIndex: longInt; key: ansiChar) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(ansiChar), @key, @_compareC);
end;

(**
 * Searches the specified array of doubles for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of double; key: double) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(double), @key, @_compareD);
end;

(**
 * Searches a range of the specified array of doubles for the specified
 * value using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of double; fromIndex: longInt; toIndex: longInt; key: double) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(double), @key, @_compareD);
end;

(**
 * Searches the specified array of floats for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of single; key: single) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(single), @key, @_compareF);
end;

(**
 * Searches a range of the specified array of floats for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of single; fromIndex: longInt; toIndex: longInt; key: single) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(single), @key, @_compareF);
end;

(**
 * Searches the specified array of ints for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of longInt; key: longInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(longInt), @key, @_compareI);
end;

(**
 * Searches a range of the specified array of ints for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of longInt; fromIndex: longInt; toIndex: longInt; key: longInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(longInt), @key, @_compareI);
end;

(**
 * Searches the specified array of longs for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of int64; key: int64) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(int64), @key, @_compareL);
end;

(**
 * Searches a range of the specified array of longs for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of int64; fromIndex: longInt; toIndex: longInt; key: int64) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(int64), @key, @_compareL);
end;

(**
 * Searches the specified array for the specified object using the binary
 * search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of Object_; key: Object_) : longInt;
begin
  binarySearch := binarySearchObject(a, 0, length(a), key, ObjectComparator.create());
end;

(**
 * Searches a range of the specified array for the specified object using
 * the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of Object_; fromIndex: longInt; toIndex: longInt; key: Object_) : longInt;
begin
  binarySearch := binarySearchObject(a, fromIndex, toIndex, key, ObjectComparator.create());
end;

(**
 * Searches the specified array of shorts for the specified value using the
 * binary search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of smallInt; key: smallInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], 0, length(a), sizeOf(smallInt), @key, @_compareS);
end;

(**
 * Searches a range of the specified array of shorts for the specified value
 * using the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of smallInt; fromIndex: longInt; toIndex: longInt; key: smallInt) : longInt;
begin
  binarySearch := binarySearchPointer(@a[0], fromIndex, toIndex, sizeOf(smallInt), @key, @_compareS);
end;

(**
 * Searches the specified array for the specified object using the binary
 * search algorithm.
 *
 * @param a the array to be searched
 * @param key the value to be searched for
 * @param c the comparator by which the array is ordered. A null value
 * indicates that the elements' natural ordering should be used.
 * @return index of the search key, if it is contained in the array;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the array: the index of
 * the first element greater than the key, or a.length if all elements in
 * the array are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
class function Arrays.binarySearch(var a: array of Object_; key: Object_; c: Comparator) : longInt;
begin
  binarySearch := binarySearchObject(a, 0, length(a), key, c);
end;

(**
 * Searches a range of the specified array for the specified object using
 * the binary search algorithm.
 *
 * @param a the array to be searched
 * @param fromIndex the index of the first element (inclusive) to be
 * searched
 * @param toIndex the index of the last element (exclusive) to be searched
 * @param key the value to be searched for
 * @param c the comparator by which the array is ordered. A null value
 * indicates that the elements' natural ordering should be used.
 * @return index of the search key, if it is contained in the array within
 * the specified range; otherwise, (-(insertion point) - 1). The insertion
 * point is defined as the point at which the key would be inserted into the
 * array: the index of the first element in the range greater than the key,
 * or toIndex if all elements in the range are less than the specified key.
 * Note that this guarantees that the return value will be >= 0 if and only
 * if the key is found.
 *)
class function Arrays.binarySearch(var a: array of Object_; fromIndex: longInt; toIndex: longInt; key: Object_; c: Comparator) : longInt;
begin
  binarySearch := binarySearchObject(a, fromIndex, toIndex, key, c);
end;

(**
 * Copies the specified array, truncating or padding with false (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with false
 * elements to obtain the specified length
 *)
class function Arrays.copyOf(var original: array of boolean; newLength: longInt) : BooleanArray;
var
  copyArray: array of boolean;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(boolean), 0, newLength, @defaultBoolean);
end;

(**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of shortInt; newLength: longInt) : ShortIntArray;
var
  copyArray: array of shortInt;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(shortInt), 0, newLength, @defaultByte);
end;

(**
 * Copies the specified array, truncating or padding with null characters
 * (if necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with null
 * characters to obtain the specified length
 *)
class function Arrays.copyOf(var original: array of ansiChar; newLength: longInt) : AnsiCharArray;
var
  copyArray: array of ansiChar;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(ansiChar), 0, newLength, @defaultChar);
end;

(**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of double; newLength: longInt) : DoubleArray;
var
  copyArray: array of double;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(double), 0, newLength, @defaultDouble);
end;

(**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of single; newLength: longInt) : SingleArray;
var
  copyArray: array of single;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(single), 0, newLength, @defaultFloat);
end;

(**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of longInt; newLength: longInt) : LongIntArray;
var
  copyArray: array of longInt;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(longInt), 0, newLength, @defaultInt);
end;

(**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of int64; newLength: longInt) : Int64Array;
var
  copyArray: array of int64;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(int64), 0, newLength, @defaultLong);
end;

(**
 * Copies the specified array, truncating or padding with zeros (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with zeros to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of smallInt; newLength: longInt) : SmallIntArray;
var
  copyArray: array of smallInt;
begin
  setLength(copyArray, newLength);
  copyOf := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(smallInt), 0, newLength, @defaultShort);
end;

(**
 * Copies the specified array, truncating or padding with nulls (if
 * necessary) so the copy has the specified length.
 *
 * @param original the array to be copied
 * @param newLength the length of the copy to be returned
 * @return a copy of the original array, truncated or padded with nulls to
 * obtain the specified length
 *)
class function Arrays.copyOf(var original: array of Object_; newLength: longInt) : ObjectArray;
begin
  copyOf := copyOfRangeObject(original, 0, newLength);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with false elements to obtain the required
 * length
 *)
class function Arrays.copyOfRange(var original: array of boolean; from: longInt; to_: longInt) : BooleanArray;
var
  copyArray: array of boolean;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(boolean), from, to_, @defaultBoolean);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of shortInt; from: longInt; to_: longInt) : ShortIntArray;
var
  copyArray: array of shortInt;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(shortInt), from, to_, @defaultByte);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with null characters to obtain the required
 * length
 *)
class function Arrays.copyOfRange(var original: array of ansiChar; from: longInt; to_: longInt) : AnsiCharArray;
var
  copyArray: array of ansiChar;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(ansiChar), from, to_, @defaultChar);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of double; from: longInt; to_: longInt) : DoubleArray;
var
  copyArray: array of double;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(double), from, to_, @defaultDouble);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of single; from: longInt; to_: longInt) : SingleArray;
var
  copyArray: array of single;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(single), from, to_, @defaultFloat);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of longInt; from: longInt; to_: longInt) : LongIntArray;
var
  copyArray: array of longInt;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(longInt), from, to_, @defaultInt);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of int64; from: longInt; to_: longInt) : Int64Array;
var
  copyArray: array of int64;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(int64), from, to_, @defaultLong);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with zeros to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of smallInt; from: longInt; to_: longInt) : SmallIntArray;
var
  copyArray: array of smallInt;
begin
  setLength(copyArray, to_ - from);
  copyOfRange := copyOfRangePointer(@original[0], @copyArray[0], length(original), sizeOf(smallInt), from, to_, @defaultShort);
end;

(**
 * Copies the specified range of the specified array into a new array.
 *
 * @param original the array from which a range is to be copied
 * @param from the initial index of the range to be copied, inclusive
 * @param to the final index of the range to be copied, exclusive. (This
 * index may lie outside the array.)
 * @return a new array containing the specified range from the original
 * array, truncated or padded with nulls to obtain the required length
 *)
class function Arrays.copyOfRange(var original: array of Object_; from: longInt; to_: longInt) : ObjectArray;
begin
  copyOfRange := copyOfRangeObject(original, from, to_);
end;

(**
 * Returns true if the two specified arrays of booleans are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of boolean; a2: array of boolean) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(boolean), @_equalsBool);
end;

(**
 * Returns true if the two specified arrays of bytes are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of shortInt; a2: array of shortInt) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(shortInt), @_equalsB);
end;

(**
 * Returns true if the two specified arrays of chars are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of ansiChar; a2: array of ansiChar) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(ansiChar), @_equalsC);
end;

(**
 * Returns true if the two specified arrays of doubles are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of double; a2: array of double) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(double), @_equalsD);
end;

(**
 * Returns true if the two specified arrays of floats are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of single; a2: array of single) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(single), @_equalsF);
end;

(**
 * Returns true if the two specified arrays of ints are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of longInt; a2: array of longInt) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(longInt), @_equalsI);
end;

(**
 * Returns true if the two specified arrays of longs are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of int64; a2: array of int64) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(int64), @_equalsL);
end;

(**
 * Returns true if the two specified arrays of Objects are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of Object_; a2: array of Object_) : boolean;
begin
  equals := equalsObject(a, a2);
end;

(**
 * Returns true if the two specified arrays of shorts are equal to one
 * another.
 *
 * @param a one array to be tested for equality
 * @param a2 the other array to be tested for equality
 * @return true if the two arrays are equal
 *)
class function Arrays.equals(a: array of smallInt; a2: array of smallInt) : boolean;
var
  p, p2: pointer;
  l, l2: longInt;
begin
  l := length(a);
  l2 := length(a2);

  if length(a) = 0 then begin
    p := nil;
  end
  else begin
    p := @a[0];
  end;

  if length(a2) = 0 then begin
    p2 := nil;
  end
  else begin
    p2 := @a2[0];
  end;

  equals := equalsPointer(p, l, p2, l2, sizeOf(smallInt), @_equalsS);
end;

(**
 * Assigns the specified boolean value to each element of the specified
 * array of booleans.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of boolean; val: boolean);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(boolean), @val);
end;

(**
 * Assigns the specified boolean value to each element of the specified
 * range of the specified array of booleans.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of boolean; fromIndex: longInt; toIndex: longInt; val: boolean);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(boolean), @val);
end;

(**
 * Assigns the specified byte value to each element of the specified array
 * of bytes.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of shortInt; val: shortInt);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(shortInt), @val);
end;

(**
 * Assigns the specified byte value to each element of the specified range
 * of the specified array of bytes.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of shortInt; fromIndex: longInt; toIndex: longInt; val: shortInt);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(shortInt), @val);
end;

(**
 * Assigns the specified char value to each element of the specified array
 * of chars.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of ansiChar; val: ansiChar);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(ansiChar), @val);
end;

(**
 * Assigns the specified char value to each element of the specified range
 * of the specified array of chars.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of ansiChar; fromIndex: longInt; toIndex: longInt; val: ansiChar);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(ansiChar), @val);
end;

(**
 * Assigns the specified double value to each element of the specified array
 * of doubles.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of double; val: double);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(double), @val);
end;

(**
 * Assigns the specified double value to each element of the specified range
 * of the specified array of doubles.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of double; fromIndex: longInt; toIndex: longInt; val: double);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(double), @val);
end;

(**
 * Assigns the specified float value to each element of the specified array
 * of floats.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of single; val: single);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(single), @val);
end;

(**
 * Assigns the specified float value to each element of the specified range
 * of the specified array of floats.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of single; fromIndex: longInt; toIndex: longInt; val: single);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(single), @val);
end;

(**
 * Assigns the specified int value to each element of the specified array of
 * ints.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of longInt; val: longInt);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(longInt), @val);
end;

(**
 * Assigns the specified int value to each element of the specified range of
 * the specified array of ints.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of longInt; fromIndex: longInt; toIndex: longInt; val: longInt);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(longInt), @val);
end;

(**
 * Assigns the specified long value to each element of the specified array
 * of longs.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of int64; val: int64);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(int64), @val);
end;

(**
 * Assigns the specified long value to each element of the specified range
 * of the specified array of longs.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of int64; fromIndex: longInt; toIndex: longInt; val: int64);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(int64), @val);
end;

(**
 * Assigns the specified Object reference to each element of the specified
 * array of Objects.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of Object_; val: Object_);
begin
  fillObject(a, 0, length(a), val);
end;

(**
 * Assigns the specified Object reference to each element of the specified
 * range of the specified array of Objects.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of Object_; fromIndex: longInt; toIndex: longInt; val: Object_);
begin
  fillObject(a, fromIndex, toIndex, val);
end;

(**
 * Assigns the specified short value to each element of the specified array
 * of shorts.
 *
 * @param a the array to be filled
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of smallInt; val: smallInt);
begin
  fillPointer(@a[0], 0, length(a), sizeOf(smallInt), @val);
end;

(**
 * Assigns the specified short value to each element of the specified range
 * of the specified array of shorts.
 *
 * @param a the array to be filled
 * @param fromIndex the index of the first element (inclusive) to be filled
 * with the specified value
 * @param toIndex the index of the last element (exclusive) to be filled
 * with the specified value
 * @param val the value to be stored in all elements of the array
 *)
class procedure Arrays.fill(var a: array of smallInt; fromIndex: longInt; toIndex: longInt; val: smallInt);
begin
  fillPointer(@a[0], fromIndex, toIndex, sizeOf(smallInt), @val);
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of shortInt);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(shortInt), @_compareB);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of shortInt; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(shortInt), @_compareB);
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of ansiChar);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(ansiChar), @_compareC);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of ansiChar; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(ansiChar), @_compareC);
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of double);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(double), @_compareD);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of double; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(double), @_compareD);
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of single);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(single), @_compareF);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of single; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(single), @_compareF);
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of longInt);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(longInt), @_compareI);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of longInt; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(longInt), @_compareI);
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of int64);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(int64), @_compareL);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of int64; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(int64), @_compareL);
end;

(**
 * Sorts the specified array of objects into ascending order, according to
 * the natural ordering of its elements.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of Object_);
begin
  sortObject(a, 0, length(a), ObjectComparator.create());
end;

(**
 * Sorts the specified range of the specified array of objects into
 * ascending order, according to the natural ordering of its elements.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of Object_; fromIndex: longInt; toIndex: longInt);
begin
  sortObject(a, fromIndex, toIndex, ObjectComparator.create());
end;

(**
 * Sorts the specified array into ascending numerical order.
 *
 * @param a the array to be sorted
 *)
class procedure Arrays.sort(var a: array of smallInt);
begin
  sortPointer(@a[0], 0, length(a), sizeOf(smallInt), @_compareS);
end;

(**
 * Sorts the specified range of the array into ascending order.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 *)
class procedure Arrays.sort(var a: array of smallInt; fromIndex: longInt; toIndex: longInt);
begin
  sortPointer(@a[0], fromIndex, toIndex, sizeOf(smallInt), @_compareS);
end;

(**
 * Sorts the specified array of objects according to the order induced by
 * the specified comparator.
 *
 * @param a the array to be sorted
 * @param c the comparator to determine the order of the array. A null value
 * indicates that the elements' natural ordering should be used.
 *)
class procedure Arrays.sort(var a: array of Object_; c: Comparator);
begin
  sortObject(a, 0, length(a), c);
end;

(**
 * Sorts the specified range of the specified array of objects according to
 * the order induced by the specified comparator.
 *
 * @param a the array to be sorted
 * @param fromIndex the index of the first element (inclusive) to be sorted
 * @param toIndex the index of the last element (exclusive) to be sorted
 * @param c the comparator to determine the order of the array. A null value
 * indicates that the elements' natural ordering should be used.
 *)
class procedure Arrays.sort(var a: array of Object_; fromIndex: longInt; toIndex: longInt; c: Comparator);
begin
  sortObject(a, fromIndex, toIndex, c);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of boolean) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(boolean), @_toStringBool);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of shortInt) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(shortInt), @_toStringB);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of ansiChar) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(ansiChar), @_toStringC);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of double) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(double), @_toStringD);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of single) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(single), @_toStringF);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of longInt) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(longInt), @_toStringI);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of int64) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(int64), @_toStringL);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of Object_) : String_;
begin
  toString := toStringObject(a);
end;

(**
 * Returns a string representation of the contents of the specified array.
 *
 * @param a the array whose string representation to return
 * @return a string representation of a
 *)
class function Arrays.toString(var a: array of smallInt) : String_;
begin
  toString := toStringPointer(@a[0], length(a), sizeOf(smallInt), @_toStringS);
end;

end.
