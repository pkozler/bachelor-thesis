unit ArrayListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit;

type
  TObjectArray = array of TObject;

  ArrayList = class
    private
      const
           DEFAULT_CAPACITY = 10;
           RESIZE_COEF = 2;
      var
        dynamicArray: array of TObject;
        count: longInt;
      procedure expand();
      procedure shrink();
    public
      constructor create();
      constructor create(c: ArrayList);
      destructor destroy(); override;
      function getArray() : TObjectArray;
      function add(e: TObject) : boolean;
      procedure add(index: longInt; element: TObject);
      function get(index: longInt) : TObject;
      function set_(index: longInt; element: TObject) : TObject;
      function remove(index: longInt) : TObject;
      function size() : longInt;
      function isEmpty() : boolean;
      procedure clear();
      function toString() : ansiString; override;
      function toString() : String_;
  end;

implementation

uses
  Classes, SysUtils;

constructor ArrayList.create();
begin
  setLength(dynamicArray, DEFAULT_CAPACITY);
  count := 0;
end;

constructor ArrayList.create(c: ArrayList);
var
  len, i: longInt;
begin
  setLength(dynamicArray, length(c.dynamicArray));
  count := c.count;

  for i := 0 to count - 1 do begin
    dynamicArray[i] := c.dynamicArray[i];
  end;
end;

destructor ArrayList.destroy();
begin
  inherited;
end;

procedure ArrayList.expand();
var
  len: longInt;
begin
  inc(count);
  len := length(dynamicArray);

  if count = len then begin
    setLength(dynamicArray, len * RESIZE_COEF);
  end;
end;

procedure ArrayList.shrink();
var
  len: longInt;
begin
  dec(count);
  len := length(dynamicArray);

  if (count < len div RESIZE_COEF) and (len >= DEFAULT_CAPACITY * RESIZE_COEF) then begin
    setLength(dynamicArray, len div RESIZE_COEF);
  end;
end;

function ArrayList.getArray() : TObjectArray;
begin
  getArray := dynamicArray;
end;

function ArrayList.add(e: TObject) : boolean;
begin
  dynamicArray[count] := e;
  expand();
  add := true;
end;

procedure ArrayList.add(index: longInt; element: TObject);
var
  i: longInt;
begin
  for i := count downto index + 1 do begin
    dynamicArray[i] := dynamicArray[i - 1];
  end;

  dynamicArray[index] := element;
  expand();
end;

function ArrayList.get(index: longInt) : TObject;
begin
  get := dynamicArray[index];
end;

function ArrayList.set_(index: longInt; element: TObject) : TObject;
var
  original: TObject;
begin
  original := dynamicArray[index];
  dynamicArray[index] := element;
  set_ := original;
end;

function ArrayList.remove(index: longInt) : TObject;
var
  removed: TObject;
  i: longInt;
begin
  removed := dynamicArray[index];

  for i := index to count - 1 do begin
    dynamicArray[i] := dynamicArray[i + 1];
  end;

  shrink();
  remove := removed;
end;

function ArrayList.size() : longInt;
begin
  size := count;
end;

function ArrayList.isEmpty() : boolean;
begin
  isEmpty := (count = 0);
end;

procedure ArrayList.clear();
begin
  setLength(dynamicArray, 0);
  count := 0;
  setLength(dynamicArray, DEFAULT_CAPACITY);
end;

function ArrayList.toString() : ansiString;
var
  s: ansiString;
  i: longInt;
begin
  s := '[';

  if count > 0 then begin
    s += dynamicArray[0].toString();
  end;

  for i := 1 to count - 1 do begin
    s += ', ' + dynamicArray[i].toString();
  end;

  s += ']';
  toString := s;
end;

function ArrayList.toString() : String_;
begin
  toString := String_.create(ToString());
end;

end.

